#define _SSTD_HAS_GLEW_0_1 (1u)

#include "GLSSTD/glew.h"
#include "sstd_glew_utility.hpp"
#include <cassert>

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

}/*namespace sstd*/





//
// https://www.khronos.org/registry/OpenGL-Refpages/gl4/
//









