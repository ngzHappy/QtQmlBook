TEMPLATE = lib

QT += gui
QT += qml
QT += core
QT += quick
QT += widgets
QT += concurrent
QT += quickwidgets
QT += quickcontrols2

QT += gui_private
QT += qml_private
QT += core_private
QT += quick_private
QT += widgets_private

CONFIG(debug,debug|release){
    TARGET = sstd_qt_and_qml_libraryd
}else{
    TARGET = sstd_qt_and_qml_library
}

DEFINES *= _1_SSTD_QT_AND_QML_LIBRARY

#define out put dir
include($$PWD/../outdirpath.pri)
#define cplusplus environment
include($$PWD/../cplusplus.pri)
#import sstd_library
include($$PWD/../sstd_library/import_sstd_library.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

DESTDIR = $${RootDestDir}

HEADERS += $$PWD/sstd_qt_and_qml_library.hpp
HEADERS += $$PWD/global/sstd_qt_and_qml_global.hpp
HEADERS += $$PWD/application/sstd_application.hpp
HEADERS += $$PWD/application/sstd_application_environment.hpp
HEADERS += $$PWD/opengl_default_format/sstd_opengl_default_format.hpp
HEADERS += $$PWD/root_window/sstd_root_window.hpp
HEADERS += $$PWD/get_local_file_full_path/sstd_get_local_file_full_path.hpp
HEADERS += $$PWD/thread/sstd_qt_thread.hpp
HEADERS += $$PWD/thread/sstd_qt_thread_object.hpp
HEADERS += $$PWD/thread/sstd_private/sstd_qt_thread_private.hpp
HEADERS += $$PWD/glew/sstd_glew.hpp
HEADERS += $$PWD/quick_memory_image/sstd_quick_memory_image.hpp
HEADERS += $$PWD/glew/sstd_glew_initialization.hpp
HEADERS += $$PWD/glew/sstd_glew_utility.hpp
HEADERS += $$PWD/direct_draw_image/sstd_direct_draw_image.hpp
HEADERS += $$PWD/scene_node/sstd_simple_rectangle_node.hpp
HEADERS += $$PWD/scene_node/sstd_scene_node.hpp
HEADERS += $$PWD/root_window/sstd_private/sstd_qquickview_resize.hpp
HEADERS += $$PWD/event/sstd_qrunevent.hpp
HEADERS += $$PWD/local_qml_window_creator/sstd_local_qml_window_creator.hpp

SOURCES += $$PWD/application/sstd_application.cpp
SOURCES += $$PWD/application/sstd_application_environment.cpp
SOURCES += $$PWD/opengl_default_format/sstd_opengl_default_format.cpp
SOURCES += $$PWD/root_window/sstd_root_window.cpp
SOURCES += $$PWD/get_local_file_full_path/sstd_get_local_file_full_path.cpp
SOURCES += $$PWD/thread/sstd_qt_thread.cpp
SOURCES += $$PWD/thread/sstd_qt_thread_object.cpp
SOURCES += $$PWD/thread/sstd_private/sstd_qt_thread_private.cpp
SOURCES += $$PWD/glew/sstd_glew.cpp
SOURCES += $$PWD/glew/glew.c
INCLUDEPATH += $$PWD/glew
SOURCES += $$PWD/quick_memory_image/sstd_quick_memory_image.cpp
SOURCES += $$PWD/glew/sstd_glew_initialization.cpp
SOURCES += $$PWD/glew/sstd_glew_utility.cpp
SOURCES += $$PWD/direct_draw_image/sstd_direct_draw_image.cpp
SOURCES += $$PWD/scene_node/sstd_simple_rectangle_node.cpp
SOURCES += $$PWD/root_window/sstd_private/sstd_qquickview_resize.cpp
SOURCES += $$PWD/event/sstd_qrunevent.cpp
SOURCES += $$PWD/local_qml_window_creator/sstd_local_qml_window_creator.cpp

DEFINES *= GLEW_NO_GLU
DEFINES *= GLEW_STATIC

win32:{
LIBS+= -lopengl32 -lgdi32 -luser32 -lkernel32
} else {
###libglu1-mesa-dev
###libgl1-mesa-dev
LIBS+=-lXmu -lXi -lGL -lXext -lX11
}

RESOURCES += $$PWD/resource/sstd_qt_and_qml_library.qrc



