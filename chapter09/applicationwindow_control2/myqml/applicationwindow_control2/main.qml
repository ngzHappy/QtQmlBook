/*applicationwindow_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ApplicationWindow {
    id : idRoot
    width: 640;
    height: 480;
    visible: true

    menuBar: MenuBar{
        Menu {
            title: qsTr("&File")
            Action { text: qsTr("&New...") }
            Action { text: qsTr("&Open...") }
            Action { text: qsTr("&Save") }
            Action { text: qsTr("Save &As...") }
            MenuSeparator { }
            Action { text: qsTr("&Quit") }
        }
        Menu {
            title: qsTr("&Edit")
            Action { text: qsTr("Cu&t") }
            Action { text: qsTr("&Copy") }
            Action { text: qsTr("&Paste") }
        }
        Menu {
            title: qsTr("&Help")
            Action { text: qsTr("&About") }
        }
    }

    header: ToolBar{
        RowLayout {
            anchors.fill: parent
            ToolButton {
                text: qsTr("A")
            }
            ToolButton {
                text: qsTr("B")
            }
            ToolButton {
                text: qsTr("C")
            }
            ToolButton {
                text: qsTr("D")
            }
        }
    }

    footer: TabBar{
    }

    StackView {
        anchors.fill: parent
    }

}

