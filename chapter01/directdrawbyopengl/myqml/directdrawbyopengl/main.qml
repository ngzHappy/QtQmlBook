import QtQuick 2.9
import sstd.quick 1.0

Rectangle{

    objectName: "root_object";
    width: 512 ;
    height: 512 ;
    color: Qt.rgba(1,0,0,1);

    DrawImageItem{

        width: parent.width /2  ;
        height: parent.height /2;
        anchors.centerIn: parent;
        transformOrigin: Item.Center ;
        rawImage : Qt.resolvedUrl( "0000.jpg" );

        Timer{
            repeat: true;
            running: true;
            interval : 500 ;
            triggeredOnStart: true;
            onTriggered: {
                parent.rotation += 15 ;
                if(parent.rotation>360){
                    parent.rotation -= 360 ;
                }
                parent.opacity = Math.random() * 0.3 + 0.7 ;
                parent.scale = Math.random() * 0.3 + 0.7 ;
            }
        }

    }

}/*Rectangle*/










