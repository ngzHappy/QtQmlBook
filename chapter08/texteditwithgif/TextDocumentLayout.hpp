#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include <QtGui/private/qtextdocumentlayout_p.h>

class TextDocumentLayout :
    public QTextDocumentLayout,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(TextDocumentLayout) {
private:
    Q_OBJECT
private:
    using Super = QTextDocumentLayout;
public:
    TextDocumentLayout(QTextDocument *);
protected:
    void documentChanged(int position, int charsRemoved, int charsAdded) override;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TextDocumentLayout);
};




















