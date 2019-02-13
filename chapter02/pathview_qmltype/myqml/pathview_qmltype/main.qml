/*pathview_qmltype/main.qml*/
import QtQuick 2.12
import QtQml.Models 2.12

Rectangle {
    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    PathView{

        model: ObjectModel {
            Text{text:"H" ;
                color:Qt.rgba(Math.random()/2,Math.random()/3,Math.random(),1)
                scale : PathView.scaleValue }
            Text{text:"e" ;
                color:Qt.rgba(Math.random(),Math.random()/2,Math.random()/3,1)
                scale : PathView.scaleValue }
            Text{text:"l";
                color:Qt.rgba(Math.random()/3,Math.random(),Math.random()/2,1)
                scale : PathView.scaleValue }
            Text{text:"l";
                color:Qt.rgba(Math.random(),Math.random()/2,Math.random()/3,1)
                scale : PathView.scaleValue}
            Text{text:"o";
                scale : PathView.scaleValue}
            Text{text:"w";
                color:Qt.rgba(Math.random()/2,Math.random()/3,Math.random(),1)
                scale : PathView.scaleValue}
            Text{text:" "}
            Text{text:"W";
                color:Qt.rgba(Math.random()/3,Math.random()/2,Math.random(),1)
                scale : PathView.scaleValue}
            Text{text:"o";
                color:Qt.rgba(Math.random(),Math.random()/3,Math.random()/2,1)
                scale : PathView.scaleValue}
            Text{text:"r";
                color:Qt.rgba(Math.random()/3,Math.random()/2,Math.random(),1)
                scale : PathView.scaleValue}
            Text{text:"l";
                color:Qt.rgba(Math.random()/2,Math.random(),Math.random()/3,1)
                scale : PathView.scaleValue}
            Text{text:"d";
                color:Qt.rgba(Math.random(),Math.random()/2,Math.random()/3,1)
                scale : PathView.scaleValue}
            Text{text:"!";
                color:Qt.rgba(Math.random()/3,Math.random(),Math.random()/2,1)
                scale : PathView.scaleValue}
        }

        path: Path{
            startX: idRoot.width * 0.2
            startY: idRoot.height *0.2
            PathAttribute { name: "scaleValue"; value: 3.2 }
            PathLine{
                x : idRoot.width * 0.5
                y : idRoot.height *0.8
            }
            PathAttribute { name: "scaleValue"; value: 5.7 }
            PathLine{
                x : idRoot.width * 0.8
                y : idRoot.height *0.2
            }
        }

    }

}
