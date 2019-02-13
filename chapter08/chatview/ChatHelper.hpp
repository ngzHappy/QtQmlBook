#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "TextDocumentLayoutBasic.hpp"

class ChatHelper :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ChatHelper) {
    Q_OBJECT
private:
    using Super = QQuickItem;
private:
    Q_PROPERTY(qreal rightDocumentLimit READ getRightDocumentLimit WRITE setRightDocumentLimit NOTIFY rightDocumentLimitChanged)
private:
    Q_PROPERTY(qreal leftDocumentLimit READ getLeftDocumentLimit WRITE setLeftDocumentLimit NOTIFY leftDocumentLimitChanged)
private:
    Q_PROPERTY(QQuickItem * textArea READ getTextArea WRITE setTextArea NOTIFY textAreaChanged)
private:
    Q_PROPERTY(qreal nativeTextWidth READ getNativeTextWidth WRITE setNativeTextWidth NOTIFY nativeTextWidthChanged)
public:
    ChatHelper();
public:
    Q_SLOT void checkVisible();
public:
    inline qreal getNativeTextWidth() const;
    void setNativeTextWidth(qreal);
    Q_SIGNAL void nativeTextWidthChanged();
public:
    inline qreal getLeftDocumentLimit() const ;
    void setLeftDocumentLimit(qreal );
    Q_SIGNAL void leftDocumentLimitChanged();
public:
    inline qreal getRightDocumentLimit() const ;
    void setRightDocumentLimit(qreal);
    Q_SIGNAL void rightDocumentLimitChanged();
public:
    inline QQuickItem * getTextArea() const;
    void setTextArea(QQuickItem *);
    Q_SIGNAL void textAreaChanged();
private:
    QQuickItem * mmmTextView{ nullptr };
    QQuickTextDocument * mmmTextDocument{ nullptr };
    TextDocumentLayoutBasic * mmmTextLayout{ nullptr };
    QQuickItem * mmmForeGroundItem{ nullptr };
    qreal mmmNativeTextWidth{ 0.0 };
    qreal mmmLeftLimit{ 0.0 };
    qreal mmmRightLimit{ 0.0 };
protected:
    virtual void componentComplete() override;
protected:
    void classBegin() override;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ChatHelper);
};

inline qreal ChatHelper::getLeftDocumentLimit() const {
    return mmmLeftLimit;
}

inline qreal ChatHelper::getRightDocumentLimit() const {
    return mmmRightLimit;
}

inline qreal ChatHelper::getNativeTextWidth() const{
    return mmmNativeTextWidth;
}

inline QQuickItem * ChatHelper::getTextArea() const {
    return mmmTextView;
}
