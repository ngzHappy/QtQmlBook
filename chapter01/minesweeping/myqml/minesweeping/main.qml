/*main.qml*/
import QtQuick 2.9
import sstd.minesweeping 1.0

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.3,0.3,0.38,1);

    MineSweeping{
        anchors.centerIn: parent;
        property double minWidthHeight: Math.min( parent.height , parent.width )
        width: minWidthHeight * 0.8;
        height: minWidthHeight * 0.8;

        maskItem : Rectangle {
            anchors.fill: parent ;
            anchors.margins: 1 ;
        }

    }


}/*~Rectangle*/



