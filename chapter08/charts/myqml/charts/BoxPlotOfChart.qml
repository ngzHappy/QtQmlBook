/*charts/SplineOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3

import "main_private/control" as Control

DemoBasic {

    ChartView {
        title: qsTr("盒图")
        anchors.fill: parent
        antialiasing: true
        id : idView

        BoxPlotSeries {
            id: plotSeries
            name: "Income"
            BoxSet {
                label: "Jan";
                values: [3, 4, 5.1, 6.2, 8.5]
            }
            BoxSet {
                label: "Feb";
                values: [5, 6, 7.5, 8.6, 11.8]
            }
            BoxSet {
                label: "Mar";
                values: [3.2, 5, 5.7, 8, 9.2]
            }
            BoxSet {
                label: "Apr";
                values: [3.8, 5, 6.4, 7, 8]
            }
            BoxSet {
                label: "May";
                values: [4, 5, 5.2, 6, 7]
            }
        }
    }

}

/*endl_input_of_latex_for_clanguage_lick*/
/*http://doc.qt.io/qt-5/qtquick-effects-particles.html*/







