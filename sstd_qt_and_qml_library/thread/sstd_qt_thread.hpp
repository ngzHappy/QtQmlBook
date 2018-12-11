#pragma once

#include "sstd_qt_thread_object.hpp"

namespace sstd {

    class EXPORT_SSTD_QT_AND_QML_LIBRARY Thread :
        public QThread,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Thread) {
        Q_OBJECT
    public:
        Thread();
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Thread);
    };

}/**/






