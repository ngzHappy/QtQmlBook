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
    Label{
        id : idLabel
        text: "unknow"
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
    }/*~Label*/

    RowLayout{

        spacing: 0
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop

        Item {
            id : idIconItem
            width: 64
            height: 64
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Rectangle{
                anchors.fill : idIconItem
                color: Qt.rgba(0.2,0.2,0.2,0.5)
            }
        }/*~Item*/

        Item{

            id : textAreaLayoutItem
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true
            visible: true

            TextArea {

                id : idTextArea
                width: textAreaLayoutItem.width - idTextArea.anchorsMargins*2
                anchors.top: textAreaLayoutItem.top
                anchors.left: textAreaLayoutItem.left
                property real anchorsMargins: 16
                anchors.margins: idTextArea.anchorsMargins

                text: "test"
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
                    textArea : idTextArea
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
    }/*~RowLayout*/
}/*~ColumnLayout*/


