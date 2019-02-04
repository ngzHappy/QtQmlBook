/*ListView 的模型*/
import QtQuick 2.11

ListModel {

    /****/
    ListElement {
        programName :  QT_TR_NOOP("遮罩(MaskEmit.qml)") ;
        programSource : "../MaskEmit.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("速度(VelocityOfEmit.qml)") ;
        programSource : "../VelocityOfEmit.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("加速度(AccelerationEmit.qml)") ;
        programSource : "../AccelerationEmit.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("随动速度(VelocityFromMovementOfEmit.qml)") ;
        programSource : "../VelocityFromMovementOfEmit.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("尾发射器(TrailEmit.qml)") ;
        programSource : "../TrailEmit.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("脉冲发射(Pulse Emit.qml)") ;
        programSource : "../PulseOfEmit.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("瞬时发射(Burst Emit.qml)") ;
        programSource : "../BurstOfEmit.qml";
    }

}
