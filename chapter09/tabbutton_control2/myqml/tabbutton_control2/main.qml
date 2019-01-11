/*tabbutton_control2/main.qml*/
import QtQuick 2.9
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Pane {
    id : idRoot
    width: 640;
    height: 480;

    ColumnLayout{
        anchors.fill: parent
        TabButton{
            text: qsTr( "Good!" )
            Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
            onClicked: {
                console.log(qsTr("Clicked!"))
            }
        }
    }

}

/*endl_input_of_latex_for_clanguage_lick*/
/*TabButton是TabBar的一个组件*/

