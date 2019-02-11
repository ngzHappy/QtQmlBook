import QtQuick 2.12
import QtQuick.Particles 2.12

Item {

    id : idRoot

    ParticleSystem{
        id : idSystem
        anchors.fill: parent;

        ImageParticle{
            source:"qrc:///particleresources/star.png"
            colorVariation: 0.8
            groups: [ "s02" ,"s03" ]
        }

        ImageParticle{
            source:"qrc:///particleresources/star.png"
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
            interval : 1234
            repeat : true
            running : true
            triggeredOnStart : true
            onTriggered: {
                idS01.burst( 4 * Math.random() + 4 )
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
            lifeSpan: 3006
            maximumEmitted: 16
            size: 6
            acceleration: PointDirection {
                y: idRoot.height * 2 /9.0 ;
                yVariation: 20
            }
            velocity: CumulativeDirection {
                PointDirection {
                    y: idRoot.height *(-4)/9.0
                }
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
                    y: -80
                }
                AngleDirection {
                    angleVariation: 360;
                    magnitudeVariation: 0.20 * Math.min(idRoot.height,idRoot.width) ;
                }
            }
            acceleration: PointDirection {
                y:100;
                yVariation: 20
            }
        }

    }

}

















