/*lineargradient_effect/main.qml*/
import QtQuick 2.9
import QtGraphicalEffects 1.12

Rectangle {
    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    LinearGradient {
        id : idEffect
        anchors.fill: parent
        start: Qt.point(parent.x, parent.y)
        end: Qt.point(parent.x+parent.width,
                      parent.y+parent.height)
        gradient: Gradient {
            GradientStop { position: 0.0; color: "white" }
            GradientStop { position: 1.0; color: "black" }
        }
    }

}

