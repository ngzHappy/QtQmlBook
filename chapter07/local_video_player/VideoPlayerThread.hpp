#pragma once

#include <sstd_qt_and_qml_library.hpp>

class VideoPlayerThread :
    public QThread,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(VideoPlayerThread) {
    Q_OBJECT
public:
    VideoPlayerThread();
private:
    class ConnectState {
    public:
        sstd$(mmmDeleteOnce, std::once_flag);
        sstd$(mmmConnect1, QMetaObject::Connection);
        sstd$(mmmConnect2, QMetaObject::Connection);
    private:
        SSTD_DEFINE_STATIC_CLASS(ConnectState);
    };
    sstd$(mmmConnectState, std::shared_ptr<ConnectState>);
private:
    void deleteOnce(ConnectState *);
    void clearData();
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(VideoPlayerThread);
};





