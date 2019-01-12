/*brightnesscontrast_effect/BrightnessContrastControl.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

ColumnLayout {
    width: parent.width
    anchors.bottom: parent.bottom

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("colorR")
        }
        SliderControl{
            from : 0
            to : 1
            value: 0.5
            stepSize: 0.01
            Layout.fillWidth: true
            id : idColorR
            onValueChanged: updateApplyColor();
        }
    }
    property alias colorRItem : idColorR

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("colorG")
        }
        SliderControl{
            from : 0
            to : 1
            value: 0.5
            stepSize: 0.01
            Layout.fillWidth: true
            id : idColorG
            onValueChanged: updateApplyColor();
        }
    }
    property alias colorGItem : idColorG

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("colorB")
        }
        SliderControl{
            from : 0
            to : 1
            value: 0.5
            stepSize: 0.01
            Layout.fillWidth: true
            id : idColorB
            onValueChanged: updateApplyColor();
        }
    }
    property alias colorBItem : idColorB

    RowLayout{
        Layout.fillWidth: true
        Label{
            Layout.minimumWidth: 64
            text:qsTr("colorA")
        }
        SliderControl{
            from : 0
            to : 1
            value: 0.5
            stepSize: 0.01
            Layout.fillWidth: true
            id : idColorA
            onValueChanged: updateApplyColor();
        }
    }
    property alias colorAItem : idColorA

    property color applyColor: Qt.rgba(idColorR.value,
                                       idColorG.value,
                                       idColorB.value,
                                       idColorA.value);

    function updateApplyColor(){
        applyColor = Qt.rgba( idColorR.value,
                             idColorG.value,
                             idColorB.value,
                             idColorA.value);
    }

}
















