#pragma once
#include "../global/sstd_qt_and_qml_global.hpp"

namespace sstd {

    EXPORT_SSTD_QT_AND_QML_LIBRARY bool glew_initialize();

}/*namespace sstd*/

#if defined(SSTD_HAS_GLEW_APPLICATION_INITIALIZE)

#ifndef sstd_glew_initialize
#define sstd_glew_initialize() static_assert(true)
#endif

#else

#ifndef sstd_glew_initialize
#define sstd_glew_initialize sstd::glew_initialize
#endif

#endif
