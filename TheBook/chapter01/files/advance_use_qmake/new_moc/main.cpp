#include <iostream>
#include <fstream>

#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

int main(int,char ** argv){
    std::ifstream varInput{  argv[1] };
    std::ofstream varOutput{ argv[2] };
    varOutput<<"/*****************************/";
    varOutput<<std::endl;
    varOutput<<"inline static int a = 1 ; ";
    varOutput<<std::endl;
    return 0;
}














