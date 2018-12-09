#pragma once

#include "../global/sstd_qt_and_qml_global.hpp"
#include <QtGui/qimage.h>
#ifndef _SSTD_HAS_GLEW_0_1
#include <QtGui/qopenglfunctions.h>
#include <QtGui/qopenglfunctions_4_5_core.h>
#endif

namespace sstd{

    EXPORT_SSTD_QT_AND_QML_LIBRARY GLuint createTexture(QImage );
    EXPORT_SSTD_QT_AND_QML_LIBRARY void updateTexture(GLuint,QImage);


}/*namespace sstd*/











