
#include <string>
#include <string_view>
using namespace std::string_literals;
using namespace std::string_view_literals;

#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#include <list>
#include <vector>

#include <iostream>
#include <fstream>

#include <regex>

inline static std::string get_file_path(const fs::path & arg) {
    return fs::canonical(arg).string();
}

inline static std::string_view trim_right(const std::string & arg) {
    if (arg.empty()) {
        return ""sv;
    }
    const auto varLastPos =
        arg.find_last_not_of(" \r\n"sv);
    if (varLastPos == std::string::npos) {/*empty line ...*/
        return ""sv;
    }
    return std::string_view{ arg.c_str(), 1 + varLastPos };
}

inline static void cast_a_file(const fs::path & arg) {

    std::list<std::string > varLines;

    const auto varFileName = get_file_path(arg);
    {
        std::ifstream varInput{ varFileName ,std::ios::binary };
        if (!varInput.is_open()) {
            return;
        }
        while (varInput.good()) {
            auto & varLine = varLines.emplace_back();
            std::getline(varInput, varLine);
        }
    }

    if (varLines.empty()) {
        return;
    }

    std::vector< std::string_view > varAllAboutToWrite;
    varAllAboutToWrite.reserve( varLines.size() );
    for (const auto & varLine : varLines) {
        varAllAboutToWrite.push_back ( trim_right(varLine) ) ;
    }

    while (!varAllAboutToWrite.empty()) {
        if (varAllAboutToWrite.back().empty()) {
            varAllAboutToWrite.pop_back();
        } else {
            break;
        }
    }

    const constexpr char varRawBom[ 4 ]{static_cast<char>( 0x0ef ),
                static_cast<char>(0x0bb),
                static_cast<char>(0x0bf),
                static_cast<char>(0x00)};

    std::ofstream varOutPut{ varFileName,std::ios::binary };
    if(varAllAboutToWrite.empty()){
        const std::string_view varBom{ varRawBom,3 };
        varOutPut << varBom << "\n"sv;
        return;
    }

    {
        const auto & varFirstLine = varAllAboutToWrite[0];
        bool varNeedWriteBom=false;
        if(varFirstLine.size()<3){
            varNeedWriteBom=true;
        }else{
            if((varFirstLine[0]!=varRawBom[0])||
               (varFirstLine[1]!=varRawBom[1])||
               (varFirstLine[2]!=varRawBom[2])){
                varNeedWriteBom=true;
            }
        }
        if(varNeedWriteBom){
            const std::string_view varBom{ varRawBom,3 };
            varOutPut << varBom;
        }
    }

    for (const auto & varLine : varAllAboutToWrite) {
        varOutPut << varLine << "\n"sv;
    }

}

inline static void castCRLFOrCRToLF(const fs::path & arg) {
    if (!fs::is_directory(arg)) {
        return;
    }
    std::list<fs::path> varAboutToDo;
    {
        fs::recursive_directory_iterator varIt{ arg };
        fs::recursive_directory_iterator const varEnd;
        for (; varIt != varEnd; ++varIt) {
            if (!fs::is_regular_file(*varIt)) {
                continue;
            }
            const auto & varFileNamePath = varIt->path();
            const auto varFileName =
                varFileNamePath.filename().string();
            const static std::regex varCheckFormat{
                u8R"!(^[^.].*\.(?:(?:txt)|(?:cpp)|(?:c)|(?:h)|(?:hpp)|(?:hxx)|(?:qml)|(?:tex))$)!" ,
                std::regex_constants::icase | std::regex_constants::ECMAScript
            };
            if (std::regex_match(varFileName, varCheckFormat)) {
                varAboutToDo.push_back(varFileNamePath);
            }
        }
    }
    for (const auto & varI : varAboutToDo) {
        cast_a_file(varI);
    }
}

int main(int,char **){
    fs::path varPath{ CURRENT_DEBUG_PATH };
    castCRLFOrCRToLF( varPath / ".." / ".." );
}
