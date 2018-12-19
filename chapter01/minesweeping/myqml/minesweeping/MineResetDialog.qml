import QtQuick 2.9
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.12

Dialog{

    id: idDialog
    width: parent.width * 0.8 ;
    height: parent.height * 0.8 ;
    x : parent.width * 0.1 ;
    y : parent.height * 0.1 ;
    signal resizeMine(int rowAndColumn,int mineSize);

    ColumnLayout {

        anchors.fill: parent ;

        RowLayout{
            Label {
                Layout.minimumWidth: 64
                text: qsTr("行列数")
            }
            SpinBox{
                id : idColumn
                from : 10
                to : 1024
                value: 10
                Layout.fillWidth :true;
                editable: true
                wheelEnabled :true
            }
        }

        RowLayout{
            Label {
                text: qsTr("地雷数")
                Layout.minimumWidth: 64
            }
            SpinBox{
                id : idMine
                from : 10
                to : idColumn.value * idColumn.value;
                value: 10
                Layout.fillWidth :true;
                editable: true
                wheelEnabled :true
            }
        }

        RowLayout{
            Button{
                text: qsTr("确定")
                onClicked: {
                    idDialog.resizeMine(
                                idColumn.value ,
                                idMine.value);
                    idDialog.close() ;
                }
                Layout.fillWidth :true;
            }
            Button{
                text: qsTr("取消")
                onClicked: {
                    idDialog.close() ;
                }
                Layout.fillWidth :true;
            }
        }

    }

}






