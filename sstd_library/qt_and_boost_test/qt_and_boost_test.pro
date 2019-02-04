TEMPLATE = app

QT += core
QT += gui
QT += widgets


CONFIG(debug,debug|release){
    TARGET = qt_and_boost_test_debug
}else{
    TARGET = qt_and_boost_test
}

#define out put dir
include($$PWD/../../outdirpath.pri)
#define cplusplus environment
include($$PWD/../../cplusplus.pri)
#import sstd_library
include($$PWD/../import_sstd_library.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

win32-msvc*{
    CONFIG += console
}

DESTDIR = $${TestRootDestDir}

DEFINES += CURRENT_DEBUG_PATH=\\\"$$PWD\\\"

SOURCES += $$PWD/main.cpp
