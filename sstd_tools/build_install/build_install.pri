SOURCES += $$PWD/main.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_codecvt_error_category.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_error_code.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_operations.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_path.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_path_traits.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_portability.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_unique_path.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_utf8_codecvt_facet.cpp \
    $$PWD/boost_filesystem_libs/boost_filesystem_windows_file_codecvt.cpp

win32-msvc*{
    QMAKE_CXXFLAGS += /std:c++latest
}else{
    CONFIG += c++17
}

win32-msvc*{
    CONFIG+=suppress_vcproj_warnings
}else{
    QMAKE_CFLAGS += -std=c11
    QMAKE_CXXFLAGS += -Wno-unused-parameter
    QMAKE_CXXFLAGS += -Wno-deprecated-declarations
}

INCLUDEPATH += $$PWD/boost_filesystem
DEFINES *= BOOST_ALL_NO_LIB
DEFINES *= BOOST_THREAD_PROVIDES_FUTURE_CTOR_ALLOCATORS
DEFINES *= BOOST_THREAD_VERSION=4
win32{
    DEFINES *= BOOST_USE_WINAPI_VERSION=0x0501
}

