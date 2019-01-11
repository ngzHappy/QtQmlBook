﻿import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml.StateMachine 1.11 as QSM

DemoBasic{

    RowLayout {
        anchors.top: parent.top;
        anchors.left: parent.left;
        width: parent.width;
        Button{
            id : _id_pause_button;
            text: qsTr("暂停");
            Layout.fillWidth: true
        }
        Button{
            id : _id_continue_button;
            text: qsTr("继续");
            Layout.fillWidth: true
        }
    }

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
        initialState: _id_run

        QSM.State{
            id : _id_pause
            QSM.SignalTransition{
                targetState: _id_history
                signal: _id_continue_button.clicked
            }
            onEntered:{_id_rect.color=Qt.rgba(0.5,0.5,0.5,1)}
        }

        QSM.State{
            id : _id_run
            initialState: _id_s0

            QSM.SignalTransition{
                targetState: _id_pause
                signal: _id_pause_button.clicked
            }

            QSM.HistoryState{
                id : _id_history
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






