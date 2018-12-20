/*main.qml*/
import QtQuick 2.9
import QtQuick.Particles 2.0

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent ;
    }

    ItemParticle{
        system: idParticleSystem;
        delegate: Rectangle{
			border.width: 0 ;
            antialiasing : true ;
            color: Qt.rgba(
                       Math.random()*0.5,
                       Math.random()*0.5,
                       Math.random()*0.5,
                       1);
            width: 10  ;
            height: 10 ;
            radius: 1  ;
        }
    }

    Emitter{
        system: idParticleSystem ;
        anchors.fill: idParticleSystem;
    }

}/*~Rectangle*/



