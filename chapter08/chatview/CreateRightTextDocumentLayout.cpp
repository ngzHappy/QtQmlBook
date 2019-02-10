#include <sstd_library.hpp>
#include "CreateRightTextDocumentLayout.hpp"
#include "right_qtextdocumentlayout_p.h"
#ifndef QT_NO_CSSPARSER
#define QT_NO_CSSPARSER 1
#endif
#ifdef CHAT_VIEW_RIGHT_LIBRARY
#include "right_qtextdocumentlayout.hpp"
#endif

namespace {

}/**/

CHAT_VIEW_LIBRARY_EXPORT QAbstractTextDocumentLayout * createRightTextDocumentLayout(QTextDocument *){
    return nullptr;
}


