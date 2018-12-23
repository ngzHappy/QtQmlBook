/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    RowLayout{
        id : idControls
        ComboBox {
            id: idFillMode
            textRole: "key"
            model: ListModel {
                ListElement { key: "Image.Stretch"; value : Image.Stretch ; }
                ListElement { key: "Image.PreserveAspectFit"; value : Image.PreserveAspectFit; }
                ListElement { key: "Image.PreserveAspectCrop"; value : Image.PreserveAspectCrop }
                ListElement { key: "Image.Tile"; value : Image.Tile }
                ListElement { key: "Image.TileVertically"; value : Image.TileVertically }
                ListElement { key: "Image.TileHorizontally"; value : Image.TileHorizontally }
                ListElement { key: "Image.Pad"; value : Image.Pad }
            }
            Layout.preferredWidth: idRoot.width * 0.3333
            function getCurrentValue(){
                return  idFillMode.model.get(
                            idFillMode.currentIndex).value;
            }
        }
        ComboBox {
            id: idHorizontalAlignment
            textRole: "key"
            model: ListModel {
                ListElement { key: "Image.AlignLeft"; value :Image.AlignLeft }
                ListElement { key: "Image.AlignRight"; value : Image.AlignRight }
                ListElement { key: "Image.AlignHCenter"; value : Image.AlignHCenter }
            }
            Layout.preferredWidth: idRoot.width * 0.3333
            function getCurrentValue(){
                return idHorizontalAlignment.model.get(
                            idHorizontalAlignment.currentIndex).value;
            }
        }
        ComboBox {
            id: idVerticalAlignment
            textRole: "key"
            model: ListModel {
                ListElement { key: "Image.AlignTop"; value : Image.AlignTop }
                ListElement { key: "Image.AlignBottom"; value : Image.AlignBottom }
                ListElement { key: "Image.AlignVCenter"; value : Image.AlignVCenter }
            }
            Layout.preferredWidth: idRoot.width * 0.3333
            function getCurrentValue(){
                return idVerticalAlignment.model.get(
                            idVerticalAlignment.currentIndex).value;
            }
        }
    }

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



