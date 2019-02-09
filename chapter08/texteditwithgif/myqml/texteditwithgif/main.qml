/*texteditwithgif/main.qml*/
import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import sstd.giftextarea.help 1.0

ApplicationWindow {
    id : idRoot
    width: 640;
    height: 480;
    visible: true

    Flickable {
        id: idFlickable
        flickableDirection: Flickable.VerticalFlick
        anchors.fill: parent

        ScrollBar.vertical: ScrollBar {
        }

        TextArea.flickable: TextArea {
            id: idTextArea
            textFormat: Qt.RichText
            wrapMode: TextArea.Wrap
            focus: true
            selectByMouse: true
            persistentSelection: true

            leftPadding: 0
            rightPadding: 0
            topPadding: 0
            bottomPadding: 0
            background: GifTextAreaHelper{
                id : idGifTextAreaHelper
                textArea: idTextArea
                flickable: idFlickable
                document: idTextArea.textDocument
            }

            MouseArea {
                acceptedButtons: Qt.RightButton
                anchors.fill: parent
                onClicked: {
                    idContextMenu.popup();
                }
            }

            onLinkActivated: Qt.openUrlExternally(link)
        }

    }

    Component.onCompleted: {
        idTextArea.append("rrrrr");
        idTextArea.append("A：%1:A".arg(
        "<img width=32 height=32 src='image://placeholderimageprovider/GifItem.qml'>") );
    }

    Menu {
        id: idContextMenu

        MenuItem {
            text: qsTr("复制")
            enabled: idTextArea.selectedText
            onTriggered: idTextArea.copy()
        }

        MenuItem {
            text: qsTr("剪贴")
            enabled: idTextArea.selectedText
            onTriggered: idTextArea.cut()
        }

        MenuItem {
            text: qsTr("黏贴")
            enabled: idTextArea.canPaste
            onTriggered: idTextArea.paste()
        }

    }

}

