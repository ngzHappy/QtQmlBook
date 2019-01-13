#include "VideoPlayerThread.hpp"

VideoPlayerThread::VideoPlayerThread() {
    assert(qApp);
    this->moveToThread(qApp->thread());
    auto varConnectState = sstd_make_shared< ConnectState >();
    mmmConnectState = varConnectState;
    mmmConnectState->mmmConnect1 =
        connect(this, &QThread::finished,
            this, [varConnectState, this]() {
        deleteOnce(varConnectState.get());
        deleteLater();
    });
    mmmConnectState->mmmConnect2 =
        connect(this, &QThread::destroyed,
            this, [varConnectState, this]() {
        deleteOnce(varConnectState.get());
    });
}

void VideoPlayerThread::clearData() {
}

void VideoPlayerThread::deleteOnce(ConnectState * arg) {
    std::call_once(arg->mmmDeleteOnce, [this, arg]() {
        clearData();
        disconnect(arg->mmmConnect1);
        disconnect(arg->mmmConnect2);
    });
}





