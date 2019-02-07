#pragma once

#include <sstd_library.hpp>
#include <QtCore/qobject.h>
#include <QtCore/qthread.h>
#include "sstd_qt_thread_event.hpp"
#include "../global/sstd_qt_and_qml_global.hpp"

class EXPORT_SSTD_QT_AND_QML_LIBRARY sstd_qt_thread_object :
    public QObject,
    public sstd_qt_thread_event,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(sstd_qt_thread_object) {
    Q_OBJECT
public:
    sstd_qt_thread_object();
    ~sstd_qt_thread_object() override;
protected:
    bool event(QEvent *) override;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_object);
};






