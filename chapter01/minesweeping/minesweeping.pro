TEMPLATE = app

CONFIG(debug,debug|release){
    TARGET = minesweeping_debug
}else{
    TARGET = minesweeping
}

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

SOURCES += $$PWD/MineSweeping.cpp
HEADERS += $$PWD/MineSweeping.hpp

SOURCES += $$PWD/MineSweepingWindow.cpp
HEADERS += $$PWD/MineSweepingWindow.hpp

SOURCES += $$PWD/MineSweepingLineNode.cpp
HEADERS += $$PWD/MineSweepingLineNode.hpp

SOURCES += $$PWD/MineSweepingLine.cpp
HEADERS += $$PWD/MineSweepingLine.hpp

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${DESTDIR}/build_install_debug $$PWD "myqml"
}else{
    QMAKE_POST_LINK += $${DESTDIR}/build_install $$PWD "myqml"
}
export(QMAKE_POST_LINK)

QMLSOURCES += $$PWD/myqml/minesweeping/main.qml
QMLSOURCES += $$PWD/myqml/minesweeping/Flag.qml
QMLSOURCES += $$PWD/myqml/minesweeping/Error.qml
QMLSOURCES += $$PWD/myqml/minesweeping/Number.qml
QMLSOURCES += $$PWD/myqml/minesweeping/Mine.qml
QMLSOURCES += $$PWD/myqml/minesweeping/Boom.qml
QMLSOURCES += $$PWD/myqml/minesweeping/OkMine.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES







