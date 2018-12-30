import QtQuick 2.11
import QtQuick.Controls 1.4
import QtQml.StateMachine 1.11 as QSM

DemoBasic {

    Row{
        anchors.top: parent.top;
        anchors.left: parent.left;
        width: parent.width;
        Button{
            id : _id_change_background_color;
            width: parent.width*0.5;
            text: qsTr("更改背景颜色");
        }
        Button{
            id : _id_change_border_color;
            width: parent.width*0.5;
            text: qsTr("更改边界颜色");
        }
    }

    Rectangle{
        id : _id_rect ;
        anchors.centerIn: parent ;
        width : 100 ;
        height : 100 ;
        border.width: 10;
        color : Qt.rgba(0,0,0,0);
        Behavior on color {
            PropertyAnimation{}
        }
        Behavior on border.color {
            PropertyAnimation{}
        }
    }/**Rectangle**/

    QSM.StateMachine{
        running: true ;
        initialState: _id_state_loop;

        QSM.State{
            id : _id_state_loop ;
            childMode: QSM.QState.ParallelStates ;

            QSM.State{
                id : _id_back_ground_color;
                property bool stateValue: false;
                property color stateColor_0 : Qt.rgba(0.2,0.8,0.8,1)
                property color stateColor_1 : Qt.rgba(0.8,0.2,0.2,1)
                QSM.SignalTransition{
                    signal: _id_change_background_color.clicked;
                    onTriggered: {
                        _id_back_ground_color.stateValue=!_id_back_ground_color.stateValue;
                        if(_id_back_ground_color.stateValue){
                            _id_rect.color = _id_back_ground_color.stateColor_1;
                        }else{
                            _id_rect.color = _id_back_ground_color.stateColor_0;
                        }
                    }
                }
                onEntered: {
                    if(_id_back_ground_color.stateValue){
                        _id_rect.color = _id_back_ground_color.stateColor_1;
                    }else{
                        _id_rect.color = _id_back_ground_color.stateColor_0;
                    }
                }
            }/*QSM.State.Child*/

            QSM.State{
                id : _id_border_color;
                property bool stateValue: false;
                property color stateColor_0 : Qt.rgba(0.8,0.2,0.8,1)
                property color stateColor_1 : Qt.rgba(0.8,0.8,0.2,1)
                QSM.SignalTransition{
                    signal: _id_change_border_color.clicked;
                    onTriggered: {
                        _id_border_color.stateValue=!_id_border_color.stateValue;
                        if(_id_border_color.stateValue){
                                _id_rect.border.color = _id_border_color.stateColor_1;
                        }else{
                                _id_rect.border.color = _id_border_color.stateColor_0;
                        }
                    }
                }
                onEntered: {
                    if(_id_border_color.stateValue){
                            _id_rect.border.color = _id_border_color.stateColor_1;
                    }else{
                            _id_rect.border.color = _id_border_color.stateColor_0;
                    }
                }
            }/*QSM.State.Child*/

        }/*QSM.State.Parent*/

    }/*State Machine*/

}/*Window*/

/**
  https://stackoverflow.com/questions/30818886/qml-window-resize-move-flicker
  https://stackoverflow.com/questions/34267979/qt-openglwindow-flicker-on-resizing
  https://forum.qt.io/topic/81785/resizing-of-qquickview-very-slow-and-flickering/3
**/




















