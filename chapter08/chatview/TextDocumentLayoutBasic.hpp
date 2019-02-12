#pragma once

#if defined(CHAT_VIEW_LIBRARY)
#define CHAT_VIEW_BASIC_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#define CHAT_VIEW_BASIC_LIBRARY_EXPORT Q_DECL_IMPORT
#endif

#include <sstd_library.hpp>
#include <QtGui/qabstracttextdocumentlayout.h>

class CHAT_VIEW_BASIC_LIBRARY_EXPORT TextDocumentLayoutQmlItem {
public:
    TextDocumentLayoutQmlItem(const QString & argImageFileName, int argWidth, int argHeight);
public:
    inline void setNeedUpdatePos(bool);
    inline bool getNeedUpdatePos() const;
private:
    const QString mmmQMlItemPath;
    const double mmmItemWidth;
    const double mmmItemHeight;
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

inline bool TextDocumentLayoutQmlItem::getNeedUpdatePos() const {
    return mmmNeedUpdate;
}

inline void TextDocumentLayoutQmlItem::setNeedUpdatePos(bool arg){
    mmmNeedUpdate = arg;
}











