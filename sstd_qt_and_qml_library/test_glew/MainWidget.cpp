﻿#include "MainWidget.hpp"
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
    ioTexturePos = argTexturePos  ;
    gl_Position =  argPosition    ;
}

/*简单顶点着色器，用于渲染一个图片*/

)1---1"sv,

u8R"2---2(

#version 450

in vec4 ioTexturePos                            ;
out vec4 outColor                               ;
layout (binding=1) uniform sampler2D argTexture ;

void main(){
    outColor = texture( argTexture , ioTexturePos.xy ) ;
}

/*简单片段着色器*/

)2---2"sv);

    sstd::glCreateVertexArrays(1, &mmmVAO);
    sstd::glCreateBuffers(1, &mmmBuffer);
    sstd::glCreateBuffers(1, &mmmBufferIndex);

    using row_type = std::array<float, 8>;
    constexpr const std::array<row_type, 4 > varPoints{
        row_type{-1,1,0,1,/**/0,0,0,1},
        row_type{-1,-1,0,1,/**/0,1,0,1},
        row_type{1,-1,0,1,/**/1,1,0,1},
        row_type{1,1,0,1,/**/1,0,0,1},
    };
    constexpr const std::array<std::uint16_t, 6> varIndex{
           3,2,1,
           3,1,0
    };

    sstd::glBindVertexArray(mmmVAO);
    sstd::glNamedBufferData(mmmBuffer, sizeof(varPoints), varPoints.data(), GL_STATIC_DRAW);

    sstd::glEnableVertexAttribArray(0);
    sstd::glVertexArrayVertexBuffer(mmmVAO, 0, mmmBuffer, 0, sizeof(row_type));
    sstd::glVertexArrayAttribFormat(mmmVAO, 0, 4, GL_FLOAT, false, 0);
    sstd::glVertexArrayAttribBinding(mmmVAO, 0, 0);

    sstd::glEnableVertexAttribArray(1);
    sstd::glVertexArrayVertexBuffer(mmmVAO, 1, mmmBuffer, (sizeof(row_type) >> 1), sizeof(row_type));
    sstd::glVertexArrayAttribFormat(mmmVAO, 1, 4, GL_FLOAT, false, 0);
    sstd::glVertexArrayAttribBinding(mmmVAO, 1, 1);

    sstd::glNamedBufferData(mmmBufferIndex, sizeof(varIndex), varIndex.data(), GL_STATIC_DRAW);
    sstd::glVertexArrayElementBuffer(mmmVAO, mmmBufferIndex);

    QImage varImage{
        sstd::getLocalFileFullFilePath(QStringLiteral("myqml/test_glew/0000.jpg")) };
    mmmTexture = sstd::opengl_utility::createTexture(varImage);

}

void MainWidget::paintGL() {

    sstd::glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    sstd::glClear(GL_COLOR_BUFFER_BIT);

    sstd::glUseProgram(mmmProgram);
    sstd::glBindVertexArray(mmmVAO);
    sstd::glBindTexture(GL_TEXTURE_2D, mmmTexture);
    sstd::glActiveTexture(GL_TEXTURE0 + 1);
    sstd::glBindTextureUnit(1, mmmTexture);
    sstd::glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);

}

void MainWidget::resizeGL(int width, int height) {
    sstd::glViewport(0, 0, width, height);
}

MainWidget::~MainWidget() {

    sstd::glDeleteProgram(mmmProgram);
    sstd::glDeleteVertexArrays(1, &mmmVAO);
    sstd::glDeleteBuffers(1, &mmmBuffer);
    sstd::glDeleteBuffers(1, &mmmBufferIndex);
    sstd::glDeleteTextures(1, &mmmTexture);

}
