/*main.qml*/
import QtQuick 2.9
import sstd.bigscene 1.0

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Flickable {

        width: parent.width   ;
        height: parent.height ;
        contentWidth: _id_big_scene.width ;
        contentHeight: _id_big_scene.height ;

        BigScene {
            id : _id_big_scene ;

        }



        onFlickEnded: {
            _id_big_scene.update() ;
        }

    }

}/*~Rectangle*/



