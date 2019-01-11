TEMPLATE = app

CONFIG(debug,debug|release){
    TARGET = statemachine_debug
}else{
    TARGET = statemachine
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

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${DESTDIR}/build_install_debug $$PWD "myqml"
}else{
    QMAKE_POST_LINK += $${DESTDIR}/build_install $$PWD "myqml"
}
export(QMAKE_POST_LINK)

QMLSOURCES += $$PWD/myqml/statemachine/main.qml
QMLSOURCES += $$PWD/myqml/statemachine/DemoBasic.qml
QMLSOURCES += $$PWD/myqml/statemachine/DemoCircleState.qml
QMLSOURCES += $$PWD/myqml/statemachine/DemoCircleStatePause.qml
QMLSOURCES += $$PWD/myqml/statemachine/DemoCircleStateQuit.qml
QMLSOURCES += $$PWD/myqml/statemachine/DemoParallelStateAnimation.qml
QMLSOURCES += $$PWD/myqml/statemachine/DemoParallelStateSelectRun.qml
QMLSOURCES += $$PWD/myqml/statemachine/main_private/MainListItem.qml
QMLSOURCES += $$PWD/myqml/statemachine/main_private/MainListModel.qml
QMLSOURCES += $$PWD/myqml/statemachine/main_private/MainListView.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES




