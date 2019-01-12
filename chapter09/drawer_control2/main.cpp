/*drawer_control2/main.cpp*/
#include <sstd_qt_and_qml_library.hpp>
#include "QmlApplicationEngine.hpp"

int main(int argc, char ** argv) {

    /*初始化程序*/
    auto varApp = sstd_make_unique< sstd::Application >(argc, argv);
    /*初始化Qml/Quick引擎*/
    auto varWindow = sstd_make_unique< QmlApplicationEngine >();
    {
        /*获得Qml文件绝对路径*/
        auto varFullFileName = sstd::getLocalFileFullPath(
            QStringLiteral("myqml/drawer_control2/main.qml"));
        /*加载Qml文件*/
        varWindow->load(varFullFileName);
    }

    return varApp->exec();

}


