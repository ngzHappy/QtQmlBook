/*charts/ScatterOfChart.qml*/
import QtQuick 2.11
import QtCharts 2.3
import sstd.charts.help 1.0

DemoBasic {

    Component{
        id : idAddItem
        Rectangle {

            color: Qt.rgba(
                       Math.random()*0.5+0.4,
                       Math.random()*0.5+0.45,
                       Math.random()*0.5+0.55,
                       1);
            property double labelY: 0
            property string labelYString: "Good"
            property int index: 0
            property double value: 0
            property var series: null
            property alias labelText: idLabelText

            Text {
                height: parent.height
                anchors.left: parent.left
                anchors.leftMargin: 5
                id : idLabelText
                text: labelYString
                verticalAlignment : Text.AlignVCenter
                font.pointSize: Math.max( parent.height*0.45 ,1 )
                style: Text.Outline;
                styleColor: Qt.rgba(0.6,0.6,0.6,0.8)
            }

            Text {
                anchors.left: parent.right
                anchors.leftMargin: 5
                height: parent.height
                text: parent.value
                font.pointSize: Math.max( parent.height*0.35 ,1 )
                verticalAlignment : Text.AlignVCenter
            }

            Text {
                anchors.right: parent.left
                anchors.rightMargin: 10
                height: parent.height
                font.pointSize: Math.max(
                                    parent.height*(0.55 +
                                                   0.1*
                                                   Math.max(0, (3- index) ) )
                                    ,1 )
                verticalAlignment : Text.AlignVCenter
                text: index
                visible: index<4
            }

        }
    }

    ChartView {
        title: qsTr("自定义水平柱状图")
        anchors.fill: parent
        antialiasing: true
        id : idView

        legend.visible : false
        margins.left: 30
        margins.right: 50
        margins.top: 20
        margins.bottom: 20

        onPlotAreaChanged: {
            idView.updateSeriesPosition();
        }

        property var addItems: []

        function updateSeriesPosition(){
            for( var varKey in idView.addItems ){
                var varItem = idView.addItems[varKey];
                var varBarWidth = varItem.series.barWidth/*dy*/;
                var varCurrentPoint0=
                        idView.mapToPosition(
                            Qt.point(0,varItem.labelY-varBarWidth*0.5) ,
                            varItem.series);
                var varCurrentPoint1=
                        idView.mapToPosition(
                            Qt.point(varItem.value,varItem.labelY+varBarWidth*0.5) ,
                            varItem.series);
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
            varAxisX.labelsVisible = true;
            var varBarSetValues = varBarSet.values;
            for( var varKey in varBarSetValues ){
                var varAddItem=idAddItem.createObject(idView);
                varAddItem.labelY = varKey;
                varAddItem.series = argS;
                varAddItem.value = varBarSetValues[varKey];
                varAddItem.labelYString = varAxisY.categories[varKey];
                varAddItem.index = varBarSetValues.length - varKey
                idView.addItems.push(varAddItem);
            }
            updateSeriesPosition();
        }

        HorizontalBarSeries{

            axisY: BarCategoryAxis {
                categories: [
                    "赵四",
                    "刘能",
                    "广坤",
                    "小蒙",
                    "长贵",
                    "永强" ]
            }

            BarSet {
                label: "NotUsed";
                color: Qt.rgba(0,0,0,0)
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












