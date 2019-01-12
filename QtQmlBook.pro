TEMPLATE = subdirs

#in some platform may be need this ..
#!win32{
#    CONFIG += ordered
#}

build_install.file = $$PWD/sstd_tools/build_install/build_install.pro
SUBDIRS += build_install

sstd_library.file = $$PWD/sstd_library/sstd_library.pro
sstd_library.depends = build_install
SUBDIRS += sstd_library

sstd_qt_and_qml_library.file = $$PWD/sstd_qt_and_qml_library/sstd_qt_and_qml_library.pro
sstd_qt_and_qml_library.depends = build_install sstd_library
SUBDIRS += sstd_qt_and_qml_library

sstd_qml_control.file = $$PWD/sstd_qml_control/sstd_qml_control.pro
sstd_qml_control.depends = build_install sstd_library sstd_qt_and_qml_library
SUBDIRS += sstd_qml_control

##############01##############

app_hellowworld.file = $$PWD/chapter01/hellowworld/hellowworld.pro
app_hellowworld.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_hellowworld

app_shadereffect.file = $$PWD/chapter01/shadereffect/shadereffect.pro
app_shadereffect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_shadereffect

app_shadereffectwithimage.file = $$PWD/chapter01/shadereffectwithimage/shadereffectwithimage.pro
app_shadereffectwithimage.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_shadereffectwithimage

app_firstapplication.file = $$PWD/chapter01/firstapplication/firstapplication.pro
app_firstapplication.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_firstapplication

app_externbycplusplus.file = $$PWD/chapter01/externbycplusplus/externbycplusplus.pro
app_externbycplusplus.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_externbycplusplus

app_directdrawbyopengl.file = $$PWD/chapter01/directdrawbyopengl/directdrawbyopengl.pro
app_directdrawbyopengl.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_directdrawbyopengl

app_colormodel.file = $$PWD/chapter01/colormodel/colormodel.pro
app_colormodel.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_colormodel

app_bigscene.file = $$PWD/chapter01/bigscene/bigscene.pro
app_bigscene.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_bigscene

app_bigscene2dviewer.file = $$PWD/chapter01/bigscene2dviewer/bigscene2dviewer.pro
app_bigscene2dviewer.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_bigscene2dviewer

app_defaultstyle.file = $$PWD/chapter01/defaultstyle/defaultstyle.pro
app_defaultstyle.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_defaultstyle

app_minesweeping.file = $$PWD/chapter01/minesweeping/minesweeping.pro
app_minesweeping.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_minesweeping

##############02##############

app_image_qmltype.file = $$PWD/chapter02/image_qmltype/image_qmltype.pro
app_image_qmltype.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_image_qmltype

app_animatedimage_qmltype.file = $$PWD/chapter02/animatedimage_qmltype/animatedimage_qmltype.pro
app_animatedimage_qmltype.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_animatedimage_qmltype

app_animatedsprite_qmltype.file = $$PWD/chapter02/animatedsprite_qmltype/animatedsprite_qmltype.pro
app_animatedsprite_qmltype.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_animatedsprite_qmltype

app_borderimage_qmltype.file = $$PWD/chapter02/borderimage_qmltype/borderimage_qmltype.pro
app_borderimage_qmltypee.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_borderimage_qmltype

app_rectangle_qmltype.file = $$PWD/chapter02/rectangle_qmltype/rectangle_qmltype.pro
app_rectangle_qmltype.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_rectangle_qmltype

app_text_qmltype.file = $$PWD/chapter02/text_qmltype/text_qmltype.pro
app_text_qmltype.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_text_qmltype

app_enum_qml.file = $$PWD/chapter02/enum_qml/enum_qml.pro
app_enum_qml.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_enum_qml

##############03##############

app_baidu_pan_password_get.file = $$PWD/chapter03/baidu_pan_password_get/baidu_pan_password_get.pro
app_baidu_pan_password_get.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_baidu_pan_password_get

app_first_cplusplus_extern.file = $$PWD/chapter03/first_cplusplus_extern/first_cplusplus_extern.pro
app_first_cplusplus_extern.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_first_cplusplus_extern

app_first_plugin_import.file = $$PWD/chapter03/first_plugin_import/first_plugin_import.pro
app_first_plugin_import.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_first_plugin_import

##############04##############

app_statemachine.file = $$PWD/chapter04/statemachine/statemachine.pro
app_statemachine.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_statemachine

##############05##############

app_emitters_particlesystem.file = $$PWD/chapter05/emitters_particlesystem/emitters_particlesystem.pro
app_emitters_particlesystem.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_emitters_particlesystem

