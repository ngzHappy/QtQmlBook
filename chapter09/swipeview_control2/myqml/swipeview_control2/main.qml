/*swipeview_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    SwipeView{
        anchors.fill: parent;

        Rectangle{
            color: Qt.rgba(0.5,1,0.5,1)
        }

        Rectangle{
            color: Qt.rgba(0.5,0.5,1,1)
        }

        Rectangle{
            color: Qt.rgba(1,0.5,0.5,1)
        }

        id:idSwipeView
    }

    PageIndicator{
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        count: idSwipeView.count
        currentIndex: idSwipeView.currentIndex
    }

}

