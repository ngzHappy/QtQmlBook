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

SOURCES += $$PWD/TheBookSources/license.cpp

DESTDIR = $$PWD/bin/final

HEADERS += $$PWD/TheBookSources/InputStream.hpp

HEADERS += $$PWD/TheBookSources/the_book_global.hpp
SOURCES += $$PWD/TheBookSources/main.cpp

HEADERS += $$PWD/TheBookSources/MainWindow.hpp
SOURCES += $$PWD/TheBookSources/MainWindow.cpp

HEADERS += $$PWD/TheBookSources/ReadSource.hpp
SOURCES += $$PWD/TheBookSources/ReadSource.cpp

HEADERS += $$PWD/TheBookSources/GetTheBookConstexpr.hpp
SOURCES += $$PWD/TheBookSources/GetTheBookConstexpr.cpp

HEADERS += $$PWD/TheBookSources/output_main_index.hpp
SOURCES += $$PWD/TheBookSources/output_main_index.cpp

HEADERS += $$PWD/TheBookSources/ReadTable.hpp
SOURCES += $$PWD/TheBookSources/ReadTable.cpp

HEADERS += $$PWD/TheBookSources/OutPutStream.hpp
SOURCES += $$PWD/TheBookSources/OutPutStream.cpp

HEADERS += $$PWD/TheBookSources/ImageConvert.hpp
SOURCES += $$PWD/TheBookSources/ImageConvert.cpp

HEADERS += $$PWD/TheBookSources/TexBuilder.hpp
SOURCES += $$PWD/TheBookSources/TexBuilder.cpp

HEADERS += $$PWD/TheBookSources/CreateMakeFile.hpp
SOURCES += $$PWD/TheBookSources/CreateMakeFile.cpp

DEFINES *= THE_PROJECT_PWD_DIR=\\\"$${PWD}\\\"

DISTFILES += $$PWD/TheBookSources/the_book_constexpr.txt
DISTFILES += $$PWD/MakeFile.txt




