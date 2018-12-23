import QtQuick 2.11
import QtQuick.Particles 2.0

DemoBasic {

    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent ;

        ImageParticle {
            groups : ["images"]
            sprites:[
                Sprite {
                    name : "From" ;
                    source : "qrc:///particleresources/glowdot.png" ;
                    frameCount: 1 ;
                    frameDuration : 1000 ;
                    to: {"To":0, "From":1}
                } ,
                Sprite {
                    name : "To" ;
                    source : "qrc:///particleresources/star.png" ;
                    frameCount: 1;
                    frameDuration : 1000;
                    to: {"To":1, "From":0}
                }
            ]
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
            group: "images"
        }

        SpriteGoal  {
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: parent.top
            height: parent.height*0.45
            system: idParticleSystem ;
            jump: true      ;
            goalState: "To"  ;
            groups: ["images"]
        }

    }

}
