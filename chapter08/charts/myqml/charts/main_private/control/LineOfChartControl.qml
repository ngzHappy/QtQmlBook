import QtQuick.Controls 2.12
import QtQuick.Layouts 1.3
import QtQuick 2.11
import QtCharts 2.3

ColumnLayout {

    width: parent.width
    anchors.bottom: parent.bottom

    ComboBox{
        id : idStyle
        textRole: "key"
        property int currentValue: Qt.SolidLine
        model: ListModel {
            id: idModel1
            ListElement { key: "Qt.SolidLine" ;value : Qt.SolidLine }
            ListElement { key: "Qt.NoPen" ; value : Qt.NoPen }
            ListElement { key: "Qt.DashLine" ; value : Qt.DashLine}
            ListElement { key: "Qt.DotLine" ; value : Qt.DotLine}
            ListElement { key: "Qt.DashDotLine" ; value : Qt.DashDotLine}
            ListElement { key: "Qt.DashDotDotLine" ; value : Qt.DashDotDotLine}
        }
        onActivated: {
            currentValue =
                    idModel1.get(currentIndex).value;
        }
    }

    ComboBox{
        id : idCapStyle
        textRole: "key"
        property int currentValue: Qt.SolidLine
        model: ListModel {
            id: idModel2
            ListElement { key: "Qt.SquareCap" ;value : Qt.SquareCap }
            ListElement { key: "Qt.FlatCap" ; value : Qt.FlatCap }
            ListElement { key: "Qt.RoundCap" ; value : Qt.RoundCap}
        }
        onActivated: {
            currentValue =
                    idModel2.get(currentIndex).value;
        }
    }

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("width")
        }
        SliderControl{
            from : 0
            to : 5
            value: 1
            stepSize: 0.1
            Layout.fillWidth: true
            id : idWidth
        }
    }

    property alias widthItem : idWidth
    property alias styleItem : idStyle
    property alias capStyleItem : idCapStyle

}







