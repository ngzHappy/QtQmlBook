import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import sstd.chat.help 1.0

ColumnLayout{

    id : idRootLayout
    property var thisChatItem: ChatDataItem{
        id : idThisItem
        title: "unknow title x"
        bodyItems:["unknow items"]
    }

    function resetDataByChatDataItem(){
        idRootLayout.thisChatItem.isLeftItem = true;
        idTextArea.text="";
        var varItems = idRootLayout.thisChatItem.bodyItems;
        for( var varKey in varItems ){
            idTextArea.append( varItems[varKey] );
        }
        idLabel.text = Qt.binding( function(){
            if(thisChatItem){
                return thisChatItem.title;
            }
            return"";
        } );
    }

    Component.onCompleted: {
        idRootLayout.resetDataByChatDataItem();
    }

    onThisChatItemChanged: {
        resetDataByChatDataItem();
    }

    height: Math.max(
                idIconItem.height ,
                idTextArea.anchorsMargins*2 + idTextArea.contentHeight)
            + idLabel.contentHeight ;

    spacing: 0
    Label{
        id : idLabel
        text: "unknow" ;
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
    }/*~Label*/

    RowLayout{

        spacing: 0
        Layout.fillHeight: true
        Layout.fillWidth: true
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        Layout.minimumWidth:128

        Item {
            id : idIconItem
            width: 64
            height: 64
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Rectangle{ /* TODO : replace here ... */
                anchors.fill : idIconItem
                color: Qt.rgba(0.2,0.7,0.2,0.5)
            }
        }/*~Item*/

        Item{

            id : textAreaLayoutItem
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            Layout.fillWidth: true
            Layout.fillHeight: true
            visible: true

            Rectangle{ /* TODO : replace here ... */
                width: idChatHelper.nativeTextWidth + idTextArea.anchorsMargins
                height: idTextArea.contentHeight + idTextArea.anchorsMargins
                anchors.left: textAreaLayoutItem.left
                anchors.top: textAreaLayoutItem.top
                anchors.margins: idTextArea.anchorsMargins*0.5
                border.color: Qt.rgba(0,1,0,1)
                border.width: 2
                radius: 3.5
                color: Qt.rgba( 0.3 , 0.8 , 0.9 , 0.3 )
            }

            TextArea {

                id : idTextArea
                anchors.fill: parent
                property real anchorsMargins: 16
                anchors.margins: idTextArea.anchorsMargins

                text: "empty "

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

        Item{/*右边的spacing*/
            width: 16
            height: 16
        }

    }/*~RowLayout*/
}/*~ColumnLayout*/
