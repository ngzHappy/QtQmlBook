#chatview.pro
TEMPLATE = lib

CONFIG(debug,debug|release){
    TARGET = chatview_utility_leftd
}else{
    TARGET = chatview_utility_left
}

QT += core_private
QT += gui_private
QT += widgets_private

#define out put dir
include($$PWD/../../../outdirpath.pri)
#define cplusplus environment
include($$PWD/../../../cplusplus.pri)
#import sstd_library
include($$PWD/../../../sstd_library/import_sstd_library.pri)
#import sstd_qt_and_qml_library
include($$PWD/../../../sstd_qt_and_qml_library/import_sstd_qt_and_qml_library.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

win32-msvc*{
    CONFIG += console
}

CONFIG(debug,debug|release){
    LIBS += -L$${RootDestDir} -lchatview_utility_basicd
}else{
    LIBS += -L$${RootDestDir} -lchatview_utility_basic
}

DEFINES += CURRENT_DEBUG_PATH=\\\"$$PWD\\\"
DEFINES *= CHAT_VIEW_LIBRARY
DEFINES *= CHAT_VIEW_LEFT_LIBRARY

DESTDIR = $${RootDestDir}

HEADERS += $$PWD/../left_qtextdocumentlayout.hpp
HEADERS += $$PWD/../left_qtextdocumentlayout_p.h
HEADERS += $$PWD/../CreateTextDocument.hpp

SOURCES += $$PWD/../CreateLeftTextDocumentLayout.cpp
HEADERS += $$PWD/../CreateLeftTextDocumentLayout.hpp
