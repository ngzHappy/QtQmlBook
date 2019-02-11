#pragma once

#if defined(CHAT_VIEW_LIBRARY)
#define CHAT_VIEW_BASIC_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#define CHAT_VIEW_BASIC_LIBRARY_EXPORT Q_DECL_IMPORT
#endif

#include <sstd_library.hpp>
#include <QtGui/qabstracttextdocumentlayout.h>

class TextDocumentLayoutQmlItem{
public:

private:
    SSTD_DEFINE_STATIC_CLASS(TextDocumentLayoutQmlItem);
};


class CHAT_VIEW_BASIC_LIBRARY_EXPORT TextDocumentLayoutBasic {
public:
    using QmlItemsMap =
    sstd::map<  int, std::shared_ptr< TextDocumentLayoutQmlItem > >;
public:
    virtual ~TextDocumentLayoutBasic();
    TextDocumentLayoutBasic();

    QmlItemsMap & getQmlItems();
    const QmlItemsMap & getQmlItems() const;

    QAbstractTextDocumentLayout * getLayout() const;
    void setLayout(QAbstractTextDocumentLayout *);

private:
    QmlItemsMap mmmQmlItems;
    QAbstractTextDocumentLayout * mmmLayout{nullptr};
};














