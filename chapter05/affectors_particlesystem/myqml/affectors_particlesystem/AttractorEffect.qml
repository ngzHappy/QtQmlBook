import QtQuick 2.11
import QtQuick.Particles 2.0

DemoBasic {

    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent ;

        ImageParticle {
            source: "qrc:///particleresources/glowdot.png" ;
            system: idParticleSystem ;
        }

        Emitter{
            size: 32
            emitRate : 100 ;
            maximumEmitted : 10000 ;
            lifeSpan : 2500;
            system: idParticleSystem ;
            x : idParticleSystem.x +
                idParticleSystem.width*0.5;
            y : idParticleSystem.y +
                idParticleSystem.height *0.5;
            velocity: AngleDirection{
                magnitude: idParticleSystem.width/5 ;
                angleVariation: 360
            }
        }

        Attractor {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            height: parent.height*0.45
            system: idParticleSystem ;
            pointX : idParticleSystem.x +
                     idParticleSystem.width*0.5;
            pointY : idParticleSystem.y +
                     idParticleSystem.height * 0.4 ;
            strength : 1.1 ;
            affectedParameter : Attractor.Velocity ;
            proportionalToDistance : Attractor.Linear ;
        }

    }


}
