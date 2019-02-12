#pragma once

#if defined(CHAT_VIEW_LIBRARY)
#define CHAT_VIEW_BASIC_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#define CHAT_VIEW_BASIC_LIBRARY_EXPORT Q_DECL_IMPORT
#endif

#include <sstd_library.hpp>
#include <QtGui/qabstracttextdocumentlayout.h>
#include <QtQuick/qquickitem.h>
#include <QtCore/qpointer.h>

class CHAT_VIEW_BASIC_LIBRARY_EXPORT TextDocumentLayoutQmlItem {
public:
    TextDocumentLayoutQmlItem(const QString & argImageFileName, int argWidth, int argHeight);
public:
    inline void setNeedUpdatePos(bool);
    inline bool getNeedUpdatePos() const;
public:
    inline double getItemWidth() const;
    inline double getItemHeight() const;
    inline QString getQmlPathName() const;
public:
    inline QQuickItem * getItem() const;
    inline void setItem(QQuickItem * arg);
    inline void releaseItem();
private:
    const QString mmmQMlItemPath;
    const double mmmItemWidth;
    const double mmmItemHeight;
    QQuickItem * mmmItem{ nullptr };
    QPointer< QQuickItem > mmmWatcher;
    sstd_bool mmmNeedUpdate{ true };
private:
    SSTD_DEFINE_STATIC_CLASS(TextDocumentLayoutQmlItem);
};

class CHAT_VIEW_BASIC_LIBRARY_EXPORT TextDocumentLayoutBasic {
public:
    using QmlItemsMap =
        sstd::map< int, std::shared_ptr< TextDocumentLayoutQmlItem > >;
public:
    virtual ~TextDocumentLayoutBasic();
    TextDocumentLayoutBasic();

    QmlItemsMap & getQmlItems();
    const QmlItemsMap & getQmlItems() const;

    QAbstractTextDocumentLayout * getLayout() const;
    void setLayout(QAbstractTextDocumentLayout *);

    QTextDocument * getDocument() const;
    void setDocument(QTextDocument *);

    int getLastDocumentLength() const;
    void setLastDocumentLength(int);

private:
    QmlItemsMap mmmQmlItems;
    QAbstractTextDocumentLayout * mmmLayout{ nullptr };
    QTextDocument * mmmDocument{ nullptr };
    int mmmLastDocumentLength{ 0 };
};

inline QString TextDocumentLayoutQmlItem::getQmlPathName() const {
    return mmmQMlItemPath;
}

inline void TextDocumentLayoutQmlItem::releaseItem() {
    auto varItem = mmmWatcher.data();
    mmmItem = nullptr;
    mmmWatcher.clear();
    if (varItem) {
        varItem->setVisible(false);
        delete varItem;
    }
}

inline void TextDocumentLayoutQmlItem::setItem(QQuickItem * arg) {
    assert(mmmItem == nullptr);
    mmmItem = arg;
    mmmWatcher = arg;
}

inline QQuickItem * TextDocumentLayoutQmlItem::getItem() const {
    return mmmItem;
}

inline bool TextDocumentLayoutQmlItem::getNeedUpdatePos() const {
    return mmmNeedUpdate;
}

inline void TextDocumentLayoutQmlItem::setNeedUpdatePos(bool arg){
    mmmNeedUpdate = arg;
}

inline double TextDocumentLayoutQmlItem::getItemWidth() const {
    return mmmItemWidth;
}

inline double TextDocumentLayoutQmlItem::getItemHeight() const {
    return mmmItemHeight;
}









