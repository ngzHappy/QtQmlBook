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

inline const std::string & bom(){
    const static std::string varAns = "\xEF\xBB\xBF"s;
    return varAns;
}

inline std::string replace(
        const std::string & argInput,
        const std::string & argKey,
        const std::string & argValue){
    auto varPos = argInput.find(argKey);
    if(varPos==std::string::npos){
        return argInput;
    }
    std::string varAns = argInput;
    for(;;){
        varAns.replace(varPos,argKey.size(),argValue);
        varPos = varAns.find(argKey);
        if(varPos==std::string::npos){
            return std::move(varAns);
        }
    }
    return std::move(varAns);
}

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

class Application{
    std::string fileName;
public:
    inline Application(const char * argFileName ) :
        fileName(argFileName) {}
    inline void create_main_cpp(const fs::path & arg){
        OutPutStream varOutPutStream{ arg / "main.cpp"s };
        const auto varAns = replace(
                    u8R"_1_2_(/*#outputdirname#/main.cpp*/
#include <sstd_qt_and_qml_library.hpp>

int main(int argc, char ** argv) {

    /*初始化程序*/
    auto varApp = sstd_make_unique< sstd::Application >(argc, argv);
    /*初始化Qml/Quick引擎*/
    auto varWindow = sstd_make_unique< sstd::DefaultRoowWindow >();
    {
        /*获得Qml文件绝对路径*/
        auto varFullFileName = sstd::getLocalFileFullPath(
            QStringLiteral("myqml/#outputdirname#/main.qml"));
        /*加载Qml文件*/
        varWindow->load(varFullFileName);
        /*检查并报错*/
        if (varWindow->status() != sstd::LoadState::Ready) {
            qWarning() << QStringLiteral("can not load : ") << varFullFileName;
            return -1;
        }
    }
    varWindow->show();

    return varApp->exec();

}
)_1_2_"s,
                    "#outputdirname#"s,
                    fileName);
        varOutPutStream << bom() << varAns ;
    }
    inline void create_pro(const fs::path & arg){
        OutPutStream varOutPutStream{ arg / ( fileName + ".pro"s) };
        const auto varAns = replace(
u8R"_1_2_(##outputdirname#.pro
TEMPLATE = app

CONFIG(debug,debug|release){
    TARGET = #outputdirname#_debug
}else{
    TARGET = #outputdirname#
}

#define out put dir
include($$PWD/../../outdirpath.pri)
#define cplusplus environment
include($$PWD/../../cplusplus.pri)
#import sstd_library
include($$PWD/../../sstd_library/import_sstd_library.pri)
#import sstd_qt_and_qml_library
include($$PWD/../../sstd_qt_and_qml_library/import_sstd_qt_and_qml_library.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

win32-msvc*{
    CONFIG += console
}

DEFINES += CURRENT_DEBUG_PATH=\\\"$$PWD\\\"

DESTDIR = $${RootDestDir}

SOURCES += $$PWD/main.cpp

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${DESTDIR}/build_install_debug $$PWD "myqml"
}else{
    QMAKE_POST_LINK += $${DESTDIR}/build_install $$PWD "myqml"
}
export(QMAKE_POST_LINK)

QMLSOURCES += $$PWD/myqml/#outputdirname#/main.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES
)_1_2_"s,
                    "#outputdirname#"s,
                    fileName);
        varOutPutStream << varAns;
    }
    inline void create_qml_main(const fs::path & arg){
        fs::create_directory( arg/"myqml"s );
        auto varOutPutDir = arg/"myqml"s/fileName ;
        fs::create_directory( varOutPutDir );
        OutPutStream varOutPutStream{ varOutPutDir / "main.qml"s };
        const auto varAns = replace(u8R"_1_2_(/*#outputdirname#/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);
}

)_1_2_"s,
                                    "#outputdirname#"s,
                                    fileName);
        varOutPutStream << bom() << varAns;
    }
    inline int exec(){
        fs::path varOutPutDir{ fileName };
        /*在当前目录创建文件夹*/
        fs::create_directory(varOutPutDir);
        /*创建main.cpp*/
        create_main_cpp(varOutPutDir);
        /*创建pro文件*/
        create_pro(varOutPutDir);
        /*创建qml文件*/
        create_qml_main(varOutPutDir);
        return 0;
    }
};


int main(int argc,char ** argv) try {

    if(argc<2) {
        return -1;
    }

    Application varApplication{argv[1]};
    return varApplication.exec();

}catch(...){
    return -2;
}














