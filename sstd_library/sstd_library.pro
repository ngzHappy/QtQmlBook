TEMPLATE = lib

QT -=core
QT -=gui

CONFIG(debug,debug|release){
    TARGET = sstd_libraryd
}else{
    TARGET = sstd_library
}

DEFINES *= _1_SSTD_CORE_LIBRARY

#define out put dir
include($$PWD/../outdirpath.pri)
#define cplusplus environment
include($$PWD/../cplusplus.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

HEADERS += $$PWD/global/sstd_basic_library_global.hpp
HEADERS += $$PWD/sstd_library.hpp

SOURCES += $$PWD/memory/sstd_memory.cpp
SOURCES += $$PWD/runtime/sstd_runtime.cpp

HEADERS += $$PWD/memory/sstd_memory.hpp
HEADERS += $$PWD/runtime/sstd_runtime.hpp

HEADERS += $$PWD/container/sstd_container.hpp
HEADERS += $$PWD/allocator/sstd_allocator.hpp
HEADERS += $$PWD/new/sstd_new.hpp

DESTDIR = $${RootDestDir}
INCLUDEPATH += $$[QT_INSTALL_HEADERS]
#qmake -query

