#pragma once

#include <sstd_qt_and_qml_library.hpp>

class QmlApplicationEngine :
    public QQmlApplicationEngine,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(QmlApplicationEngine) {
private:
    Q_OBJECT
public:
    QmlApplicationEngine();
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(QmlApplicationEngine);
};













