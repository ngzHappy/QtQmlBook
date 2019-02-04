/*toolseparator_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    RowLayout{
        anchors.fill: parent

        Item {
            Layout.fillWidth: true
        }

        ToolButton {
            text: qsTr("Action 1")
        }
        ToolButton {
            text: qsTr("Action 2")
        }

        ToolSeparator {
            orientation: Qt.Vertical
        }

        ToolButton {
            text: qsTr("Action 3")
        }
        ToolButton {
            text: qsTr("Action 4")
        }

        ToolSeparator {
        }

        ToolButton {
            text: qsTr("Action 5")
        }
        ToolButton {
            text: qsTr("Action 6")
        }

        Item {
            Layout.fillWidth: true
        }

    }

}
