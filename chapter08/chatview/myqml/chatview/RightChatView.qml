import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import sstd.chat.help 1.0

ColumnLayout{

    id : idRootLayout
    height: Math.max(
                idIconItem.height ,
                idTextArea.anchorsMargins*2 + idTextArea.contentHeight)
            + idLabel.contentHeight ;

    spacing: 0
    RowLayout{
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        spacing: 0
        Item{
            height: 1
            Layout.fillWidth: true
        }
        Label{
            id : idLabel
            text: "unknow"
        }/*~Label*/
    }

    RowLayout{

        spacing: 0
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignRight | Qt.AlignTop
        Layout.minimumWidth:128

       Item{/*左边的spacing*/
           width: 16
           height: 16
       }

        Item{

            id : textAreaLayoutItem
            Layout.alignment: Qt.AlignRight | Qt.AlignTop
            Layout.fillWidth: true
            Layout.fillHeight: true
            visible: true

            Rectangle{ /* TODO : replace here ... */
                width: idChatHelper.nativeTextWidth + idTextArea.anchorsMargins
                height: idTextArea.contentHeight + idTextArea.anchorsMargins
                anchors.right: textAreaLayoutItem.right
                anchors.top: textAreaLayoutItem.top
                anchors.margins: idTextArea.anchorsMargins*0.5
                border.color: Qt.rgba(0,1,0,1)
                border.width: 2
            }

            TextArea {

                id : idTextArea
                anchors.fill: parent
                property real anchorsMargins: 16
                anchors.margins: idTextArea.anchorsMargins

                text: "test test test test test test test test test test test test test test test test test test test test test test test test test test test test test test test test test test test test"
                //text:"fff<img width=24 height=24 src='image://placeholderimageprovider/GifItem.qml'>dsfds"

                property bool isLeftChat: true
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
                    id : idChatHelper
                    textArea : idTextArea
                    /*qreal nativeTextWidth*/
                }
                MouseArea {
                    acceptedButtons: Qt.RightButton
                    anchors.fill: parent
                    onClicked: {
                        idContextMenu.popup();
                    }
                }/*~MouseArea*/
                onLinkActivated: Qt.openUrlExternally(link)
                Menu {
                    id: idContextMenu
                    MenuItem {
                        text: qsTr("复制")
                        enabled: idTextArea.selectedText
                        onTriggered: idTextArea.copy()
                    }/*~MenuItem*/
                }/*~Menu*/
            }/*~TextArea*/
        }/*~Item*/

        Item {
            id : idIconItem
            width: 64
            height: 64
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Rectangle{ /* TODO : replace here ... */
                anchors.fill : idIconItem
                color: Qt.rgba(0.2,0.2,0.2,0.5)
            }
        }/*~Item*/

    }/*~RowLayout*/
}/*~ColumnLayout*/


