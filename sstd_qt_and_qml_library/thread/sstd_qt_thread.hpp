#pragma once

#include <QtCore/qobject.h>
#include <QtCore/qthread.h>
#include "../global/sstd_qt_and_qml_global.hpp"
#include <sstd_library.hpp>

class EXPORT_SSTD_QT_AND_QML_LIBRARY sstd_qt_thread_object :
        public QObject ,
        public virtual sstd_intrusive_ptr_basic,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_object) {
    Q_OBJECT
public:

private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_object);
};

EXPORT_SSTD_QT_AND_QML_LIBRARY auto sstd_get_thread_object(QThread *)
->sstd::intrusive_ptr<sstd_qt_thread_object>;



