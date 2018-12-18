#include "sstd_qquickview_resize.hpp"
#include <chrono>
using namespace std::chrono_literals;

namespace _sstd1::_3_private_api {

    class ResizeQuickViewPrivate :
        public QTimer,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ResizeQuickViewPrivate) {
        ResizeQuickView * const mmmSuper;
        QSize mmmLastSize;
        int mmmFinishedCount{ 0 };
    public:
        inline ResizeQuickViewPrivate(ResizeQuickView * arg) :
            QTimer(arg),
            mmmSuper(arg) {
            connect(
                this, &QTimer::timeout,
                this, &ResizeQuickViewPrivate::checkIsResizeEnd);
            this->start(5ms);
        }
        inline void checkIsResizeEnd() {
            if (mmmLastSize == mmmSuper->pppGetSize()) {
                ++mmmFinishedCount;
                if (mmmFinishedCount > (16 + (std::rand() & 3))) {
                    this->stop();
                    mmmSuper->pppEndResize();
                    delete this;
                }
            } else {
                mmmLastSize = mmmSuper->pppGetSize();
                mmmFinishedCount = 0;
            }
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(ResizeQuickViewPrivate);
    };

    ResizeQuickView::ResizeQuickView() :
        mmmResizeEventFinal(QSize{}, QSize{}) {

    }

    ResizeQuickView::~ResizeQuickView() {

    }

    void ResizeQuickView::resizeEvent(QResizeEvent *ev) {
        /*copy the event ... */
        mmmResizeEventFinal = *ev;

        /*the first show ? ...*/
        if (mmmIsFirstResize) {
            mmmIsFirstResize = false;
            return pppDoResize();
        }

        if (false == mmmIsResize) {
            /*start resize ...*/
            pppBeginResize();
            return;
        } else {
            /*call base resize ...*/
            QWindow::resizeEvent(ev);
            return;
        }

    }

    void ResizeQuickView::showEvent(QShowEvent * ev) {
        mmmIsFirstResize = true;
        Super::showEvent(ev);
    }

    void ResizeQuickView::pppDoResize() {
        Super::resizeEvent(&mmmResizeEventFinal);
    }

    void ResizeQuickView::pppBeginResize() {
        mmmIsResize = true;
        sstd_new<ResizeQuickViewPrivate>(this);
    }

    void ResizeQuickView::pppEndResize() {
        mmmIsResize = false;
        pppDoResize();
    }

    QSize ResizeQuickView::pppGetSize() const {
        return mmmResizeEventFinal.size();
    }

}/* namespace sstd::private_api */











