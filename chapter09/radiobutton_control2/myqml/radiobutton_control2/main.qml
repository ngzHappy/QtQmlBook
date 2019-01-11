/*radiobutton_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ColumnLayout{
        anchors.fill: parent
        RadioButton {
            text: qsTr( "Good!" )
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked: {
                console.log(qsTr("Clicked!"))
            }
        }
    }

}

