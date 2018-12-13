/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Pane {

    width: 640;
    height: 480;

    ColumnLayout {
        id: column
        anchors.fill: parent

        Button {
            id: button
            text: qsTr("Button")
            Layout.fillWidth : true
        }

        TextField {
            id: textField
            text: qsTr("Text Field")
            Layout.fillWidth : true
        }

        TabButton {
            id: tabButton
            text: qsTr("Tab Button")
            Layout.fillWidth : true
        }

        ProgressBar {
            id: progressBar
            value: 0.5
            Layout.fillWidth : true
        }

    }

}/*~Pane*/



