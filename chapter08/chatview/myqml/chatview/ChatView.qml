import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import sstd.chat.help 1.0

TextArea{
    anchors.fill: parent;

    textFormat: Qt.RichText
    wrapMode: TextArea.Wrap
    focus: true
    selectByMouse: true
    persistentSelection: true
    readOnly: true

    leftPadding: 0
    rightPadding: 0
    topPadding: 0
    bottomPadding: 0
    background: ChatHelper{
    }

    MouseArea {
        acceptedButtons: Qt.RightButton
        anchors.fill: parent
        onClicked: {
            idContextMenu.popup();
        }
    }

    onLinkActivated: Qt.openUrlExternally(link)

    Menu {
        id: idContextMenu

        MenuItem {
            text: qsTr("复制")
            enabled: idTextArea.selectedText
            onTriggered: idTextArea.copy()
        }

    }

}




