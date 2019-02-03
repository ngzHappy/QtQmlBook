TEMPLATE = app

CONFIG(debug,debug|release){
    TARGET = charts_debug
}else{
    TARGET = charts
}

QT += charts

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

SOURCES += $$PWD/ScatterSeriesHelp.cpp
HEADERS += $$PWD/ScatterSeriesHelp.hpp

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${DESTDIR}/build_install_debug $$PWD "myqml"
}else{
    QMAKE_POST_LINK += $${DESTDIR}/build_install $$PWD "myqml"
}
export(QMAKE_POST_LINK)

QMLSOURCES += $$PWD/myqml/charts/LineOfChart.qml
QMLSOURCES += $$PWD/myqml/charts/SplineOfChart.qml
QMLSOURCES += $$PWD/myqml/charts/ScatterOfChart.qml
QMLSOURCES += $$PWD/myqml/charts/AreaOfChart.qml
QMLSOURCES += $$PWD/myqml/charts/BarOfChart.qml

QMLSOURCES += $$PWD/myqml/charts/main_private/control/LineOfChartControl.qml

QMLSOURCES += $$PWD/myqml/charts/main.qml
QMLSOURCES += $$PWD/myqml/charts/DemoBasic.qml
QMLSOURCES += $$PWD/myqml/charts/main_private/MainListItem.qml
QMLSOURCES += $$PWD/myqml/charts/main_private/MainListModel.qml
QMLSOURCES += $$PWD/myqml/charts/main_private/MainListView.qml
QMLSOURCES += $$PWD/myqml/charts/main_private/control/SliderControl.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES




