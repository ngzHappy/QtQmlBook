 
win32-g++*{#win32-g++*

    DEFINES *= _0_SSTD_HAS_JE_MALLLOC
    LIBS += -L$$PWD/memory/libs -ljemalloc_win64_mingw_730

} else {#win32-g++*

win32-msvc*{#win32-msvc*

    DEFINES *= _0_SSTD_HAS_JE_MALLLOC
    include($$PWD/memory/libs/jemalloc_msvc_64/jemalloc_msvc_64.pri)

}#win32-msvc*

}#win32-g++*

