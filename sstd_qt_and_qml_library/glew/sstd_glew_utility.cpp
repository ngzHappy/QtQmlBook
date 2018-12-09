#define _SSTD_HAS_GLEW_0_1 (1u)

#include "GLSSTD/glew.h"
#include "sstd_glew_utility.hpp"
#include <cassert>
#include <tuple>
#include <utility>
#include <array>
#include <string_view>
using namespace std::string_view_literals;

namespace sstd::opengl_utility {

    EXPORT_SSTD_QT_AND_QML_LIBRARY QSize getTextureSize(GLuint arg) {

        if (arg < 1) {
            return{ 0,0 };
        }

        GLint width{ 0 };
        GLint height{ 0 };
        glGetTextureLevelParameteriv(arg, 0, GL_TEXTURE_WIDTH, &width);
        glGetTextureLevelParameteriv(arg, 0, GL_TEXTURE_HEIGHT, &height);

        return{ width,height };

    }

    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint createTexture(QImage arg) {

        const auto varImage =
            arg.convertToFormat(QImage::Format_RGBA64);

        if (varImage.isNull()) {
            return 0;
        }

        GLuint varAns{ 0 };
        glCreateTextures(GL_TEXTURE_2D, 1, &varAns);

        if (varAns < 1) {
            return 0;
        }

        glTextureStorage2D(varAns, 1, GL_RGBA16UI,
            varImage.width(), varImage.height());
        glTextureSubImage2D(varAns, 0,
            0, 0,
            varImage.width(), varImage.height(),
            GL_RGBA, GL_UNSIGNED_SHORT,
            varImage.constBits());
        return varAns;
    }

    EXPORT_SSTD_QT_AND_QML_LIBRARY void updateTexture(GLuint * argTextureID, QImage argImage) {

        assert(argTextureID);

        if (*argTextureID < 1) {
            *argTextureID = createTexture(argImage);
            return;
        }

        auto varImageSize = argImage.size();
        auto varTextureSize = getTextureSize(*argTextureID);

        if (varImageSize != varTextureSize) {
            *argTextureID = createTexture(argImage);
            return;
        }

        const auto & varImage = argImage;
        glTextureSubImage2D(*argTextureID, 0,
            0, 0,
            varImage.width(), varImage.height(),
            GL_RGBA, GL_UNSIGNED_SHORT,
            varImage.constBits());

    }

    namespace {
        using gl_program_type = std::pair<std::string, GLenum>;
    }/*namespace*/

    inline static bool _1_createAShader(const gl_program_type & arg, GLuint * ans) {

        *ans = glCreateShader(std::get<1>(arg));

        if (0 == (*ans)) {
            sstd_log("create shader false "sv);
            return false;
        }

        return true;
    }

    template<std::size_t argC>
    inline static GLuint _1_createVFProgram(const std::initializer_list<gl_program_type> & args) {

        for (const auto & varI : args) {
            if (std::get<0>(varI).empty()) {
                return 0;
            }
        }

        class ShaderFree {
        public:
            std::array< GLuint, argC > data;
            inline ShaderFree() {
                for (auto & varI : data) {
                    varI = 0;
                }
            }
            inline ~ShaderFree() {
                for (auto & varI : data) {
                    glDeleteShader(varI);
                }
            }
        } shaders;

        {/*1*/
            std::size_t varJ = 0;
            for (const auto & varI : args) {
                if (false == _1_createAShader(varI, &(shaders.data[varJ]))) {
                    return 0;
                }
                ++varJ;
            }
        }

        {/*2*/
            const GLchar * sources[argC];
            GLint lengths[argC];

            std::size_t varJ = 0;
            for (const auto & varI : args) {
                sources[varJ] = std::get<0>(varI).data();
                lengths[varJ] = static_cast<GLint>(
                    std::get<0>(varI).size());
                ++varJ;
            }

            varJ = 0;
            for (; varJ < argC; ++varJ) {
                glShaderSource(shaders.data[varJ], 1, &sources[varJ], &lengths[varJ]);
                glCompileShader(shaders.data[varJ]);
                GLint testVal{ false };
                glGetShaderiv(shaders.data[varJ], GL_COMPILE_STATUS, &testVal);
                if (testVal == GL_FALSE) {
                    GLint log_length;
                    glGetShaderiv(shaders.data[varJ], GL_INFO_LOG_LENGTH, &log_length);
                    log_length += 16;
                    sstd::string infos_;
                    infos_.resize(log_length, char(0));
                    char * info = infos_.data();
                    glGetShaderInfoLog(shaders.data[varJ], log_length, nullptr, info);
                    sstd_log(info);
                    return 0;
                }
            }

        }

        GLuint program = glCreateProgram();
        if (0 == program) {
            sstd_log("create program error "sv);
            return 0;
        }

        for (const auto & varI : shaders.data) {
            glAttachShader(program, varI);
        }

        glLinkProgram(program);

        {
            GLint testVal{ false };
            glGetProgramiv(program, GL_LINK_STATUS, &testVal);
            if (testVal == GL_FALSE) {
                GLint log_length;
                glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
                log_length += 16;
                sstd::string infos_;
                infos_.resize(log_length, char(0));
                char * info = infos_.data();
                glGetProgramInfoLog(program, log_length, nullptr, info);
                sstd_log(info);
                glDeleteProgram(program);
                return 0;
            }
        }

        return program;
    }

    template<typename ... Args>
    inline static GLuint _0_createVFProgram(const Args & ... args) {
        return _1_createVFProgram<sizeof...(Args)>({ args... });
    }

    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint createVFProgram(
        std::string_view argV,
        std::string_view argF) {

        return _0_createVFProgram(
            gl_program_type{ argV, GL_VERTEX_SHADER },
            gl_program_type{ argF, GL_FRAGMENT_SHADER });

    }

}/*namespace sstd*/





//
// https://www.khronos.org/registry/OpenGL-Refpages/gl4/
//









