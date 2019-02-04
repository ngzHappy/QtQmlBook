import QtQuick 2.11
import QtQuick.Particles 2.0

DemoBasic {
    id : idRoot ;
    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent  ;

        ImageParticle {
            source: "qrc:///particleresources/star.png" ;
        }

        Emitter {

            emitRate : 100 ;
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

        }

    }

}
