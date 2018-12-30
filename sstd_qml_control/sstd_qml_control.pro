TEMPLATE = lib
CONFIG += plugin

CONFIG(debug,debug|release){
    TARGET = sstd_qml_controld
}else{
    TARGET = sstd_qml_control
}

DEFINES *= _1_SSTD_QML_CONTROL

#define out put dir
include($$PWD/../outdirpath.pri)
#define cplusplus environment
include($$PWD/../cplusplus.pri)
#import sstd_library
include($$PWD/../sstd_library/import_sstd_library.pri)
#import sstd_qt_and_qml_library
include($$PWD/../sstd_qt_and_qml_library/import_sstd_qt_and_qml_library.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

DESTDIR = $${RootDestDir}/sstd/qml/control

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${RootDestDir}/build_install_debug $$PWD "sstd"
}else{
    QMAKE_POST_LINK += $${RootDestDir}/build_install $$PWD "sstd"
}
export(QMAKE_POST_LINK)

uri = sstd.qml.control
HEADERS += $$PWD/sstd_qml_control_global.hpp
HEADERS += $$PWD/sstd_qml_control.hpp
SOURCES += $$PWD/sstd_qml_control.cpp

HEADERS += $$PWD/TestData.hpp
SOURCES += $$PWD/TestData.cpp

DISTFILES = $$PWD/sstd/qml/control/qmldir

QMLSOURCES += $$PWD/sstd/qml/control/TestText.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES






