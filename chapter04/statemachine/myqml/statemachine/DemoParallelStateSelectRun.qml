import QtQuick 2.11
import QtQuick.Controls 1.4
import QtQml.StateMachine 1.11 as QSM

DemoBasic{

    ComboBox{
        anchors.top: parent.top ;
        anchors.topMargin: 6 ;
        width: parent.width*0.8 ;
        anchors.horizontalCenter: parent.horizontalCenter;
        id : _id_ss
        model: [
            "c0",
            "c1",
            "c2",
            "c3"]
        onCurrentIndexChanged: { currentIndexChanedWrap() }
        signal currentIndexChanedWrap();
    }

    Rectangle{
        id : _id_rect
        color: Qt.rgba(0,0,0,0)
        width: 100
        height: 100
        anchors.centerIn: parent;
        Behavior on color {
            PropertyAnimation{}
        }
    }

    QSM.StateMachine{
        running: true ;
        initialState: QSM.State{

            childMode: QSM.State.ParallelStates
            QSM.State{
                id : _id_s0
                function changedStateValue(){
                    if(_id_ss.currentIndex!=0)return;
                    _id_rect.color = Qt.rgba(0.2,0.5,0.6,1)
                }
                onEntered: changedStateValue();
                QSM.SignalTransition{
                    signal: _id_ss.currentIndexChanedWrap
                    onTriggered: _id_s0.changedStateValue();
                }
            }

            QSM.State{
                id : _id_s1
                function changedStateValue() {
                    if(_id_ss.currentIndex!=1)return;
                    _id_rect.color = Qt.rgba(0.8,0.3,0.6,1)
                }
                onEntered: changedStateValue();
                QSM.SignalTransition{
                    signal: _id_ss.currentIndexChanedWrap
                    onTriggered: _id_s1.changedStateValue();
                }
            }

            QSM.State{
                id : _id_s2
                function changedStateValue() {
                    if(_id_ss.currentIndex!=2)return;
                    _id_rect.color = Qt.rgba(0.2,0.8,0.1,1)
                }
                onEntered: changedStateValue();
                QSM.SignalTransition{
                    signal: _id_ss.currentIndexChanedWrap
                    onTriggered: _id_s2.changedStateValue();
                }
            }

            QSM.State{
                id : _id_s3
                function changedStateValue() {
                    if(_id_ss.currentIndex!=3)return;
                    _id_rect.color = Qt.rgba(0.8,0.8,0.6,1)
                }
                onEntered: changedStateValue();
                QSM.SignalTransition{
                    signal: _id_ss.currentIndexChanedWrap
                    onTriggered: _id_s3.changedStateValue();
                }
            }
        }
    }/*QSM.StateMachine*/
}

















