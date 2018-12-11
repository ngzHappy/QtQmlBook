#include "sstd_qt_thread_object.hpp"
#include "sstd_private/sstd_qt_thread_private.hpp"
#include <QtCore/qcoreapplication.h>
#include <cassert>
#include <atomic>

inline static sstd::intrusive_ptr<_0_sstd_qt_thread_object> _sstd_get_main_thread_object() {
    assert(qApp);
    assert(qApp->thread());
    return _0_sstd_get_thread_object(qApp->thread());
}

inline static sstd::intrusive_ptr<_0_sstd_qt_thread_object> sstd_get_main_thread_object() {
    static sstd::intrusive_ptr<_0_sstd_qt_thread_object> varAns
        = _sstd_get_main_thread_object();
    return varAns;
}

namespace {
    class RegisterData {
    public:
        std::recursive_mutex mutex;
    };
}/**/

sstd_qt_thread_object::sstd_qt_thread_object(_0_sstd_qt_thread_object * arg) {
    this->moveToThread(qApp->thread());
    connect(this, &sstd_qt_thread_object::_call_private_,
        arg, &_0_sstd_qt_thread_object::_call_private_,
        Qt::QueuedConnection);
}

void sstd_qt_thread_call_object::_do_exception() noexcept {
    if (false == this->mmmHasException) {
        this->mmmHasException = true;
        mmmPromise.set_exception(std::current_exception());
    }
}

sstd_qt_thread_call_object::~sstd_qt_thread_call_object() {

    if (mmmIsCalled) {
        return;
    }
    mmmIsCalled = true;
    mmmExitButNoCall = true;

    try {
        this->exitButNoCall();
        this->mmmPromise.set_value();
    } catch (...) {
        this->_do_exception();
    }

}

sstd_qt_thread_call_object_ptr::sstd_qt_thread_call_object_ptr() {
}

sstd_qt_thread_call_object_ptr::sstd_qt_thread_call_object_ptr(sstd_qt_thread_call_object *v)
    :super_type_(v) {
}

sstd_qt_thread_call_object::sstd_qt_thread_call_object() {
    mmmFuture = mmmPromise.get_future();
}

void sstd_qt_thread_call_object::call() noexcept {

    if (mmmIsCalled) {
        return;
    }
    mmmIsCalled = true;

    try {

        class Lock {
            sstd_qt_thread_call_object * a;
        public:
            Lock(sstd_qt_thread_call_object * v) : a(v) {
                a->beginCall();
            }
            ~Lock() {
                try {
                    a->endCall();
                } catch (...) {
                    a->_do_exception();
                }
            }
        } varLock{ this };

        try {
            this->do_call();
        } catch (...) {
            this->_do_exception();
        }

    } catch (...) {

        this->_do_exception();

    }

    if (false == this->mmmHasException) {
        this->mmmPromise.set_value();
    }

}

void _0_sstd_qt_thread_object::_call_private_(sstd_qt_thread_call_object_ptr arg) {
    arg->call();
}

namespace {
    class DestoryObject {
        std::once_flag mmmFlag;
        QThread * const mmmThread;
        sstd_register_qthread_object_private * const mmmRegister;
    public:
        inline DestoryObject(QThread * a, sstd_register_qthread_object_private * b)
            :mmmThread(a), mmmRegister(b) {
        }
        inline void doDestory() {
            std::call_once(mmmFlag, [this]() {
                mmmRegister->remove_qthread(mmmThread);
            });
        }
    private:
        SSTD_DEFINE_STATIC_CLASS(DestoryObject);
    };
}/****/

EXPORT_SSTD_QT_AND_QML_LIBRARY auto _0_sstd_get_thread_object(QPointer<QThread> argThread)
->sstd::intrusive_ptr<_0_sstd_qt_thread_object> {

    QThread * varThread = argThread;
    static RegisterData varRegisterData;
    if (varThread == nullptr) {
        return sstd_get_main_thread_object();
    }
    auto varRegister = instance_sstd_register_qthread_object_private();

    sstd::intrusive_ptr<_0_sstd_qt_thread_object> varAns = varRegister->find_qthread(argThread);
    if (varAns) {
        return std::move(varAns);
    }

    {
        std::unique_lock varLock{ varRegisterData.mutex };
        varAns = varRegister->find_qthread(argThread);
        if (varAns) {
            return std::move(varAns);
        }
        assert(qApp);
        varAns = varRegister->add_qthread(varThread);
        varAns->mmmThread = argThread;
        varAns->moveToThread(varThread);
        auto varObj = sstd_new<sstd_qt_thread_object>(varAns.get());
        varAns->mmmObject = std::shared_ptr<sstd_qt_thread_object>(varObj,
            [](sstd_qt_thread_object *a) {a->deleteLater()/*delete in main thread...*/; },
            sstd::allocator<sstd_qt_thread_object>{});
    }

    auto varDestoryObject =
        sstd_make_shared<DestoryObject>(varThread, varRegister);

    QObject::connect(argThread, &QObject::destroyed,
        varRegister, [varDestoryObject]() {
        varDestoryObject->doDestory();
    }, Qt::DirectConnection);

    QObject::connect(argThread, &QThread::finished,
        varRegister, [varDestoryObject]() {
        varDestoryObject->doDestory();
    }, Qt::DirectConnection);

    /*before return the thread can not be destoryed ... */
    assert(argThread);

    return std::move(varAns);
}









