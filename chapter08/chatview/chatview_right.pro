#chatview.pro
TEMPLATE = lib

CONFIG(debug,debug|release){
    TARGET = chatview_utility_rightd
}else{
    TARGET = chatview_utility_right
}

QT += core_private
QT += gui_private
QT += widgets_private

#define out put dir
include($$PWD/../../outdirpath.pri)
#define cplusplus environment
include($$PWD/../../cplusplus.pri)
#import sstd_library
include($$PWD/../../sstd_library/import_sstd_library.pri)
#import sstd_qt_and_qml_library
include($$PWD/../../sstd_qt_and_qml_library/import_sstd_qt_and_qml_library.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

win32-msvc*{
    CONFIG += console
}

DEFINES += CURRENT_DEBUG_PATH=\\\"$$PWD\\\"
DEFINES *= CHAT_VIEW_LIBRARY
DEFINES *= CHAT_VIEW_RIGHT_LIBRARY

DESTDIR = $${RootDestDir}

HEADERS += $$PWD/right_qtextdocumentlayout.hpp
HEADERS += $$PWD/right_qtextdocumentlayout_p.h

SOURCES += $$PWD/CreateRightTextDocumentLayout.cpp
HEADERS += $$PWD/CreateRightTextDocumentLayout.hpp


