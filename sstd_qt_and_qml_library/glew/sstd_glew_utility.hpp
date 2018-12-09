#pragma once

#include "../global/sstd_qt_and_qml_global.hpp"
#include <QtGui/qimage.h>
#include <string_view>

#ifndef _SSTD_HAS_GLEW_0_1
#include <QtGui/qopenglfunctions.h>
#include <QtGui/qopenglfunctions_4_5_core.h>
#endif

namespace sstd::opengl_utility {

    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint createTexture(QImage);
    EXPORT_SSTD_QT_AND_QML_LIBRARY QSize getTextureSize(GLuint);
    EXPORT_SSTD_QT_AND_QML_LIBRARY void updateTexture(GLuint *, QImage);
    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint createVFProgram(std::string_view,std::string_view);

}/*namespace sstd*/











