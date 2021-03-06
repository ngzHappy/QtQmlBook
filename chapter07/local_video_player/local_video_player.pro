TEMPLATE = app

CONFIG(debug,debug|release){
    TARGET = local_video_player_debug
}else{
    TARGET = local_video_player
}

#define out put dir
include($$PWD/../../outdirpath.pri)
#define cplusplus environment
include($$PWD/../../cplusplus.pri)
#import sstd_library
include($$PWD/../../sstd_library/import_sstd_library.pri)
#import sstd_qt_and_qml_library
include($$PWD/../../sstd_qt_and_qml_library/import_sstd_qt_and_qml_library.pri)
#import multimedia and ffmpge
include($$PWD/../import_ffmpeg_and_qt_multimedia.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

win32-msvc*{
    CONFIG += console
}

DEFINES += CURRENT_DEBUG_PATH=\\\"$$PWD\\\"

DESTDIR = $${RootDestDir}

SOURCES += $$PWD/main.cpp
HEADERS += $$PWD/VideoInformation.hpp

HEADERS += $$PWD/AudioFrame.hpp
HEADERS += $$PWD/AudioNumber.hpp

SOURCES += $$PWD/VideoReader.cpp
HEADERS += $$PWD/VideoReader.hpp

SOURCES += $$PWD/VideoPlayer.cpp
HEADERS += $$PWD/VideoPlayer.hpp

SOURCES += $$PWD/VideoPlayerThread.cpp
HEADERS += $$PWD/VideoPlayerThread.hpp

SOURCES += $$PWD/FFMPEGOpenCloseThread.cpp
HEADERS += $$PWD/FFMPEGOpenCloseThread.hpp

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${DESTDIR}/build_install_debug $$PWD "myqml"
}else{
    QMAKE_POST_LINK += $${DESTDIR}/build_install $$PWD "myqml"
}
export(QMAKE_POST_LINK)

QMLSOURCES += $$PWD/myqml/local_video_player/main.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES
