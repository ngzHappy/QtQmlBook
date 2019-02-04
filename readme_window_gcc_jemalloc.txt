under windows use mingw-32 ,
you should build static jemalloc yourself ,
and copy it to sstd_library/memory/libs/jemalloc_win64_mingw_730.a ,
or/and change sstd_library/_sstd_library_memory.pri

win32-g++*{#win32-g++*

DEFINES *= _0_SSTD_HAS_JE_MALLLOC
LIBS += -L$$PWD/memory/libs -ljemalloc_win64_mingw_730

}

if you could not build jemalloc , just delete all data in _sstd_library_memory.pri .
