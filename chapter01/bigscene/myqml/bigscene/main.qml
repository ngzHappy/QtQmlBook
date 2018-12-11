/*main.qml*/
import QtQuick 2.9
import sstd.bigscene 1.0

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Flickable {

        id : idf ;
        width: parent.width   ;
        height: parent.height ;
        contentWidth: idb.width ;
        contentHeight: idb.height ;

        BigScene {
            id : idb ;
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



