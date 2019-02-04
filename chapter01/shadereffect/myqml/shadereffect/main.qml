/*shadereffect/main.qml*/
import QtQuick 2.9

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.8,0.8,0.8,1);

    Rectangle{
        anchors.centerIn: parent    ;
        width: parent.width * 0.8   ;
        height: parent.height * 0.8 ;
        ShaderEffect{
            anchors.fill: parent ;
            fragmentShader:"
/*片段着色器*/
#version 460

in vec2  qt_TexCoord0/*纹理坐标*/  ;
out vec4 fragColor   /*输出值*/    ;

uniform float qt_Opacity/*透明度*/ ;

void main() {
    vec4 varColor  = vec4( qt_TexCoord0.x ,  qt_TexCoord0.y , 0.5 , 1);
    fragColor = varColor * qt_Opacity;
}

"
            vertexShader :"
/*顶点着色器*/
#version 460

in vec4 qt_Vertex/*输入点坐标*/    ;
out vec2 qt_TexCoord0/*纹理坐标*/  ;

uniform mat4 qt_Matrix/*投影矩阵*/ ;

void main() {
    gl_Position = qt_Matrix * qt_Vertex;
    qt_TexCoord0 = gl_Position.xy*0.5 + 0.5 ;
}

"
        }
    }

}/*~Rectangle*/
