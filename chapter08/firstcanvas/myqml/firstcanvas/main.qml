/*main.qml*/
import QtQuick 2.9

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Canvas{
        anchors.fill: parent ;
        renderTarget: Canvas.Image ;
        renderStrategy: Canvas.Threaded ;
        property color drawFillColor:
            Qt.rgba(
                Math.random() * 0.5,
                Math.random() * 0.5,
                Math.random() * 0.5,
                1);
        onPaint: {
            var ctx = getContext("2d");
            ctx.fillStyle = drawFillColor;
            ctx.beginPath();
            ctx.arc(idRoot.width * 0.5 ,
                    idRoot.height * 0.5 ,
                    Math.min(idRoot.width,
                             idRoot.height)
                    * 0.5 ,
                    0, Math.PI * 2 ,
                    true );
            ctx.closePath();
            ctx.fill();
        }
    }

}/*~Rectangle*/
