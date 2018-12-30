import QtQuick 2.11
import QtQuick.Controls 1.4
import QtQml.StateMachine 1.11 as QSM

DemoBasic{

    Rectangle{
        id : _id_rect
        color: Qt.rgba(0,0,0,1)
        width: 100
        height: 100
        anchors.centerIn: parent
        Behavior on color{
            PropertyAnimation{}
        }
    }

    QSM.StateMachine{

        running: true
        initialState: _id_s0

        QSM.State{
            id : _id_s0
            QSM.TimeoutTransition{
                targetState: _id_s1;
                timeout: 1000;
            }
            onEntered: { _id_rect.color=Qt.rgba(0,1,0,1) }
        }

        QSM.State{
            id : _id_s1
            QSM.TimeoutTransition{
                targetState: _id_s2;
                timeout: 1000;
            }
            onEntered: { _id_rect.color=Qt.rgba(1,1,0,1) }
        }

        QSM.State{
            id : _id_s2
            QSM.TimeoutTransition{
                targetState: _id_s3;
                timeout: 1000;
            }
            onEntered: { _id_rect.color=Qt.rgba(0,0,1,1) }
        }

        QSM.State{
            id : _id_s3
            QSM.TimeoutTransition{
                targetState: _id_s0;
                timeout: 1000;
            }
            onEntered: { _id_rect.color=Qt.rgba(1,0,0,1) }
        }

    }

    
}

/**
  The Declarative State Machine Framework
**/






