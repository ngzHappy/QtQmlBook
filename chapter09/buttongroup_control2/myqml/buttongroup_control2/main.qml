/*buttongroup_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ButtonGroup {
        id: idRadioGroup
    }

    Column {
        anchors.centerIn: parent;
        RadioButton {
            checked: true
            text: qsTr("A")
            ButtonGroup.group: idRadioGroup
        }
        RadioButton {
            text: qsTr("B")
            ButtonGroup.group: idRadioGroup
        }
        RadioButton {
            text: qsTr("C")
            ButtonGroup.group: idRadioGroup
        }
    }

}

