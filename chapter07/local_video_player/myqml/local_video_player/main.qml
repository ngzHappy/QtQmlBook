/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.3
import sstd.video 1.0

Pane {

    id: idRoot
    width: 640
    height: 640

    VideoPlayer {
        id: idVideoPlayer
        volume: idVolume.value
    }

    function openPlayerFile(fileUrl) {
        idUrl.text = fileUrl
    }

    FileDialog {
        id: idFileDialog
        title: qsTr("选择媒体文件")
        selectExisting: true
        selectFolder: false
        selectMultiple: false
        onAccepted: {
            openPlayerFile(fileUrl.toLocaleString())
        }
        onRejected: {

        }
        //nameFilters: [ "Image files (*.jpg *.png)", "All files (*)" ]
        Component.onCompleted: {
            idFileDialog.folder = "TestAudio"
        }
    }

    Timer {
        interval: 1000
        repeat: true
        triggeredOnStart: false
        running: true
        onTriggered: {

        }
    }

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 8

        ProgressBar {
            id: idProgressBar
            value: 0.0
            Layout.fillWidth: true
            MouseArea {
                anchors.fill: parent
                acceptedButtons: Qt.LeftButton
                onClicked: {

                }
            }
        }

        TextField {
            Layout.fillWidth: true
            id: idUrl
        }

        RowLayout {

            Button {
                id: idStartButton
                text: qsTr("开始")
                Layout.fillWidth: true
                onClicked: {}
            }

            Button {
                id: idPauseButton
                text: qsTr("暂停")
                Layout.fillWidth: true
                onClicked: {}
            }

            Button {
                id: idContinueButton
                text: qsTr("继续")
                Layout.fillWidth: true
                onClicked: {}
            }

            Button {
                id: idStopButton
                text: qsTr("停止")
                Layout.fillWidth: true
                onClicked: {}
            }

            Button {
                id: idOpenButton
                text: qsTr("打开")
                Layout.fillWidth: true
                onClicked: {

                }
            }
        }

        Flickable {

            Layout.fillWidth: true
            Layout.fillHeight: true

            id: idFlick

            width: 300
            height: 200
            contentWidth: idTextArea.paintedWidth
            contentHeight: idTextArea.paintedHeight
            clip: true

            function ensureVisible(r) {
                if (contentX >= r.x){
                    contentX = r.x
                }
                else if (contentX + width <= r.x + r.width) {
                    contentX = r.x + r.width - width
                }
                if (contentY >= r.y){
                    contentY = r.y
                }
                else if (contentY + height <= r.y + r.height){
                    contentY = r.y + r.height - height
                }
            }

            TextArea {
                id: idTextArea
                mouseSelectionMode: TextEdit.SelectCharacters
                selectByMouse: true
                readOnly: true
                width: parent.width
            }
        }
    }

    Slider {
        id: idVolume
        orientation: Qt.Vertical
        height: parent.height * 0.75
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        value: 0.5
    }
} /*~Rectangle*/
