TEMPLATE = app

QT -= core
QT -= gui

include($$PWD/build_install.pri)
include($$PWD/../../outdirpath.pri)

CONFIG(debug,debug|release){
    TARGET = build_install_debug
}else{
    TARGET = build_install
}

DESTDIR = $${RootDestDir}

DEFINES += FromDir=\\\"$$PWD\\\"
DEFINES += ToDir=\\\"$$DESTDIR\\\"





