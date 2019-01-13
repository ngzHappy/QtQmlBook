#include "VideoPlayerThread.hpp"

VideoPlayerThread::VideoPlayerThread() {
    assert(qApp);
    this->moveToThread(qApp->thread());
    auto varConnectState = sstd_make_shared< ConnectState >();
    mmmConnectState = varConnectState;
    mmmConnectState->mmmConnect1 =
        connect(this, &QThread::finished,
            this, [varConnectState, this]() {
        deleteOnce();
        deleteLater();
        clearData();
    });
    mmmConnectState->mmmConnect2 =
        connect(this, &QThread::destroyed,
            this, [varConnectState, this]() {
        clearData();
    });
}

void VideoPlayerThread::clearData() {
}

void VideoPlayerThread::deleteOnce() {
    std::call_once(mmmConnectState->mmmDeleteOnce, [this]() {
        disconnect(mmmConnectState->mmmConnect1);
        disconnect(mmmConnectState->mmmConnect2);
    });
}





