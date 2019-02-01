import QtQuick 2.11
import QtQuick.Particles 2.0


DemoBasic {

    ParticleSystem{
        id : idSystem
        anchors.fill: parent;

        ImageParticle{
            source:"qrc:///particleresources/star.png"
            colorVariation: 0.8
            groups: [ "s02" ,"s03" ]
        }

        ImageParticle{
            source:"qrc:///particleresources/fuzzydot.png"
            colorVariation: 0.8
            groups: ["s01"]
        }

        ParticleGroup{
            name : "s01"
            duration: 1000
            to : { "s02" :1  }
        }

        ParticleGroup{
            name : "s02"
            duration: 1000
            /*s04 is to hide all ...*/
            to: { "s04":1 }
            TrailEmitter {
                id : idS02
                group: "s03"
                emitRatePerParticle: 100
                lifeSpan: 1000
                maximumEmitted: 1200
                size: 8
                velocity: AngleDirection {
                    angle: 270;
                    angleVariation: 45;
                    magnitude: 20;
                    magnitudeVariation: 20;
                }
                acceleration: PointDirection {
                    y:100;
                    yVariation: 20
                }
            }
        }

        ParticleGroup{
            name: "s04"
            duration: 1000
            Affector {
                once: true
                onAffected: idS03.burst(400,x,y)
            }
        }

        /*on s01 ...*/
        Timer{
            interval : 6006
            repeat : true
            running : true
            triggeredOnStart : true
            onTriggered: {
                idS01.burst( 8 )
            }
        }
        Emitter{
            id :   idS01
            group: "s01"
            width: parent.width
            y : parent.height + parent.x
            enabled: false
            emitRate: 100
            /*the lifespan should long than oters...*/
            lifeSpan: 6000
            maximumEmitted: 200
            size: 6
            acceleration: PointDirection {
                y:100;
                yVariation: 20
            }
            velocity: CumulativeDirection {
                PointDirection {y: -300 }
            }
        }

        /*on s03 ...*/
        Emitter {
            id: idS03
            group: "s03"
            enabled: false
            emitRate: 100
            lifeSpan: 1000
            maximumEmitted: 6400
            size: 8
            velocity: CumulativeDirection {
                PointDirection {
                    y:-100
                }
                AngleDirection {
                    angleVariation: 360;
                    magnitudeVariation: 80;
                }
            }
            acceleration: PointDirection {
                y:100;
                yVariation: 20
            }
        }

    }

}

/*http://doc.qt.io/qt-5/qtquick-effects-particles.html*/







