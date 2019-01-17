
#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string_view>
using namespace std::string_literals;
using namespace std::string_view_literals;

class OutPutStream : public std::ofstream {
    using super = std::ofstream;
public:
    template<typename T,
             typename = std::enable_if_t<
                 std::is_constructible_v<super,T&& >>>
    inline OutPutStream(T && arg) :
        super(std::forward<T>(arg),std::ios::binary) {
    }
    template<typename T,
             typename = void,
             typename = std::enable_if_t<
                 !std::is_constructible_v<super,T&& >>>
    inline OutPutStream(T && arg) :
        super(std::forward<T>(arg).string(),std::ios::binary) {
    }
};

int main(int argc,char ** argv){

    if(argc<1){
        return -1;
    }

    fs::path varRootPath {argv[1]};
    fs::path varRootFileName{ varRootPath/"msvc_boost.pri"s };
    OutPutStream varStream{ varRootFileName };

    fs::directory_iterator varIt{varRootPath};
    const fs::directory_iterator varEnd{};

    std::vector<std::string> varFileNames{};
    for(;varIt!=varEnd;++varIt){
        const auto & varFilePath = varIt->path();
        varFileNames.emplace_back( varFilePath.filename().string() );
    }

    std::vector<std::string> varRelease{};
    std::vector<std::string> varDebug{};
    for(auto & varName : varFileNames ){
        if(varName.find(".lib"sv)==std::string::npos){
            continue;
        }
        if(varName.find("lib")==0){
            auto varName1 = varName.substr(3);
            fs::rename(varRootPath/varName,varName1);
            varName=std::move(varName1);
        }
        if(varName.find("-gd-"sv)==std::string::npos){
            varRelease.push_back(varName);
        }else{
            varDebug.push_back(varName);
        }
    }


    varStream << "CONFIG(debug,debug|release){"sv << std::endl ;
    for(const auto & varName : varRelease){
        varStream << "    LIBS+= -l"sv
                  << varName.substr(0,varName.size()-4)
                  << std::endl;
    }
    varStream << "}else{"sv << std::endl ;
    for(const auto & varName : varDebug ){
        varStream << "    LIBS+= -l"sv
                  << varName.substr(0,varName.size()-4)
                  << std::endl;
    }
     varStream << "}"sv << std::endl ;

}






























