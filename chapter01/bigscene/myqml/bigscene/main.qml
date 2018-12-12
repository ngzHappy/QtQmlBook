/*main.qml*/
import QtQuick 2.9
import sstd.bigscene 1.0

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.3,0.3,0.38,1);

    Flickable {

        id : idf ;
        width: parent.width   ;
        height: parent.height ;
        contentWidth: idb.width ;
        contentHeight: idb.height ;
        x : 0 ;
        y : 0 ;
        rotation: 0
        scale: 1
        transformOrigin : Item.Center
        clip:true
        antialiasing: true

        BigScene {
            id : idb ;
            antialiasing: true ;
        }

        visibleArea.onXPositionChanged: {
            idb.visibleXPosition =
                    idf.visibleArea.xPosition * idb.width ;
            /*begin:debug*/
            console.log("x",idb.visibleXPosition)
            /*end:debug*/
        }

        visibleArea.onYPositionChanged: {
            idb.visibleYPosition =
                    idf.visibleArea.yPosition * idb.height ;
            /*begin:debug*/
            console.log("y",idb.visibleYPosition)
            /*end:debug*/
        }

        visibleArea.onWidthRatioChanged: {
            idb.visibleWidth = idf.width ;
            /*begin:debug*/
            console.log("w",idb.visibleWidth )
            /*end:debug*/
        }

        visibleArea.onHeightRatioChanged: {
            idb.visibleHeight = idf.height ;
            /*begin:debug*/
            console.log("h",idb.visibleHeight)
            /*end:debug*/
        }

    }

}/*~Rectangle*/



