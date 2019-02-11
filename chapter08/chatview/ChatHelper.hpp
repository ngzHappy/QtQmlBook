#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "TextDocumentLayoutBasic.hpp"

class ChatHelper : 
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ChatHelper) {
    Q_OBJECT
private:
    Q_PROPERTY(QQuickItem * textArea READ getTextArea WRITE setTextArea NOTIFY textAreaChanged)
private:

public:
    ChatHelper();
public:
    inline QQuickItem * getTextArea() const;
    void setTextArea(QQuickItem *);
    Q_SIGNAL void textAreaChanged();
private:
    QQuickItem * mmmTextView{ nullptr };
    QQuickTextDocument * mmmTextDocument{nullptr};
    TextDocumentLayoutBasic * mmmTextLayout{ nullptr };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ChatHelper);
};

inline QQuickItem * ChatHelper::getTextArea() const {
    return mmmTextView;
}









