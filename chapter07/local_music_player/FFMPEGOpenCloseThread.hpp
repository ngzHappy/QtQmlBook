#pragma once

#include <sstd_qt_and_qml_library.hpp>

class _FFMPEGOpenCloseThreadPrivate;
class _FFMPEGOpenCloseThreadCaller :
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_FFMPEGOpenCloseThreadCaller) {
public:
    virtual void run() = 0;
    std::promise<void> promise;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(_FFMPEGOpenCloseThreadCaller);
};

template<typename T>
class _T_FFMPEGOpenCloseThreadCaller :
    public _FFMPEGOpenCloseThreadCaller,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_T_FFMPEGOpenCloseThreadCaller<T>) {
public:
    T function;
    bool isCalled{ false };
    inline void run() override {
        isCalled = true;
        try {
            function();
        } catch (...) {
            promise.set_exception(std::current_exception());
            return;
        }
        promise.set_value();
    }
    template<typename U>
    inline _T_FFMPEGOpenCloseThreadCaller(U && arg) :
        function(std::forward<U>(arg)) {
    }
    inline ~_T_FFMPEGOpenCloseThreadCaller() {
        if (isCalled) {
            return;
        }
        promise.set_value();
    }
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(_T_FFMPEGOpenCloseThreadCaller);
};

class FFMPEGOpenCloseThread {
public:
    FFMPEGOpenCloseThread();
    FFMPEGOpenCloseThread(const FFMPEGOpenCloseThread &) = default;
    FFMPEGOpenCloseThread(FFMPEGOpenCloseThread &&) = default;
    FFMPEGOpenCloseThread&operator=(const FFMPEGOpenCloseThread &) = default;
    FFMPEGOpenCloseThread&operator=(FFMPEGOpenCloseThread &&) = default;
public:
    template<typename T>
    inline std::future<void> call(T &&);
private:
    std::shared_ptr<_FFMPEGOpenCloseThreadPrivate> mmmData;
    std::future<void> pppCall(std::shared_ptr<_FFMPEGOpenCloseThreadCaller> arg);
private:
    SSTD_DEFINE_STATIC_CLASS(FFMPEGOpenCloseThread);
};

template<typename T>
inline std::future<void> FFMPEGOpenCloseThread::call(T && arg) {
    using U = std::remove_cv_t< std::remove_reference_t<T> >;
    using F = _T_FFMPEGOpenCloseThreadCaller<U>;
    auto varFunction = sstd_make_shared<F>(std::forward<T>(arg));
    return pppCall(std::move(varFunction));
}

