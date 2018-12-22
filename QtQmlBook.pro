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

app_bigscene.file = $$PWD/chapter01/bigscene/bigscene.pro
app_bigscene.depends = sstd_qt_and_qml_library
SUBDIRS += app_bigscene

app_bigscene2dviewer.file = $$PWD/chapter01/bigscene2dviewer/bigscene2dviewer.pro
app_bigscene2dviewer.depends = sstd_qt_and_qml_library
SUBDIRS += app_bigscene2dviewer

app_defaultstyle.file = $$PWD/chapter01/defaultstyle/defaultstyle.pro
app_defaultstyle.depends = sstd_qt_and_qml_library
SUBDIRS += app_defaultstyle

app_minesweeping.file = $$PWD/chapter01/minesweeping/minesweeping.pro
app_minesweeping.depends = sstd_qt_and_qml_library
SUBDIRS += app_minesweeping

app_firstparticlesystem.file = $$PWD/chapter05/firstparticlesystem/firstparticlesystem.pro
app_firstparticlesystem.depends = sstd_qt_and_qml_library
SUBDIRS += app_firstparticlesystem

app_firstcanvas.file = $$PWD/chapter08/firstcanvas/firstcanvas.pro
app_firstcanvas.depends = sstd_qt_and_qml_library
SUBDIRS += app_firstcanvas

app_emitters_particlesystem.file = $$PWD/chapter05/emitters_particlesystem/emitters_particlesystem.pro
app_emitters_particlesystem.depends = sstd_qt_and_qml_library
SUBDIRS += app_emitters_particlesystem

app_affectors_particlesystem.file = $$PWD/chapter05/affectors_particlesystem/affectors_particlesystem.pro
app_affectors_particlesystem.depends = sstd_qt_and_qml_library
SUBDIRS += app_affectors_particlesystem

