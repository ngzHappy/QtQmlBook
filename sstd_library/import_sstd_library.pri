INCLUDEPATH += $$PWD
CONFIG(debug,debug|release){
    LIBS +=-L$${RootDestDir} -lsstd_libraryd
}else{
    LIBS +=-L$${RootDestDir} -lsstd_library
}
