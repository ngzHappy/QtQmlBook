import QtQuick 2.11
import QtQuick.Particles 2.0

DemoBasic {

    id : idRoot ;
    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent  ;

        ImageParticle {
            source: "qrc:///particleresources/fuzzydot.png" ;
            system: idParticleSystem ;
            groups: [ "Emitter" ]
        }

        ImageParticle {
            source: "qrc:///particleresources/star.png" ;
            system: idParticleSystem ;
            groups: [ "TrailEmitter" ]
        }

        Emitter{
            emitRate : 1 ;
            maximumEmitted : 10000 ;
            lifeSpan : 2500;
            x : idRoot.width * 0.1  ;
            y : idRoot.height * 0.5 ;
            velocity: PointDirection{
                x :  200
                y : -100
                xVariation: 10
                yVariation: 10
            }
            acceleration: PointDirection {
                y : 100
            }
            group: "Emitter"
        }

        TrailEmitter{
            follow: "Emitter"
            group: "TrailEmitter"
            velocityFromMovement: 1
            size: 6
            emitRatePerParticle : 100 ;
            maximumEmitted : 10000 ;
            lifeSpan : 500;
            system: idParticleSystem ;
            velocity: PointDirection{
                x : -200      ;
                y :  100      ;
                yVariation: 12;
                xVariation: 64;
            }
        }

    }



}
