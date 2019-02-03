/*ListView 的模型*/
import QtQuick 2.11

ListModel {

    /****/
    ListElement {
        programName :  QT_TR_NOOP("折线图(LineSeries)") ;
        programSource : "../LineOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("样条曲线图(SplineSeries)") ;
        programSource : "../SplineOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("散点图(ScatterSeries)") ;
        programSource : "../ScatterOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("区域图(AreaSeries)") ;
        programSource : "../AreaOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("柱状图(BarSeries)") ;
        programSource : "../BarOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("水平柱状图(HorizontalBarSeries)") ;
        programSource : "../HorizontalBarOfChart.qml";
    }

}



