#pragma once

#include <sstd_qt_and_qml_library.hpp>

class ChatHelper : 
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ChatHelper) {
    Q_OBJECT
private:
    Q_PROPERTY(QQuickItem * textArea READ getTextArea WRITE setTextArea NOTIFY textAreaChanged)
private:
    Q_PROPERTY(QQuickTextDocument * document READ getDocument WRITE setDocument NOTIFY documentChanged)
private:

public:
    ChatHelper();
public:
    inline QQuickItem * getTextArea() const;
    void setTextArea(QQuickItem *);
    Q_SIGNAL void textAreaChanged();
public:
    inline QQuickTextDocument * getDocument() const;
    void setDocument(QQuickTextDocument *);
    Q_SIGNAL void documentChanged();
private:
    QQuickItem * mmmTextView{ nullptr };
    QQuickTextDocument * mmmDocument{ nullptr };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ChatHelper);
};

inline QQuickItem * ChatHelper::getTextArea() const {
    return mmmTextView;
}

inline QQuickTextDocument * ChatHelper::getDocument() const {
    return mmmDocument;
}







