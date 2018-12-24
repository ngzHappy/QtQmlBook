#include "FFMPEGOpenCloseThread.hpp"
#include <condition_variable>

extern "C" {
#include <libavutil/avstring.h>
#include <libavutil/eval.h>
#include <libavutil/mathematics.h>
#include <libavutil/pixdesc.h>
#include <libavutil/imgutils.h>
#include <libavutil/dict.h>
#include <libavutil/parseutils.h>
#include <libavutil/samplefmt.h>
#include <libavutil/avassert.h>
#include <libavutil/time.h>
#include <libavformat/avformat.h>
#include <libavdevice/avdevice.h>
#include <libswscale/swscale.h>
#include <libavutil/opt.h>
#include <libavcodec/avfft.h>
#include <libswresample/swresample.h>
#include <libavfilter/avfilter.h>
#include <libavfilter/buffersink.h>
#include <libavfilter/buffersrc.h>
}

#ifndef ffmpeg
#define ffmpeg
#endif

namespace {
    class InitFFMPEG {
        friend class ::_FFMPEGOpenCloseThreadPrivate;
    private:
        inline InitFFMPEG() {
            ffmpeg::av_register_all();
            ffmpeg::avformat_network_init();
        }
    };
}/*namespace*/

class _FFMPEGOpenCloseThreadPrivate {
    static InitFFMPEG mmmInit;
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

    inline void run() {
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
                mmmWait.wait_for(varLock, 10000ms,/*quit wait ...*/varQuitWait);
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

    inline void post(std::shared_ptr<_FFMPEGOpenCloseThreadCaller> arg) {
        {
            std::unique_lock varLock{ mmmMutex };
            mmmFunctions.push_back(std::move(arg));
        }
        mmmWait.notify_all();
    }

    inline void run(std::shared_ptr<_FFMPEGOpenCloseThreadCaller> arg) {
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

InitFFMPEG _FFMPEGOpenCloseThreadPrivate::mmmInit{};

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





