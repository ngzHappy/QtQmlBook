#include <QtGui/QtGui>
#include <QtQuick/QtQuick>
#include <QtWidgets/QtWidgets>
#include <QtQuickWidgets/QtQuickWidgets>

inline QUrl getLocalFileFullPath(
    const QString & argFileName,
    const QString & argBase) {
    const QDir varRootDir{ argBase };
    const auto varAns = varRootDir.absoluteFilePath(argFileName);
    if (varAns.startsWith(QChar('/'))) {
        return QStringLiteral(R"(file://)") + varAns;
    } else {
        return QStringLiteral(R"(file:///)") + varAns;
    }
}

inline QSurfaceFormat getDefaultQSurfaceFormat() {
    auto varFormat = QSurfaceFormat::defaultFormat();
    varFormat.setVersion(4, 6);
    varFormat.setProfile(QSurfaceFormat::CoreProfile);
    varFormat.setSamples(4);
    varFormat.setAlphaBufferSize(8);
    varFormat.setBlueBufferSize(8);
    varFormat.setRedBufferSize(8);
    varFormat.setGreenBufferSize(8);
    varFormat.setDepthBufferSize(24);
    varFormat.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    varFormat.setRenderableType(QSurfaceFormat::OpenGL);
    varFormat.setSwapInterval(0)/*关闭垂直同步*/;
#if defined(ENABLE_GL_DEBUG)
    varFormat.setOption(QSurfaceFormat::DebugContext, true);
#else
    varFormat.setOption(QSurfaceFormat::DebugContext, false);
#endif
    return varFormat;
}

inline void beforeApplication() {
    {
        /*初始化随机种子*/
        ::srand(static_cast<unsigned>(::time(nullptr)));
    }
    {
        /*高分屏支持*/
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    }
    {
        /*设置默认opengl环境*/
        QSurfaceFormat::setDefaultFormat(::getDefaultQSurfaceFormat());
    }
}

inline void afterApplication() {
    {
        QImage varImage{QStringLiteral("test.png")};
        (void)varImage;
    }
}

#define QML_USE_WINDOW_TYPE (1u)

int main(int argc, char ** argv) {

    if constexpr (QML_USE_WINDOW_TYPE == 1) {
        beforeApplication();
        QGuiApplication varApp{ argc,argv };
        afterApplication();
        QQuickView varView;
        varView.setResizeMode(QQuickView::ResizeMode::SizeViewToRootObject);
#ifdef _DEBUG
        varView.setSource(
            getLocalFileFullPath(
                QStringLiteral("myqml/firstapplication/main1.qml"),
                CURRENT_DEBUG_PATH));
#else
        varView.setSource(
            getLocalFileFullPath(
                QStringLiteral("myqml/firstapplication/main1.qml"),
                qApp->applicationDirPath()));
#endif
        if (varView.status() != QQuickView::Status::Ready) {
            qWarning() << QStringLiteral("can not load : main1.qml");
            return -1;
        }
        varView.show();
        return varApp.exec();
    } else if constexpr (QML_USE_WINDOW_TYPE == 2) {
        beforeApplication();
        QApplication varApp{ argc,argv };
        afterApplication();
        QQuickWidget varWidget;
        varWidget.setResizeMode(QQuickWidget::ResizeMode::SizeViewToRootObject);
#ifdef _DEBUG
        varWidget.setSource(getLocalFileFullPath(
            QStringLiteral("myqml/firstapplication/main2.qml"),
            CURRENT_DEBUG_PATH));
#else
        varWidget.setSource(getLocalFileFullPath(
            QStringLiteral("myqml/firstapplication/main2.qml"),
            qApp->applicationDirPath()));
#endif
        if (varWidget.status() != QQuickWidget::Status::Ready) {
            qWarning() << QStringLiteral("can not load : main2.qml");
            return -1;
        }
        varWidget.show();
        return varApp.exec();
    } else {
        beforeApplication();
        QGuiApplication varApp{ argc,argv };
        afterApplication();
#ifdef _DEBUG
        QQmlApplicationEngine varEngine(getLocalFileFullPath(
            QStringLiteral("myqml/firstapplication/main3.qml"),
            CURRENT_DEBUG_PATH));
#else
        QQmlApplicationEngine varEngine(getLocalFileFullPath(
            QStringLiteral("myqml/firstapplication/main3.qml"),
            qApp->applicationDirPath()));
#endif
        if (varEngine.rootObjects().isEmpty()) {
            qWarning() << QStringLiteral("can not load : main3.qml");
            return -1;
        }
        return varApp.exec();
    }

}

















