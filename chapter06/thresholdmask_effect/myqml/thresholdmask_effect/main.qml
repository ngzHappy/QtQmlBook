/*thresholdmask_effect/main.qml*/
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
        source: "image.jpg"
        visible: false
        fillMode: Image.PreserveAspectFit
        id : idImage
    }

    Image{
        width: parent.width * 0.8;
        height: parent.height * 0.8;
        anchors.centerIn: parent
        source: "image.png"
        visible: false
        fillMode: Image.PreserveAspectFit
        id : idImageMask
    }

     ThresholdMask{
         anchors.fill: idImage
         source: idImage
         maskSource: idImageMask
         spread: thisControl.spreadItem.value
         threshold: thisControl.thresholdItem.value
     }

     ThresholdMaskControl{
         id : thisControl
     }

}
