call "C:/Qt/Qt5.12.0/5.12.0/msvc2017_64/bin/qtenv2.bat"
cd /D "E:/QtQmlBookMsvc"
qmake -r -tp vc "E:/QtQmlBook/QtQmlBook.pro"
qmake -r -tp vc "E:/QtQmlBook/QtQmlMultimedia.pro"
qmake -r -tp vc "E:/QtQmlBook/QtQmlBookTest.pro"
qmake -r -tp vc "E:/QtQmlBook/TheBook/TheBook.pro"
cmd












