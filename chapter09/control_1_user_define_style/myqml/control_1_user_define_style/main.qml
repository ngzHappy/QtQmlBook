/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 1.4 as Controls1
import QtQuick.Controls.Styles 1.4 as Controls1Style

Rectangle {

    id : idRoot
    width: 256;
    height: 128;
    color: Qt.rgba(0.5,0.5,0.5,1)

    Controls1.SpinBox{

        style: Controls1Style.SpinBoxStyle{
            background: Rectangle {
                implicitWidth: 100
                implicitHeight: 20
                border.color: "gray"
                color : Qt.rgba(0.3,0.8,0.9,1)
                radius: 2
            }
        }

    }

}












