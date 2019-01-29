
QT += core gui
QT += widgets

CONFIG += console

TARGET = create_dll_link
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
        $$PWD/main.cpp \
        $$PWD/MainWindow.cpp

HEADERS += \
        $$PWD/MainWindow.hpp

FORMS += \
        $$PWD/MainWindow.ui


include($$PWD/../../outdirpath.pri)

DESTDIR = $${RootDestDir}

win32-msvc*{
    QMAKE_CXXFLAGS += /std:c++latest
}else{
    CONFIG += c++17
    LIBS += -lstdc++fs
}

win32-msvc*{
    CONFIG+=suppress_vcproj_warnings
}else{
    QMAKE_CFLAGS += -std=c11
    QMAKE_CXXFLAGS += -Wno-unused-parameter
    QMAKE_CXXFLAGS += -Wno-deprecated-declarations
}





