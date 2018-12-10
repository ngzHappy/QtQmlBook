#pragma once

#include <mutex>
#include <QtOpenGL/QtOpenGL>

class MainWidget : public QGLWidget {
    Q_OBJECT
public:
    MainWidget();
    ~MainWidget();
protected:

    bool mmmIsInitalize{false};
    virtual void initializeGL() override;
    virtual void paintGL() override;
    virtual void resizeGL(int width, int height) override;

private:
    GLuint mmmProgram{0};
    GLuint mmmVAO{0};
    GLuint mmmBuffer{ 0 };
    GLuint mmmBufferIndex{0};
};





