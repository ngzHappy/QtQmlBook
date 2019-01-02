TEMPLATE = app

QT += core
QT += gui
QT += widgets

CONFIG(debug,debug|release){
    DEFINES *= _DEBUG
    SOURCES += $$PWD/TheBookSources/Test.cpp
}else{
    DEFINES *= NDEBUG
}

win32-msvc*{
    CONFIG += console
}

win32-msvc*{
    QMAKE_CXXFLAGS += /std:c++latest
}else{
    CONFIG += c++17
}

DESTDIR = $$PWD/bin/final

HEADERS += $$PWD/TheBookSources/the_book_global.hpp
SOURCES += $$PWD/TheBookSources/main.cpp

HEADERS += $$PWD/TheBookSources/MainWindow.hpp
SOURCES += $$PWD/TheBookSources/MainWindow.cpp

HEADERS += $$PWD/TheBookSources/output_main_index.hpp
SOURCES += $$PWD/TheBookSources/output_main_index.cpp

HEADERS += $$PWD/TheBookSources/OutPutStream.hpp
SOURCES += $$PWD/TheBookSources/OutPutStream.cpp

HEADERS += $$PWD/TheBookSources/TexBuilder.hpp
SOURCES += $$PWD/TheBookSources/TexBuilder.cpp

DEFINES *= THE_PROJECT_PWD_DIR=\\\"$${PWD}\\\"

DISTFILES += $$PWD/test/test_0000.txt
DISTFILES += $$PWD/test/test_0100.txt
DISTFILES += $$PWD/test/test_0101.txt
DISTFILES += $$PWD/test/test_0200.txt

DISTFILES += $$PWD/foreword/foreword.txt
DISTFILES += $$PWD/chapter01/chapter01.txt
DISTFILES += $$PWD/chapter02/chapter02.txt
DISTFILES += $$PWD/chapter03/chapter03.txt
DISTFILES += $$PWD/chapter04/chapter04.txt
DISTFILES += $$PWD/chapter05/chapter05.txt
DISTFILES += $$PWD/chapter06/chapter06.txt
DISTFILES += $$PWD/chapter07/chapter07.txt
DISTFILES += $$PWD/chapter08/chapter08.txt
DISTFILES += $$PWD/chapter09/chapter09.txt
DISTFILES += $$PWD/chapter10/chapter10.txt










