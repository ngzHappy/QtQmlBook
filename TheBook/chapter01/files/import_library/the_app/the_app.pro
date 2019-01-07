#the_app.pro
QT += gui
QT += core

CONFIG += console

CONFIG(debug,debug|release){
    TARGET = the_app_debug
}else{
    TARGET = the_app
}

TEMPLATE = app

win32-msvc*{
    QMAKE_CXXFLAGS += /std:c++latest
}else{
    CONFIG += c++17
}

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

DESTDIR =  $$PWD/../bin

SOURCES += $$PWD/main.cpp
include($$PWD/../test_library/import_test_library.pri)




















