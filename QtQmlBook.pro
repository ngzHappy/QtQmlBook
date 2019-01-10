TEMPLATE = subdirs

!win32{
    CONFIG += ordered
}

build_install.file = $$PWD/sstd_tools/build_install/build_install.pro
SUBDIRS += build_install

sstd_library.file = $$PWD/sstd_library/sstd_library.pro
sstd_library.depends = build_install
SUBDIRS += sstd_library

sstd_qt_and_qml_library.file = $$PWD/sstd_qt_and_qml_library/sstd_qt_and_qml_library.pro
sstd_qt_and_qml_library.depends = sstd_library
SUBDIRS += sstd_qt_and_qml_library

sstd_qml_control.file = $$PWD/sstd_qml_control/sstd_qml_control.pro
sstd_qml_control.depends = sstd_qt_and_qml_library
SUBDIRS += sstd_qml_control

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

app_enum_qml.file = $$PWD/chapter02/enum_qml/enum_qml.pro
app_enum_qml.depends = sstd_qt_and_qml_library
SUBDIRS += app_enum_qml

##############03##############

app_baidu_pan_password_get.file = $$PWD/chapter03/baidu_pan_password_get/baidu_pan_password_get.pro
app_baidu_pan_password_get.depends = sstd_qt_and_qml_library
SUBDIRS += app_baidu_pan_password_get

app_first_cplusplus_extern.file = $$PWD/chapter03/first_cplusplus_extern/first_cplusplus_extern.pro
app_first_cplusplus_extern.depends = sstd_qt_and_qml_library
SUBDIRS += app_first_cplusplus_extern

app_first_plugin_import.file = $$PWD/chapter03/first_plugin_import/first_plugin_import.pro
app_first_plugin_import.depends = sstd_qml_control
SUBDIRS += app_first_plugin_import

##############04##############

app_statemachine.file = $$PWD/chapter04/statemachine/statemachine.pro
app_statemachine.depends = sstd_qt_and_qml_library
SUBDIRS += app_statemachine

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

app_firsteffect.file = $$PWD/chapter06/firsteffect/firsteffect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_firsteffect

app_blend_effect.file = $$PWD/chapter06/blend_effect/blend_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_blend_effect

app_brightnesscontrast_effect.file = $$PWD/chapter06/brightnesscontrast_effect/brightnesscontrast_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_brightnesscontrast_effect

app_colorize_effect.file = $$PWD/chapter06/colorize_effect/colorize_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_colorize_effect

app_coloroverlay_effect.file = $$PWD/chapter06/coloroverlay_effect/coloroverlay_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_coloroverlay_effect

app_desaturate_effect.file = $$PWD/chapter06/desaturate_effect/desaturate_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_desaturate_effect

app_gammaadjust_effect.file = $$PWD/chapter06/gammaadjust_effect/gammaadjust_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_gammaadjust_effect

app_huesaturation_effect.file = $$PWD/chapter06/huesaturation_effect/huesaturation_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_huesaturation_effect

app_leveladjust_effect.file = $$PWD/chapter06/leveladjust_effect/leveladjust_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_leveladjust_effect

app_conicalgradient_effect.file = $$PWD/chapter06/conicalgradient_effect/conicalgradient_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_conicalgradient_effect

app_lineargradient_effect.file = $$PWD/chapter06/lineargradient_effect/lineargradient_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_lineargradient_effect

app_radialgradient_effect.file = $$PWD/chapter06/radialgradient_effect/radialgradient_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_radialgradient_effect

app_displace_effect.file = $$PWD/chapter06/displace_effect/displace_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_displace_effect

app_dropshadow_effect.file = $$PWD/chapter06/dropshadow_effect/dropshadow_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_dropshadow_effect

app_innershadow_effect.file = $$PWD/chapter06/innershadow_effect/innershadow_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_innershadow_effect

app_fastblur_effect.file = $$PWD/chapter06/fastblur_effect/fastblur_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_fastblur_effect

app_gaussianblur_effect.file = $$PWD/chapter06/gaussianblur_effect/gaussianblur_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_gaussianblur_effect

app_maskedblur_effect.file = $$PWD/chapter06/maskedblur_effect/maskedblur_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_maskedblur_effect

app_recursiveblur_effect.file = $$PWD/chapter06/recursiveblur_effect/recursiveblur_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_recursiveblur_effect

app_directionalblur_effect.file = $$PWD/chapter06/directionalblur_effect/directionalblur_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_directionalblur_effect

app_radialblur_effect.file = $$PWD/chapter06/radialblur_effect/radialblur_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_radialblur_effect

app_zoomblur_effect.file = $$PWD/chapter06/zoomblur_effect/zoomblur_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_zoomblur_effect

app_glow_effect.file = $$PWD/chapter06/glow_effect/glow_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_glow_effect

app_rectangularglow_effect.file = $$PWD/chapter06/rectangularglow_effect/rectangularglow_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_rectangularglow_effect

app_opacitymask_effect.file = $$PWD/chapter06/opacitymask_effect/opacitymask_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_opacitymask_effect

app_thresholdmask_effect.file = $$PWD/chapter06/thresholdmask_effect/thresholdmask_effect.pro
app_firsteffect.dpends = sstd_qt_and_qml_library
SUBDIRS += app_thresholdmask_effect

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

app_control_1_user_define_style.file = $$PWD/chapter09/control_1_user_define_style/control_1_user_define_style.pro
app_control_1_user_define_style.depends = sstd_qt_and_qml_library
SUBDIRS += app_control_1_user_define_style

app_control_2_user_define_style.file = $$PWD/chapter09/control_2_user_define_style/control_2_user_define_style.pro
app_control_2_user_define_style.depends = sstd_qt_and_qml_library
SUBDIRS += app_control_2_user_define_style

app_control_2_style.file = $$PWD/chapter09/control_2_style/control_2_style.pro
app_control_2_style.depends = sstd_qt_and_qml_library
SUBDIRS += app_control_2_style

##############10##############



