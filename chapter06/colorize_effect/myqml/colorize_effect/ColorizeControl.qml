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
            text:qsTr("hue")
        }
        SliderControl{
            from : 0
            to : 1
            stepSize: 0.01
            value: 0
            Layout.fillWidth: true
            id : idHue
        }
    }

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

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("saturation")
        }
        SliderControl{
            from : 0
            to : 1
            value: 0.5
            stepSize: 0.01
            Layout.fillWidth: true
            id : idSaturation
        }
    }

    property alias saturationItem : idSaturation
    property alias lightnessItem: idLightness
    property alias hueItem: idHue

}
















