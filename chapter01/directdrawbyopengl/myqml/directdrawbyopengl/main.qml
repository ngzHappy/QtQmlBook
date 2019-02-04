/*directdrawbyopengl/main.qml*/
import QtQuick 2.9
import sstd.quick 1.0

Rectangle{
    id : root_object
    objectName: "root_object";
    width: 1024 ;
    height: 768 ;
    color: Qt.rgba(1,0,0,1);

    DrawImageItemRaw {

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
                parent.scale = Math.random() * 0.3 + 0.7   ;
            }
        }

    }


    Component.onCompleted : {
        Qt.createQmlObject(
"
import QtQuick 2.9
import sstd.quick 1.0

DrawImageItemRaw {
    width: 256   ;
    height: 256  ;
    anchors.top: parent.top                 ;
    anchors.right : parent.right            ;
    rawImage : Qt.resolvedUrl( '0000.jpg' ) ;
}

" , root_object  ) ;
    }

}/*Rectangle*/
