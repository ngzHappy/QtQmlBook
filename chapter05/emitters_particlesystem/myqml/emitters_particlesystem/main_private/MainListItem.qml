/*ListView 的代理*/
import QtQuick 2.11
import QtQuick.Controls 2.3
import myqml.emitters 1.0

Button {

    id : _id_button
    height: 32 ;
    text : programName ;

    function loadSourceFunction(){
        var obj = LocalQmlWindowCreator.createRootView(programName,Qt.resolvedUrl( programSource ) );
        if(obj){
            obj.show();
        }
    }/*loadSourceFunction*/

    onClicked : {
        loadSourceFunction();
    }

}/*Button*/





