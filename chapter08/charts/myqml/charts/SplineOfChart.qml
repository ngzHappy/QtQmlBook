/*charts/SplineOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3

import "main_private/control" as Control

DemoBasic {

    ChartView {
        title: qsTr("样条曲线图")
        anchors.fill: parent
        antialiasing: true
        id : idView

        SplineSeries {
            name: "LineSeries1"
            capStyle : idControl.capStyleItem.currentValue
            style:idControl.styleItem.currentValue
            width : idControl.widthItem.value
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1.1; y: 2.1 }
            XYPoint { x: 1.9; y: 3.3 }
            XYPoint { x: 2.1; y: 2.1 }
            XYPoint { x: 2.9; y: 4.9 }
            XYPoint { x: 3.4; y: 3.0 }
            XYPoint { x: 4.1; y: 3.3 }
            color: Qt.rgba(0.1,0.1,0.1)
            id : idLine
        }

    }

    Component.onCompleted: {
        /*ValueAxis*/
        idLine.axisY.reverse = true  ;
        idLine.axisY.min = -0.5 ;
        idLine.axisY.max = 5;
    }

    Control.LineOfChartControl{
        id : idControl
    }

}

/*endl_input_of_latex_for_clanguage_lick*/
/*http://doc.qt.io/qt-5/qtquick-effects-particles.html*/
