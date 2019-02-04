#pragma once

#include <QtGui/QtGui>
#include <QtQml/QtQml>
#include <QtCore/QtCore>
#include <QtQuick/QtQuick>
#include <sstd_library.hpp>
#include "sstd_private/sstd_qquickview_resize.hpp"
#include "sstd_private/sstd_qquickwidget_resize.hpp"
#include "sstd_private/sstd_qmlapplicationengine.hpp"
#include "../global/sstd_qt_and_qml_global.hpp"
#include <QtQuick/qquickview.h>
#include <QtQuickWidgets/qquickwidget.h>
#include <QtWidgets/qopenglwidget.h>

namespace sstd {
    Q_NAMESPACE

    enum class WindowType : std::size_t {
        QtQuickWindow,
        QtWidget,
    };
    Q_ENUM_NS(WindowType)

    enum class ResizeMode : std::size_t {
        SizeViewToRootObject,
        SizeRootObjectToView,
    };
    Q_ENUM_NS(ResizeMode)

    enum class LoadState : std::size_t {
        Null,
        Ready,
        Loading,
        Error,
    };
    Q_ENUM_NS(LoadState)

    class EXPORT_SSTD_QT_AND_QML_LIBRARY AbstractRootWindow :
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(AbstractRootWindow) {
    public:
        virtual WindowType getWindowType() const = 0;
        virtual QObject * getObject() const = 0;
        virtual void setResizeMode(sstd::ResizeMode) = 0;
        virtual void load(const QUrl &) = 0;
        virtual sstd::LoadState status() const = 0;
        virtual void setTitle(const QString &) = 0;
        virtual void setClearColor(const QColor &) = 0;
        virtual void show() = 0;
        virtual void setX(int) = 0;
        virtual void setY(int) = 0;
        virtual QQuickWindow * getQuickWindow() const = 0;
        virtual QQmlEngine * getEngine() const = 0;
        virtual QQmlContext * getRootContext() const = 0;
        virtual QQuickItem * getRootObject() const = 0;
        virtual ~AbstractRootWindow();
        SSTD_END_DEFINE_VIRTUAL_CLASS(AbstractRootWindow);
    };

    template <WindowType>
    class _RootWindow;

    namespace _private_sstd {

        class EXPORT_SSTD_QT_AND_QML_LIBRARY _WindowPrivate :
            public _sstd1::_3_private_api::ResizeQuickView,
            public AbstractRootWindow,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_WindowPrivate){
            Q_OBJECT
        public:
            Q_SLOT void setResizeMode(sstd::ResizeMode) override;
            Q_SLOT void load(const QUrl &) override;
            Q_SLOT sstd::LoadState status() const override;
            Q_SLOT void setTitle(const QString &) override;
            Q_SLOT void setClearColor(const QColor &) override;
            Q_SLOT void show() override;
            Q_SLOT void setX(int) override;
            Q_SLOT void setY(int) override;
            Q_SLOT QObject * getObject() const override;
            Q_SLOT QQuickWindow * getQuickWindow() const override;
            Q_SLOT WindowType getWindowType() const override {
                return WindowType::QtQuickWindow;
            }
            Q_SLOT QQmlEngine * getEngine() const override;
            Q_SLOT QQmlContext * getRootContext() const override;
            Q_SLOT QQuickItem * getRootObject() const override;
            _WindowPrivate();
            using PureRootWindow = QOpenGLWindow;
        private:
            using Super = _sstd1::_3_private_api::ResizeQuickView;
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(_WindowPrivate);
        };

        class EXPORT_SSTD_QT_AND_QML_LIBRARY _WidgetPrivate :
            public _sstd1::_3_private_api::ResizeQuickWiget ,
            public AbstractRootWindow,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_WidgetPrivate){
            Q_OBJECT
        public:
            Q_SLOT void setResizeMode(sstd::ResizeMode) override;
            Q_SLOT void load(const QUrl &) override;
            Q_SLOT sstd::LoadState status() const override;
            Q_SLOT void setTitle(const QString &) override;
            Q_SLOT void setClearColor(const QColor &) override;
            Q_SLOT void show() override;
            Q_SLOT void setX(int) override;
            Q_SLOT void setY(int) override;
            Q_SLOT QObject * getObject() const override;
            Q_SLOT QQuickWindow * getQuickWindow() const override;
            Q_SLOT WindowType getWindowType() const override {
                return WindowType::QtWidget;
            }
            Q_SLOT QQmlEngine * getEngine() const override;
            Q_SLOT QQmlContext * getRootContext() const override;
            Q_SLOT QQuickItem * getRootObject() const override;
            _WidgetPrivate();
            using PureRootWindow = QOpenGLWidget;
        private:
            using Super = _sstd1::_3_private_api::ResizeQuickWiget ;
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(_WidgetPrivate);
        };
    }

    template <>
    class _RootWindow<WindowType::QtWidget> {
    public:
        using type = _private_sstd::_WidgetPrivate;
    };

    template <>
    class _RootWindow<WindowType::QtQuickWindow> {
    public:
        using type = _private_sstd::_WindowPrivate;
    };

    template<WindowType St>
    using RootWindow = typename _RootWindow<St>::type ;

#if defined(_DEBUG)/*选择使用QQuickWidget还是QQuickView作为显示窗口*/
    using DefaultRoowWindow = RootWindow<sstd::WindowType::QtWidget> ;
#else
    using DefaultRoowWindow = RootWindow<sstd::WindowType::QtQuickWindow> ;
#endif

    using QmlApplicationEngine =
    _sstd1::_3_private_api::QmlApplicationEngine ;

}/*namespace sstd*/
