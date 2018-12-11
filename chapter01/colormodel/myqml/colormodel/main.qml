import QtQuick 2.9
import QtGraphicalEffects 1.0
import sstd.color.model 1.0

Rectangle{

    width: 512 ;
    height: 512 ;
    color: Qt.rgba(1,0,0,1);

    ColorModel{
        id : _id_model
    }

    ListView{
        width: parent.width ;
        height: parent.height ;
        model: _id_model ;
        delegate: Rectangle{
            color: color_role_ ;
            width: parent.width ;
            height: 32 ;

            Text {
                id : _id_text ;
                text: text_role_ ;
                anchors.fill: parent ;
                horizontalAlignment : Text.AlignHCenter ;
                verticalAlignment: Text.AlignVCenter ;
                fontSizeMode :Text.Fit ;
                minimumPixelSize: 10 ;
                font.pixelSize: 888 ;
                antialiasing: true;
            }

            DropShadow {
                anchors.fill: _id_text;
                horizontalOffset: 1.5;
                verticalOffset: 1.5;
                radius: 4.0;
                samples: 8;
                color: Qt.rgba(0.1,0.1,0.1,0.9);
                source: _id_text;
                cached: true;
                antialiasing: true;
            }

            MemoryWatcherObject{
            }
        }
    }

}/*Rectangle*/










