/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Rectangle {
        antialiasing: true
        anchors.centerIn: parent ;
        width: parent.width * 0.8 ;
        height: parent.height * 0.8 ;
        border.color: Qt.rgba(0,0,1,0)
        border.width: 3
        radius: 10
        gradient: Gradient {
                GradientStop {
                    position: 0.0;
                    color: "lightsteelblue"
                }
                GradientStop {
                    position: 1.0;
                    color: "blue"
                }
        }
    }

}/*~Rectangle*/
