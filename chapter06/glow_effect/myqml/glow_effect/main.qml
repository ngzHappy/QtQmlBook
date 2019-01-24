/*glow_effect/main.qml*/
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

    Glow{
        color: Qt.rgba(0.2,0.6,0.3,1)
        radius: 8
        samples: 16
        spread: idThisControl.spreadItem.value
        anchors.fill: idImage
        source: idImage
    }

    GlowControl{
        id : idThisControl
    }

}

/*endl_input_of_latex_for_clanguage_lick*/
/*
there is a Qt bug ...
sometimes the application will crash 
when use GlobalObject ...
*/
