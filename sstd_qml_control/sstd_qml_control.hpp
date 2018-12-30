#pragma once

#include "sstd_qml_control_global.hpp"
class EXPORT_SSTD_QML_CONTROL SSTDQmlControlPlugin :
    public QQmlExtensionPlugin ,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(SSTDQmlControlPlugin) {
    Q_OBJECT
private:
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    void registerTypes(const char *uri);
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(SSTDQmlControlPlugin);
};


















