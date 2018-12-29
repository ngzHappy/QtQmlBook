/*main.qml*/
import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as Controls1
import QtQuick.Controls 2.12 as Controls2

Rectangle {

    id : idRoot
    width: 128;
    height: 128;
    color: Qt.rgba(0.5,0.5,0.5,1);

    ColumnLayout{
        anchors.fill: parent;

        Controls1.SpinBox{
            id : c1
            selectByMouse: true
            Layout.alignment: Qt.AlignHCenter
        }

        Controls2.SpinBox{
            id : c2
            wheelEnabled: true
            Layout.alignment: Qt.AlignHCenter
        }

    }

}












