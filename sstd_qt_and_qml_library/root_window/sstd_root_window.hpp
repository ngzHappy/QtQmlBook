#pragma once

#include "../sstd_qt_and_qml_library.hpp"
#include "sstd_private/sstd_quick_view_widget.hpp"
#include "sstd_private/sstd_quick_view_window.hpp"

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
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(AbstractRootWindow){
    public:
        virtual WindowType getWindowType() const=0;
        virtual QObject * getObject() const =0;
        virtual void setResizeMode(sstd::ResizeMode)=0;
        virtual void load(const QUrl &)=0;
        virtual sstd::LoadState status() const=0;
        virtual void setTitle(const QString &)=0;
        virtual void setClearColor(const QColor &)=0;
        virtual void show()=0;
        virtual void setX(int)=0;
        virtual void setY(int)=0;
        virtual QQuickWindow * getQuickWindow() const=0;
        virtual QQmlEngine * getEngine() const =0;
        virtual QQmlContext * getRootContext() const =0;
        virtual QQuickItem * getRootObject() const=0;
        virtual ~AbstractRootWindow();
        SSTD_END_DEFINE_VIRTUAL_CLASS(AbstractRootWindow);
    };

    template <WindowType>
    class RootWindow;

    namespace _private_sstd {

        class EXPORT_SSTD_QT_AND_QML_LIBRARY _WindowPrivate :
                public QuickViewWindow ,
            public virtual AbstractRootWindow ,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_WindowPrivate){
            Q_OBJECT
        public:
            using QuickViewWindow::QuickViewWindow;
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
            Q_SLOT WindowType getWindowType() const override { return WindowType::QtQuickWindow; }
            Q_SLOT QQmlEngine * getEngine() const override ;
            Q_SLOT QQmlContext * getRootContext() const override ;
            Q_SLOT QQuickItem * getRootObject() const override ;
            _WindowPrivate();
        private:
            using Super = QuickViewWindow;
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(_WindowPrivate);
        };

        class EXPORT_SSTD_QT_AND_QML_LIBRARY _WidgetPrivate :
                public QuickViewWidget,
                public virtual AbstractRootWindow ,
                SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_WidgetPrivate){
            Q_OBJECT
        public:
            using QuickViewWidget::QuickViewWidget;
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
            Q_SLOT WindowType getWindowType() const override { return WindowType::QtWidget; }
            Q_SLOT QQmlEngine * getEngine() const override ;
            Q_SLOT QQmlContext * getRootContext() const override ;
            Q_SLOT QQuickItem * getRootObject() const override ;
            _WidgetPrivate();
        private:
            using Super = QuickViewWidget;
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(_WidgetPrivate);
        };
    }

    template <>
    class RootWindow<WindowType::QtWidget> :
        public _private_sstd::_WidgetPrivate {};

    template <>
    class RootWindow<WindowType::QtQuickWindow> :
        public _private_sstd::_WindowPrivate {};

#if !defined(_DEBUG)/*选择使用QQuickWidget还是QQuickView作为显示窗口*/
    using DefaultRoowWindow = RootWindow<sstd::WindowType::QtWidget>;
#else
    using DefaultRoowWindow = RootWindow<sstd::WindowType::QtQuickWindow>;
#endif

}/*namespace sstd*/

















