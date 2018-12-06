#pragma once

#include "../sstd_qt_thread.hpp"

class _sstd_register_qthread_object_private;
class sstd_register_qthread_object_private :
        public QObject ,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(sstd_register_qthread_object_private){
    Q_OBJECT
public:
    sstd_register_qthread_object_private();
    Q_SLOT void remove_qthread(QThread * );
    sstd::intrusive_ptr<_0_sstd_qt_thread_object> add_qthread(QThread * );
    sstd::intrusive_ptr<_0_sstd_qt_thread_object> find_qthread(QThread *);
private:
    sstd::intrusive_ptr< sstd_intrusive_ptr_basic > mmmData;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_register_qthread_object_private);
};


extern sstd_register_qthread_object_private * instance_sstd_register_qthread_object_private();




