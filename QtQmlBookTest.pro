
TEMPLATE = subdirs

build_install_test.file = $$PWD/sstd_tools/build_install/build_install_test/build_install_test.pro
SUBDIRS += build_install_test

sstd_library.file = $$PWD/sstd_library/test/sstd_library_test.pro
sstd_library.depends = build_install_test
SUBDIRS += sstd_library

sstd_qt_and_qml_library.file = $$PWD/sstd_qt_and_qml_library/test/sstd_qt_and_qml_library_test.pro
sstd_qt_and_qml_library.depends = build_install_test
SUBDIRS += sstd_qt_and_qml_library


















