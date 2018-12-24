#include "MusicPlayer.hpp"

class _MusicPlayerPrivate {
    MusicPlayer * const mmmParent;
public:
    inline _MusicPlayerPrivate(MusicPlayer * arg) : 
        mmmParent(arg) {
    }

};

MusicPlayer::MusicPlayer() : 
    mmmPrivate(sstd_new<_MusicPlayerPrivate>(this)) {

}
MusicPlayer::~MusicPlayer() {

}









