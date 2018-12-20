import QtQuick 2.11
import QtQuick.Particles 2.0
import "GetImageSourceName.js" as GetImageSourceName

DemoBasic {

    property int imageIndex : 0

    function getIndex(){
        if( imageIndex>=63 ){
            imageIndex=0;
        }else{
            ++imageIndex;
        }
        return imageIndex;
    }

    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent ;
    }

    ImageParticle {
        source: GetImageSourceName.
        getImageSourceName( 0 ) ;
        system: idParticleSystem ;
    }

    Emitter{
        size: 32
        emitRate : 100 ;
        maximumEmitted : 1000 ;
        lifeSpan : 2500;
        system: idParticleSystem ;
        anchors.fill: idParticleSystem;
        shape: MaskShape {
            source : "images/z.png"
        }
    }

}

