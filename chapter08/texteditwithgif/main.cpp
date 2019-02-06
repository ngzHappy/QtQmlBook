/*texteditwithgif/main.cpp*/
#include <sstd_qt_and_qml_library.hpp>

int main(int argc, char ** argv) {

    /*初始化程序*/
    auto varApp = sstd_make_unique< sstd::Application >(argc, argv);
    /*初始化Qml/Quick引擎*/
    auto varEngine = sstd_make_unique< sstd::QmlApplicationEngine >();
    {
        /*获得Qml文件绝对路径*/
        auto varFullFileName = sstd::getLocalFileFullPath(
            QStringLiteral("myqml/texteditwithgif/main.qml"));
        /*加载Qml文件*/
        varEngine->load(varFullFileName);
        /*检查并报错*/
        if (varEngine->rootObjects().isEmpty()) {
            qWarning() 
                << QStringLiteral("can not load : ") 
                << varFullFileName;
            return -1;
        }
    }

    return varApp->exec();

}
