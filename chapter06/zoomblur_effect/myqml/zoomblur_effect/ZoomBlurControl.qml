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
            text:qsTr("horizontalOffset")
        }
        SliderControl{
            from : -120
            to : 120
            value: 0.0
            stepSize: 0.5
            Layout.fillWidth: true
            id : idHorizontalOffset
        }
    }
    property alias horizontalOffsetItem : idHorizontalOffset

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("verticalOffset")
        }
        SliderControl{
            from : -120
            to : 120
            value: 0.0
            stepSize: 0.5
            Layout.fillWidth: true
            id : idVerticalOffset
        }
    }
    property alias verticalOffsetItem : idVerticalOffset

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("length")
        }
        SliderControl{
            from : 0
            to : 120
            value: 48
            stepSize: 0.5
            Layout.fillWidth: true
            id : idLength
        }
    }
    property alias lengthItem : idLength

}
