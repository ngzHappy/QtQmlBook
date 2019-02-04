TEMPLATE = app

QT -= core
QT -= gui

SOURCES += $$PWD/main.cpp

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
