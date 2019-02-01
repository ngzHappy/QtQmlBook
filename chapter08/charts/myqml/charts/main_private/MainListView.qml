/*ListView*/
import QtQuick 2.11

ListView {
    id : _id_list_view ;

    delegate : MainListItem {
        width: parent.width -
               ( _id_scrollbar.visible *
                _id_scrollbar.width ) ;
    }

    model: MainListModel {
    }

    /*ListView的滚动条*/
    Rectangle {

        id: _id_scrollbar
        anchors.right: _id_list_view.right ;
        width: 10 ;
        height: _id_list_view.height ;
        color: "#ccbfbf"
        radius: 10
        visible: _id_list_view.visibleArea.heightRatio < 0.999 ;

        /*按钮*/
        Rectangle {
            id: _id_button
            x: 0
            y: _id_list_view.visibleArea.yPosition *
               _id_scrollbar.height
            width: 10
            height: _id_list_view.visibleArea.heightRatio *
                    _id_scrollbar.height;
            color: "#818b81"
            radius: 10

            /*鼠标区域*/
            MouseArea {
                id: _id_mouseArea
                anchors.fill: _id_button
                drag.target: _id_button
                drag.axis: Drag.YAxis
                drag.minimumY: 0
                drag.maximumY: _id_scrollbar.height -
                               _id_button.height

                /*拖动*/
                onMouseYChanged: {
                    _id_list_view.contentY = _id_button.y /
                            _id_scrollbar.height *
                            _id_list_view.contentHeight
                }
            }
        }
    }/*Rectangle*/

}/*ListView*/






