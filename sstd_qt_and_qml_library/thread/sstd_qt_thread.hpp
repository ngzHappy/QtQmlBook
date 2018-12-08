#pragma once

#include <QtCore/qobject.h>
#include <QtCore/qthread.h>
#include <QtCore/qpointer.h>
#include "../global/sstd_qt_and_qml_global.hpp"
#include <sstd_library.hpp>
#include <future>

class EXPORT_SSTD_QT_AND_QML_LIBRARY sstd_qt_thread_call_object :
    public QObject,
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_call_object){
    Q_OBJECT
public:
    sstd_qt_thread_call_object();
    void call() noexcept;
    Q_SIGNAL void beginCall();
    Q_SIGNAL void endCall();
    Q_SIGNAL void exitButNoCall();
    ~sstd_qt_thread_call_object();
    inline bool isCalled() const;
    inline bool hasException() const;
    inline bool isExitButNoCall() const;
    inline const std::future<void> & getFuture() const;
protected:
    virtual void do_call() = 0;
private:
    void _do_exception() noexcept;
private:
    std::atomic<bool> mmmIsCalled{ false };
    std::atomic<bool> mmmHasException{ false };
    std::atomic<bool> mmmExitButNoCall{ false };
    std::promise<void> mmmPromise;
    std::future<void>  mmmFuture;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_call_object);
};

inline bool sstd_qt_thread_call_object::isCalled() const {
    return mmmIsCalled;
}
inline bool sstd_qt_thread_call_object::hasException() const {
    return mmmHasException;
}
inline bool sstd_qt_thread_call_object::isExitButNoCall() const {
    return mmmExitButNoCall;
}
inline const std::future<void> & sstd_qt_thread_call_object::getFuture() const {
    return mmmFuture;
}

class EXPORT_SSTD_QT_AND_QML_LIBRARY sstd_qt_thread_call_object_ptr :
    public sstd::intrusive_ptr<sstd_qt_thread_call_object> {
    using super_type_ = sstd::intrusive_ptr<sstd_qt_thread_call_object>;
public:
    inline sstd_qt_thread_call_object_ptr(const sstd_qt_thread_call_object_ptr &) = default;
    inline sstd_qt_thread_call_object_ptr(sstd_qt_thread_call_object_ptr &&) = default;
    inline sstd_qt_thread_call_object_ptr&operator=(const sstd_qt_thread_call_object_ptr &) = default;
    inline sstd_qt_thread_call_object_ptr&operator=(sstd_qt_thread_call_object_ptr &&) = default;
    sstd_qt_thread_call_object_ptr();
    sstd_qt_thread_call_object_ptr(sstd_qt_thread_call_object *);
private:
    SSTD_DEFINE_STATIC_CLASS(sstd_qt_thread_call_object_ptr);
};

class _0_sstd_qt_thread_object;
class EXPORT_SSTD_QT_AND_QML_LIBRARY sstd_qt_thread_object :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_object) {
    Q_OBJECT
public:
    sstd_qt_thread_object(_0_sstd_qt_thread_object *);
    inline void call(sstd_qt_thread_call_object *);
private:
    Q_SIGNAL void _call_private_(sstd_qt_thread_call_object_ptr);
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_qt_thread_object);
};

inline void sstd_qt_thread_object::call(sstd_qt_thread_call_object * arg) {
    if (arg) {
        this->_call_private_(arg);
    }
}

EXPORT_SSTD_QT_AND_QML_LIBRARY sstd::intrusive_ptr<_0_sstd_qt_thread_object>
_0_sstd_get_thread_object(QPointer<QThread>);

class EXPORT_SSTD_QT_AND_QML_LIBRARY _0_sstd_qt_thread_object :
    public QObject,
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_0_sstd_qt_thread_object) {
    Q_OBJECT
public:
    inline QPointer<QThread> getWatcherThread() const;
    inline std::shared_ptr<sstd_qt_thread_object> getWatcherObject() const;
private:
    QPointer<QThread> mmmThread;
    std::shared_ptr<sstd_qt_thread_object> mmmObject;
public:
    Q_SLOT void _call_private_(sstd_qt_thread_call_object_ptr);
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(_0_sstd_qt_thread_object);
public:
    friend EXPORT_SSTD_QT_AND_QML_LIBRARY sstd::intrusive_ptr<_0_sstd_qt_thread_object>
            _0_sstd_get_thread_object(QPointer<QThread>);
};

inline auto sstd_get_thread_object(QPointer<QThread> arg)
->std::shared_ptr <sstd_qt_thread_object> {
    return _0_sstd_get_thread_object(arg)->getWatcherObject();
}

inline QPointer<QThread> _0_sstd_qt_thread_object::getWatcherThread() const {
    return mmmThread;
}

inline std::shared_ptr<sstd_qt_thread_object> _0_sstd_qt_thread_object::getWatcherObject() const {
    return mmmObject;
}

Q_DECLARE_METATYPE(sstd_qt_thread_call_object_ptr)

