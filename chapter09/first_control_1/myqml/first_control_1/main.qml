/*main.qml*/
import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4 as Controls1
import QtQuick.Controls 2.12 as Controls2

Controls2.Pane {

    id : idRoot
    width: 256;
    height: 128;

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
            editable: true
            Layout.alignment: Qt.AlignHCenter
        }

    }

}
