#pragma once

#include <sstd_qt_and_qml_library.hpp>

class TextAreaHelper :
        QQuickItem ,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(TextAreaHelper) {
    Q_OBJECT
private:
    using Super = QQuickItem;
private:
    Q_PROPERTY(QObject * textArea READ getTextArea WRITE setTextArea NOTIFY textAreaChanged)
private:
    Q_PROPERTY(QObject * flickable READ getFlickable WRITE setFlickable NOTIFY flickableChanged)
public:
    TextAreaHelper( QQuickItem * /*parent*/=nullptr );
    QObject * getFlickable() const;
    QObject * getTextArea() const;
    void setTextArea(QObject *);
    void setFlickable(QObject *);
    Q_SIGNAL void textAreaChanged();
    Q_SIGNAL void flickableChanged();
private:
    QObject * mmmTextArea{nullptr};
    QObject * mmmFlickAble{nullptr};
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TextAreaHelper);
};


























