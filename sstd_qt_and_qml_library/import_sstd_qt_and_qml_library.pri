QT += gui
QT += qml
QT += core
QT += quick
QT += widgets
QT += concurrent

INCLUDEPATH += $$PWD
CONFIG(debug,debug|release){
    LIBS +=-L$${RootDestDir} -lsstd_qt_and_qml_libraryd
}else{
    LIBS +=-L$${RootDestDir} -lsstd_qt_and_qml_library
}

















