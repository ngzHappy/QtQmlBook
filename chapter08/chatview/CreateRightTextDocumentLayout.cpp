#include <sstd_library.hpp>
#include "CreateRightTextDocumentLayout.hpp"
#include "right_qtextdocumentlayout_p.h"
#ifndef QT_NO_CSSPARSER
#define QT_NO_CSSPARSER 1
#endif
#ifdef CHAT_VIEW_RIGHT_LIBRARY
#include "right_qtextdocumentlayout.hpp"
#endif

/*右对齐TextLayout*/
namespace this_file {

    class Layout :
            public QTextDocumentLayout ,
            public TextDocumentLayoutBasic ,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Layout) {
    public:
        inline Layout(QTextDocument * arg) :
            QTextDocumentLayout(arg) {
            this->setParent(arg);
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Layout);
    };

}/**/

CHAT_VIEW_LIBRARY_EXPORT TextDocumentLayoutBasic *
createLeftTextDocumentLayout(QTextDocument * arg) {
    return sstd_new<this_file::Layout>(arg);
}


