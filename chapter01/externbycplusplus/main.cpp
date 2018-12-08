#include <sstd_qt_and_qml_library.hpp>

int main(int argc, char ** argv) {

    /*初始化程序*/
    auto varApp = sstd_make_unique< sstd::Application >(argc, argv);
    /*初始化Qml/Quick引擎*/
    auto varWindow = sstd_make_unique< sstd::DefaultRoowWindow >();
    {
        /*获得Qml文件绝对路径*/
        auto varFullFileName = sstd::getLocalFileFullPath(
            QStringLiteral("myqml/externbycplusplus/main.qml"));
        /*装载图像加载器*/
        auto varImageProvider = sstd::QuickMemoryImage::getQuickImageProvider();
        varWindow->getEngine()->addImageProvider(
            varImageProvider.first, varImageProvider.second);
        /*加载Qml文件*/
        varWindow->load(varFullFileName);
        /*检查并报错*/
        if (varWindow->status() != sstd::LoadState::Ready) {
            qWarning() << QStringLiteral("can not load : ") << varFullFileName;
            return -1;
        }
        /*从Qml端获得对象*/
        auto varRootItem = varWindow->getRootObject();
        auto varImageObject = varRootItem->findChild<sstd::QuickMemoryImage*>(
            QStringLiteral("quick_memory_image"));
        assert(varImageObject);
        /*设置测试图片*/
        QImage varTestImage{ 128 , 512 ,QImage::Format_RGBA64_Premultiplied };
        varTestImage.fill(QColor(QRgba64::fromRgba64(1, 32215, 5535, 65535)));
        varImageObject->setImage(varTestImage);
    }
    varWindow->show();

    return varApp->exec();

}

