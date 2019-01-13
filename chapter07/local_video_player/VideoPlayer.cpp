#include "VideoPlayer.hpp"

class _VideoPlayerPrivate {
public:
    sstd$(mmmVolume, qreal)sstd$a(1);
    sstd$(mmmDuration, qint64)sstd$a(0);
    sstd$(mmmSuper, VideoPlayer * const);
    inline _VideoPlayerPrivate(VideoPlayer * s) :
        mmmSuper(s) {
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

