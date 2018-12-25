/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3
import sstd.audio 1.0

Rectangle {

    id : idRoot
    width: 640;
    height: 640;
    color: Qt.rgba(0.8,0.8,0.8,1);

    MusicPlayer{
        id : idMusicPlayer  ;
        volume : 0.1        ;
    }

    FileDialog {
        id: idFileDialog
        title: qsTr( "选择媒体文件" )
        selectExisting : true
        selectFolder : false
        selectMultiple : false
        onAccepted: {
            if( !idMusicPlayer.openFile( fileUrl ) ){
                idTextArea.text = qsTr("打开文件失败：")
                    + fileUrl.toLocaleString() ;
            }else{
                idTextArea.text =
                        idMusicPlayer.fullFileInfo();
            }
        }
        onRejected: {
        }
        //nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        Component.onCompleted: {
            idFileDialog.folder = Qt.resolvedUrl("TestAudio");
        }
    }

    Timer{
        interval : 1000;
        repeat : true;
        triggeredOnStart : false;
        running: true;
        onTriggered: {
            if(idMusicPlayer.getState()===MusicPlayer.Play){
                idProgressBar.value =
                    idMusicPlayer.currentTime()/idMusicPlayer.duration;
            }else if(idMusicPlayer.getState()===MusicPlayer.Close){
                idProgressBar.value=0;
            }
        }
    }

    ColumnLayout {
       anchors.fill: parent;
       anchors.margins: 8

        ProgressBar {
            id: idProgressBar
            value: 0.0
            Layout.fillWidth: true
            MouseArea{
                anchors.fill: parent ;
                acceptedButtons: Qt.LeftButton
                onClicked: {
                    if(idMusicPlayer.getState()===MusicPlayer.Open){
                        idProgressBar.value =  mouse.x / width ;
                        idMusicPlayer.seekPlay(
                                    1000*
                                    idProgressBar.value*
                                    idMusicPlayer.duration );
                    }
                }
            }
        }

        RowLayout {

            Button {
                id: idStartButton
                text: qsTr("开始")
                Layout.fillWidth: true
                onClicked: idMusicPlayer.startPlay(-1);
            }

            Button {
                id: idPauseButton
                text: qsTr("暂停")
                Layout.fillWidth: true
                onClicked: idMusicPlayer.pausePlay();
            }

            Button {
                id: idContinueButton
                text: qsTr("继续")
                Layout.fillWidth: true
                onClicked: idMusicPlayer.continuePlay();
            }

            Button {
                id: idStopButton
                text: qsTr("停止")
                Layout.fillWidth: true
                onClicked: idMusicPlayer.stopPlay();
            }

            Button {
                id: idOpenButton
                text: qsTr("打开")
                Layout.fillWidth: true
                onClicked : {
                    idFileDialog.visible = true
                }
            }

        }

        Flickable {

            Layout.fillWidth: true
            Layout.fillHeight: true

            id: idFlick

            width: 300; height: 200;
            contentWidth: idTextArea.paintedWidth
            contentHeight: idTextArea.paintedHeight
            clip: true

            function ensureVisible(r) {
                if (contentX >= r.x)
                    contentX = r.x;
                else if (contentX+width <= r.x+r.width)
                    contentX = r.x+r.width-width;
                if (contentY >= r.y)
                    contentY = r.y;
                else if (contentY+height <= r.y+r.height)
                    contentY = r.y+r.height-height;
            }

            TextArea{
                id : idTextArea
                mouseSelectionMode :TextEdit.SelectCharacters
                selectByMouse : true
                readOnly: true
            }

        }

    }


}/*~Rectangle*/



