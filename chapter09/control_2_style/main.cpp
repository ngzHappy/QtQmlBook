#include <sstd_qt_and_qml_library.hpp>

inline static void set_sstd_qml2_style() {
    const QDir varDir{ qApp->applicationDirPath() };
    ::qputenv("QT_QUICK_CONTROLS_CONF",
        varDir.absoluteFilePath(
            QStringLiteral("sstd/qml/control/sstdstyle_qtquickcontrols2.conf")
        ).toLocal8Bit());
}

int main(int argc, char ** argv) {

    /*初始化程序*/
    auto varApp = sstd_make_unique< sstd::Application >(argc, argv);
    set_sstd_qml2_style();
    /*初始化Qml/Quick引擎*/
    auto varWindow = sstd_make_unique< sstd::DefaultRoowWindow >();
    {
        /*获得Qml文件绝对路径*/
        auto varFullFileName = sstd::getLocalFileFullPath(
            QStringLiteral("myqml/control_2_style/main.qml"));
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







