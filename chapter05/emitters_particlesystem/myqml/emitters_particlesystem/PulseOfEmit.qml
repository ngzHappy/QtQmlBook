import QtQuick 2.11
import QtQuick.Particles 2.0

DemoBasic {

    id : idRoot
    ParticleSystem{
        id : idSystem

        ImageParticle {
            system: idSystem
            source: "qrc:///particleresources/star.png"
            colorVariation : 1
        }

        Emitter{
            system: idSystem
            enabled:false
            velocity: AngleDirection{
                magnitude: 180  ;
                magnitudeVariation : 32 ;
                angleVariation: 360
            }
            velocityFromMovement: 1 ;
            size: 16
            sizeVariation: 8
            emitRate : 2500 ;
            maximumEmitted : 500 ;
            lifeSpan : 1000 ;
            x : idRoot.width * 0.5 ;
            y : idRoot.height * 0.5 ;
            Component.onCompleted: {
                pulse( Math.min(
                          lifeSpan,
                          maximumEmitted/emitRate * 1000)
                      );
            }
        }

    }

}
