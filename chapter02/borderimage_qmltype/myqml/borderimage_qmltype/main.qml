/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    BorderImage {
        id: idBorderImage
        source: "0000.png"
        anchors.fill: parent
        border.left: 27; border.top: 27
        border.right: 27; border.bottom: 27
    }

}/*~Rectangle*/



