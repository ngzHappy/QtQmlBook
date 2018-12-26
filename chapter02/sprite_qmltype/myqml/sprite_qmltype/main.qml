/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Image{
        id : idFirstImage ;
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: idControls.bottom

        source : "0000.png"
        asynchronous : true/*开启异步加载*/
        cache : true/*进行缓存*/
        fillMode : idFillMode.getCurrentValue() /*图像重复模式*/
        horizontalAlignment : idHorizontalAlignment.getCurrentValue()/*水平对齐*/
        verticalAlignment : idVerticalAlignment.getCurrentValue()/*垂直对齐*/
        smooth :true/*开启平滑*/
        //sourceSize : Qt.size(w,h)

    }



}/*~Rectangle*/



