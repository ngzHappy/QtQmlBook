TEMPLATE = app

win32-msvc*{

CONFIG(debug,debug|release){
    TARGET = the_book_msvc_debug
}else{
    TARGET = the_book_msvc
}

}else{

CONFIG(debug,debug|release){
    TARGET = the_book_debug
}else{
    TARGET = the_book
}

}

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

HEADERS += $$PWD/TheBookSources/InputStream.hpp

HEADERS += $$PWD/TheBookSources/the_book_global.hpp
SOURCES += $$PWD/TheBookSources/main.cpp

HEADERS += $$PWD/TheBookSources/MainWindow.hpp
SOURCES += $$PWD/TheBookSources/MainWindow.cpp

HEADERS += $$PWD/TheBookSources/GetTheBookConstexpr.hpp
SOURCES += $$PWD/TheBookSources/GetTheBookConstexpr.cpp

HEADERS += $$PWD/TheBookSources/output_main_index.hpp
SOURCES += $$PWD/TheBookSources/output_main_index.cpp

HEADERS += $$PWD/TheBookSources/OutPutStream.hpp
SOURCES += $$PWD/TheBookSources/OutPutStream.cpp

HEADERS += $$PWD/TheBookSources/TexBuilder.hpp
SOURCES += $$PWD/TheBookSources/TexBuilder.cpp

DEFINES *= THE_PROJECT_PWD_DIR=\\\"$${PWD}\\\"

DISTFILES += $$PWD/TheBookSources/the_book_constexpr.txt

DISTFILES += $$PWD/test/test_0000.txt
DISTFILES += $$PWD/test/test_0100.txt
DISTFILES += $$PWD/test/test_0101.txt
DISTFILES += $$PWD/test/test_0200.txt

DISTFILES += $$PWD/test/test_0000.tex
DISTFILES += $$PWD/test/test_0100.tex
DISTFILES += $$PWD/test/test_0101.tex
DISTFILES += $$PWD/test/test_0200.tex

DISTFILES += $$PWD/foreword/foreword.txt
DISTFILES += $$PWD/chapter01/chapter01.txt
DISTFILES += $$PWD/chapter01/section01_chapter01.txt
DISTFILES += $$PWD/chapter01/setup_dev_env_on_linux.txt
DISTFILES += $$PWD/chapter01/setup_dev_env_on_windows.txt
DISTFILES += $$PWD/chapter02/chapter02.txt
DISTFILES += $$PWD/chapter03/chapter03.txt
DISTFILES += $$PWD/chapter04/chapter04.txt
DISTFILES += $$PWD/chapter05/chapter05.txt
DISTFILES += $$PWD/chapter06/chapter06.txt
DISTFILES += $$PWD/chapter07/chapter07.txt
DISTFILES += $$PWD/chapter08/chapter08.txt
DISTFILES += $$PWD/chapter09/chapter09.txt
DISTFILES += $$PWD/chapter10/chapter10.txt

DISTFILES += $$PWD/foreword/foreword.tex
DISTFILES += $$PWD/chapter01/chapter01.tex
DISTFILES += $$PWD/chapter01/section01_chapter01.tex
DISTFILES += $$PWD/chapter01/setup_dev_env_on_linux.tex
DISTFILES += $$PWD/chapter01/setup_dev_env_on_windows.tex
DISTFILES += $$PWD/chapter02/chapter02.tex
DISTFILES += $$PWD/chapter03/chapter03.tex
DISTFILES += $$PWD/chapter04/chapter04.tex
DISTFILES += $$PWD/chapter05/chapter05.tex
DISTFILES += $$PWD/chapter06/chapter06.tex
DISTFILES += $$PWD/chapter07/chapter07.tex
DISTFILES += $$PWD/chapter08/chapter08.tex
DISTFILES += $$PWD/chapter09/chapter09.tex
DISTFILES += $$PWD/chapter10/chapter10.tex

DISTFILES += $$PWD/main_index.tex
DISTFILES += $$PWD/main_index.txt



