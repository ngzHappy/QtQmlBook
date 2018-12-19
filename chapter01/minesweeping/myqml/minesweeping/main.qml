/*main.qml*/
import QtQuick 2.9
import sstd.minesweeping 1.0

Rectangle {

    width: 640;
    height: 480;
    color: Qt.rgba(0.3,0.3,0.38,1);

    MineResetDialog{
        id: idResetActionDialog ;
        /*(int rowAndColumn,int mineSize);*/
        onResizeMine : {
            idMineSweeping.setSizeScene(
                        rowAndColumn,
                        rowAndColumn,
                        mineSize);
        }
    }

    MineMenuBar{
        id : idMenuBar
        width: parent.width ;
        anchors.top: parent.top ;
        anchors.left: parent.left ;
        onToResetAction: {
            idResetActionDialog.open() ;
        }
    }

    MineSweeping{

        id : idMineSweeping

        anchors.centerIn: parent;
        property double minWidthHeight:
            Math.min( parent.height , parent.width );
        width: minWidthHeight * 0.8;
        height: minWidthHeight * 0.8;

        maskItem : Rectangle {
            anchors.centerIn: parent       ;
            width: parent.width * 0.95     ;
            height: parent.height * 0.95   ;
            color: Qt.rgba(0.2,0.22,0.22,1);
            Behavior on opacity{
                NumberAnimation{
                    duration: 333
                }
            }
            Behavior on width{
                NumberAnimation{
                    duration: 33
                }
            }
            Behavior on height{
                NumberAnimation{
                    duration: 33
                }
            }
        }

        flagItem : Flag{
            anchors.centerIn: parent ;
            width  : parent.width * 0.75 ;
            height : parent.height * 0.75 ;
            Behavior on width{
                NumberAnimation{
                    duration: 33
                }
            }
            Behavior on height{
                NumberAnimation{
                    duration: 33
                }
            }
        }

        numberItem : Number{
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
            Behavior on width{
                NumberAnimation{
                    duration: 33
                }
            }
            Behavior on height{
                NumberAnimation{
                    duration: 33
                }
            }
        }

        errorItem : Error{
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
            Behavior on width{
                NumberAnimation{
                    duration: 33
                }
            }
            Behavior on height{
                NumberAnimation{
                    duration: 33
                }
            }
        }

        mineItem : Mine{
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
            Behavior on width{
                NumberAnimation{
                    duration: 33
                }
            }
            Behavior on height{
                NumberAnimation{
                    duration: 33
                }
            }
        }

        okMineItem : OkMine{
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
            Behavior on width{
                NumberAnimation{
                    duration: 33
                }
            }
            Behavior on height{
                NumberAnimation{
                    duration: 33
                }
            }
        }

        boomItem : Boom {
            anchors.centerIn: parent ;
            width  : parent.width * 0.9 ;
            height : parent.height * 0.9 ;
            Behavior on width{
                NumberAnimation{
                    duration: 33
                }
            }
            Behavior on height{
                NumberAnimation{
                    duration: 33
                }
            }
        }

    }

}/*~Rectangle*/



