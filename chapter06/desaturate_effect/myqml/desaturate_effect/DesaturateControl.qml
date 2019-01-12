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
            text:qsTr("desaturation")
        }
        SliderControl{
            from : 0
            to : 1
            value: 0.0
            stepSize: 0.01
            Layout.fillWidth: true
            id : idDesaturation
        }
    }
    property alias desaturationItem : idDesaturation

}
















