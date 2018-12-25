/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12
import sstd.audio 1.0

Rectangle {

    id : idRoot
    width: 640;
    height: 64;
    color: Qt.rgba(0.8,0.8,0.8,1);

    MusicPlayer{
        id : idMusicPlayer
    }

    ColumnLayout {
       anchors.fill: parent;
       anchors.margins: 8

        ProgressBar {
            id: idProgressBar
            value: 0.5
            Layout.fillWidth: true
        }

        RowLayout {

            Button {
                id: idStartButton
                text: qsTr("开始")
                Layout.fillWidth: true
                onClicked: idMusicPlayer.startPlay();
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
            }

        }
    }


}/*~Rectangle*/



