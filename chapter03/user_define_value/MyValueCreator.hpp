#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "MyValue.hpp"

class MyValueCreator :
    public QObject ,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MyValueCreator) {
    Q_OBJECT
public:
    MyValueCreator();
public:
    Q_INVOKABLE QVariant create(double x,double y);
public:
    static QObject * instance(QQmlEngine *, QJSEngine *);
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MyValueCreator);
};






