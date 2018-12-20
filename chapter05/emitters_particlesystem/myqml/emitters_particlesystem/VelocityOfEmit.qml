import QtQuick 2.11
import QtQuick.Particles 2.0
import QtQuick.Controls 2.3

DemoBasic {

    ComboBox {
        id: idComboBox
        x: 0
        y: 0
        width: 256
        textRole: "key"
        model: ListModel {
            ListElement { key: "AngleDirection"; }
            ListElement { key: "PointDirection"; }
            ListElement { key: "TargetDirection"; }
            ListElement { key: "CumulativeDirection"; }
        }
    }

    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent ;

        ImageParticle {
            source: "qrc:///particleresources/glowdot.png" ;
            system: idParticleSystem ;
            groups: [ "AngleDirection" ]
        }

        ImageParticle {
            source: "qrc:///particleresources/glowdot.png" ;
            system: idParticleSystem ;
            groups: [ "TargetDirection" ]
        }

        ImageParticle {
            source: "qrc:///particleresources/star.png" ;
            system: idParticleSystem ;
            groups: [ "PointDirection"]
        }

        ImageParticle {
            source: "qrc:///particleresources/star.png" ;
            system: idParticleSystem ;
            groups: [ "CumulativeDirection"]
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
                magnitude: 64;
                angleVariation: 360
            }
            enabled: 0===idComboBox.currentIndex
            group: "AngleDirection"
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
                idParticleSystem.height *0.1;
            velocity: PointDirection{
                x : 0 ;
                y : 128;
                yVariation: 12
                xVariation: 64
            }
            enabled: 1===idComboBox.currentIndex
            group: "PointDirection"
        }

        Emitter{
            id : idEmitter3
            size: 32
            emitRate : 100 ;
            maximumEmitted : 10000 ;
            lifeSpan : 2500;
            system: idParticleSystem ;
            anchors.fill: parent ;
            shape : LineShape {
                mirrored: true
            }
            velocity: TargetDirection{
                targetX : idEmitter3.width
                targetY : idEmitter3.height
                magnitude : 128
            }
            enabled: 2===idComboBox.currentIndex
            group: "TargetDirection"
        }

        Emitter{
            size: 32
            endSize: 0
            emitRate : 100 ;
            maximumEmitted : 10000 ;
            lifeSpan : 2500;
            system: idParticleSystem ;
            anchors.fill: parent ;
            shape : EllipseShape {
               fill: false
            }
            velocity: CumulativeDirection {
                PointDirection {
                    xVariation: 128
                    x: 100;
                    y: -100
                }
                PointDirection {
                    x: -100;
                    y: 100
                }
            }
            enabled: 3===idComboBox.currentIndex
            group: "CumulativeDirection"
        }

    }

}














