#include "CreateTextDocument.hpp"

CHAT_VIEW_LIBRARY_EXPORT TextDocumentLayoutBasic *
createLeftTextDocumentLayout(QTextDocument * arg) {
    return sstd_new<this_file::Layout>(arg);
}
