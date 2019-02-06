#pragma once

#include <sstd_qt_and_qml_library.hpp>

class TextAreaHelper :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(TextAreaHelper) {
    Q_OBJECT
private:
    using Super = QQuickItem;
private:
    Q_PROPERTY(QQuickItem * textArea READ getTextArea WRITE setTextArea NOTIFY textAreaChanged)
private:
    Q_PROPERTY(QQuickItem * flickable READ getFlickable WRITE setFlickable NOTIFY flickableChanged)
public:
    TextAreaHelper(QQuickItem * /*parent*/ = nullptr);
    QQuickItem * getFlickable() const;
    QQuickItem * getTextArea() const;
    void setTextArea(QQuickItem *);
    void setFlickable(QQuickItem *);
    Q_SIGNAL void textAreaChanged();
    Q_SIGNAL void flickableChanged();
private:
    QQuickItem * mmmTextArea{ nullptr };
    QQuickItem * mmmFlickAble{ nullptr };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TextAreaHelper);
};


























