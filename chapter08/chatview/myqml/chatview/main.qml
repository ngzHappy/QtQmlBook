/*chatview/main.qml*/
import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    id : idRoot
    width: 640;
    height: 640;
    visible: true

    minimumHeight : 256
    minimumWidth :256

    Item{
        anchors.fill: parent;
        LeftChatView {
            id : idLeftItem
            width: parent.width
        }
        RightChatView{
            anchors.top: idLeftItem.bottom
            width: parent.width
        }
    }

}

