﻿/*ListView 的模型*/
import QtQuick 2.11

ListModel {

    /****/
    ListElement {
        programName :  qsTr("遮罩(MaskEmit.qml)") ;
        programSource : "../MaskEmit.qml";
    }

    ListElement {
        programName :  qsTr("速度(VelocityOfEmit.qml)") ;
        programSource : "../VelocityOfEmit.qml";
    }

    ListElement {
        programName :  qsTr("加速度(AccelerationEmit.qml)") ;
        programSource : "../AccelerationEmit.qml";
    }

    ListElement {
        programName :  qsTr("随动速度(VelocityFromMovementOfEmit.qml)") ;
        programSource : "../VelocityFromMovementOfEmit.qml";
    }

    ListElement {
        programName :  qsTr("尾发射器(TrailEmit.qml)") ;
        programSource : "../TrailEmit.qml";
    }

}
