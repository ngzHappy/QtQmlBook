#include "AttachedGlobalObject.hpp"

AttachedGlobalObject *AttachedGlobalObject::qmlAttachedProperties(QObject * arg) {
    return sstd_new<AttachedGlobalObject>(arg);
}

AttachedGlobalObject::AttachedGlobalObject(QObject * arg)
    :QObject(arg) {
}
