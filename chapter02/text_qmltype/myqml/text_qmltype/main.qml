/*main.qml*/
import QtQuick 2.9

Rectangle {

    id : idRoot
    width: 640;
    height: 480;
    color: Qt.rgba(0.5,0.5,0.5,1);

    Column{

        Text{
            id : idText
            text: "Hello World!"
            font.pointSize: 64
            color: "red"
        }

        Text{
            text: "See the <a href=\"http://qt-project.org\">Qt Project website</a>.";
            font.pointSize: 24
            onLinkActivated: {
                Qt.openUrlExternally( link );
            }
        }

        Row {
            Text { font.pointSize: 24; text: "Normal " }
            Text { font.pointSize: 24; text: "Raised ";
                style: Text.Raised; styleColor: "#AAAAAA" }
            Text { font.pointSize: 24; text: "Outline ";
                style: Text.Outline; styleColor: "red" }
            Text { font.pointSize: 24; text: "Sunken ";
                style: Text.Sunken; styleColor: "#AAAAAA" }
        }

        Item{
            width: idText.width
            height: idText.height

            ShaderEffectSource{
                id : idShaderEffectSource
                anchors.fill: parent;
                sourceItem  : idText
                hideSource  : false
                samples     : 4
                format      : ShaderEffectSource.RGBA
                visible     : false
            }

            ShaderEffect{
                property variant source: idShaderEffectSource
                anchors.fill: parent ;
                fragmentShader:"
/*片段着色器*/
#version 460

in vec2 qt_TexCoord0;

out vec4 fragColor;

uniform sampler2D source;
uniform float qt_Opacity;

void main() {

    vec4 varColor =
        texture(source, qt_TexCoord0) * qt_Opacity;

    if(varColor.a > 0.25 ){
        fragColor.r = qt_TexCoord0.x ;
        fragColor.g = qt_TexCoord0.y ;
        fragColor.b = 0.0            ;
        fragColor.a = 1              ;
    } else {
        fragColor = vec4( 
            0 , 
            0 , 
            0 , 
            0 );
    }

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

        Text{
            id : idTextLayer
            antialiasing: true
            text: "Hello World!"
            font.pointSize: 64
            color: "red"
            layer.enabled: true
            layer.effect: ShaderEffect {
                fragmentShader: "
/*片段着色器*/
#version 460

in vec2 qt_TexCoord0;
uniform sampler2D source;/*THIS ITEM*/
uniform float qt_Opacity;
out vec4 fragColor;

void main() {

    vec4 varColor =
        texture(source, qt_TexCoord0) * qt_Opacity;

    if(varColor.a > 0.25 ){
        fragColor.r = clamp( 1.0 - qt_TexCoord0.x * qt_TexCoord0.x , 0 , 1 ) ;
        fragColor.g = clamp( 1.0 - qt_TexCoord0.y * qt_TexCoord0.y , 0 , 1 );
        fragColor.b = 0.0                  ;
        fragColor.a = 1                    ;
    } else {
        fragColor = vec4( 0 , 0 , 0 , 0 );
    }

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


    }/*Column*/



}/*~Rectangle*/



