#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <utility>
#include <algorithm>
#include <string_view>
#include <type_traits>

#include <QtGui/QtGui>
#include <QtQml/QtQml>
#include <QtCore/QtCore>
#include <QtQuick/QtQuick>
#include <QtQuickControls2/QtQuickControls2>

#include "global/sstd_qt_and_qml_global.hpp"
#include "application/sstd_application.hpp"
#include "opengl_default_format/sstd_opengl_default_format.hpp"
#include "root_window/sstd_root_window.hpp"
#include "get_local_file_full_path/sstd_get_local_file_full_path.hpp"
#include "thread/sstd_qt_thread.hpp"
#include "quick_memory_image/sstd_quick_memory_image.hpp"
#include "glew/sstd_glew_initialization.hpp"
#include "glew/sstd_glew_utility.hpp"
#include "glew/sstd_glew.hpp"
#include "glew/sstd_using_glew.hpp"
#include "direct_draw_image/sstd_direct_draw_image.hpp"
#include "scene_node/sstd_scene_node.hpp"
#include "event/sstd_qrunevent.hpp"

using namespace std::chrono_literals;
using namespace std::string_view_literals;

inline QString operator""_qstr8(const char * a,std::size_t b) {
    return QString::fromUtf8(a,static_cast<int>(b));
}

inline QByteArray operator""_qbya(const char * a, std::size_t b) {
    return QByteArray{ a, static_cast<int>(b) };
}

