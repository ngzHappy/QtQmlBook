 
win32-g++*{#win32-g++*

    DEFINES *= _0_SSTD_HAS_JE_MALLLOC
    LIBS += -L$$PWD/memory/libs -ljemalloc_win64_mingw_730

} else {#!win32-g++*

win32-msvc*{#win32-msvc*

    DEFINES *= _0_SSTD_HAS_JE_MALLLOC
    include($$PWD/memory/libs/jemalloc_msvc_64/jemalloc_msvc_64.pri)

} else { #!win32-msvc*

    #use export LD_PRELOAD=/usr/lib/x86_64-linux-gnu/libtcmalloc.so
    #    export LD_LIBRARY_PATH=/home/u/Qt/5.12.0/gcc_64/lib/:$LD_LIBRARY_PATH
    #DEFINES *= _0_SSTD_HAS_TC_MALLOC
    #LIBS    += -ltcmalloc_minimal
    #sudo apt-get install libgoogle-perftools-dev

} #win32-msvc*

}#win32-g++*

