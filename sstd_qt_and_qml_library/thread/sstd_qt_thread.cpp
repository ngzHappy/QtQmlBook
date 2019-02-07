#include "sstd_qt_thread.hpp"
#include <QtCore/qcoreapplication.h>

namespace sstd {

    Thread::Thread() {
        assert(qApp);
        assert(qApp->thread());
        this->moveToThread(qApp->thread());
        connect(
            this, &QThread::finished, 
            this, &QObject::deleteLater,
            Qt::QueuedConnection);
    }

}/**/
