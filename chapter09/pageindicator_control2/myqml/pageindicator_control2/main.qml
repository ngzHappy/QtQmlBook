﻿/*pageindicator_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ColumnLayout{
        anchors.fill: parent
        PageIndicator {
            count: 16
            currentIndex: 8
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
        }
    }

}
