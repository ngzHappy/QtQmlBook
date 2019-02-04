/*charts/ScatterOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3
import sstd.charts.help 1.0

import "main_private/control" as Control

DemoBasic {

    ChartView {
        title: qsTr("水平柱状图")
        anchors.fill: parent
        antialiasing: true
        id : idView

        HorizontalBarSeries{
            axisY: BarCategoryAxis {
                categories: [
                    "2007",
                    "2008",
                    "2009",
                    "2010",
                    "2011",
                    "2012" ]
            }
            BarSet {
                label: "Bob";
                values: [2, 2, 3, 4, 5, 6]
            }
            BarSet {
                label: "Susan";
                values: [5, 1, 2, 4, 1, 7]
            }
            BarSet {
                label: "James";
                values: [3, 5, 8, 13, 5, 8]
            }
            id : idBar
        }

        ScatterSeries{
            axisX: idBar.axisX
            axisY: idBar.axisY

            XYPoint { x: 5; y: 0 }
            XYPoint { x: 1; y: 1 }
            XYPoint { x: 2; y: 2 }
            XYPoint { x: 4; y: 3 }
            XYPoint { x: 1; y: 4 }
            XYPoint { x: 7; y: 5 }

        }

    }

}
