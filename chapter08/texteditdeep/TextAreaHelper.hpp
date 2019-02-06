#pragma once

#include <sstd_qt_and_qml_library.hpp>

class TextAreaHelper :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(TextAreaHelper) {
    Q_OBJECT
private:
    using Super = QQuickItem;
private:
    Q_PROPERTY(QQmlComponent * blockBackground READ getBlockBackground WRITE setBlockBackground NOTIFY blockBackgroundChanged)
private:
    Q_PROPERTY(QQuickTextDocument * document READ getDocument WRITE setDocument NOTIFY documentChanged)
private:
    Q_PROPERTY(QQuickItem * textArea READ getTextArea WRITE setTextArea NOTIFY textAreaChanged)
private:
    Q_PROPERTY(QQuickItem * flickable READ getFlickable WRITE setFlickable NOTIFY flickableChanged)
public:
    TextAreaHelper();
    QQuickItem * getFlickable() const;
    QQuickItem * getTextArea() const;
    void setTextArea(QQuickItem *);
    void setFlickable(QQuickItem *);
    Q_SIGNAL void textAreaChanged();
    Q_SIGNAL void flickableChanged();
    QQuickTextDocument * getDocument() const;
    void setDocument(QQuickTextDocument *);
    Q_SIGNAL void documentChanged();
    QQmlComponent * getBlockBackground() const;
    void setBlockBackground(QQmlComponent *);
    Q_SIGNAL void blockBackgroundChanged();
    virtual ~TextAreaHelper() override;
    Q_SLOT void checkVisible();
protected:
    virtual void componentComplete() override;
private:
    Q_SLOT void pppOnDoMainChange();
    Q_SLOT void pppAboutUpdate();
private:
    QQuickItem * mmmTextArea{ nullptr };
    QQuickItem * mmmFlickAble{ nullptr };
    QQuickTextDocument * mmmDocument{ nullptr };
    QQmlComponent * mmmBackGround{ nullptr };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TextAreaHelper);
};
























