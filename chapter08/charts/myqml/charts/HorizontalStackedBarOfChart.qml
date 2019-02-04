/*charts/SplineOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3

import "main_private/control" as Control

DemoBasic {

    ChartView {
        title: qsTr("水平堆叠柱状图")
        anchors.fill: parent
        antialiasing: true
        id : idView

        HorizontalStackedBarSeries{
            axisY: BarCategoryAxis { categories: [
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
        }

    }

}

/*endl_input_of_latex_for_clanguage_lick*/
/*http://doc.qt.io/qt-5/qtquick-effects-particles.html*/
