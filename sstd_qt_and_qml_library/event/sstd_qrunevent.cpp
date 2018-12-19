#include "sstd_qrunevent.hpp"
#include <QtCore/qcoreapplication.h>

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

    bool MultiRunEvent::doNotCallNext() {
        return false;
    }

    void MultiRunEvent::append(RunEvent * arg) {
        if (arg && mmmData) {
            mmmData->events.emplace_back(arg);
        } else {
            delete arg;
        }
    }

    void MultiRunEvent::start() {
        bool varDeleteThis = true;
        if (mmmData) {
            auto varTarget = mmmData->target.data();
            if (varTarget) {
                QCoreApplication::postEvent(varTarget, this, mmmData->priority);
                varDeleteThis = false;
            }
        }
        if (varDeleteThis) {
            delete this;
        }
    }

    MultiRunEvent::MultiRunEvent(
        std::unique_ptr<
        _private_api_function::MultiRunEventData> && arg) :
        mmmData(std::move(arg)) {
    }

    void MultiRunEvent::run() {
        if (mmmData) {
            if (false == doNotCallNext()) {
                auto varTarget = mmmData->target.data();
                if (varTarget) {
                    if (mmmData->events.empty() == false) {
                        const auto varPriority = mmmData->priority;
                        auto varEvent = std::move(mmmData->events.front());
                        mmmData->events.pop_front();
                        varEvent->run()/*call the event ...*/;
                        if (mmmData->events.empty() == false) {
                            /*post next event ...*/
                            QCoreApplication::postEvent(
                                varTarget,
                                this->clone().release(),
                                varPriority);
                        }
                    }
                }
            }
        }
    }


}/*namespace sstd*/









