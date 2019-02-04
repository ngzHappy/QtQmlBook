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
            text:qsTr("deviation")
        }
        SliderControl{
            from : 0
            to : 16
            value: 2.7
            stepSize: 0.1
            Layout.fillWidth: true
            id : idDeviation
        }
    }
    property alias deviationItem : idDeviation


}
