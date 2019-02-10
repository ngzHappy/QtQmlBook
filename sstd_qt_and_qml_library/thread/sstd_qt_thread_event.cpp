#include "sstd_qt_thread_event.hpp"

static inline QEvent::Type getThreadEventType() {
    const static auto varAns =
        static_cast<QEvent::Type>( QEvent::registerEventType() );
    return varAns;
}

QEvent::Type sstd_qt_thread_event::getThreadEventType() {
    return ::getThreadEventType();
}

sstd_qt_thread_event::sstd_qt_thread_event() :
    QEvent(getThreadEventType()) {
}
