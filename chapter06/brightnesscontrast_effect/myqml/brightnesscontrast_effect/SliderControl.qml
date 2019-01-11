import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Slider{
    id : idSlider
    ToolTip {
        parent: idSlider.handle
        visible: idSlider.hovered
        text: idSlider.value.toFixed(2)
    }
}


















