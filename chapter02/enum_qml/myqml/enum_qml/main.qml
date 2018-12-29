/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    enum Enum1{
        Value0,
        Value1=1,
        Value2
    }

    property int enumValue : Main.Enum1.Value0
    Timer{

    }


}/*~Rectangle*/



