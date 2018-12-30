/*ListView 的模型*/
import QtQuick 2.11

ListModel {

    /****/
    ListElement {
        programName :  QT_TR_NOOP("DemoPropertyAnimation") ;
        programSource : "../DemoPropertyAnimation.qml";
    }

    /****/
    ListElement{
        programName :  QT_TR_NOOP("DemoParallelStateSelectRun")
        programSource : "../DemoParallelStateSelectRun.qml"
    }

    /****/
    ListElement{
        programName :  QT_TR_NOOP("DemoCircleState")
        programSource : "../DemoCircleState.qml"
    }

    /****/
    ListElement{
        programName :  QT_TR_NOOP("DemoCircleStatePause")
        programSource : "../DemoCircleStatePause.qml"
    }

    /****/
    ListElement{
        programName :  QT_TR_NOOP("DemoCircleStateQuit")
        programSource : "../DemoCircleStateQuit.qml"
    }

}

