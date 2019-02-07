#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include <QtGui/private/qtextdocumentlayout_p.h>

class TextQmlWrappedItem {
    const QString mmmQmlPath;
    const int mmmImageWidth;
    const int mmmImageHeight;
public:
    TextQmlWrappedItem(const QString &,int,int);
    ~TextQmlWrappedItem();
private:
    SSTD_DEFINE_STATIC_CLASS(TextQmlWrappedItem);
};

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
    sstd::map< 
        int, 
        std::shared_ptr< TextQmlWrappedItem  > 
    > mmmQmlItems;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TextDocumentLayout);
};




















