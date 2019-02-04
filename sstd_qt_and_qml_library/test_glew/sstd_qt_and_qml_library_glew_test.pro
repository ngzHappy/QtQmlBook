TEMPLATE = app

QT += testlib
QT += opengl

CONFIG(debug,debug|release){
    TARGET = sstd_qt_and_qml_library_glew_test_debug
}else{
    TARGET = sstd_qt_and_qml_library_glew_test
}

#define out put dir
include($$PWD/../../outdirpath.pri)
#define cplusplus environment
include($$PWD/../../cplusplus.pri)
#import sstd_library
include($$PWD/../../sstd_library/import_sstd_library.pri)
#import sstd_qt_and_qml_library
include($$PWD/../import_sstd_qt_and_qml_library.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

win32-msvc*{
    CONFIG += console
}

DESTDIR = $${TestRootDestDir}

SOURCES += $$PWD/main.cpp
SOURCES += $$PWD/MainWidget.cpp

HEADERS += $$PWD/MainWidget.hpp

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${DESTDIR}/build_install_test_debug $$PWD "myqml"
}else{
    QMAKE_POST_LINK += $${DESTDIR}/build_install_test $$PWD "myqml"
}
export(QMAKE_POST_LINK)

DEFINES += CURRENT_DEBUG_PATH=\\\"$$PWD\\\"
