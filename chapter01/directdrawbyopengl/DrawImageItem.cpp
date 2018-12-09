#include "DrawImageItem.hpp"
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
        std::array< std::array< GLfloat, 8 >, 4 > mmmBufferData;
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
        /*初始化OpenGL环境*/
        ppp_construct_opengl();
        /*更新数据*/

        /*开始绘制*/

    }

    inline void OpenGLPaintNode::releaseResources() {
        ppp_destory_opengl();
    }

    inline OpenGLPaintNode::~OpenGLPaintNode() {
        ppp_destory_opengl();
    }

    inline void OpenGLPaintNode::ppp_construct_opengl() {
        std::call_once(mmm_construct_opengl, [this]() {
            sstd::glew_initialize();

            using namespace sstd;
            /*初始化opengl program ...*/

            const auto varVP = u8R"(/*顶点着色器*/

#version 450

layout (location =0) in vec4 argPosition       ;
layout (location =1) in vec4 argColor          ;
layout (location =2) uniform mat4 argMVPMatrix ;
layout (location =3) uniform float argOpacity  ;

out vec4 passColor;

void main(){
    gl_Position = argMVPMatrix * argPosition ;
    passColor   = argColor * argOpacity      ;
}

)"sv;
            const auto varFP = u8R"(/*片段着色器*/
#version 450

in  vec4 passColor;
out vec4 color;

void main(void){
    color = passColor ;
}

)"sv;
            class ShaderFree {
            public:
                std::array<GLuint, 2> data;
                inline ShaderFree() {
                    data[0] = 0;
                    data[1] = 0;
                }
                inline ~ShaderFree() {
                    glDeleteShader(data[1]);
                    glDeleteShader(data[0]);
                }
            } varShaders;

            GLuint * varShader = &(varShaders.data[0]);
            varShader[0] = glCreateShader(GL_VERTEX_SHADER);
            varShader[1] = glCreateShader(GL_FRAGMENT_SHADER);

            GLint lengths[] = {
                           (GLint)(varVP.size()),
                           (GLint)(varFP.size())
            };
            const GLchar * sources[] = { varVP.data(),varFP.data() };

            glShaderSource(varShader[0], 1, &sources[0], &lengths[0]);
            glShaderSource(varShader[1], 1, &sources[1], &lengths[1]);

            glCompileShader(varShader[0]);
            glCompileShader(varShader[1]);

            mmmGLProgram = glCreateProgram();
            glAttachShader(mmmGLProgram, varShader[0]);
            glAttachShader(mmmGLProgram, varShader[1]);
            glLinkProgram(mmmGLProgram);

            glCreateBuffers(1, &mmmGLVAB);
            glCreateBuffers(1, &mmmGLVABI);
            glCreateVertexArrays(1, &mmmGLVAO);

        });
    }

    inline void OpenGLPaintNode::ppp_destory_opengl() {
        std::call_once(mmm_destory_opengl, [this]() {
            using namespace sstd;
            glDeleteProgram(mmmGLProgram);
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

        if (mmmIsImageNotUpdate || (0 == mmmGLTexture)) {
            mmmIsImageNotUpdate = false;

        }



    }

}/**/


DrawImageItem::DrawImageItem() {
    this->setFlag(QQuickItem::ItemHasContents, true);
}