app_affectors_particlesystem.file = $$PWD/chapter05/affectors_particlesystem/affectors_particlesystem.pro
app_affectors_particlesystem.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_affectors_particlesystem

app_firstparticlesystem.file = $$PWD/chapter05/firstparticlesystem/firstparticlesystem.pro
app_firstparticlesystem.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_firstparticlesystem

##############06##############

app_firsteffect.file = $$PWD/chapter06/firsteffect/firsteffect.pro
app_firsteffect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_firsteffect

app_blend_effect.file = $$PWD/chapter06/blend_effect/blend_effect.pro
app_blend_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_blend_effect

app_brightnesscontrast_effect.file = $$PWD/chapter06/brightnesscontrast_effect/brightnesscontrast_effect.pro
app_brightnesscontrast_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_brightnesscontrast_effect

app_colorize_effect.file = $$PWD/chapter06/colorize_effect/colorize_effect.pro
app_colorize_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_colorize_effect

app_coloroverlay_effect.file = $$PWD/chapter06/coloroverlay_effect/coloroverlay_effect.pro
app_coloroverlay_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_coloroverlay_effect

app_desaturate_effect.file = $$PWD/chapter06/desaturate_effect/desaturate_effect.pro
app_desaturate_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_desaturate_effect

app_gammaadjust_effect.file = $$PWD/chapter06/gammaadjust_effect/gammaadjust_effect.pro
app_gammaadjust_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_gammaadjust_effect

app_huesaturation_effect.file = $$PWD/chapter06/huesaturation_effect/huesaturation_effect.pro
app_huesaturation_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_huesaturation_effect

app_leveladjust_effect.file = $$PWD/chapter06/leveladjust_effect/leveladjust_effect.pro
app_leveladjust_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_leveladjust_effect

app_conicalgradient_effect.file = $$PWD/chapter06/conicalgradient_effect/conicalgradient_effect.pro
app_conicalgradient_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_conicalgradient_effect

app_lineargradient_effect.file = $$PWD/chapter06/lineargradient_effect/lineargradient_effect.pro
app_lineargradient_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_lineargradient_effect

app_radialgradient_effect.file = $$PWD/chapter06/radialgradient_effect/radialgradient_effect.pro
app_radialgradient_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_radialgradient_effect

app_displace_effect.file = $$PWD/chapter06/displace_effect/displace_effect.pro
app_displace_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_displace_effect

app_dropshadow_effect.file = $$PWD/chapter06/dropshadow_effect/dropshadow_effect.pro
app_dropshadow_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_dropshadow_effect

app_innershadow_effect.file = $$PWD/chapter06/innershadow_effect/innershadow_effect.pro
app_innershadow_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_innershadow_effect

app_fastblur_effect.file = $$PWD/chapter06/fastblur_effect/fastblur_effect.pro
app_fastblur_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_fastblur_effect

app_gaussianblur_effect.file = $$PWD/chapter06/gaussianblur_effect/gaussianblur_effect.pro
app_gaussianblur_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_gaussianblur_effect

app_maskedblur_effect.file = $$PWD/chapter06/maskedblur_effect/maskedblur_effect.pro
app_maskedblur_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_maskedblur_effect

app_recursiveblur_effect.file = $$PWD/chapter06/recursiveblur_effect/recursiveblur_effect.pro
app_recursiveblur_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_recursiveblur_effect

app_directionalblur_effect.file = $$PWD/chapter06/directionalblur_effect/directionalblur_effect.pro
app_directionalblur_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_directionalblur_effect

app_radialblur_effect.file = $$PWD/chapter06/radialblur_effect/radialblur_effect.pro
app_radialblur_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_radialblur_effect

app_zoomblur_effect.file = $$PWD/chapter06/zoomblur_effect/zoomblur_effect.pro
app_zoomblur_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_zoomblur_effect

app_glow_effect.file = $$PWD/chapter06/glow_effect/glow_effect.pro
app_glow_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_glow_effect

app_rectangularglow_effect.file = $$PWD/chapter06/rectangularglow_effect/rectangularglow_effect.pro
app_rectangularglow_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_rectangularglow_effect

app_opacitymask_effect.file = $$PWD/chapter06/opacitymask_effect/opacitymask_effect.pro
app_opacitymask_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_opacitymask_effect

app_thresholdmask_effect.file = $$PWD/chapter06/thresholdmask_effect/thresholdmask_effect.pro
app_thresholdmask_effect.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_thresholdmask_effect

