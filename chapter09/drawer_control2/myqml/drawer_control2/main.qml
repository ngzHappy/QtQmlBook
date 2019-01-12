/*drawer_control2/main.qml*/
import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    id : idRoot
    width: 640;
    height: 480;
    visible: true

    Drawer {
        id: idDrawer
        width: 0.66 * idRoot.width
        height: idRoot.height

        Label {
            text: qsTr("向左拖动关闭我")
            anchors.centerIn: parent
        }

        onClosed: {
            console.log("I have closed!")
        }

        Component.onCompleted: {
            idDrawer.open();
        }

    }

}

