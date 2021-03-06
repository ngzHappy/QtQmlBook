﻿///*texteditdeep/main.qml*/
import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import sstd.textarea.help 1.0

Pane {
    id : idRoot
    width: 640;
    height: 480;

    Flickable {
        id: idFlickable
        flickableDirection: Flickable.VerticalFlick
        anchors.fill: parent

        ScrollBar.vertical: ScrollBar {
        }

        TextArea.flickable: TextArea {
            id: idTextArea
            textFormat: Qt.RichText
            wrapMode: TextArea.Wrap
            focus: true
            selectByMouse: true
            persistentSelection: true

            leftPadding: 6
            rightPadding: 6
            topPadding: 6
            bottomPadding: 0
            background: TextAreaHelper {
                textArea: idTextArea
                flickable: idFlickable
                document: idTextArea.textDocument
                blockBackground: Rectangle{
                    border.width: 1
                    border.color: Qt.rgba(0,0,0,1)
                    color: Qt.rgba(1,1,1,0)
                }
            }

            MouseArea {
                acceptedButtons: Qt.RightButton
                anchors.fill: parent
                onClicked: idContextMenu.open()
            }

            onLinkActivated: Qt.openUrlExternally(link)
        }

    }

    Component.onCompleted: {
        for(var i =0;i<100;++i){
            idTextArea.append( "行：%1".arg(i) );
        }
    }

    Menu {
        id: idContextMenu

        MenuItem {
            text: qsTr("复制")
            enabled: idTextArea.selectedText
            onTriggered: idTextArea.copy()
        }

        MenuItem {
            text: qsTr("剪贴")
            enabled: idTextArea.selectedText
            onTriggered: idTextArea.cut()
        }

        MenuItem {
            text: qsTr("黏贴")
            enabled: idTextArea.canPaste
            onTriggered: idTextArea.paste()
        }

    }

}