##############07##############

##############08##############

app_firstcanvas.file = $$PWD/chapter08/firstcanvas/firstcanvas.pro
app_firstcanvas.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_firstcanvas

app_firstchart.file = $$PWD/chapter08/firstchart/firstchart.pro
app_firstchart.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_firstchart

##############09##############

app_first_control_1.file = $$PWD/chapter09/first_control_1/first_control_1.pro
app_first_control_1.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_first_control_1

app_control_1_user_define_style.file = $$PWD/chapter09/control_1_user_define_style/control_1_user_define_style.pro
app_control_1_user_define_style.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_control_1_user_define_style

app_control_2_user_define_style.file = $$PWD/chapter09/control_2_user_define_style/control_2_user_define_style.pro
app_control_2_user_define_style.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_control_2_user_define_style

app_control_2_style.file = $$PWD/chapter09/control_2_style/control_2_style.pro
app_control_2_style.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_control_2_style

app_action_control2.file = $$PWD/chapter09/action_control2/action_control2.pro
app_action_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_action_control2

app_actiongroup_control2.file = $$PWD/chapter09/actiongroup_control2/actiongroup_control2.pro
app_actiongroup_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_actiongroup_control2

app_applicationwindow_control2.file = $$PWD/chapter09/applicationwindow_control2/applicationwindow_control2.pro
app_applicationwindow_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_applicationwindow_control2

app_busyindicator_control2.file = $$PWD/chapter09/busyindicator_control2/busyindicator_control2.pro
app_busyindicator_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_busyindicator_control2

app_button_control2.file = $$PWD/chapter09/button_control2/button_control2.pro
app_button_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_button_control2

app_buttongroup_control2.file = $$PWD/chapter09/buttongroup_control2/buttongroup_control2.pro
app_buttongroup_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_buttongroup_control2

app_checkbox_control2.file = $$PWD/chapter09/checkbox_control2/checkbox_control2.pro
app_checkbox_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_checkbox_control2

app_checkdelegate_control2.file = $$PWD/chapter09/checkdelegate_control2/checkdelegate_control2.pro
app_checkdelegate_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_checkdelegate_control2

app_combobox_control2.file = $$PWD/chapter09/combobox_control2/combobox_control2.pro
app_combobox_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_combobox_control2

app_container_control2.file = $$PWD/chapter09/container_control2/container_control2.pro
app_container_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_container_control2

app_control_control2.file = $$PWD/chapter09/control_control2/control_control2.pro
app_control_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_control_control2

app_delaybutton_control2.file = $$PWD/chapter09/delaybutton_control2/delaybutton_control2.pro
app_delaybutton_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_delaybutton_control2

app_dial_control2.file = $$PWD/chapter09/dial_control2/dial_control2.pro
app_dial_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_dial_control2

app_dialog_control2.file = $$PWD/chapter09/dialog_control2/dialog_control2.pro
app_dialog_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_dialog_control2

app_dialogbuttonbox_control2.file = $$PWD/chapter09/dialogbuttonbox_control2/dialogbuttonbox_control2.pro
app_dialogbuttonbox_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_dialogbuttonbox_control2

app_drawer_control2.file = $$PWD/chapter09/drawer_control2/drawer_control2.pro
app_drawer_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_drawer_control2

app_frame_control2.file = $$PWD/chapter09/frame_control2/frame_control2.pro
app_frame_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_frame_control2

app_groupbox_control2.file = $$PWD/chapter09/groupbox_control2/groupbox_control2.pro
app_groupbox_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_groupbox_control2

app_itemdelegate_control2.file = $$PWD/chapter09/itemdelegate_control2/itemdelegate_control2.pro
app_itemdelegate_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_itemdelegate_control2

app_label_control2.file = $$PWD/chapter09/label_control2/label_control2.pro
app_label_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_label_control2

app_menu_control2.file = $$PWD/chapter09/menu_control2/menu_control2.pro
app_menu_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_menu_control2

app_menubar_control2.file = $$PWD/chapter09/menubar_control2/menubar_control2.pro
app_menubar_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_menubar_control2

app_menubaritem_control2.file = $$PWD/chapter09/menubaritem_control2/menubaritem_control2.pro
app_menubaritem_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_menubaritem_control2

app_menuitem_control2.file = $$PWD/chapter09/menuitem_control2/menuitem_control2.pro
app_menuitem_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_menuitem_control2

app_menuseparator_control2.file = $$PWD/chapter09/menuseparator_control2/menuseparator_control2.pro
app_menuseparator_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_menuseparator_control2

