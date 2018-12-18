#pragma once

#include <sstd_qt_and_qml_library.hpp>

void constructMineSweepingWindow();
class MineSweepingWindow :
    public sstd::DefaultRoowWindow::PureRootWindow,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MineSweepingWindow) {
    Q_OBJECT
public:
    MineSweepingWindow();
    void setWineSweepingWindow(sstd::DefaultRoowWindow *);
private:
    using Super = sstd::DefaultRoowWindow::PureRootWindow;
protected:
    void resizeEvent(QResizeEvent *ev) override;
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
private:
    bool mmmIsResize{ false };
    QSize mmmStartResizeSize;
    sstd::DefaultRoowWindow * mmmMineSweepingWindow{ nullptr };
    void pppBeginResize();
    void pppEndResize();
    friend void ::constructMineSweepingWindow();
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MineSweepingWindow);
};

















