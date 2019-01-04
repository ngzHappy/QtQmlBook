#include "sstd_qml_control.hpp"
#include "TestData.hpp"

#ifdef _DEBUG
/*debug 模式下copy sstd control files*/
#include <mutex>
inline static void copy_once() {
    static std::once_flag copy_once_flag;
    std::call_once(copy_once_flag, []() {
        const QDir varFromDirRoot{ MocFromDir };
        const QDir varToDirRoot{ MocToDir };
        sstd::copyDir(
            varFromDirRoot.absoluteFilePath(QStringLiteral(
                "sstd")),
            varToDirRoot.absoluteFilePath(QStringLiteral(
                "sstd")));
    });
}
#endif

void SSTDQmlControlPlugin::registerTypes(const char *uri) {
#ifdef _DEBUG
    std::string_view argUri{ uri };
    assert(argUri == "sstd.qml.control"sv);
    copy_once();
#endif
    qmlRegisterType<TestData>(uri, 1, 0, "TestData");
}













