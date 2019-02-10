#pragma once

#if defined(CHAT_VIEW_LIBRARY)
#define CHAT_VIEW_BASIC_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#define CHAT_VIEW_BASIC_LIBRARY_EXPORT Q_DECL_IMPORT
#endif

#include <QtGui/qabstracttextdocumentlayout.h>

class CHAT_VIEW_BASIC_LIBRARY_EXPORT TextDocumentLayoutBasic {
public:
    virtual ~TextDocumentLayoutBasic();
    TextDocumentLayoutBasic();
};














