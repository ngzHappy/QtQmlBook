#pragma once

#include "GlobalObject.hpp"
#include "sstd_qml_control_global.hpp"


class AttachedGlobalObject :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(AttachedGlobalObject){
    Q_OBJECT
public:
    AttachedGlobalObject(QObject *arg);
    static AttachedGlobalObject *qmlAttachedProperties(QObject *object);
public slots:
    inline qint64 getTimeSinceProgramStart() const;
private:
    GlobalObject * const mmmData{
        GlobalObject::instanceRaw() };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(AttachedGlobalObject);
};

inline qint64 AttachedGlobalObject::getTimeSinceProgramStart() const {
    return mmmData->getTimeSinceProgramStart();
}

QML_DECLARE_TYPEINFO(AttachedGlobalObject, QML_HAS_ATTACHED_PROPERTIES)

/**
Defining QML Types from C++
**/
