#use Qt 5.12.0 or later

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
}

#boost environment
DEFINES *= BOOST_THREAD_PROVIDES_FUTURE_CTOR_ALLOCATORS
DEFINES *= BOOST_THREAD_VERSION=4
DEFINES *= BOOST_ALL_NO_LIB
DEFINES *= BOOST_ALL_DYN_LINK
win32{
    DEFINES *= BOOST_USE_WINAPI_VERSION=0x0501
}

win32{
    win32-msvc*{
        include($$PWD/msvc_boost.pri)
    }else{
        include($$PWD/mingw_boost.pri)
    }
}













