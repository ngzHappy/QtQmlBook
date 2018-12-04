/*MainText.qml*/
import QtQuick 2.9
import QtQuick.Window 2.2

Text {
    text: qsTr("你好世界！");
    color: Qt.rgba(Math.random()/10,Math.random()/10,Math.random()/10,1);
    font.pointSize: 32;
    verticalAlignment : Text.AlignVCenter;
    horizontalAlignment : Text.AlignHCenter;
}

