/*charts/ScatterOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3
import sstd.charts.help 1.0

import "main_private/control" as Control

DemoBasic {

    ChartView {
        title: qsTr("区域图")
        anchors.fill: parent
        antialiasing: true
        id : idView

        AreaSeries{
            name:"Area1"
            id : idArea1
            upperSeries: LineSeries {
                XYPoint { x: 0; y: 1 }
                XYPoint { x: 1; y: 1 }
                XYPoint { x: 2; y: 1 }
                XYPoint { x: 3; y: 1 }
                XYPoint { x: 4; y: 1 }
                XYPoint { x: 5; y: 0 }
                XYPoint { x: 6; y: 1 }
                XYPoint { x: 7; y: 1 }
                XYPoint { x: 8; y: 4 }
                XYPoint { x: 9; y: 3 }
                XYPoint { x: 10; y: 2 }
                XYPoint { x: 11; y: 1 }
            }

            lowerSeries : LineSeries {
                XYPoint { x: 0; y:  1-0.5-0.2 }
                XYPoint { x: 1; y:  1-0.5-0.5 }
                XYPoint { x: 2; y:  1-0.5-0.3 }
                XYPoint { x: 3; y:  1-0.5-0.7 }
                XYPoint { x: 4; y:  1-0.5-0.2 }
                XYPoint { x: 5; y:  0-0.5-0.1 }
                XYPoint { x: 6; y:  1-0.5-0.5 }
                XYPoint { x: 7; y:  1-0.5-0.2 }
                XYPoint { x: 8; y:  4-0.5-0.4 }
                XYPoint { x: 9; y:  3-0.5-0.3 }
                XYPoint { x: 10; y: 2-0.5-0.7 }
                XYPoint { x: 11; y: 1-0.5-0.1 }
            }

        }

        AreaSeries{
            name:"Area2"
            upperSeries : LineSeries {
                XYPoint { x: 0; y:  1-0.5-0.2 }
                XYPoint { x: 1; y:  1-0.5-0.5 }
                XYPoint { x: 2; y:  1-0.5-0.3 }
                XYPoint { x: 3; y:  1-0.5-0.7 }
                XYPoint { x: 4; y:  1-0.5-0.2 }
                XYPoint { x: 5; y:  0-0.5-0.1 }
                XYPoint { x: 6; y:  1-0.5-0.5 }
                XYPoint { x: 7; y:  1-0.5-0.2 }
                XYPoint { x: 8; y:  4-0.5-0.4 }
                XYPoint { x: 9; y:  3-0.5-0.3 }
                XYPoint { x: 10; y: 2-0.5-0.7 }
                XYPoint { x: 11; y: 1-0.5-0.1 }
            }
        }

    }

}
