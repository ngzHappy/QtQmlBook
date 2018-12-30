/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12 as Controls2

Rectangle {

    id : idRoot
    width: 256;
    height: 128;
    color: Qt.rgba(0.5,0.5,0.5,1)

    Controls2.SpinBox {
        id: control
        value: 50
        editable: true

        contentItem: TextInput {
            z: 2
            text: control.textFromValue(control.value, control.locale)

            font: control.font
            color: Qt.rgba(0.1,0.1,0.1,1)
            selectionColor: "#21be2b"
            selectedTextColor: Qt.rgba(0.9,0.9,0.9,1)
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter

            readOnly: !control.editable
            validator: control.validator
            inputMethodHints: Qt.ImhFormattedNumbersOnly
            selectByMouse: true
        }

        palette.base : Qt.rgba(0.8,0.1,0.1,1)

    }

}












