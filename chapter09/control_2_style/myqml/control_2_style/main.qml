/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12

Pane {

    id : idRoot
    width: 512;
    height: 512;

    SpinBox {
        id : idSpinBox
        onValueChanged: {
            if(value&1){
                idRoot.Material.theme=Material.Dark
            }else{
                idRoot.Material.theme=Material.Light
            }
        }
        ToolTip.visible: hovered
        ToolTip.text: qsTr("Good!")
    }

    Component.onCompleted: {
        idSpinBox.value = 2 ;
    }

}












