#include "sstd_qml_control.hpp"
#include "TestData.hpp"
#include "GlobalObject.hpp"

void SSTDQmlControlPlugin::registerTypes(const char *uri) {
#ifdef _DEBUG
    std::string_view argUri{ uri };
    assert(argUri == "sstd.qml.control"sv);
#endif
    qmlRegisterType<TestData>(uri, 1, 0, "TestData");
    qmlRegisterSingletonType<GlobalObject>(uri, 1, 0,
        "GlobalObject",
        &GlobalObject::instance);
}













