/*pane_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    topInset: 0
    leftInset: 0
    bottomInset: 0
    rightInset: 0

    padding: 0

    contentItem: Rectangle{
        color: Qt.rgba(0.3,0.2,0.4,1)
    }

}
