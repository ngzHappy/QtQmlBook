/*gaussianblur_effect/main.qml*/
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
        visible: false
        fillMode: Image.PreserveAspectFit
        id : idImage
    }

    GaussianBlur{
        anchors.fill: idImage
        source: idImage
        radius: 8
        samples: 16
        deviation: idThisControl.deviationItem.value
    }

    GaussianBlurControl{
        id : idThisControl
    }

}
