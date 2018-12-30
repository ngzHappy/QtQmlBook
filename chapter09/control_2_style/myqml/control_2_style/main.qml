﻿/*main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12 as Controls2
import QtQuick.Controls.Material 2.12 as Style2

Controls2.Pane {

    id : idRoot
    width: 256;
    height: 128;
    Style2.Material.theme : idSpinBox.Style2.Material.theme;

    Controls2.SpinBox {
        id : idSpinBox
        onValueChanged: {
            if(value&1){
                Style2.Material.theme=Style2.Material.Dark
            }else{
                Style2.Material.theme=Style2.Material.Light
            }
        }
    }

    Component.onCompleted: {
        idSpinBox.value = 3 ;
    }

}












