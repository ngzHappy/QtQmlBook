/*charts/SplineOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3

import "main_private/control" as Control

DemoBasic {

    ChartView {
        title: qsTr("K线图")
        anchors.fill: parent
        antialiasing: true
        id : idView

        CandlestickSeries{
            name: "Acme Ltd."
            increasingColor: "green"
            decreasingColor: "red"

            CandlestickSet {
                timestamp: 1435708800000;
                open: 690;
                high: 694;
                low: 599;
                close: 660
            }
            CandlestickSet {
                timestamp: 1435795200000;
                open: 669;
                high: 669;
                low: 669;
                close: 669
            }
            CandlestickSet {
                timestamp: 1436140800000;
                open: 485;
                high: 623;
                low: 485;
                close: 600
            }
            CandlestickSet {
                timestamp: 1436227200000;
                open: 589;
                high: 615;
                low: 377;
                close: 569
            }
            CandlestickSet {
                timestamp: 1436313600000;
                open: 464;
                high: 464;
                low: 254;
                close: 254
            }
        }

    }

}

/*endl_input_of_latex_for_clanguage_lick*/
/*http://doc.qt.io/qt-5/qtquick-effects-particles.html*/







