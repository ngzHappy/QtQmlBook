#include "sstd_root_window.hpp"

namespace sstd::_private_sstd {

    void _WindowPrivate::load(const QUrl & arg) {
        Super::setSource(arg);
    }

    void _WidgetPrivate::load(const QUrl & arg) {
        Super::setSource(arg);
    }

    void _WindowPrivate::setResizeMode(sstd::ResizeMode arg) {
        switch (arg) {
        case sstd::ResizeMode::SizeViewToRootObject:
        {
            Super::setResizeMode(Super::SizeViewToRootObject);
            break;
        }
        case sstd::ResizeMode::SizeRootObjectToView:
        {
            Super::setResizeMode(Super::SizeRootObjectToView);
            break;
        }
        }
    }

    void _WidgetPrivate::setResizeMode(sstd::ResizeMode arg) {
        switch (arg) {
        case sstd::ResizeMode::SizeViewToRootObject:
        {
            Super::setResizeMode(Super::SizeViewToRootObject);
            break;
        }
        case sstd::ResizeMode::SizeRootObjectToView:
        {
            Super::setResizeMode(Super::SizeRootObjectToView);
            break;
        }
        }
    }

    _WindowPrivate::_WindowPrivate() {
        this->setClearColor(QColor(0, 0, 0, 255));
        this->setResizeMode(sstd::ResizeMode::SizeRootObjectToView);
    }

    _WidgetPrivate::_WidgetPrivate() {
        this->setClearColor(QColor(0, 0, 0, 255));
        this->setResizeMode(sstd::ResizeMode::SizeRootObjectToView);
        {
            auto varP = this->palette();
            varP.setBrush(QPalette::Background, QColor(0, 0, 0, 255));
            this->setPalette(varP);
            this->setAutoFillBackground(true);
        }
    }

    sstd::LoadState _WidgetPrivate::status() const {
        switch (Super::status()) {
        case Super::Null:return sstd::LoadState::Null;
        case Super::Ready:return sstd::LoadState::Ready;
        case Super::Loading:return sstd::LoadState::Loading;
        case Super::Error:return sstd::LoadState::Error;
        }
        return sstd::LoadState::Error;
    }

    sstd::LoadState _WindowPrivate::status() const {
        switch (Super::status()) {
        case Super::Null:return sstd::LoadState::Null;
        case Super::Ready:return sstd::LoadState::Ready;
        case Super::Loading:return sstd::LoadState::Loading;
        case Super::Error:return sstd::LoadState::Error;
        }
        return sstd::LoadState::Error;
    }

    void _WidgetPrivate::setTitle(const QString & arg) {
        Super::setWindowTitle(arg);
    }

    void _WindowPrivate::setTitle(const QString & arg) {
        Super::setTitle(arg);
    }

    void _WindowPrivate::setClearColor(const QColor & arg) {
        Super::setColor(arg);
    }

    void _WidgetPrivate::setClearColor(const QColor & arg) {
        Super::setClearColor(arg);
    }

    void _WidgetPrivate::show() {
        Super::show();
    }

    void _WindowPrivate::show() {
        Super::show();
    }

    void _WindowPrivate::setX(int arg) {
        Super::setX(arg);
    }

    void _WindowPrivate::setY(int arg) {
        Super::setY(arg);
    }

    void _WidgetPrivate::setX(int arg) {
        const auto varGeomety = Super::geometry();
        Super::setGeometry(arg, varGeomety.y(), varGeomety.width(), varGeomety.height());
    }

    void _WidgetPrivate::setY(int arg) {
        const auto varGeomety = Super::geometry();
        Super::setGeometry(varGeomety.x(), arg, varGeomety.width(), varGeomety.height());
    }

    QObject * _WidgetPrivate::getObject() const {
        return const_cast<_WidgetPrivate*>(this);
    }

    QObject * _WindowPrivate::getObject() const {
        return const_cast<_WindowPrivate*>(this);
    }

    QQuickWindow * _WindowPrivate::getQuickWindow() const {
        return Super::getQuickWindow();
    }

    QQuickWindow * _WidgetPrivate::getQuickWindow() const {
        return Super::getQuickWindow();
    }

    QQmlEngine * _WidgetPrivate::getEngine() const {
        return Super::engine();
    }

    QQmlContext * _WidgetPrivate::getRootContext() const {
        return Super::rootContext();
    }

    QQuickItem * _WidgetPrivate::getRootObject() const {
        return Super::rootObject();
    }

    QQmlEngine * _WindowPrivate::getEngine() const {
        return Super::engine();
    }

    QQmlContext * _WindowPrivate::getRootContext() const {
        return Super::rootContext();
    }

    QQuickItem * _WindowPrivate::getRootObject() const {
        return Super::rootObject();
    }

}/**/

namespace sstd {
    AbstractRootWindow::~AbstractRootWindow() {
    }
}/**/
















