/*brightnesscontrast_effect/BrightnessContrastControl.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    width: parent.width
    anchors.bottom: parent.bottom

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("radius")
        }
        SliderControl{
            from : 0
            to : 128
            value: 0.0
            stepSize: 0.5
            Layout.fillWidth: true
            id : idRadius
        }
    }
    property alias radiusItem : idRadius

}
