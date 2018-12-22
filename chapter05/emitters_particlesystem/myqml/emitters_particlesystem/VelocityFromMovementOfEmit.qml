import QtQuick 2.11
import QtQuick.Particles 2.0

DemoBasic {

    id : idRoot
    property int indexOfPoint : 0       ;
    property var pointCacheArray : [] ;
    function getPointPosition( ){
        var varMaxIndex = 256 ;

        var varIndex = indexOfPoint++ ;
        if( varIndex > varMaxIndex ){
            varIndex = 1;
            indexOfPoint=2;
        } else if( varIndex < 0 ){
            varIndex = 0;
            indexOfPoint=0;
        }

        if( pointCacheArray.length > varIndex ){
            return pointCacheArray[varIndex];
        }

        var varIndexAngleStep = Math.PI / varMaxIndex * 2 ;
        var varAngle =  varIndexAngleStep * varIndex ;
        var varCos = Math.cos(varAngle) ;
        var varSin = Math.sin(varAngle) ;
        var varAns = Qt.point(
                    0.5 + 0.45 * varCos ,
                    0.5 + 0.45 * varSin );
        pointCacheArray.push(varAns);
        return varAns ;
    }

    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent ;

        Emitter{
            id : idEmitter
            size: 8
            emitRate : 100 ;
            maximumEmitted : 10000 ;
            lifeSpan : 500 ;
            system: idParticleSystem ;
            velocity: AngleDirection{
                magnitude: 16 ;
                angleVariation: 360
            }
            velocityFromMovement: 1 ;
        }

        ImageParticle {
            source: "qrc:///particleresources/star.png" ;
            system: idParticleSystem ;
        }
    }

    Timer{
        interval: 200 ;
        repeat: true ;
        running: true;
        triggeredOnStart: true;
        onTriggered: {
            var varPoint =
                    getPointPosition();
            idEmitter.x = idRoot.x +
                    varPoint.x * idRoot.width ;
            idEmitter.y = idRoot.y +
                    varPoint.y * idRoot.height ;
        }
    }

}

















