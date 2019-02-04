/*charts/ScatterOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3
import sstd.charts.help 1.0

import "main_private/control" as Control

DemoBasic {

    ChartView {
        title: qsTr("柱状图")
        anchors.fill: parent
        antialiasing: true
        id : idView
        legend.visible : false

        Column{
            x : idView.plotArea.x+16
            y : idView.plotArea.y+16
            Text {
                text: "\u25CF"+idBar1.label
                color: idBar1.color
                font.bold: true
                font.pointSize: 12
            }
            Text {
                text: "\u25CF"+idBar2.label
                color: idBar2.color
                font.bold: true
                font.pointSize: 12
            }
            Text {
                text: "\u25CF"+idBar3.label
                color: idBar3.color
                font.bold: true
                font.pointSize: 12
            }
        }

        BarSeries {
            axisX: BarCategoryAxis {
                categories: [
                    "2007",
                    "2008",
                    "2009",
                    "2010",
                    "2011",
                    "2012" ]
            }
            BarSet {
                label: "ABar"
                values: [2, 2, 3, 4, 5, 6]
                color: "#209fdf"
                id:idBar1
            }
            BarSet {
                label: "BBar"
                values: [5, 1, 2, 4, 1, 7]
                color: "#99ca53"
                id:idBar2
            }
            BarSet {
                label: "CBar"
                values: [3, 5, 8, 13, 5, 8]
                color: "#f6a625"
                id:idBar3
            }
            barWidth: 0.81
            id : idBar
        }

        LineSeries{
            name:idBar1.label
            XYPoint { x: 0-0.81/3; y: 2 }
            XYPoint { x: 1-0.81/3; y: 2 }
            XYPoint { x: 2-0.81/3; y: 3 }
            XYPoint { x: 3-0.81/3; y: 4 }
            XYPoint { x: 4-0.81/3; y: 5 }
            XYPoint { x: 5-0.81/3; y: 6 }
            axisY: idBar.axisY
            axisX: idBar.axisX
            pointsVisible: true
            pointLabelsVisible : false
            width: 2
            color: idBar1.color
        }

        LineSeries{
            name:idBar2.label
            XYPoint { x: 0-0.0; y: 5 }
            XYPoint { x: 1-0.0; y: 1 }
            XYPoint { x: 2-0.0; y: 2 }
            XYPoint { x: 3-0.0; y: 4 }
            XYPoint { x: 4-0.0; y: 1 }
            XYPoint { x: 5-0.0; y: 7 }
            axisY: idBar.axisY
            axisX: idBar.axisX
            pointsVisible: true
            pointLabelsVisible : false
            width: 2
            color: idBar2.color
        }

        LineSeries{
            name:idBar3.label
            XYPoint { x: 0+0.81/3; y: 3 }
            XYPoint { x: 1+0.81/3; y: 5 }
            XYPoint { x: 2+0.81/3; y: 8 }
            XYPoint { x: 3+0.81/3; y: 13 }
            XYPoint { x: 4+0.81/3; y: 5 }
            XYPoint { x: 5+0.81/3; y: 8 }
            axisY: idBar.axisY
            axisX: idBar.axisX
            pointsVisible: true
            pointLabelsVisible : false
            width: 2
            color: idBar3.color
        }

    }
}
