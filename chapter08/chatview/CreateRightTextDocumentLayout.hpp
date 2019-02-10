﻿#pragma once

#include <QtGui/qabstracttextdocumentlayout.h>

#ifdef CHAT_VIEW_LIBRARY
#define CHAT_VIEW_LIBRARY_EXPORT Q_DECL_EXPORT
#else
#define CHAT_VIEW_LIBRARY_EXPORT Q_DECL_IMPORT
#endif

CHAT_VIEW_LIBRARY_EXPORT QAbstractTextDocumentLayout * createRightTextDocumentLayout(QTextDocument *);
