/*externbycplusplus/main.qml*/
import QtQuick 2.9
import sstd.quick 1.0

Rectangle{

    width: 512 ;
    height: 512 ;
    color: Qt.rgba(1,0,0,1);

    QuickMemoryImage{
        id : idQuickMemoryImage ;
        objectName: "quick_memory_image";
    }

    Image {
        anchors.centerIn: parent ;
        width: parent.width * 0.8 ;
        height: parent.height * 0.8 ;
        source: idQuickMemoryImage.imageName;
        fillMode: Image.PreserveAspectFit;
    }

    Image {
        anchors.centerIn: parent ;
        width: parent.width * 0.8 ;
        height: parent.height * 0.8 ;
        source: contex_quick_memory_image.imageName;
        fillMode: Image.PreserveAspectFit;
    }

}/*Rectangle*/










