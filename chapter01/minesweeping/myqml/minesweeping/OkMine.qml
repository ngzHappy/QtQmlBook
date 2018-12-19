/*OkMine.qml*/
import QtQuick 2.9
import QtGraphicalEffects 1.0

Item {

    Image {
        id : idImage
        source: "Mine.png"
        anchors.fill: parent;
        fillMode: Image.Stretch
    }

    Colorize{
        anchors.fill: idImage
        source: idImage
        hue: 0.35
        saturation: 1.5
        lightness: -0.2
    }

}
