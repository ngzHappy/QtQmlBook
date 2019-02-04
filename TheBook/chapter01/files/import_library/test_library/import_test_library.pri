#import_test_library.pri
INCLUDEPATH += $$PWD
CONFIG(debug,debug|release){
    LIBS += -L$$PWD/../bin -ltest_libraryd
}else{
    LIBS += -L$$PWD/../bin -ltest_library
}
