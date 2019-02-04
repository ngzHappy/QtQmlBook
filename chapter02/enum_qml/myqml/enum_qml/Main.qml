/*enum_qml/Main.qml*/
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
        interval : 1000
        repeat : true
        running : true
        triggeredOnStart : true
        onTriggered: {
            switch(enumValue){
            case Main.Enum1.Value0:
                idRoot.color = Qt.rgba(0.8,0.4,0.8,1);
                enumValue=Main.Enum1.Value1;
                break;
            case Main.Enum1.Value1:
                idRoot.color = Qt.rgba(0.4,0.8,0.8,1);
                enumValue=Main.Enum1.Value2;
                break;
            case Main.Enum1.Value2:
                idRoot.color = Qt.rgba(0.0,0.8,0.0,1);
                enumValue=Main.Enum1.Value0;
                break;
            }
        }
    }


}/*~Rectangle*/
