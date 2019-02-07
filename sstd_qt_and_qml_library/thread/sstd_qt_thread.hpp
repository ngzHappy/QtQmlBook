#pragma once

#include <future>
#include <exception>
#include <QtCore/qcoreapplication.h>
#include "sstd_qt_thread_object.hpp"
#include "sstd_qt_thread_event.hpp"
#include "../global/sstd_qt_and_qml_global.hpp"

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

    class EXPORT_SSTD_QT_AND_QML_LIBRARY AnsWatcher :
        public QObject,
        public std::future<void>,
        public sstd_intrusive_ptr_basic,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(AnsWatcher) {
        Q_OBJECT
    private:
        bool mmmIsFunctionCalled{ false };
    public:
        AnsWatcher(std::future<void>);
        inline bool isFunctionCalled() const {
            return mmmIsFunctionCalled;
        }
        Q_SIGNAL void finished();
    protected:
        inline void setFunctionCalled() {
            mmmIsFunctionCalled = true;
        }
        inline void callFinished() {
            this->finished();
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(AnsWatcher);
    };

}/**/

namespace sstd {
    namespace _12_sstd_private {

        class ThreadWatcher_ final :
            public AnsWatcher,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(ThreadWatcher_) {
        public:
            inline void setFunctionCalled() {
                AnsWatcher::setFunctionCalled();
            }
            inline void callFinished() {
                try {
                    AnsWatcher::callFinished();
                } catch (...) {
                }
            }
            inline ThreadWatcher_(std::future<void> && arg) :
                AnsWatcher(std::move(arg)) {
            }
            SSTD_END_DEFINE_VIRTUAL_CLASS(ThreadWatcher_);
        };

        template<typename F>
        class sstd_call_in_qthread_ final :
            public sstd_qt_thread_object,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(sstd_call_in_qthread_<F>){
            F mmmFunction;
            std::promise<void> mmmPromise;
            sstd::intrusive_ptr< ThreadWatcher_ > mmmWatcher;
        public:
            inline void call_thread_event() noexcept override {
                mmmWatcher->setFunctionCalled();
                try {
                    mmmFunction();
                    mmmPromise.set_value();
                } catch (...) {
                    mmmPromise.set_exception(std::current_exception());
                }
                mmmWatcher->callFinished();
            }
            inline ~sstd_call_in_qthread_() {
                if (mmmWatcher->isFunctionCalled()) {
                    return;
                }
                mmmPromise.set_value();
                mmmWatcher->callFinished();
                return;
            }
            inline sstd_call_in_qthread_() {
                mmmWatcher = sstd_new< ThreadWatcher_ >(
                    mmmPromise.get_future());
            }
            inline sstd::intrusive_ptr< ThreadWatcher_ > getWatcher() const {
                return mmmWatcher;
            }
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_call_in_qthread_);
        };

    }/**/
}/**/

template<typename TF>
inline sstd::intrusive_ptr< sstd::AnsWatcher >
sstd_call_in_qthread(TF && f, QThread * arg) {

    using FunctionType_ = sstd::_12_sstd_private::sstd_call_in_qthread_<
        std::remove_cv_t< std::remove_reference_t<TF> > >;

    if (QThread::currentThread() == arg) {
        /*direct call the function*/
        std::promise< void > varPromise;
        auto varAns = sstd_new< sstd::_12_sstd_private::ThreadWatcher_ >(
            varPromise.get_future());
        varAns->setFunctionCalled();
        try {
            f();
            varPromise.set_value();
        } catch (...) {
            varPromise.set_exception(std::current_exception());
        }
        varAns->callFinished();
        return varAns;
    } else {
        auto varFunction =
            sstd_new< FunctionType_ >(std::forward<TF>(f));
        auto varAns = varFunction->getWatcher();
        varFunction->moveToThread(arg);
        QCoreApplication::postEvent(varFunction, varFunction);
        return std::move(varAns);
    }

}




