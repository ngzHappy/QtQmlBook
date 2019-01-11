/*tumbler_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    Tumbler{
        model: 128
        visibleItemCount : 7
        anchors.centerIn: parent
        height: parent.height
        onCurrentIndexChanged: {
            console.log( currentIndex )
        }
    }

}

