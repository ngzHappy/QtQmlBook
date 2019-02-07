#include "sstd_qt_thread_object.hpp"

sstd_qt_thread_object::sstd_qt_thread_object() {

}

sstd_qt_thread_object::~sstd_qt_thread_object() {

}

bool sstd_qt_thread_object::event(QEvent * e) {
    if (e->type() == sstd_qt_thread_event::getThreadEventType()) {
        auto var =
            static_cast<sstd_qt_thread_event *>(e);
        var->call_thread_event();
        return true;
    }
    return QObject::event(e);
}





