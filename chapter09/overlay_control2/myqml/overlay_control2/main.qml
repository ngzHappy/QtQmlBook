/*overlay_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    id : idRoot
    width: 640;
    height: 480;
    visible: true

    ColumnLayout{
        anchors.fill: parent
        Button {
            text : qsTr("弹窗")
            onClicked: idPopup.open()
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            Popup {
                id: idPopup
                parent: Overlay.overlay
                x: Math.round((parent.width - width) / 2)
                y: Math.round((parent.height - height) / 2)
                width: 128
                height: 128
            }
        }
    }

}
