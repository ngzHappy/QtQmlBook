#include "sstd_qt_thread.hpp"
#include "sstd_private/sstd_qt_thread_private.hpp"


EXPORT_SSTD_QT_AND_QML_LIBRARY auto sstd_get_thread_object(QThread *)
->sstd::intrusive_ptr<sstd_qt_thread_object>{

}









