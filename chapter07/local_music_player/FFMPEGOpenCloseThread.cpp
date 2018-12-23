#include "FFMPEGOpenCloseThread.hpp"
#include <condition_variable>

class _FFMPEGOpenCloseThreadPrivate {
public:
    std::thread mmmThread;
    std::atomic<bool> mmmQuit{ false };
    std::mutex mmmMutex;
    sstd::list< std::shared_ptr<_FFMPEGOpenCloseThreadCaller> > mmmFunctions;
    std::condition_variable mmmWait;

    inline _FFMPEGOpenCloseThreadPrivate() {
        mmmThread = std::thread([this]() {
            this->run();
        });
    }

    void run() {
        auto varQuitWait = [this]() {
            if (mmmQuit.load()) {
                return true;
            }
            return !mmmFunctions.empty();
        };
        while (false == mmmQuit.load()) {
            std::shared_ptr<_FFMPEGOpenCloseThreadCaller> varCaller;
            {
                std::unique_lock varLock{ mmmMutex };
                mmmWait.wait_for(varLock, 100ms,/*quit wait ...*/varQuitWait);
                if (false == mmmFunctions.empty()) {
                    varCaller = std::move(mmmFunctions.front());
                    mmmFunctions.pop_front();
                } else {
                    continue;
                }
            }
            varCaller->run();
        }
    }

    void post(std::shared_ptr<_FFMPEGOpenCloseThreadCaller> arg) {
        {
            std::unique_lock varLock{ mmmMutex };
            mmmFunctions.push_back(std::move(arg));
        }
        mmmWait.notify_all();
    }

    void run(std::shared_ptr<_FFMPEGOpenCloseThreadCaller> arg) {
        if (std::this_thread::get_id() == mmmThread.get_id()) {
            arg->run();
            return;
        }
        this->post(std::move(arg));
    }

    inline ~_FFMPEGOpenCloseThreadPrivate() {
        mmmQuit.store(true);
        mmmWait.notify_all();
        if (mmmThread.joinable()) {
            mmmThread.join();
        }
    }

    SSTD_DEFINE_STATIC_CLASS(_FFMPEGOpenCloseThreadPrivate);
};

inline static std::shared_ptr<_FFMPEGOpenCloseThreadPrivate>
instanceFFMPEGOpenCloseThreadPrivate() {
    static auto varAns =
        sstd_make_shared<_FFMPEGOpenCloseThreadPrivate>();
    return varAns;
}

std::future<void> FFMPEGOpenCloseThread::
pppCall(std::shared_ptr<_FFMPEGOpenCloseThreadCaller> arg) {
    auto varAns = arg->promise.get_future();
    mmmData->run(arg);
    return std::move(varAns);
}

FFMPEGOpenCloseThread::FFMPEGOpenCloseThread() {
    mmmData = instanceFFMPEGOpenCloseThreadPrivate();
}





