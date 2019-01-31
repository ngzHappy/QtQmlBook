/*first_model_view/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import sstd.model 1.0 as ThisModel

Rectangle {
    id : idRoot
    width: 308;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    ListView {

        anchors.fill: parent;
        id : idList

        header : Rectangle {
            color: Qt.rgba(0.5,0.8,0.8,1)
            width: idList.width
            height: 16
        }

        footer : Rectangle{
            color: Qt.rgba(0.8,0.5,0.8,1)
            width: idList.width
            height: 16
        }

        model:  ThisModel.ListModel{
            id : idModel
        }

        delegate: Rectangle{
            id : idDelegate
            width: idList.width
            height: 64
            color: rawColor
            Text {
                anchors.fill: parent ;
                font.pointSize: 16
                text: rawString
            }
            RowLayout{
                anchors.fill: parent;
                Item{
                    Layout.fillWidth: true;
                }
                ToolButton{
                    text:"C"
                    onClicked: {
                        if(rawString.length<1) {
                            rawString = 'x';
                        }
                        if(rawString.substr(0,1)==="-") {
                            if(rawString.length>1){
                                rawString =
                                        rawString.substr(1, rawString.length);
                            }else{
                                 rawString = 'x';
                            }
                        }else{
                             rawString = "-"+ rawString;
                        }
                    }
                }
                ToolButton{
                    text:"+"
                    onClicked: {
                        idModel.insert( index );
                    }
                }
                ToolButton{
                    text:"-"
                    onClicked: {
                        idModel.remove( index );
                    }
                }
            }
        }

    }

}




