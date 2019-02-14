/*user_define_value/main.qml*/
import QtQuick 2.9
import example.myvalue 1.0

Rectangle {
    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Component.onCompleted: {
        var varMyValue = MyValueCreator.create(3,2);
        console.log( varMyValue.getX(),varMyValue.getY() );
        console.log( varMyValue === MyValueCreator.create(1,2) );
        console.log( varMyValue === MyValueCreator.create(3,2) );
    }

}

