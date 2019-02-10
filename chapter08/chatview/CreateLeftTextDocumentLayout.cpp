﻿#include <sstd_library.hpp>
#include "CreateLeftTextDocumentLayout.hpp"
#include "left_qtextdocumentlayout_p.h"
#ifndef QT_NO_CSSPARSER
#define QT_NO_CSSPARSER 1
#endif

#ifdef CHAT_VIEW_LEFT_LIBRARY
#include "left_qtextdocumentlayout.hpp"
#endif

/*左对齐TextLayout*/
namespace this_file{

    class Layout : public QTextDocumentLayout {
    public:
        inline Layout(QTextDocument * arg) : 
            QTextDocumentLayout(arg) {
            this->setParent(arg);
        }
    };

}/**/

CHAT_VIEW_LIBRARY_EXPORT QAbstractTextDocumentLayout * 
createLeftTextDocumentLayout(QTextDocument * arg){
    return sstd_new<this_file::Layout>(arg);
}


