/*horizontal_list/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id : idRoot
    width: 640;
    height: 128;
    color: Qt.rgba(0.8,0.8,0.8,1);

    ListView{
        anchors.fill: parent

        orientation: ListView.Horizontal

        delegate: Rectangle {
            width: 128
            height: 128
            color: rawColor
            Text {
                anchors.fill: parent
                text: rawString
                verticalAlignment:Text.AlignVCenter
                horizontalAlignment:Text.AlignHCenter
                font.pointSize: 24
            }
        }

        model: ListModel{

            ListElement {
                rawString: "A"
                rawColor:  "red"
            }
            ListElement {
                rawString: "B"
                rawColor:  "green"
            }
            ListElement {
                rawString: "C"
                rawColor:  "blue"
            }

            ListElement {
                rawString: "D"
                rawColor:  "red"
            }
            ListElement {
                rawString: "E"
                rawColor:  "green"
            }
            ListElement {
                rawString: "F"
                rawColor:  "blue"
            }

            ListElement {
                rawString: "G"
                rawColor:  "red"
            }
            ListElement {
                rawString: "H"
                rawColor:  "green"
            }
            ListElement {
                rawString: "I"
                rawColor:  "blue"
            }

        }

    }

}
