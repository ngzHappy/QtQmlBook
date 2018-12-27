﻿/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12
import myqml.baidu 1.0

Pane {

    id : idRoot
    width: 640;
    height: 480;

    BaiduPanPasswordGet{
        id : idPassWordGet
        url : idUrl.text
        passWord: idPassWord.text
    }

    ColumnLayout{
        anchors.fill: parent;

        RowLayout {

            Label {
                id: idLabel1
                wrapMode : Text.WordWrap
                text: qsTr("资源地址")
                width: Math.max( idLabel1.contentWidth,idLabel2.contentWidth )
                Layout.minimumWidth: idLabel1.width
            }

            TextField {
                Layout.fillWidth: true
                readOnly : false
                selectByMouse: true
                text : "https://pan.baidu.com/share/init?surl=34r85fxwJxxiuQ-aSqVS-g"
                id: idUrl
            }

        }

        RowLayout {

            Label {
                id: idLabel2
                text: qsTr("密码")
                Layout.minimumWidth: idLabel1.width
                wrapMode : Text.WordWrap
            }

            TextField {
                Layout.fillWidth: true
                text : "1234"
                readOnly : false
                selectByMouse: true
                id: idPassWord
            }

        }

        RowLayout{
            Item{
                Layout.fillWidth: true
            }
            Button {
                id: idRun
                text: qsTr("执行")
                onClicked: {
                    idPassWordGet.start();
                }
            }
        }

        TextArea{
            Layout.fillWidth: true;
            Layout.fillHeight: true;
            readOnly: true
            selectByMouse: true
        }

    }/*ColumnLayout*/

}/*~Rectangle*/



