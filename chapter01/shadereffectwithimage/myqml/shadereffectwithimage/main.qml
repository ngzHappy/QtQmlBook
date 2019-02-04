/*shadereffectwithimage/main.qml*/
import QtQuick 2.9

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Rectangle{
        anchors.centerIn: parent    ;
        width: parent.width * 0.8   ;
        height: parent.height * 0.8 ;
        Image{
            id : idSourceImage;
            source: "0000.jpg";
            visible: false    ;
        }
        ShaderEffect{
            property variant source: idSourceImage/*the image...*/
            anchors.fill: parent ;
            fragmentShader:"
/*片段着色器*/
#version 460

in vec2 qt_TexCoord0;

out vec4 fragColor;

uniform sampler2D source/*the image...*/;
uniform float qt_Opacity;

void main() {
    fragColor = texture(source, qt_TexCoord0) * qt_Opacity;
}

"
            vertexShader :"
/*顶点着色器*/
#version 460

in vec4 qt_Vertex;
in vec2 qt_MultiTexCoord0;

out vec2 qt_TexCoord0;

uniform mat4 qt_Matrix;

void main() {
    qt_TexCoord0 = qt_MultiTexCoord0;
    gl_Position = qt_Matrix * qt_Vertex;
}

"
        }
    }

}/*~Rectangle*/
