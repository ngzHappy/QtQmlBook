/*Mine.qml*/
import QtQuick 2.9
import QtGraphicalEffects 1.0

Item {

    Image {
        id : image
        source: "Mine.png"
        anchors.fill: parent;
        fillMode: Image.Stretch
    }

    Colorize{
        anchors.fill: image
        source: image
        hue: 0.0
        saturation: 1.5
        lightness: -0.2
    }

}
