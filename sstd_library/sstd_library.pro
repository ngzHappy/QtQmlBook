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
SOURCES += $$PWD/runtime/sstd_private_runtime_cast_gcc.cpp
SOURCES += $$PWD/runtime/sstd_private_runtime_cast_msvc.cpp
SOURCES += $$PWD/runtime/sstd_runtime_dynamic_object.cpp
SOURCES += $$PWD/log/sstd_log.cpp
SOURCES += $$PWD/intrusive_ptr/sstd_intrusive_ptr.cpp
SOURCES += $$PWD/function_stack/sstd_function_stack.cpp

HEADERS += $$PWD/memory/sstd_memory.hpp
HEADERS += $$PWD/runtime/sstd_runtime.hpp
HEADERS += $$PWD/container/sstd_container.hpp
HEADERS += $$PWD/allocator/sstd_allocator.hpp
HEADERS += $$PWD/new/sstd_new.hpp
HEADERS += $$PWD/log/sstd_log.hpp
HEADERS += $$PWD/intrusive_ptr/sstd_intrusive_ptr.hpp
HEADERS += $$PWD/function_stack/sstd_function_stack.hpp

DESTDIR = $${RootDestDir}
#qmake -query
INCLUDEPATH += $$[QT_INSTALL_HEADERS]

#remove here if you can not build static jemalloc ...
include($$PWD/_sstd_library_memory.pri)
