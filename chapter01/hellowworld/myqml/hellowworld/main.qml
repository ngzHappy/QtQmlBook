/*main.qml*/
import QtQuick 2.9
import QtQuick.Window 2.2
import "main_private" as MainPrivate

Rectangle {
    visible: true;
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    MainPrivate.MainText{
        z : 1 ;
        anchors.fill : parent;
    }/*~MainText*/

    MainPrivate.MainRectangle {
        z : 0 ;
        anchors.fill : parent;
    }/*~MainRectangle*/

}/*~Window*/



