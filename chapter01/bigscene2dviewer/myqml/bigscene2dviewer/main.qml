/*main.qml*/
import QtQuick 2.9
import sstd.bigscene2dviewer 1.0
import QtQuick.Controls 1.6
import QtGraphicalEffects 1.0

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.3,0.3,0.38,1);

    Text{
        id : idControlCenterXTextView
        text : "controlCenterX : " + ids.controlCenterX
        anchors.left: parent.left
        font.pixelSize: 22
        z : 10
        font.bold: true
        color: Qt.rgba(0.3,0.8,1,1)
    }

    Text{
        id : idControlCenterYTextView
        text : "controlCenterY : " +ids.controlCenterY
        anchors.right: parent.right
        font.pixelSize: 22
        z : 10.5
        font.bold: true
        color: Qt.rgba(0.3,0.8,1,1)
    }

    DropShadow{
        anchors.fill: idControlCenterYTextView
        horizontalOffset: 0.7
        verticalOffset: 0.7
        radius: 3
        samples: 12
        color: Qt.rgba(0.1,0.1,0.1,0.6)
        source: idControlCenterYTextView
    }

    DropShadow{
        anchors.fill: idControlCenterXTextView
        horizontalOffset: 0.7
        verticalOffset: 0.7
        radius: 3
        samples: 12
        color: Qt.rgba(0.1,0.1,0.1,0.6)
        source: idControlCenterXTextView
    }

    TextField {
        id : idCommand
        anchors.bottom: parent.bottom;
        width: parent.width
        height: 32
        font.pixelSize: 30
        onAccepted: {
            ids.runCommand( idCommand.text );
            idCommand.text=""               ;
        }
    }

    BigScene2DViewer{

        id : ids
        width: parent.width * 0.9   ;
        height: parent.height * 0.9 ;
        anchors.centerIn: parent ;

        controlItem : Rectangle{

            id : idcr ;
            width: 26 ;
            height: 26 ;
            color: Qt.rgba( 0 , 0 , 0 , 1 );
            x : 100 ;
            y : 100 ;

            MouseArea {
                anchors.fill: idcr ;
                drag.target:  idcr ;
                drag.axis :  Drag.XAndYAxis ;
                drag.minimumX  : 0 ;
                drag.maximumX : ids.width - idcr.width ;
                drag.minimumY: 0 ;
                drag.maximumY: ids.height - idcr.height ;
            }

        }

    }

}












