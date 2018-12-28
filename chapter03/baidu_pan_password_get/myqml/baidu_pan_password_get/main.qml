/*main.qml*/
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
            Button {
                id: idRun
                text: qsTr("执行")
                onClicked: {
                    idOkUrl.text="";
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
        onFinished: {
            /*argUrl argPassWord argErrorCode*/
            idLog.append(
                        argUrl +
                        " : " +
                        argPassWord +
                        " : " +
                        errorCodeString(argErrorCode) +
                        "\n");

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
        interval : 2211
        repeat : true
        running : false
        triggeredOnStart : false
        onTriggered: {

            if(idPassWordReader.isEndl()){
                return;
            }

            /*每2s提交10个测试，防止封IP*/
            for(var i =0;i<10;++i){
                if(idPassWordGet.tryCount<64) {
                    idPassWord.text = idPassWordReader.getNext();
                    idPassWordGet.start();
                }
            }

        }
    }

}/*~Rectangle*/


//X-Forwarded-For: 162.150.10.16
//Proxy-Client-IP
//WL-Proxy-Client-IP

