
#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

#include <iostream>
#include <fstream>

#include <string>
using namespace std::string_literals;

int main(int ,char ** argv){

    fs::path varRootFileName{ argv[0] };
    

}






























