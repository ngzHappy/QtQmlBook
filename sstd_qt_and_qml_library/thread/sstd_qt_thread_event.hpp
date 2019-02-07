#pragma once

#include <sstd_library.hpp>
#include <QtCore/qcoreevent.h>
#include <QtCore/qthread.h>
#include "../global/sstd_qt_and_qml_global.hpp"

class EXPORT_SSTD_QT_AND_QML_LIBRARY sstd_qt_thread_event :
    public QEvent ,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_event) {
public:
    static QEvent::Type getThreadEventType();
    sstd_qt_thread_event();
    virtual void call_thread_event() noexcept = 0 ;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_event);
};




