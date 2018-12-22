/*ListView 的模型*/
import QtQuick 2.11

ListModel {

    /****/
    ListElement {
        programName :  qsTr("生命(AgeEffect.qml)") ;
        programSource : "../AgeEffect.qml";
    }

    ListElement {
        programName :  qsTr("吸引(AttractorEffect.qml)") ;
        programSource : "../AttractorEffect.qml";
    }

    ListElement {
        programName :  qsTr("重力(GravityEffect.qml)") ;
        programSource : "../GravityEffect.qml";
    }

    ListElement {
        programName :  qsTr("摩擦(FrictionEffect.qml)") ;
        programSource : "../FrictionEffect.qml";
    }

    ListElement {
        programName :  qsTr("湍流(TurbulenceEffect.qml)") ;
        programSource : "../TurbulenceEffect.qml";
    }

    ListElement {
        programName :  qsTr("漂移(WanderEffect.qml)") ;
        programSource : "../WanderEffect.qml";
    }

    ListElement {
        programName :  qsTr("子目标(SpriteGoalEffect.qml)") ;
        programSource : "../SpriteGoalEffect.qml";
    }

    ListElement {
        programName :  qsTr("组目标(GroupGoalEffect.qml)") ;
        programSource : "../GroupGoalEffect.qml";
    }

}


