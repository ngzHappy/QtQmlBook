/*charts/ScatterOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3
import sstd.charts.help 1.0

DemoBasic {

    Component{
        id : idAddItem
        Item{
            property double labelY: 0
            property double value: 0
            property var series: null
            Text {
                text: labelY
            }
        }
    }

    ChartView {
        title: qsTr("自定义水平柱状图")
        anchors.fill: parent
        antialiasing: true
        id : idView

        legend.visible : false
        margins.left: 20
        margins.right: 20
        margins.top: 20
        margins.bottom: 20

        property var addItems: []

        function updateSeriesPosition(){
             for( var varKey in idView.addItems ){
                var varItem = idView.addItems[varKey];
                var varBarWidth = varItem.series.barWidth/*dy*/;
                var varCurrentPoint0=
                    idView.mapToPosition( Qt.point(0,varItem.labelY-varBarWidth*0.5) , varItem.series);
                var varCurrentPoint1=
                    idView.mapToPosition( Qt.point(varItem.value,varItem.labelY+varBarWidth*0.5) , varItem.series);
                 varItem.x = varCurrentPoint0.x;
                 varItem.y = varCurrentPoint1.y;
                 varItem.width = varCurrentPoint1.x - varCurrentPoint0.x ;
                 varItem.height =   varCurrentPoint0.y - varCurrentPoint1.y;
             }
        }

        function addToSeries(argS){
            var varBarSet = argS.at(0);
            var varAxisY = argS.axisY;
            var varAxisX = argS.axisX;
            varAxisY.labelsVisible =false;
            varAxisX.labelsVisible = false;
            var varBarSetValues = varBarSet.values;
            var varLableY = 0;
            for( var varKey in varBarSetValues ){
                var varAddItem=idAddItem.createObject(idView);
                varAddItem.labelY = varLableY++;
                varAddItem.series = argS;
                varAddItem.value = varBarSetValues[varKey];
                idView.addItems.push(varAddItem);
            }
            updateSeriesPosition();
        }

        HorizontalBarSeries{

            axisY: BarCategoryAxis {
                categories: [
                    "6",
                    "5",
                    "4",
                    "3",
                    "2",
                    "1" ]
            }

            BarSet {
                label: "NotUsed";
                values: [
                    40,
                    50,
                    60,
                    70,
                    80,
                    90]
            }

            id : idBS

            Component.onCompleted: {
                idView.addToSeries(idBS);
            }

        }

    }

}












