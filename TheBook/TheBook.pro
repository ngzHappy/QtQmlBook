TEMPLATE = app

QT += core
QT += gui
QT += widgets

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

DEFINES *= THE_PROJECT_PWD_DIR=\\\"$${PWD}\\\"












