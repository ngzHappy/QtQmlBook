#pragma once

#include <QtOpenGL/QtOpenGL>

class MainWidget : public QGLWidget {
    Q_OBJECT
public:
    MainWidget();
protected:

    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int width, int height) override;

};





