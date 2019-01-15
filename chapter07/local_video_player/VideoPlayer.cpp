#include "VideoPlayer.hpp"
#include "VideoPlayerThread.hpp"

class _VideoPlayerPrivate {
public:
    sstd$(mmmVolume, qreal)sstd$a(1);
    sstd$(mmmDuration, qint64)sstd$a(0);
    sstd$(mmmSuper, VideoPlayer * const);
    sstd$(mmmPlayerThread, std::atomic<VideoPlayerThread *>)sstd$a(nullptr);
    inline _VideoPlayerPrivate(VideoPlayer * s) :
        mmmSuper(s) {
    }
    inline void stop() {
        sstd$(varPlayerThread, VideoPlayerThread *)sstd$a(nullptr);
        while (!mmmPlayerThread.compare_exchange_weak(varPlayerThread, nullptr)) {
            continue;
        }
        if (varPlayerThread) {
            varPlayerThread->quit();
        }
    }
    ~_VideoPlayerPrivate() {
        stop();
    }
public:
    SSTD_DEFINE_STATIC_CLASS(_VideoPlayerPrivate);
};

VideoPlayer::VideoPlayer() :
    thisp(sstd_new<_VideoPlayerPrivate>(this)) {

}

VideoPlayer::~VideoPlayer() {
    delete thisp;
}

qint64 VideoPlayer::getDuration() const {
    return thisp->mmmDuration;
}

qreal VideoPlayer::getVolume() const {
    return thisp->mmmVolume;
}

void VideoPlayer::setVolume(qreal) {

}

static inline void registerThis() {
    qmlRegisterType<VideoPlayer>(
        "sstd.video",
        1, 0,
        "VideoPlayer");
}
Q_COREAPP_STARTUP_FUNCTION(registerThis)

