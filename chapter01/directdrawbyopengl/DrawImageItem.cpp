﻿#include "DrawImageItem.hpp"
#include <string_view>
#include <array>

using namespace std::string_view_literals;

/* Scene Graph - OpenGL Under QML */

namespace {

    class OpenGLPaintNode :
        public QSGRenderNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(OpenGLPaintNode) {
        QQuickItem * const mmmQuickItem;
    public:
        inline OpenGLPaintNode(QQuickItem *);
        inline QSGRenderNode::StateFlags changedStates() const override;
        inline QSGRenderNode::RenderingFlags flags() const override;
        inline QRectF rect() const override;
        inline void render(const QSGRenderNode::RenderState *state) override;
        inline void releaseResources() override;
        inline ~OpenGLPaintNode();
    public:
        inline void setData(const QImage &);
    private:
        std::once_flag mmm_construct_opengl;
        std::once_flag mmm_destory_opengl;
        inline void ppp_construct_opengl();
        inline void ppp_destory_opengl();
        inline void ppp_update_data();
    private:
        QImage mmmImage;
        bool mmmIsImageNotUpdate{ true };
    private:
        GLuint mmmGLProgram{ 0 };
        GLuint mmmGLVAO{ 0 };
        GLuint mmmGLVAB{ 0 };
        GLuint mmmGLVABI{ 0 };
        GLuint mmmGLTexture{ 0 };
        std::array< std::array< GLfloat, 8 >, 4 > mmmGLVABData;
        std::array< GLuint, 4 > mmmIndexBufferData;
        QRectF mmmRect;
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(OpenGLPaintNode);
    };

    inline OpenGLPaintNode::OpenGLPaintNode(QQuickItem * arg) :
        mmmQuickItem(arg) {
    }

    inline QSGRenderNode::StateFlags OpenGLPaintNode::changedStates() const {
        return nullptr;
    }

    inline QSGRenderNode::RenderingFlags OpenGLPaintNode::flags() const {
        return QSGRenderNode::BoundedRectRendering |
            QSGRenderNode::DepthAwareRendering |
            QSGRenderNode::OpaqueRendering;
    }

    inline QRectF OpenGLPaintNode::rect() const {
        return mmmRect;
    }

    inline void OpenGLPaintNode::render(const QSGRenderNode::RenderState *argState) {
        USING_SSTD_GLEW;
        /*初始化OpenGL环境*/
        ppp_construct_opengl();
        /*更新数据*/
        ppp_update_data();
        {
            /*更新矩阵*/
            const auto * varMVMatrix = this->matrix();
            const auto * varPMatrix = argState->projectionMatrix();
            auto varMatrix = (*varPMatrix) * (*varMVMatrix);
            glUniformMatrix4fv(2, 1, false, varMatrix.data());
        }
        {
            /*更新透明度*/
            const GLfloat varOpacity = static_cast<GLfloat>(this->inheritedOpacity());
            glUniform1f(3, varOpacity);
        }

        /*开始绘制*/
        sstd::glUseProgram(mmmGLProgram);
        sstd::glBindVertexArray(mmmGLVAO);
        sstd::glBindTexture(GL_TEXTURE_2D, mmmGLTexture);
        sstd::glActiveTexture(GL_TEXTURE0 + 1);
        sstd::glBindTextureUnit(1, mmmGLTexture);
        sstd::glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);

    }

    inline void OpenGLPaintNode::releaseResources() {
        ppp_destory_opengl();
    }

    inline OpenGLPaintNode::~OpenGLPaintNode() {
        ppp_destory_opengl();
    }

    inline void OpenGLPaintNode::ppp_construct_opengl() {
        USING_SSTD_GLEW;
        std::call_once(mmm_construct_opengl, [this]() {
            /*初始化glew库*/
            sstd::glew_initialize();

            /*初始化opengl program ...*/

            const auto varVP = u8R"(

#version 450

layout( location = 0 ) in vec4 argPosition       ;
layout( location = 1 ) in vec4 argTexturePos     ;
layout (location = 2 ) uniform mat4 argMVPMatrix ;
out vec4 ioTexturePos                            ;

void main(){
    ioTexturePos = argMVPMatrix * argTexturePos  ;
    gl_Position =  argPosition                   ;
}

/*简单顶点着色器，用于渲染一个图片*/

)"sv;

            const auto varFP = u8R"(
#version 450

in vec4 ioTexturePos                               ;
out vec4 outColor                                  ;
layout (location = 3 ) uniform float argOpacity    ;
layout (binding = 1 ) uniform sampler2D argTexture ;

void main(){
    outColor = texture( argTexture , ioTexturePos.xy ) * argOpacity ;
}

/*简单片段着色器*/

)"sv;

            mmmGLProgram = sstd::opengl_utility::createVFProgram(varVP, varFP);
            glCreateBuffers(1, &mmmGLVAB);
            glCreateBuffers(1, &mmmGLVABI);
            glCreateVertexArrays(1, &mmmGLVAO);

            using row_type = std::array<GLfloat, 8>;
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

            glBindVertexArray(mmmGLVAO);
            glNamedBufferData(mmmGLVAB, sizeof(varPoints), varPoints.data(), GL_DYNAMIC_DRAW);

            glEnableVertexAttribArray(0);
            glVertexArrayVertexBuffer(mmmGLVAO, 0, mmmGLVAB, 0, sizeof(row_type));
            glVertexArrayAttribFormat(mmmGLVAO, 0, 4, GL_FLOAT, false, 0);
            glVertexArrayAttribBinding(mmmGLVAO, 0, 0);

            glEnableVertexAttribArray(1);
            glVertexArrayVertexBuffer(mmmGLVAO, 1, mmmGLVAB, (sizeof(row_type) >> 1), sizeof(row_type));
            glVertexArrayAttribFormat(mmmGLVAO, 1, 4, GL_FLOAT, false, 0);
            glVertexArrayAttribBinding(mmmGLVAO, 1, 1);

            glNamedBufferData(mmmGLVABI, sizeof(varIndex), varIndex.data(), GL_STATIC_DRAW);
            glVertexArrayElementBuffer(mmmGLVAO, mmmGLVABI);

        });
    }

    using sstd::glDeleteTextures;
    inline void OpenGLPaintNode::ppp_destory_opengl() {
        USING_SSTD_GLEW;
        std::call_once(mmm_destory_opengl, [this]() {
            glDeleteProgram(mmmGLProgram);
            glDeleteVertexArrays(1, &mmmGLVAO);
            glDeleteTextures(1, &mmmGLTexture);
            glDeleteBuffers(1, &mmmGLVAB);
            glDeleteBuffers(1, &mmmGLVABI);
        });
    }

    inline void OpenGLPaintNode::setData(const QImage & arg) {
        mmmImage = arg;
        mmmIsImageNotUpdate = true;
        mmmRect = { 0 , 0,
            mmmQuickItem->width(),
            mmmQuickItem->height() };
    }

    inline void OpenGLPaintNode::ppp_update_data() {
        USING_SSTD_GLEW;
        /*更新图片信息*/
        if (mmmIsImageNotUpdate || (0 == mmmGLTexture)) {
            mmmIsImageNotUpdate = false;
            sstd::opengl_utility::updateTexture(&mmmGLTexture, mmmImage);
        }

        /*更新逻辑大小*/
        {
            using row_type = std::array<GLfloat, 8>;
            const auto varWidth = static_cast<GLfloat>(mmmRect.width());
            const auto varHeight = static_cast<GLfloat>(mmmRect.height());
            const std::array<row_type, 4 > varPoints{
                row_type{-varWidth,varHeight,0,1,/**/0,0,0,1},
                row_type{-varWidth,-varHeight,0,1,/**/0,1,0,1},
                row_type{varWidth,-varHeight,0,1,/**/1,1,0,1},
                row_type{varWidth,varHeight,0,1,/**/1,0,0,1},
            };
            glNamedBufferSubData(mmmGLVAB, 0, sizeof(varPoints), varPoints.data());
        }

    }

}/**/

DrawImageItem::DrawImageItem() {
    this->setFlag(QQuickItem::ItemHasContents, true);
}

QSGNode * DrawImageItem::updatePaintNode(
    QSGNode *oldNode,
    QQuickItem::UpdatePaintNodeData *) {

    OpenGLPaintNode * varNode;
    if (oldNode == nullptr) {
        varNode = sstd_new<OpenGLPaintNode>(this);
    } else {
        varNode = static_cast<OpenGLPaintNode *>(oldNode);
    }

    varNode->setData(mmmImage);

    return varNode;

}














