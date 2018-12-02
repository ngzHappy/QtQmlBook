#use Qt 5.12.0 or later
CONFIG += c++17

win32-msvc*{
}else{
     QMAKE_CFLAGS += -std=c11
}

#boost environment
DEFINES *= BOOST_THREAD_PROVIDES_FUTURE_CTOR_ALLOCATORS
DEFINES *= BOOST_THREAD_VERSION=4

















