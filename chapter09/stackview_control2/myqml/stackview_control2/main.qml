/*stackview_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    StackView{
        anchors.fill: parent;
        id : idStackView
    }

    Component.onCompleted: {
        idStackView.push(idComponent1);
        idStackView.push(idComponent2);
        idStackView.push(idComponent3);
    }

    Timer {
        interval : 1000
        repeat : true
        running : true
        triggeredOnStart : false
        onTriggered: {
            idStackView.pop();
            var varJudge = Math.random();
            if(varJudge>0.7){
                idStackView.push(idComponent1);
            }else if(varJudge>0.3){
                idStackView.push(idComponent2);
            }else {
                idStackView.push(idComponent3);
            }
        }
    }

     Component{
         id : idComponent1
         Rectangle{
             color: Qt.rgba(0.5,1,0.5,1)
         }
     }

     Component{
         id : idComponent2
         Rectangle{
             color: Qt.rgba(0.5,0.5,1,1)
         }
     }

     Component{
         id : idComponent3
         Rectangle{
             color: Qt.rgba(1,0.5,0.5,1)
         }
     }

}
