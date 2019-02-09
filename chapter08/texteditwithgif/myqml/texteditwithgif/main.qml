/*texteditwithgif/main.qml*/
import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import sstd.giftextarea.help 1.0

ApplicationWindow {
    id : idRoot
    width: 640;
    height: 640;
    visible: true

    Flickable {
        id: idFlickable
        flickableDirection:
            Flickable.HorizontalAndVerticalFlick
        anchors.fill: parent

        ScrollBar.vertical: ScrollBar {
        }

        ScrollBar.horizontal: ScrollBar {
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
        idTextArea.append("E:%1G".arg(
        "<img width=24 height=24 src='image://placeholderimageprovider/GifItem.qml'>") );
        idTextArea.append("中：%1文".arg(
        "<img width=32 height=32 src='image://placeholderimageprovider/FlowerItem.qml'>") );
        idTextArea.append("chart:");
        idTextArea.append("%1".arg(
        "<img width=512 height=512 src='image://placeholderimageprovider/ChartItem.qml'>") );
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

