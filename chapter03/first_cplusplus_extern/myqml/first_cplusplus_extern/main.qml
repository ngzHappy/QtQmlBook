/*main.qml*/
import QtQuick 2.9
import sstd.externbycplusplus 1.0

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.5,0.5,0.5,1);

    ExternByCplusplus{
        id : idData
    }

    Text{
        text : idData.data
        font.pixelSize: 64
        anchors.centerIn: parent
        verticalAlignment : Text.AlignVCenter
        horizontalAlignment:Text.AlignHCenter
    }

}/*~Rectangle*/



