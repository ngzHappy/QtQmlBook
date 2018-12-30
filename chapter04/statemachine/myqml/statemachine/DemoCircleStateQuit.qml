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

    Button{
        id : _id_quit_button;
        width: parent.width*0.5;
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("退出");
    }

    QSM.StateMachine{

        running: true
        initialState: _id_run

        QSM.FinalState{
            id : _id_final
        }

        QSM.State{

            id : _id_run
            initialState : _id_s0

            QSM.SignalTransition{
                signal: _id_quit_button.clicked
                targetState: _id_final
            }

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

    
}

/**
  The Declarative State Machine Framework
**/






