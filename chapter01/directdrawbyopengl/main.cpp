#include <sstd_qt_and_qml_library.hpp>
#include "DrawImageItem.hpp"

int main(int argc, char ** argv) {

    /*初始化程序*/
    auto varApp = sstd_make_unique< sstd::Application >(argc, argv);
    /*初始化Qml/Quick引擎*/
    auto varWindow = sstd_make_unique< sstd::DefaultRoowWindow >();
    {
        /*获得Qml文件绝对路径*/
        auto varFullFileName = sstd::getLocalFileFullPath(
            QStringLiteral("myqml/directdrawbyopengl/main.qml"));

        /*加载Qml文件*/
        varWindow->load(varFullFileName);
        /*检查并报错*/
        if (varWindow->status() != sstd::LoadState::Ready) {
            qWarning() << QStringLiteral("can not load : ") << varFullFileName;
            return -1;
        }

    }

    varWindow->show();

    {   
        /*运行时由C++端添加对象*/
        auto varRootObject = varWindow->getRootObject();
        assert(varRootObject);
        assert(varRootObject->objectName() == QStringLiteral("root_object"));
        auto varItem = sstd_new<DrawImageItem>();
        varItem->setParent(varRootObject);
        const auto varImage = QImage(sstd::getLocalFileFullFilePath(
            QStringLiteral("myqml/directdrawbyopengl/0000.jpg")));
        varItem->setImage(varImage);
        varItem->setWidth(360);
        varItem->setHeight(256);
        varItem->setTransformOrigin(QQuickItem::Center);
        varItem->setRotation(45);
        varItem->setParentItem(varRootObject);
    }

    {
        /*运行时由C++编译QML对象*/
        const auto varQmlCode = u8R"+++(

import QtQuick 2.9
import sstd.quick 1.0

DrawImageItemRaw { 

    width: 256                             ;
    height: 256                            ;
    rawImage : Qt.resolvedUrl( "0000.jpg" );
    anchors.bottom: parent.bottom          ;
    anchors.right : parent.right           ;

}

)+++"sv;

        QQmlComponent varComponent{ varWindow->getEngine() };
        auto varContex = QQmlEngine::contextForObject( varWindow->getRootObject() );
        varComponent.setData(   
            QByteArray( varQmlCode.data(),static_cast<int>(varQmlCode.size()) ),
            varContex->baseUrl()
        );
        auto varObject = sstd_runtime_cast<DrawImageItem>(
            varComponent.beginCreate( varContex ) );
        assert(varObject);
        varObject->setParent(varWindow->getRootObject());
        varObject->setParentItem(varWindow->getRootObject());
        varComponent.completeCreate();

    }

    return varApp->exec();

}

