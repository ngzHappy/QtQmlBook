import QtQuick 2.9
import QtQuick.Controls 2.3

MenuBar {

    id : idRoot
    Menu {
        title: qsTr("菜单")

        MenuItem{
            text: qsTr("重置")
            onTriggered:{
                idRoot.toResetAction();
            }
        }

    }

    signal toResetAction();

}

