/*switchdelegate_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ListView {
        anchors.fill: parent
        model: [
            QT_TR_NOOP("Option 1"),
            QT_TR_NOOP("Option 2"),
            QT_TR_NOOP("Option 3")]
        delegate: SwitchDelegate {
            text: modelData
        }
    }

}




