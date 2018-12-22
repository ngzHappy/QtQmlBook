import QtQuick 2.11
import QtQuick.Particles 2.0

DemoBasic {

    property int indexOfPoint : 0 ;

    function getPointPosition( ){
        switch(indexOfPoint++){
        case 0 :return Qt.point(0,0);
        }
        indexOfPoint=0;
        return getPointPosition( );
    }




    Timer{
        interval: 200 ;
        repeat: true ;
        running: true;
        triggeredOnStart: true;
        onTriggered: {
            var varPoint =
                    getPointPosition();
        }
    }

}

















