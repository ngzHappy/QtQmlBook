#include "MusicPlayer.hpp"

class _MusicPlayerPrivate {
    MusicPlayer * const mmmParent;
public:
    inline _MusicPlayerPrivate(MusicPlayer * arg) :
        mmmParent(arg) {
    }
    sstd::intrusive_ptr< MusicReader > mmmMusicReader;
};

MusicPlayer::MusicPlayer() :
    mmmPrivate(sstd_new<_MusicPlayerPrivate>(this)) {

}

MusicPlayer::~MusicPlayer() {
    delete mmmPrivate;
}

void MusicPlayer::startPlay() {

}

void MusicPlayer::pausePlay() {

}

void MusicPlayer::stopPlay() {

}

void MusicPlayer::continuePlay() {

}

bool MusicPlayer::openFile(const QUrl & arg) {
    if (mmmPrivate->mmmMusicReader) {
        sstd_log("close the file first ..."sv);
        return false;
    }
    auto varReader =
        sstd_make_intrusive_ptr<MusicReader>();
    if (varReader->open( arg.toLocalFile() )) {
        mmmPrivate->mmmMusicReader 
            = std::move(varReader);
        return true;
    }
    sstd_log("open file faild!"sv);
    return false;
}

static inline void registerThis() {
    qmlRegisterType<MusicPlayer>(
        "sstd.audio",
        1, 0,
        "MusicPlayer");
}
Q_COREAPP_STARTUP_FUNCTION(registerThis)








