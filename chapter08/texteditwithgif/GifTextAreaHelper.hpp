#pragma once

#include <sstd_qt_and_qml_library.hpp>

class TextDocumentLayout;
class GifTextAreaHelper :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(GifTextAreaHelper){
    Q_OBJECT
private:
    using Super = QQuickItem;
private:
    Q_PROPERTY(QQuickTextDocument * document READ getDocument WRITE setDocument NOTIFY documentChanged)
private:
    Q_PROPERTY(QQuickItem * textArea READ getTextArea WRITE setTextArea NOTIFY textAreaChanged)
private:
    Q_PROPERTY(QQuickItem * flickable READ getFlickable WRITE setFlickable NOTIFY flickableChanged)
public:
    GifTextAreaHelper();
public:
    QQuickItem * getFlickable() const;
    QQuickItem * getTextArea() const;
    void setTextArea(QQuickItem *);
    void setFlickable(QQuickItem *);
    Q_SIGNAL void textAreaChanged();
    Q_SIGNAL void flickableChanged();
    QQuickTextDocument * getDocument() const;
    void setDocument(QQuickTextDocument *);
    Q_SIGNAL void documentChanged();
    Q_SLOT void checkVisible();
protected:
    void classBegin() override;
private:
    void pppAboutUpdate();
protected:
    virtual void componentComplete() override;
private:
    QQuickItem * mmmTextArea{ nullptr };
    QQuickItem * mmmFlickAble{ nullptr };
    QQuickTextDocument * mmmDocument{ nullptr };
    TextDocumentLayout * mmmTextLayout{ nullptr };
    QQuickItem * mmmForeGroundItem{ nullptr };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(GifTextAreaHelper);
};
