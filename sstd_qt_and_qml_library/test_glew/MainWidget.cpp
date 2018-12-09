#include "MainWidget.hpp"
#include <sstd_qt_and_qml_library.hpp>

MainWidget::MainWidget() :
    QGLWidget(QGLFormat::fromSurfaceFormat(
                  sstd::getDefaultQSurfaceFormat() )) {

}

void MainWidget::initializeGL() {
    if(mmmIsInitalize){
        return;
    }
    mmmIsInitalize=true;
    this->makeCurrent();
    sstd::glew_initialize();
}

void MainWidget::paintGL() {

}

void MainWidget::resizeGL(int width, int height) {
    sstd::glViewport(0,0,width,height);
}

MainWidget::~MainWidget(){

}

