TEMPLATE = subdirs

build_install.file = $$PWD/sstd_tools/build_install/build_install.pro
SUBDIRS += build_install

sstd_library.file = $$PWD/sstd_library/sstd_library.pro
sstd_library.depends = build_install
SUBDIRS += sstd_library

sstd_qt_and_qml_library.file = $$PWD/sstd_qt_and_qml_library/sstd_qt_and_qml_library.pro
sstd_qt_and_qml_library.depends = sstd_library
SUBDIRS += sstd_qt_and_qml_library

app_hellowworld.file = $$PWD/chapter01/hellowworld/hellowworld.pro
app_hellowworld.depends = sstd_qt_and_qml_library
SUBDIRS += app_hellowworld

app_firstapplication.file = $$PWD/chapter01/firstapplication/firstapplication.pro
app_firstapplication.depends = sstd_qt_and_qml_library
SUBDIRS += app_firstapplication

app_externbycplusplus.file = $$PWD/chapter01/externbycplusplus/externbycplusplus.pro
app_externbycplusplus.depends = sstd_qt_and_qml_library
SUBDIRS += app_externbycplusplus

app_directdrawbyopengl.file = $$PWD/chapter01/directdrawbyopengl/directdrawbyopengl.pro
app_directdrawbyopengl.depends = sstd_qt_and_qml_library
SUBDIRS += app_directdrawbyopengl

app_colormodel.file = $$PWD/chapter01/colormodel/colormodel.pro
app_colormodel.depends = sstd_qt_and_qml_library
SUBDIRS += app_colormodel











