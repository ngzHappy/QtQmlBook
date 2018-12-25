#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "MusicReader.hpp"
 

class _MusicPlayerPrivate;
class MusicPlayer :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MusicPlayer){
    Q_OBJECT
public:
    MusicPlayer();
    ~MusicPlayer();
public:
    Q_SLOT bool open(const QString &);
    Q_SLOT void startPlay();
    Q_SLOT void pausePlay();
    Q_SLOT void stopPlay();
    Q_SLOT void continuePlay();
private:
    _MusicPlayerPrivate * const mmmPrivate;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MusicPlayer);
};





