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
        delegate: Canvas{
            width: 20  ;
            height: 20 ;
            renderTarget: Canvas.Image ;
            renderStrategy: Canvas.Threaded ;
            property color drawFillColor:
                Qt.rgba(
                    Math.random() * 0.5,
                    Math.random() * 0.5,
                    Math.random() * 0.5,
                    1);
            onPaint: {
                var ctx = getContext("2d");
                ctx.fillStyle = drawFillColor;
                ctx.beginPath();
                ctx.arc(10 , 10 ,
                        10,
                        0, Math.PI * 2 ,
                        true );
                ctx.closePath();
                ctx.fill();
            }
        }
    }

    Emitter{
        emitRate : 100 ;
        maximumEmitted : 1000 ;
        lifeSpan : 2500;
        system: idParticleSystem ;
        anchors.fill: idParticleSystem;
    }

}/*~Rectangle*/
