#include "MineSweepingWindow.hpp"

namespace {

    void (MineSweepingWindow::* finishedResizeFunction)() = nullptr;

    class ResizeTimer : public QTimer,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ResizeTimer) {
    private:
        QSize mmmLastSize;
        MineSweepingWindow * const mmmSuper;
        int mmmFinishedCount{ 0 };
    public:
        ResizeTimer(MineSweepingWindow * arg) :
            QTimer(arg),
            mmmSuper(arg) {
            connect(
                this, &QTimer::timeout,
                this, &ResizeTimer::checkIsResizeEnd);
            this->start(3ms);
        }
        void checkIsResizeEnd() {
            if (mmmLastSize == mmmSuper->size()) {
                ++mmmFinishedCount;
                if (mmmFinishedCount > 15) {
                    this->stop();
                    (mmmSuper->*finishedResizeFunction)();
                    delete this;
                }
            } else {
                assert(finishedResizeFunction);
                mmmLastSize = mmmSuper->size();
                mmmFinishedCount = 0;
            }
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(ResizeTimer);
    };
}

void constructMineSweepingWindow() {
    finishedResizeFunction = &MineSweepingWindow::pppEndResize;
}

MineSweepingWindow::MineSweepingWindow() {
    this->resize(1024, 768);
}

void MineSweepingWindow::resizeEvent(QResizeEvent * argEvent) {
    const auto varCurrentSize = this->size();
    const auto varTargetSize = argEvent->size();
    Super::resizeEvent(argEvent);
    if (false == mmmIsResize) {
        mmmStartResizeSize = varCurrentSize;
        pppBeginResize();
        return;
    } else {
        /*过滤小的扰动*/
        if ((std::abs(varTargetSize.width() - mmmStartResizeSize.width()) < 15) &&
            (std::abs(varTargetSize.height() - mmmStartResizeSize.height()) < 15)) {
            mmmMineSweepingWindow->resize(varTargetSize);
            return;
        }
        return;
    }
}

void MineSweepingWindow::initializeGL() {
    USING_SSTD_GLEW;
    this->makeCurrent();
    sstd_glew_initialize();
}

void MineSweepingWindow::paintGL() {
    USING_SSTD_GLEW;
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
}

void MineSweepingWindow::resizeGL(int w, int h) {
    USING_SSTD_GLEW;
    glViewport(0, 0, w, h);
}

void MineSweepingWindow::pppBeginResize() {
    if (mmmMineSweepingWindow == nullptr) {
        return;
    }
    mmmIsResize = true;
    assert(mmmMineSweepingWindow);
    sstd_new<ResizeTimer>(this);
}

void MineSweepingWindow::pppEndResize() {
    mmmIsResize = false;
    assert(mmmMineSweepingWindow);
    mmmMineSweepingWindow->resize(this->size());
}

void MineSweepingWindow::setWineSweepingWindow(sstd::DefaultRoowWindow * arg) {
    assert(mmmMineSweepingWindow == nullptr);
    mmmMineSweepingWindow = arg;
    mmmMineSweepingWindow->setParent(this);
    mmmMineSweepingWindow->resize(this->size());
    mmmMineSweepingWindow->show();
}

static inline void register_this() {
    constructMineSweepingWindow();
}
Q_COREAPP_STARTUP_FUNCTION(register_this)













