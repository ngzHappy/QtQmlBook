/*dropshadow_effect/main.qml*/
import QtQuick 2.9
import QtGraphicalEffects 1.12

Rectangle {
    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Image{
        width: parent.width * 0.8;
        height: parent.height * 0.8;
        anchors.centerIn: parent
        source: "image"
        visible: true
        fillMode: Image.PreserveAspectFit
        id : idImage
    }

    DropShadow{
        color: Qt.rgba(0.2,0.6,0.3,1)
        horizontalOffset: 8
        verticalOffset: -8
        radius: 8
        samples: 36
        source: idImage
        spread: 0.5
        anchors.fill: idImage
    }

}

