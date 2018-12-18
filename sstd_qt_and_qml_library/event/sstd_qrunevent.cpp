#include "sstd_qrunevent.hpp"

namespace sstd {

    QEvent::Type RunEvent::getEventID() {
        const static auto varAns =
            static_cast<QEvent::Type>(
                QEvent::registerEventType());
        return varAns;
    }

    RunEvent::RunEvent() :
        QEvent(RunEvent::getEventID()) {
    }

}/*namespace sstd*/









