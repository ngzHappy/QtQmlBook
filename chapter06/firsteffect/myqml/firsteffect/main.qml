/*main.qml*/
import QtQuick 2.9
import QtGraphicalEffects 1.12

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Text{
        id : idText
        text: "Good!"
        font.pointSize: 128
        font.bold: true
        anchors.centerIn: parent
    }

    DropShadow{
        anchors.fill: idText
        horizontalOffset: 3
        verticalOffset: 3
        radius: 8.0
        samples: 17
        color: Qt.rgba(0.1,0.1,0.1,1)
        source: idText
    }

    InnerShadow{
        anchors.fill: idText
        radius: 8.0
        samples: 16
        horizontalOffset: 5.5
        verticalOffset: -2.8
        color: Qt.rgba(1,0.9,0.8,1)
        source: idText
    }

}/*~Rectangle*/

/*DropShadow QML Type*/
/*InnerShadow QML Type*/
