/*main.qml*/
import QtQuick 2.9
import sstd.minesweeping 1.0

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.3,0.3,0.38,1);

    MineSweeping{

        anchors.centerIn: parent;
        property double minWidthHeight:
            Math.min( parent.height , parent.width );
        width: minWidthHeight * 0.8;
        height: minWidthHeight * 0.8;

        maskItem : Rectangle {
            anchors.centerIn: parent
            width: parent.width * 0.95
            height: parent.height * 0.95
            color: Qt.rgba(0.2,0.2,0.2,1);
            Behavior on opacity{
                NumberAnimation{
                    duration: 333
                }
            }
        }

        flagItem : Flag{
            anchors.centerIn: parent ;
            width  : parent.width * 0.75 ;
            height : parent.height * 0.75 ;
        }

        numberItem : Number{
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
        }

        errorItem : Error{
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
        }

        mineItem : Mine{
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
        }

        okMineItem : OkMine{
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
        }

        boomItem : Boom {
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
        }

        onIsGameOverChanged: {
            console.log( isGameWin )
        }

    }

}/*~Rectangle*/



