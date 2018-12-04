TEMPLATE = subdirs

build_install.file = $$PWD/sstd_tools/build_install/build_install.pro
SUBDIRS += build_install

sstd_library.file = $$PWD/sstd_library/sstd_library.pro
sstd_library.depends = build_install
SUBDIRS += sstd_library

sstd_qt_and_qml_library.file = $$PWD/sstd_qt_and_qml_library/sstd_qt_and_qml_library.pro
sstd_qt_and_qml_library.depends = sstd_library
SUBDIRS += sstd_qt_and_qml_library



 


















