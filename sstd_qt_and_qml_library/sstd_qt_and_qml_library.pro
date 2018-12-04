TEMPLATE = lib

QT += gui
QT += qml
QT += core
QT += quick
QT += widgets
QT += concurrent

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

SOURCES += $$PWD/application/sstd_application.cpp
SOURCES += $$PWD/application/sstd_application_environment.cpp
SOURCES += $$PWD/opengl_default_format/sstd_opengl_default_format.cpp



