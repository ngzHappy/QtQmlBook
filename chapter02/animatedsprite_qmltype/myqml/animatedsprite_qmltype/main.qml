
import QtQuick 2.12

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    AnimatedSprite {
        id: s1
        anchors.centerIn: parent
        running: true
        paused: true
        height: 125
        width: 125
        frameCount: 13
        interpolate: false
        loops : AnimatedSprite.Infinite
        source: "bear_brown.png"
    }

    AnimatedSprite {
        id: s2
        anchors.fill: s1
        running: true
        paused: s1.paused
        frameCount: 13
        interpolate: false
        loops :s1.loops
        source: "bear_eyes_brown.png"
        onSourceChanged: { currentFrame = s1.currentFrame }
    }

    AnimatedSprite {
        id: s3
        anchors.fill: s1
        running: true
        paused: s1.paused
        frameCount: 13
        interpolate: false
        loops :s1.loops
        source: "bear_fur_orange.png"
        onSourceChanged: { currentFrame = s1.currentFrame }
    }

    Timer{
        interval: 75 ;
        repeat: true
        running: true
        triggeredOnStart: true
        onTriggered: {
            s1.advance() ;
            s2.advance() ;
            s3.advance() ;
        }
    }


}
