/*tooltip_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ColumnLayout{
        anchors.fill: parent
        Button{
            text: qsTr( "Good!" )
            Layout.alignment: Qt.AlignHCenter
            ToolTip.text: qsTr("Good Button")
            ToolTip.visible: hovered
        }
        Slider{
            value: 0.5
            Layout.fillWidth: true
            id : idSlider
            ToolTip {
                parent: idSlider.handle
                visible: idSlider.hovered
                text: idSlider.value.toFixed(1)
            }
        }
    }

}
