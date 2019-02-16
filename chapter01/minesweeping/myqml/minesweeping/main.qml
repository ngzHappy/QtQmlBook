/*minesweeping/main.qml*/
import QtQuick 2.9
import sstd.minesweeping 1.0
import QtQuick.Controls 2.12

Pane {

    id : idRootOfMine

    padding: 0
    topInset: 0
    leftInset: 0
    rightInset: 0
    bottomInset: 0

    width: 640;
    height: 480;

    MineResetDialog{/*重置对话框*/
        id: idResetActionDialog ;
        onResizeMine : {
            idMineSweeping.setSizeScene(
                        rowAndColumn,
                        rowAndColumn,
                        mineSize);
        }
    }

    MineMenuBar{/*菜单*/
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

        maskItem : Rectangle {/*遮罩*/
            anchors.centerIn: parent       ;
            width: parent.width * 0.95     ;
            height: parent.height * 0.95   ;
            color: Qt.rgba( 0.45,0.46,0.47,0.5 ) ;
            Behavior on opacity{
                NumberAnimation{
                    duration: 333
                }
            }
            Behavior on width{
                NumberAnimation{
                    duration: 25
                }
            }
            Behavior on height{
                NumberAnimation{
                    duration: 25
                }
            }
        }

        flagItem : Flag{/*地雷标记*/
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

        numberItem : Number{/*数字*/
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

        errorItem : Error{/*识别错误标记*/
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

        mineItem : Mine{/*未识别的地雷*/
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

        okMineItem : OkMine{/*正确识别的地雷*/
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

        boomItem : Boom {/*引爆的地雷*/
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

        winItem : Win {/*游戏成功时现实*/
            anchors.centerIn: parent
            width:idRootOfMine.width * 0.85
            height:idRootOfMine.height
        }

    }

}/*~Pane*/
