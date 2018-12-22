/*ListView 的代理*/
import QtQuick 2.11
import QtQuick.Controls 2.3
import myqml.affectors 1.0

Item{

    height: 32 ;

    Button {

        id : _id_button
        width: parent.width - 2 ;
        height: parent.height  -2 ;
        anchors.centerIn: parent
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

}



