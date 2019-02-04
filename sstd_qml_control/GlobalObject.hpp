#pragma once

#include <chrono>
#include "sstd_qml_control_global.hpp"

class EXPORT_SSTD_QML_CONTROL GlobalObject : public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(GlobalObject) {
    Q_OBJECT
public:
    Q_SLOT qint64 getTimeSinceProgramStart() const;
public:
    GlobalObject();
public:
    static GlobalObject * instanceRaw();
    static QObject * instance(QQmlEngine *, QJSEngine *);
private:
    const std::chrono::steady_clock::time_point mmmStartTime;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(GlobalObject);
};

/**
Creating C++ Plugins for QML
**/
