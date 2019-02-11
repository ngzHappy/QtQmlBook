#pragma once

#include <sstd_library.hpp>
#ifndef QT_NO_CSSPARSER
#define QT_NO_CSSPARSER 1
#endif

#if defined(CHAT_VIEW_LEFT_LIBRARY) && defined(CHAT_VIEW_RIGHT_LIBRARY)
static_assert(false,"can not defined both of them ...");
#endif

#ifdef CHAT_VIEW_LEFT_LIBRARY
#include "left_qtextdocumentlayout.hpp"
#include "CreateLeftTextDocumentLayout.hpp"
#include "left_qtextdocumentlayout_p.h"
#endif

#ifdef CHAT_VIEW_RIGHT_LIBRARY
#include "right_qtextdocumentlayout.hpp"
#include "CreateRightTextDocumentLayout.hpp"
#include "right_qtextdocumentlayout_p.h"
#endif

/*左对齐TextLayout*/
namespace this_file {

    class Layout :
        public QTextDocumentLayout,
        public TextDocumentLayoutBasic,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Layout) {
        using Super = QTextDocumentLayout;
        using Basic = TextDocumentLayoutBasic;
    public:
        inline Layout(QTextDocument * arg) :
            QTextDocumentLayout(arg) {
            this->setParent(arg);
            Basic::setLayout(this);
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Layout);
    };

}/**/


















