/*toolbar_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ToolBar{
        width: parent.width
        anchors.top: parent.top
        anchors.left: parent.left

        RowLayout{

            ToolButton{
                icon.source: "5.png"
            }

            ToolButton{
                icon.source: "4.png"
            }

            ToolButton{
                icon.source: "3.png"
            }

            ToolButton{
                icon.source: "2.png"
            }

            ToolButton{
                icon.source: "1.png"
            }

        }

    }


}

