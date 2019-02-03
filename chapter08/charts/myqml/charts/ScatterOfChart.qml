/*charts/ScatterOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3
import sstd.charts.help 1.0

import "main_private/control" as Control

DemoBasic {

    ChartView {
        title: qsTr("散点图")
        anchors.fill: parent
        antialiasing: true
        id : idView
        legend.markerShape : Legend.MarkerShapeFromSeries

        ScatterSeries {
            id: idScatter1
            name: "Scatter1"
            XYPoint { x: 1.5; y: 1.5 }
            XYPoint { x: 1.5; y: 1.6 }
            XYPoint { x: 1.57; y: 1.55 }
            XYPoint { x: 1.8; y: 1.8 }
            XYPoint { x: 1.9; y: 1.6 }
            XYPoint { x: 2.1; y: 1.3 }
            XYPoint { x: 2.5; y: 2.1 }
            markerShape : ScatterSeries.MarkerShapeCircle
            borderColor: Qt.rgba(0.9,0.6,0.5,1)
            borderWidth: 2
        }

        ScatterSeries {
            id: idScatter2
            name: "Scatter2"
            XYPoint { x: 1.5; y: 1.6 }
            XYPoint { x: 1.5; y: 1.5 }
            XYPoint { x: 1.57; y: 1.7 }
            XYPoint { x: 1.8; y: 1.9 }
            XYPoint { x: 1.9; y: 1.7 }
            XYPoint { x: 2.1; y: 2.0 }
            XYPoint { x: 2.5; y: 1.8 }
            axisY: idScatter1.axisY
            axisX: idScatter1.axisX
            ScatterSeriesHelp.flag: 1
        }

    }

}

