import QtQuick 2.11
import QtQuick.Particles 2.0
import "GetImageSourceName.js" as GetImageSourceName

DemoBasic {

    id : idRoot
    ParticleSystem{
        id : idParticleSystem ;
        anchors.fill: parent ;
    }

    Component{
        id : idShapedEmitter
        Item{
            id : idItemRoot
            anchors.fill: parent
            property string imageName : "" ;

            ImageParticle {
                source: idItemRoot.imageName ;
                system: idParticleSystem ;
                groups: [ imageName ]
            }

            Emitter{
                size: 32
                emitRate : 10 ;
                maximumEmitted : 10 ;
                lifeSpan : 2500;
                system: idParticleSystem ;
                anchors.fill: parent;
                shape: MaskShape {
                    source : "images/z.png"
                }
                group: idItemRoot.imageName
            }

        }
    }

    Component.onCompleted: {
        var varIndex = 0;
        for(;varIndex < 64 ; ++varIndex ){
            idShapedEmitter.createObject(
                        idRoot,
                        { "imageName" :
                            GetImageSourceName.
                            getImageSourceName(
                                varIndex)  });
        }
    }


}

