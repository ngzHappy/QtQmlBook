#include "MainWidget.hpp"
#include <sstd_qt_and_qml_library.hpp>
using namespace std::string_view_literals;

MainWidget::MainWidget() :
    QGLWidget(QGLFormat::fromSurfaceFormat(
        sstd::getDefaultQSurfaceFormat())) {

}

void MainWidget::initializeGL() {
    if (mmmIsInitalize) {
        return;
    }
    mmmIsInitalize = true;
    this->makeCurrent();
    sstd::glew_initialize();

    mmmProgram = sstd::opengl_utility::createVFProgram(
        u8R"1---1(
#version 450

layout( location = 0 ) in vec4 argPosition  ;
layout( location = 1 ) in vec4 argTexturePos;
out vec4 ioTexturePos                       ;

void main(){
    ioTexturePos = argTexturePos ;
    gl_Position = argPosition    ;
}

/*简单顶点着色器，用于渲染一个图片*/

)1---1"sv,

u8R"2---2(

#version 450

in vec4 ioTexturePos                            ;
out vec4 outColor                               ;
layout (binding=1) uniform sampler2D argTexture ;

void main(){
    outColor = texture2D( argTexture , ioTexturePos.xy ) ;
}

/*简单片段着色器*/

)2---2"sv);

    sstd::glCreateVertexArrays(1,&mmmVAO);
    sstd::glCreateBuffers(1,&mmmBuffer);
    sstd::glCreateBuffers(1,&mmmBufferIndex);

    std::array< std::array<float, 8>, 4 > varPoints;


}

void MainWidget::paintGL() {
    
    sstd::glClearColor(0.2f, 0.3f, 0.4f, 1.0f);
    sstd::glClear(GL_COLOR_BUFFER_BIT);




}

void MainWidget::resizeGL(int width, int height) {
    sstd::glViewport(0, 0, width, height);
}

MainWidget::~MainWidget() {

    sstd::glDeleteProgram(mmmProgram);
    sstd::glDeleteVertexArrays(1,&mmmVAO);
    sstd::glDeleteBuffers(1,&mmmBuffer);
    sstd::glDeleteBuffers(1, &mmmBufferIndex);

}