app_overlay_control2.file = $$PWD/chapter09/overlay_control2/overlay_control2.pro
app_overlay_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_overlay_control2

app_page_control2.file = $$PWD/chapter09/page_control2/page_control2.pro
app_page_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_page_control2

app_pageindicator_control2.file = $$PWD/chapter09/pageindicator_control2/pageindicator_control2.pro
app_pageindicator_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_pageindicator_control2

app_pane_control2.file = $$PWD/chapter09/pane_control2/pane_control2.pro
app_pane_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_pane_control2

app_popup_control2.file = $$PWD/chapter09/popup_control2/popup_control2.pro
app_popup_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_popup_control2

app_progressbar_control2.file = $$PWD/chapter09/progressbar_control2/progressbar_control2.pro
app_progressbar_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_progressbar_control2

app_radiobutton_control2.file = $$PWD/chapter09/radiobutton_control2/radiobutton_control2.pro
app_radiobutton_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_radiobutton_control2

app_radiodelegate_control2.file = $$PWD/chapter09/radiodelegate_control2/radiodelegate_control2.pro
app_radiodelegate_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_radiodelegate_control2

app_rangeslider_control2.file = $$PWD/chapter09/rangeslider_control2/rangeslider_control2.pro
app_rangeslider_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_rangeslider_control2

app_roundbutton_control2.file = $$PWD/chapter09/roundbutton_control2/roundbutton_control2.pro
app_roundbutton_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_roundbutton_control2

app_scrollbar_control2.file = $$PWD/chapter09/scrollbar_control2/scrollbar_control2.pro
app_scrollbar_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_scrollbar_control2

app_scrollindicator_control2.file = $$PWD/chapter09/scrollindicator_control2/scrollindicator_control2.pro
app_scrollindicator_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_scrollindicator_control2

app_scrollview_control2.file = $$PWD/chapter09/scrollview_control2/scrollview_control2.pro
app_scrollview_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_scrollview_control2

app_slider_control2.file = $$PWD/chapter09/slider_control2/slider_control2.pro
app_slider_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_slider_control2

app_spinbox_control2.file = $$PWD/chapter09/spinbox_control2/spinbox_control2.pro
app_spinbox_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_spinbox_control2

app_stackview_control2.file = $$PWD/chapter09/stackview_control2/stackview_control2.pro
app_stackview_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_stackview_control2

app_swipedelegate_control2.file = $$PWD/chapter09/swipedelegate_control2/swipedelegate_control2.pro
app_swipedelegate_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_swipedelegate_control2

app_swipeview_control2.file = $$PWD/chapter09/swipeview_control2/swipeview_control2.pro
app_swipeview_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_swipeview_control2

app_switch_control2.file = $$PWD/chapter09/switch_control2/switch_control2.pro
app_switch_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_switch_control2

app_switchdelegate_control2.file = $$PWD/chapter09/switchdelegate_control2/switchdelegate_control2.pro
app_switchdelegate_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_switchdelegate_control2

app_tabbar_control2.file = $$PWD/chapter09/tabbar_control2/tabbar_control2.pro
app_tabbar_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_tabbar_control2

app_tabbutton_control2.file = $$PWD/chapter09/tabbutton_control2/tabbutton_control2.pro
app_tabbutton_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_tabbutton_control2

app_textarea_control2.file = $$PWD/chapter09/textarea_control2/textarea_control2.pro
app_textarea_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_textarea_control2

app_textfield_control2.file = $$PWD/chapter09/textfield_control2/textfield_control2.pro
app_textfield_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_textfield_control2

app_toolbar_control2.file = $$PWD/chapter09/toolbar_control2/toolbar_control2.pro
app_toolbar_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_toolbar_control2

app_toolbutton_control2.file = $$PWD/chapter09/toolbutton_control2/toolbutton_control2.pro
app_toolbutton_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_toolbutton_control2

app_toolseparator_control2.file = $$PWD/chapter09/toolseparator_control2/toolseparator_control2.pro
app_toolseparator_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_toolseparator_control2

app_tooltip_control2.file = $$PWD/chapter09/tooltip_control2/tooltip_control2.pro
app_tooltip_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_tooltip_control2

app_tumbler_control2.file = $$PWD/chapter09/tumbler_control2/tumbler_control2.pro
app_tumbler_control2.depends = sstd_qml_control sstd_qt_and_qml_library build_install sstd_library
SUBDIRS += app_tumbler_control2

##############10##############



