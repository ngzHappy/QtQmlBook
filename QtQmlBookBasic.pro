TEMPLATE = subdirs

#the project is really build in order ...
CONFIG+=ordered

build_install.file = $$PWD/sstd_tools/build_install/build_install.pro
SUBDIRS += build_install

sstd_library.file = $$PWD/sstd_library/sstd_library.pro
SUBDIRS += sstd_library

sstd_qt_and_qml_library.file = $$PWD/sstd_qt_and_qml_library/sstd_qt_and_qml_library.pro
SUBDIRS += sstd_qt_and_qml_library

sstd_qml_control.file = $$PWD/sstd_qml_control/sstd_qml_control.pro
SUBDIRS += sstd_qml_control

#if remove CONFIG+=ordered then add this ...
#sstd_library.depends = build_install
#sstd_qt_and_qml_library.depends = build_install sstd_library
#sstd_qml_control.depends = build_install sstd_library sstd_qt_and_qml_library
