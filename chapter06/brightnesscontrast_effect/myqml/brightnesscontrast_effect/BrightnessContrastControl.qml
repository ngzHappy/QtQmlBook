/*brightnesscontrast_effect/BrightnessContrastControl.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    width: parent.width

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("AAAA")
        }
        Slider{
            from : -1
            to : 1
            stepSize: 0.01
            value: 0
            Layout.fillWidth: true
            id : idBrightness
        }
    }

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("BBBB")
        }
        Slider{
            from : -1
            to : 1
            value: 0
            stepSize: 0.01
            Layout.fillWidth: true
            id : idContrast
        }
    }

    property alias brightnessItem : idBrightness
    property alias contrastItem: idContrast

}
















