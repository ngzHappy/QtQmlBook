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

    {   /*运行时由C++端添加对象*/
        auto varRootObject = varWindow->getRootObject();
        assert(varRootObject);
        assert(varRootObject->objectName() == QStringLiteral("root_object"));
        auto varItem = sstd_new<DrawImageItem>();
        varItem->setParent(varRootObject);
        const auto varImage = QImage(sstd::getLocalFileFullFilePath(
            QStringLiteral("myqml/directdrawbyopengl/0000.jpg")));
        varItem->setImage(varImage);
        varItem->setWidth(varRootObject->width() / 2);
        varItem->setHeight(varRootObject->height() / 2);
        varItem->setTransformOrigin(QQuickItem::Center);
        varItem->setRotation(45);
        varItem->setParentItem(varRootObject);
    }

    return varApp->exec();

}

