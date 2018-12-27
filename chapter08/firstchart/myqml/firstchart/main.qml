/*main.qml*/
import QtQuick 2.9
import QtCharts 2.3

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    ChartView{

        anchors.centerIn: parent ;
        width: parent.width * 0.95 ;
        height: parent.height * 0.95 ;
        theme: ChartView.ChartThemeDark
        antialiasing: true
        dropShadowEnabled : true
        legend.visible : false

        BarSeries {
            id: idBar
            axisX: BarCategoryAxis {
                categories: [
                    "2007",
                    "2008",
                    "2009",
                    "2010",
                    "2011",
                    "2012" ] }
            BarSet {
                label: qsTr( "FirstChart" );
                values: [4, 3.5, 2, 3, 5, 9]
            }
        }

        LineSeries{
            XYPoint { x: 0; y: 4 }
            XYPoint { x: 1; y: 3.5 }
            XYPoint { x: 2; y: 2 }
            XYPoint { x: 3; y: 3 }
            XYPoint { x: 4; y: 5 }
            XYPoint { x: 5; y: 9 }
            axisX: idBar.axisX
            axisY: idBar.axisY
            pointsVisible: true
            pointLabelsVisible : false
        }

    }

}/*~Rectangle*/



