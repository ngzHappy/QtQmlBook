TEMPLATE = lib

CONFIG(debug,debug|release){
    TARGET = sstd_qml_controld
}else{
    TARGET = sstd_qml_control
}

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

DESTDIR = $${RootDestDir}

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${DESTDIR}/build_install_debug $$PWD "sstd"
}else{
    QMAKE_POST_LINK += $${DESTDIR}/build_install $$PWD "sstd"
}
export(QMAKE_POST_LINK)













