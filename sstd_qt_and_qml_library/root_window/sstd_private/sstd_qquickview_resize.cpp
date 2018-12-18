#include "sstd_qquickview_resize.hpp"
#include "../../glew/sstd_glew.hpp"
#include "../../glew/sstd_using_glew.hpp"
#include "../../glew/sstd_glew_initialization.hpp"
#include "../../glew/sstd_glew_utility.hpp"

#include <chrono>
using namespace std::chrono_literals;

#include <string_view>
using namespace std::string_view_literals;

#include <array>

namespace _sstd1::_3_private_api {

    class ResizeQuickViewPrivate :
        public QTimer,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ResizeQuickViewPrivate) {
        ResizeQuickView * const mmmSuper;
        QSize mmmLastSize;
        int mmmFinishedCount{ 0 };
        constexpr const static int mmmOnShowCount{ 18 };
        constexpr const static int mmmOnFinishedCount{ 6 };
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
            static_assert(mmmOnShowCount > mmmOnFinishedCount);
            if (mmmLastSize == mmmSuper->pppGetSize()) {
                ++mmmFinishedCount;
                if (mmmFinishedCount > mmmOnShowCount) {
                    /*显示resize...*/
                    this->stop();
                    mmmSuper->pppShowResizeItem();
                    delete this;
                } else if (mmmFinishedCount > mmmOnFinishedCount) {
                    /*预先resize...*/
                    mmmSuper->pppUpdateResize();
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
        connect(this, &QQuickWindow::beforeSynchronizing,
            this, &ResizeQuickView::pppResizeOpenGL, Qt::DirectConnection);
        connect(this, &QQuickWindow::sceneGraphInvalidated,
            this, &ResizeQuickView::pppCleanUpOpenGL, Qt::DirectConnection);
        connect(this, &QQuickWindow::beforeRendering,
            this, &ResizeQuickView::pppRendingOpenGL, Qt::DirectConnection);
        this->setClearBeforeRendering(false);
    }

    void ResizeQuickView::pppCleanUpOpenGL() {
        USING_SSTD_GLEW;
        glDeleteProgram(mmmGLProgram);
        glDeleteBuffers(1, &mmmGLVAOB);
        glDeleteBuffers(1, &mmmGLVAOBI);
        glDeleteTextures(1, &mmmGLTexture);
        glDeleteVertexArrays(1, &mmmGLVAO);
    }

    void ResizeQuickView::pppResizeOpenGL() {
        sstd_glew_initialize();
        const auto varGLSize =
            this->size() * this->devicePixelRatio();
        USING_SSTD_GLEW;
        glViewport(0, 0, varGLSize.width(), varGLSize.height());
    }

    void ResizeQuickView::pppRendingOpenGL() {
        USING_SSTD_GLEW;
        const auto varCleanColor = this->color();
        glClearColor(
            static_cast<GLfloat>(varCleanColor.redF()),
            static_cast<GLfloat>(varCleanColor.greenF()),
            static_cast<GLfloat>(varCleanColor.blueF()),
            static_cast<GLfloat>(varCleanColor.alphaF()));
        glClearDepth(1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        if (false == mmmIsResize) {
            return;
        }

        if (0 == mmmGLProgram) {
            mmmGLProgram = sstd::opengl_utility::createVFProgram(
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
            assert(mmmGLProgram);
            glUseProgram(mmmGLProgram);
        }

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

        if (0 == mmmGLVAO) {
            glCreateVertexArrays(1, &mmmGLVAO);
            glBindVertexArray(mmmGLVAO);
        }

        if (0 == mmmGLVAOB) {
            glCreateBuffers(1, &mmmGLVAOB);
            glNamedBufferData(mmmGLVAOB, sizeof(varPoints), varPoints.data(), GL_STATIC_DRAW);

            glEnableVertexAttribArray(0);
            glVertexArrayVertexBuffer(mmmGLVAO, 0, mmmGLVAOB, 0, sizeof(row_type));
            glVertexArrayAttribFormat(mmmGLVAO, 0, 4, GL_FLOAT, false, 0);
            glVertexArrayAttribBinding(mmmGLVAO, 0, 0);

            glEnableVertexAttribArray(1);
            glVertexArrayVertexBuffer(mmmGLVAO, 1, mmmGLVAOB, (sizeof(row_type) >> 1), sizeof(row_type));
            glVertexArrayAttribFormat(mmmGLVAO, 1, 4, GL_FLOAT, false, 0);
            glVertexArrayAttribBinding(mmmGLVAO, 1, 1);

        }

        if (0 == mmmGLVAOBI) {
            glCreateBuffers(1, &mmmGLVAOBI);
            glNamedBufferData(mmmGLVAOBI, sizeof(varIndex), varIndex.data(), GL_STATIC_DRAW);
        }

        if (mmmIsImageChanged) {
            sstd::opengl_utility::updateTexture(
                &mmmGLTexture,
                mmmResizeImage);
            mmmIsImageChanged = false;
        }

        glUseProgram(mmmGLProgram);
        glBindVertexArray(mmmGLVAO);
        glVertexArrayElementBuffer(mmmGLVAO, mmmGLVAOBI);
        glBindTexture(GL_TEXTURE_2D, mmmGLTexture);
        glActiveTexture(GL_TEXTURE0 + 1);
        glBindTextureUnit(1, mmmGLTexture);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);

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
        pppUpdateImage();
        sstd_new<ResizeQuickViewPrivate>(this);
    }

    void ResizeQuickView::pppUpdateImage() {
        if ((this->isActive()) && (this->rootObject())) {
            const QImage varImage =
                this->grabWindow();
            mmmResizeImage =
                varImage.convertToFormat(QImage::Format_RGBA64);
            mmmIsImageChanged = true;
            this->rootObject()->setVisible(false);
        }
    }

    void ResizeQuickView::pppShowResizeItem() {
        mmmIsResize = false;
        pppUpdateResize();
        if (this->rootObject()) {
            this->rootObject()->setVisible(true);
        }
    }

    void ResizeQuickView::pppUpdateResize() {
        pppDoResize();
    }

    QSize ResizeQuickView::pppGetSize() const {
        return mmmResizeEventFinal.size();
    }

}/* namespace sstd::private_api */











