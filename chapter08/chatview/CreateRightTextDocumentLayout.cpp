#include "CreateTextDocument.hpp"

CHAT_VIEW_LIBRARY_EXPORT TextDocumentLayoutBasic *
createRightTextDocumentLayout(QTextDocument * arg) {
    return sstd_new<this_file::Layout>(arg);
}
