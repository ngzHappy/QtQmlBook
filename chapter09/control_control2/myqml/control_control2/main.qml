﻿/*control_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    Control{
        anchors.fill: parent
        contentItem: Rectangle{
            color: Qt.rgba(0.2,0.2,0.5,1)
        }
    }

}
