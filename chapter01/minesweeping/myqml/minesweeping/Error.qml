/*Flag.qml*/
import QtQuick 2.9
import sstd.minesweeping 1.0

Item{

    id : root ;
    property color lineColor : Qt.rgba(1,0,0,1) ;
    property double lineWidth : 1 ;

    onWidthChanged: {
        root.updatePonits() ;
    }

    onHeightChanged: {
        root.updatePonits() ;
    }

    function updatePonits(){
        line0.updatePoints();
        line1.updatePoints();
    }

    MineSweepingLine {
        id : line0
        lineWidth: parent.lineWidth ;
        lineColor : parent.lineColor ;
        function updatePoints(){
            line0.beginPoint =
                    Qt.point( 0 , 0 ) ;
            line0.endPoint =
                    Qt.point( root.width  ,
                              root.height ) ;
        }
        anchors.fill: root
    }

    MineSweepingLine{
        id : line1
        lineColor : parent.lineColor ;
        lineWidth: parent.lineWidth ;
        function updatePoints(){
            line1.beginPoint =
                     Qt.point( root.width , 0 );
            line1.endPoint =
                    Qt.point( 0 , root.height );
        }
        anchors.fill: root
    }

}
