/*ListView 的模型*/
import QtQuick 2.11

ListModel {

    /****/
    ListElement {
        programName :  QT_TR_NOOP("生命(AgeEffect.qml)") ;
        programSource : "../AgeEffect.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("吸引(AttractorEffect.qml)") ;
        programSource : "../AttractorEffect.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("重力(GravityEffect.qml)") ;
        programSource : "../GravityEffect.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("摩擦(FrictionEffect.qml)") ;
        programSource : "../FrictionEffect.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("湍流(TurbulenceEffect.qml)") ;
        programSource : "../TurbulenceEffect.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("漂移(WanderEffect.qml)") ;
        programSource : "../WanderEffect.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("组目标(GroupGoalEffect.qml)") ;
        programSource : "../GroupGoalEffect.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("图片目标(SpriteGoalEffect.qml)") ;
        programSource : "../SpriteGoalEffect.qml";
    }

}
