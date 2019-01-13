#pragma once

#include <sstd_qt_and_qml_library.hpp>

class _VideoPlayerPrivate;
class VideoPlayer :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(VideoPlayer) {
    Q_OBJECT
public:
    enum StatePlayer {
        Open,
        Play,
        Close,
        Pause,
    };
public:
    Q_ENUM(StatePlayer)
private:
    Q_PROPERTY(qreal volume READ getVolume WRITE setVolume NOTIFY volumeChanged)
private:
    Q_PROPERTY(qint64 duration READ getDuration NOTIFY durationChanged)
public:
    VideoPlayer();
    ~VideoPlayer();
public:
    qreal getVolume() const;
    void setVolume(qreal);
    Q_SIGNAL void volumeChanged();
public:
    qint64 getDuration() const;
    Q_SIGNAL void durationChanged();
private:
    _VideoPlayerPrivate * const thisp;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(VideoPlayer);
};













