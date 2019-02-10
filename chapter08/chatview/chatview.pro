#chatview.pro
TEMPLATE = app

CONFIG(debug,debug|release){
    TARGET = chatview_debug
}else{
    TARGET = chatview
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

DESTDIR = $${RootDestDir}

SOURCES += $$PWD/main.cpp

SOURCES += $$PWD/ChatHelper.cpp
HEADERS += $$PWD/ChatHelper.hpp

SOURCES += $$PWD/ChatDataItem.cpp
HEADERS += $$PWD/ChatDataItem.hpp

SOURCES += $$PWD/right_qtextdocumentlayout.cpp
HEADERS += $$PWD/right_qtextdocumentlayout_p.h

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${DESTDIR}/build_install_debug $$PWD "myqml"
}else{
    QMAKE_POST_LINK += $${DESTDIR}/build_install $$PWD "myqml"
}
export(QMAKE_POST_LINK)

QMLSOURCES += $$PWD/myqml/chatview/main.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES