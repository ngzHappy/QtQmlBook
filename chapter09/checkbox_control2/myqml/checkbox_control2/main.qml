/*checkbox_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    Column {
        anchors.fill: parent

         ButtonGroup {
             id: idChildGroup
             exclusive: false
             checkState: idParentBox.checkState
         }

         CheckBox {
             id: idParentBox
             text: qsTr("Parent")
             checkState: idChildGroup.checkState
         }

         CheckBox {
             checked: true
             text: qsTr("Child 1")
             leftPadding: indicator.width
             ButtonGroup.group: idChildGroup
         }

         CheckBox {
             text: qsTr("Child 2")
             leftPadding: indicator.width
             ButtonGroup.group: idChildGroup
         }
     }

}
