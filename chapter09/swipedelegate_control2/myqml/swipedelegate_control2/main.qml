/*swipedelegate_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ListView {
         id: listView
         anchors.fill: parent
         model: ListModel {
             ListElement {
                 sender: "Bob Bobbleton";
                 title: "How are you going?"
             }
             ListElement {
                 sender: "Rug Emporium";
                 title: "SALE! All rugs MUST go!"
             }
             ListElement {
                 sender: "Electric Co.";
                 title: "Electricity bill 15/07/2016 overdue"
             }
             ListElement {
                 sender: "Tips";
                 title: "Five ways this tip will save your life"
             }
         }

         delegate : SwipeDelegate {

             id: idSwipeDelegate
             width: parent.width

             Text {
                 verticalAlignment : Text.AlignVCenter
                 horizontalAlignment:Text.AlignHCenter
                 anchors.fill: parent
                 text:  model.sender + " - " + model.title
             }

             ListView.onRemove: SequentialAnimation {
                 PropertyAction {
                     target: idSwipeDelegate
                     property: "ListView.delayRemove"
                     value: true
                 }
                 NumberAnimation {
                     target: idSwipeDelegate
                     property: "height"
                     to: 0
                     easing.type: Easing.InOutQuad
                 }
                 PropertyAction {
                     target: idSwipeDelegate
                     property: "ListView.delayRemove"
                     value: false
                 }
             }

             swipe.right: Label {
                 id: deleteLabel
                 text: qsTr("Delete")
                 color: "white"
                 verticalAlignment: Label.AlignVCenter
                 padding: 12
                 height: parent.height
                 anchors.right: parent.right

                 SwipeDelegate.onClicked: listView.model.remove(index)

                 background: Rectangle {
                     color: deleteLabel.SwipeDelegate.pressed ?
                                Qt.darker("tomato", 1.1) : "tomato"
                 }
             }

         }
     }

}

