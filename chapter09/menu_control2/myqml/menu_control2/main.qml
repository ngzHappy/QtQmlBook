/*menu_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    TextArea{
        id:idTextArea
        width: parent.width * 0.8 ;
        height: parent.width*0.8;
        x:parent.width * 0.2;
        y:parent.height * 0.2;
        text: "AAA bbb CCC ddd"
        selectByMouse: true
        selectByKeyboard: true
        persistentSelection:true
        MouseArea {
            anchors.fill: parent;
            acceptedButtons: Qt.RightButton | Qt.LeftButton
            onPressed: {
                if(mouse.button === Qt.RightButton   ){
                    console.log( idTextArea.selectedText );
                    idContentMenu.x = mouse.x ;
                    idContentMenu.y = mouse.y ;
                    idContentMenu.open();
                }else{
                    mouse.accepted =false
                    idContentMenu.close();
                }
            }
            Menu {
                id: idContentMenu
                closePolicy: Popup.CloseOnPressOutside
                             |Popup.CloseOnPressOutsideParent
                             |Popup.CloseOnReleaseOutside
                             |Popup.CloseOnReleaseOutsideParent
                             |Popup.CloseOnEscape ;
                Action {
                    text: qsTr("Copy")
                }
            }
        }

    }

}

