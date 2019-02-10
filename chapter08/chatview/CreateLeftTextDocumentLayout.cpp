#include <sstd_library.hpp>
#include "CreateLeftTextDocumentLayout.hpp"
#include "left_qtextdocumentlayout_p.h"
#ifndef QT_NO_CSSPARSER
#define QT_NO_CSSPARSER 1
#endif

#ifdef CHAT_VIEW_LEFT_LIBRARY
#include "left_qtextdocumentlayout.hpp"
#endif


namespace {

}/**/

CHAT_VIEW_LIBRARY_EXPORT QAbstractTextDocumentLayout * createLeftTextDocumentLayout(QTextDocument *){
    return nullptr;
}


