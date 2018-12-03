TEMPLATE = app

QT += core
QT += gui
QT += widgets
QT += testlib

CONFIG(debug,debug|release){
    TARGET = sstd_library_test_debug
}else{
    TARGET = sstd_library_test
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

DESTDIR = $${TestRootDestDir}

SOURCES += $$PWD/main.cpp
SOURCES += $$PWD/TestApplication.cpp

HEADERS += $$PWD/TestApplication.hpp


