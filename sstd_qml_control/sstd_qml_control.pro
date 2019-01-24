TEMPLATE = lib
CONFIG += plugin

QT += gui_private
QT += qml_private
QT += core_private
QT += quick_private
QT += widgets_private
QT += quickcontrols2_private

TARGET = $$qtLibraryTarget(sstd_qml_control)

DEFINES *= _1_SSTD_QML_CONTROL

#define out put dir
include($$PWD/../outdirpath.pri)
#define cplusplus environment
include($$PWD/../cplusplus.pri)
#import sstd_library
include($$PWD/../sstd_library/import_sstd_library.pri)
#import sstd_qt_and_qml_library
include($$PWD/../sstd_qt_and_qml_library/import_sstd_qt_and_qml_library.pri)

!win32 {
    QMAKE_LFLAGS += -Wl,-rpath .
}

DESTDIR = $${RootDestDir}/sstd/qml/control

DEFINES += MocFromDir=\\\"$${PWD}\\\"
DEFINES += MocToDir=\\\"$${RootDestDir}\\\"

CONFIG(debug,debug|release){
    QMAKE_POST_LINK += $${RootDestDir}/build_install_debug $$PWD "sstd"
}else{
    QMAKE_POST_LINK += $${RootDestDir}/build_install $$PWD "sstd"
}
export(QMAKE_POST_LINK)

uri = sstd.qml.control
HEADERS += $$PWD/sstd_qml_control_global.hpp
HEADERS += $$PWD/sstd_qml_control.hpp
SOURCES += $$PWD/sstd_qml_control.cpp

HEADERS += $$PWD/TestData.hpp
SOURCES += $$PWD/TestData.cpp

HEADERS += $$PWD/GlobalObject.hpp
SOURCES += $$PWD/GlobalObject.cpp

HEADERS += $$PWD/AttachedGlobalObject.hpp
SOURCES += $$PWD/AttachedGlobalObject.cpp

DISTFILES = $$PWD/sstd/qml/control/qmldir

QMLSOURCES += $$PWD/sstd/qml/control/TestText.qml

QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ApplicationWindow.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/BoxShadow.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/BusyIndicator.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Button.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/CheckBox.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/CheckDelegate.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/CheckIndicator.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ComboBox.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/CursorDelegate.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/DelayButton.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Dial.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Dialog.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/DialogButtonBox.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Drawer.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ElevationEffect.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Frame.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/GroupBox.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ItemDelegate.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Label.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Menu.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/MenuBar.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/MenuBarItem.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/MenuItem.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/MenuSeparator.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Page.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/PageIndicator.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Pane.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Popup.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ProgressBar.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/RadioButton.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/RadioDelegate.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/RadioIndicator.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/RangeSlider.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/RectangularGlow.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/RoundButton.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ScrollBar.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ScrollIndicator.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Slider.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/SliderHandle.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/SpinBox.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/StackView.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/SwipeDelegate.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/SwipeView.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Switch.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/SwitchDelegate.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/SwitchIndicator.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/TabBar.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/TabButton.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/TextArea.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/TextField.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ToolBar.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ToolButton.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ToolSeparator.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/ToolTip.qml
QMLSOURCES += $$PWD/sstd/qml/control/SSTDStyle/Tumbler.qml

lupdate_only{
    SOURCES += $$QMLSOURCES
}

DISTFILES += $$QMLSOURCES






