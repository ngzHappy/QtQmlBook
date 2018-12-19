/*Number.qml*/
import QtQuick 2.9
import QtGraphicalEffects 1.0

Item{

    id : idRoot
    property string text : "0"

    Text {

        id : idText
        anchors.fill: parent ;

        function getTextColor(str){
            if( str === "1" ){
                return Qt.rgba(0.38671875,0.7421875,0.48046875,1);
            } else if( str === "2" ){
                return Qt.rgba(0.59375,0.8046875,0.49609375,1);
            } else if( str === "3" ){
                return Qt.rgba(0.796875,0.86328125,0.5078125,1);
            } else if( str === "4" ){
                return Qt.rgba(0.99609375,0.91796875,0.515625,1);
            } else if( str === "5" ){
                return Qt.rgba(0.98828125,0.7890625,0.48828125,1);
            } else if( str === "6" ){
                return Qt.rgba(0.98046875,0.6640625,0.46484375,1);
            } else if( str === "7" ){
                return Qt.rgba(0.97265625,0.53515625,0.44140625,1);
            } else if( str === "8" ){
                return Qt.rgba(0.96875,0.41015625,0.41796875,1);
            }
            return Qt.rgba(0,0,0,1)
        }

        verticalAlignment: Text.AlignVCenter
        horizontalAlignment : Text.AlignHCenter
        minimumPixelSize : 1
        fontSizeMode : Text.Fit
        font.pixelSize : 512 ;
        font.bold: true;
        text: idRoot.text

        onTextChanged:{
            idText.color = getTextColor( idText.text );
        }

    }

    DropShadow{
        anchors.fill: idText
        horizontalOffset: 2
        verticalOffset: 2
        radius: 3.6
        samples: 16
        color: Qt.darker( idText.color )
        source: idText
        cached: false
    }

}

