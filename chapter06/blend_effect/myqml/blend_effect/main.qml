﻿/*blend_effect/main.qml*/
import QtQuick 2.9
import QtGraphicalEffects 1.12

Rectangle {
    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    BlendControl {
    }

    Image{
        anchors.fill: parent;
    }

    Image{
        anchors.fill: parent;
    }

    Blend{

    }

}

