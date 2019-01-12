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
            text:qsTr("angle")
        }
        SliderControl{
            from : -180
            to : 180
            value: 0.0
            stepSize: 0.1
            Layout.fillWidth: true
            id : idAngle
        }
    }
    property alias angleItem : idAngle

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("length")
        }
        SliderControl{
            from : 0
            to : 128/*samples*/
            value: 0
            stepSize: 1
            Layout.fillWidth: true
            id : idLength
        }
    }
    property alias lengthItem : idLength


}
















