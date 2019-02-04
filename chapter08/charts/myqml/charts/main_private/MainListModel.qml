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

    ListElement {
        programName :  QT_TR_NOOP("CandlestickOfChart(HorizontalBarSeries)") ;
        programSource : "../CandlestickOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("HorizontalPercentBarOfChart(HorizontalBarSeries)") ;
        programSource : "../HorizontalPercentBarOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("HorizontalStackedBarOfChart(HorizontalBarSeries)") ;
        programSource : "../HorizontalStackedBarOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("PercentBarOfChart(HorizontalBarSeries)") ;
        programSource : "../PercentBarOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("PieOfChart(HorizontalBarSeries)") ;
        programSource : "../PieOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("StackedBarOfChart(HorizontalBarSeries)") ;
        programSource : "../StackedBarOfChart.qml";
    }

    ListElement {
        programName :  QT_TR_NOOP("箱体图(BoxPlotSeries)") ;
        programSource : "../BoxPlotOfChart.qml";
    }

}



