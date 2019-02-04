/*dial_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ColumnLayout{
        anchors.fill: parent
        Dial {
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            from : 0
            to : 1
            stepSize: 0.01
            value: 0.35
        }
    }

}
