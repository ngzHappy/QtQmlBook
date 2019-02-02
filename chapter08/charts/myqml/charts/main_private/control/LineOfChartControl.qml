import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick 2.11

ColumnLayout {

    width: parent.width
    anchors.bottom: parent.bottom

    ComboBox{
    }

    ComboBox{
    }

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("width")
        }
        SliderControl{
            from : 0
            to : 5
            value: 0.5
            stepSize: 0.1
            Layout.fillWidth: true
            id : idWidth
        }
    }
    property alias widthItem : idWidth


}







