/*chatview/main.qml*/
import QtQuick 2.11
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12
import QtQml.Models 2.12
import sstd.chat.help 1.0

ApplicationWindow {
    id : idRoot
    width: 640;
    height: 640;
    visible: true

    minimumHeight : 256
    minimumWidth :  256

    ListView{
        anchors.fill : parent
        model: ObjectModel{

            LeftChatView{
                width: idRoot.width
                thisChatItem: ChatDataItem{
                    title: "A"
                    bodyItems:["x",
                    "<img width=24 height=24
                    src='image://placeholderimageprovider/GifItem.qml'>"]
                }
            }

            RightChatView{
                width: idRoot.width
                thisChatItem: ChatDataItem{
                     title: "Me"
                     bodyItems:["x",
                     "<img width=24 height=24
                     src='image://placeholderimageprovider/GifItem.qml'>"]
                }
            }

            LeftChatView{
                width: idRoot.width
                thisChatItem: ChatDataItem{
                     title: "B"
                     bodyItems:["x",
                     "<img width=24 height=24
                     src='image://placeholderimageprovider/GifItem.qml'>"]
                }
            }

            RightChatView{
                width: idRoot.width
                thisChatItem: ChatDataItem{
                     title: "Me"
                     bodyItems:["x",
                     "test test test test test test test
                     test test test test test test test test ",
                     "<img width=24 height=24
                     src='image://placeholderimageprovider/GifItem.qml'>"]
                }
            }

        }
    }

}
