import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import sstd.chat.help 1.0

ColumnLayout{

    spacing: 0
    Label{
        text: "zzzzz"
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
    }/*~Label*/

    RowLayout{

        spacing: 0
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop

        Rectangle{
            width: 64
            height: 64
            color: "black"
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }/*~Rectangle*/

        TextArea {

            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true

            text:"fff<img width=24 height=24 src='image://placeholderimageprovider/GifItem.qml'>dsfds"

            id : idTextArea
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

    }/*~RowLayout*/

}/*~ColumnLayout*/


