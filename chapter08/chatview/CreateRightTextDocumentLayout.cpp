#include <sstd_library.hpp>
#include "CreateRightTextDocumentLayout.hpp"
#include "this_qtextdocumentlayout_p.h"
#ifndef QT_NO_CSSPARSER
#define QT_NO_CSSPARSER 1
#endif
#include "right_qtextdocumentlayout.hpp"

namespace {

}/**/

CHAT_VIEW_LIBRARY_EXPORT QAbstractTextDocumentLayout * createRightTextDocumentLayout(QTextDocument *){
    return nullptr;
}


