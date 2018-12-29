TEMPLATE = subdirs

build_install.file = $$PWD/sstd_tools/build_install/build_install.pro
SUBDIRS += build_install

sstd_library.file = $$PWD/sstd_library/sstd_library.pro
sstd_library.depends = build_install
SUBDIRS += sstd_library

sstd_qt_and_qml_library.file = $$PWD/sstd_qt_and_qml_library/sstd_qt_and_qml_library.pro
sstd_qt_and_qml_library.depends = sstd_library
SUBDIRS += sstd_qt_and_qml_library

##############01##############

app_hellowworld.file = $$PWD/chapter01/hellowworld/hellowworld.pro
app_hellowworld.depends = sstd_qt_and_qml_library
SUBDIRS += app_hellowworld

app_shadereffect.file = $$PWD/chapter01/shadereffect/shadereffect.pro
app_shadereffect.depends = sstd_qt_and_qml_library
SUBDIRS += app_shadereffect

app_shadereffectwithimage.file = $$PWD/chapter01/shadereffectwithimage/shadereffectwithimage.pro
app_shadereffectwithimage.depends = sstd_qt_and_qml_library
SUBDIRS += app_shadereffectwithimage

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

##############02##############

app_image_qmltype.file = $$PWD/chapter02/image_qmltype/image_qmltype.pro
app_image_qmltype.depends = sstd_qt_and_qml_library
SUBDIRS += app_image_qmltype

app_animatedimage_qmltype.file = $$PWD/chapter02/animatedimage_qmltype/animatedimage_qmltype.pro
app_animatedimage_qmltype.depends = sstd_qt_and_qml_library
SUBDIRS += app_animatedimage_qmltype

app_animatedsprite_qmltype.file = $$PWD/chapter02/animatedsprite_qmltype/animatedsprite_qmltype.pro
app_animatedsprite_qmltype.depends = sstd_qt_and_qml_library
SUBDIRS += app_animatedsprite_qmltype

app_borderimage_qmltype.file = $$PWD/chapter02/borderimage_qmltype/borderimage_qmltype.pro
app_borderimage_qmltypee.depends = sstd_qt_and_qml_library
SUBDIRS += app_borderimage_qmltype

app_rectangle_qmltype.file = $$PWD/chapter02/rectangle_qmltype/rectangle_qmltype.pro
app_rectangle_qmltype.depends = sstd_qt_and_qml_library
SUBDIRS += app_rectangle_qmltype

app_text_qmltype.file = $$PWD/chapter02/text_qmltype/text_qmltype.pro
app_text_qmltype.depends = sstd_qt_and_qml_library
SUBDIRS += app_text_qmltype

##############03##############

app_baidu_pan_password_get.file = $$PWD/chapter03/baidu_pan_password_get/baidu_pan_password_get.pro
app_baidu_pan_password_get.depends = sstd_qt_and_qml_library
SUBDIRS += app_baidu_pan_password_get

app_first_cplusplus_extern.file = $$PWD/chapter03/first_cplusplus_extern/first_cplusplus_extern.pro
app_first_cplusplus_extern.depends = sstd_qt_and_qml_library
SUBDIRS += app_first_cplusplus_extern

##############04##############

##############05##############

app_emitters_particlesystem.file = $$PWD/chapter05/emitters_particlesystem/emitters_particlesystem.pro
app_emitters_particlesystem.depends = sstd_qt_and_qml_library
SUBDIRS += app_emitters_particlesystem

app_affectors_particlesystem.file = $$PWD/chapter05/affectors_particlesystem/affectors_particlesystem.pro
app_affectors_particlesystem.depends = sstd_qt_and_qml_library
SUBDIRS += app_affectors_particlesystem

app_firstparticlesystem.file = $$PWD/chapter05/firstparticlesystem/firstparticlesystem.pro
app_firstparticlesystem.depends = sstd_qt_and_qml_library
SUBDIRS += app_firstparticlesystem

##############06##############

##############07##############

##############08##############

app_firstcanvas.file = $$PWD/chapter08/firstcanvas/firstcanvas.pro
app_firstcanvas.depends = sstd_qt_and_qml_library
SUBDIRS += app_firstcanvas

app_firstchart.file = $$PWD/chapter08/firstchart/firstchart.pro
app_firstchart.depends = sstd_qt_and_qml_library
SUBDIRS += app_firstchart

##############09##############

app_first_control_1.file = $$PWD/chapter09/first_control_1/first_control_1.pro
app_first_control_1.depends = sstd_qt_and_qml_library
SUBDIRS += app_first_control_1

##############10##############



