﻿/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12
import myqml.baidu 1.0

Pane {

    id : idRoot
    width: 640;
    height: 480;

    ColumnLayout{
        anchors.fill: parent;

        RowLayout {

            Label {
                id: idLabel1
                wrapMode : Text.WordWrap
                text: qsTr("资源地址")
                width: Math.max( idLabel1.contentWidth,idLabel2.contentWidth ,idLabel3.contentWidth)
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

        RowLayout {

            Label {
                id: idLabel3
                wrapMode : Text.WordWrap
                text: qsTr("正确密码")
                Layout.minimumWidth: idLabel1.width
            }

            TextField {
                Layout.fillWidth: true
                readOnly : false
                selectByMouse: true
                text : ""
                id: idOkUrl
            }

        }

        RowLayout{
            Item{
                Layout.fillWidth: true
            }
            SpinBox{
                id : idFileIndex
                editable: true
                wheelEnabled: true
                from     : 0
                to       : 167
                stepSize : 1
                enabled: !idRunControl.running
            }
            Button {
                id: idRun
                text: qsTr("执行")
                onClicked: {
                    idOkUrl.text="";
                    idPassWordReader.openFile(idFileIndex.value);
                    idPassWordReader.moveToStart();
                    idRunControl.running=!idRunControl.running;
                }
            }
        }

        Flickable {
            id : idLogScrollView
            Layout.fillWidth: true
            Layout.fillHeight: true
            contentWidth: idLog.width
            contentHeight: idLog.height
            clip: true
            TextArea {
                id : idLog
                readOnly: true
                selectByMouse: true
            }

        }

    }/*ColumnLayout*/

    BaiduPanPasswordReader{
        id : idPassWordReader
    }

    BaiduPanPasswordGet{
        id : idPassWordGet
        url : idUrl.text
        passWord: idPassWord.text
        property var logStrings : []
        onFinished: {
            /*argUrl argPassWord argErrorCode*/
            var logString = argUrl +
            " : " +
            argPassWord +
            " : " +
            errorCodeString(argErrorCode) +
            "\n";
            logStrings.push(logString);
            while( logStrings.length > 16 ){
                logStrings.shift();
            }
            logString = "";
            for(var i in logStrings ){
                logString += logStrings[i];
            }
            idLog.text = logString ;

            //if(idLogScrollView.contentHeight<idLogScrollView.height){
            //    idLogScrollView.contentY = 0;
            //}else{
            //    idLogScrollView.contentY =
            //            idLogScrollView.contentHeight -
            //            idLogScrollView.height;
            //}

            if(argErrorCode == BaiduPanPasswordGet.Ok){
                idRunControl.running =false ;
                idOkUrl.text = argPassWord;
            }

        }
    }

    Component.onCompleted: {
        idPassWordReader
        .setMaximumBlockCount(idLog.textDocument);
    }

    Timer{
        id : idRunControl
        interval : 1
        repeat : true
        running : false
        triggeredOnStart : false
        onTriggered: {

            if(idPassWordReader.isEndl()){
                if(idPassWordGet.tryCount<1){
                    running =false;
                }
                return;
            }

            if(idPassWordGet.tryCount<64) {
                idPassWord.text = idPassWordReader.getNext();
                idPassWordGet.start();
            }

        }
    }

}/*~Rectangle*/


//X-Forwarded-For: 162.150.10.16
//Proxy-Client-IP
//WL-Proxy-Client-IP
