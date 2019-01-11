import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Slider{
    id : idSlider
    property bool inValueChangeRange : false
    property variant posWhenValueChange: null ;
    property variant oldPosWhenValueChange : null ;
    onValueChanged: {
        inValueChangeRange = true;
        var varTimeObject = new Date() ;
        posWhenValueChange = varTimeObject.getTime();
        varTimeObject=null;
        oldPosWhenValueChange = posWhenValueChange;
    }
    function checkIfInValueChangeRange(){
        var varTimeObject = new Date() ;
        posWhenValueChange = varTimeObject.getTime();
        varTimeObject=null;
        if( (posWhenValueChange - oldPosWhenValueChange)>1000 ){
            inValueChangeRange = false
        }else{
            inValueChangeRange = true
        }
    }
    Timer{
        interval : 600
        repeat : true
        running : idSlider.inValueChangeRange
        triggeredOnStart : false
        onTriggered: {
            idSlider.checkIfInValueChangeRange();
        }
    }
    ToolTip {
        parent: idSlider.handle
        visible: idSlider.hovered || idSlider.inValueChangeRange
        text: idSlider.value.toFixed(2)
    }
}


















