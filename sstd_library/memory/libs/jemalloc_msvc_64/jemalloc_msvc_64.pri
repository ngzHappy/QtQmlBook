SOURCES += \
    $$PWD/src/arena.c \
    $$PWD/src/background_thread.c \
    $$PWD/src/base.c \
    $$PWD/src/bin.c \
    $$PWD/src/bitmap.c \
    $$PWD/src/ckh.c \
    $$PWD/src/ctl.c \
    $$PWD/src/div.c \
    $$PWD/src/extent.c \
    $$PWD/src/extent_dss.c \
    $$PWD/src/extent_mmap.c \
    $$PWD/src/hash.c \
    $$PWD/src/hook.c \
    $$PWD/src/jemalloc.c \
    $$PWD/src/large.c \
    $$PWD/src/log.c \
    $$PWD/src/malloc_io.c \
    $$PWD/src/mutex.c \
    $$PWD/src/mutex_pool.c \
    $$PWD/src/nstime.c \
    $$PWD/src/pages.c \
    $$PWD/src/prng.c \
    $$PWD/src/prof.c \
    $$PWD/src/rtree.c \
    $$PWD/src/sc.c \
    $$PWD/src/stats.c \
    $$PWD/src/sz.c \
    $$PWD/src/tcache.c \
    $$PWD/src/test_hooks.c \
    $$PWD/src/ticker.c \
    $$PWD/src/tsd.c \
    $$PWD/src/witness.c

INCLUDEPATH += $$PWD/src/msvc_compat

CONFIG(debug,debug|release){
DEFINES *= JEMALLOC_NO_PRIVATE_NAMESPACE
DEFINES *= JEMALLOC_DEBUG
DEFINES *= _REENTRANT
DEFINES *= JEMALLOC_EXPORT= #
DEFINES *= _DEBUG
DEFINES *= _LIB
}else{
DEFINES *= JEMALLOC_NO_PRIVATE_NAMESPACE
DEFINES *= _REENTRANT
DEFINES *= NDEBUG
DEFINES *= JEMALLOC_EXPORT= #
DEFINES *= _LIB
}


