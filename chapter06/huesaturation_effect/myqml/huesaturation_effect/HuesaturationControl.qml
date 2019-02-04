/*desaturate_effect/DesaturateControl.qml*/
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
            text:qsTr("lightness")
        }
        SliderControl{
            from : -1
            to : 1
            value: 0
            stepSize: 0.01
            Layout.fillWidth: true
            id : idLightness
        }
    }
    property alias lightnessItem : idLightness

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("hue")
        }
        SliderControl{
            from : -1
            to : 1
            value: 0.0
            stepSize: 0.01
            Layout.fillWidth: true
            id : idHue
        }
    }
    property alias hueItem : idHue

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("saturation")
        }
        SliderControl{
            from : -1
            to : 1
            value: 0.0
            stepSize: 0.01
            Layout.fillWidth: true
            id : idSaturation
        }
    }
    property alias saturationItem : idSaturation


}
