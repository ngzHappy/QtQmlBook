TEMPLATE = app

QT -= core
QT -= gui

include($$PWD/../build_install.pri)
include($$PWD/../../../outdirpath.pri)

CONFIG(debug,debug|release){
    TARGET = build_install_test_debug
}else{
    TARGET = build_install_test
}

DESTDIR = $${TestRootDestDir}

DEFINES += FromDir=\\\"$$PWD\\\"
DEFINES += ToDir=\\\"$$DESTDIR\\\"





