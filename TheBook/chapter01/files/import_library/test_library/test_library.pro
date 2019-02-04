#test_library.pro
QT += gui
QT += core

CONFIG += console

CONFIG(debug,debug|release){
    TARGET = test_libraryd
}else{
    TARGET = test_library
}

TEMPLATE = lib

win32-msvc*{
    QMAKE_CXXFLAGS += /std:c++latest
}else{
    CONFIG += c++17
}

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

SOURCES += $$PWD/TestLibrary.cpp
HEADERS += $$PWD/TestLibrary.hpp

DESTDIR =  $$PWD/../bin
DEFINES *= D_TEST_LIBRARY
