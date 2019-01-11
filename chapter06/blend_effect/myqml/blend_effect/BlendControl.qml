/*blend_effect/BlendControl*/

import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

RowLayout {
    width: parent.width

    ComboBox {
        id: idComboBox
        model: [
           "normal",
           "addition",
           "average",
           "color",
           "colorBurn",
           "colorDodge",
           "darken",
           "darkerColor",
           "difference",
           "divide",
           "exclusion",
           "hardLight",
           "hue",
           "lighten",
           "lighterColor",
           "lightness",
           "multiply",
           "negation",
           "saturation",
           "screen",
           "subtract",
           "softLight"
        ]
    }




}









