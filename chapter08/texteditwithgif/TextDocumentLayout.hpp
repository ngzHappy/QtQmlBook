#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include <QtGui/private/qtextdocumentlayout_p.h>

class TextQmlWrappedItem {
    const QString mmmQmlPath;
    const int mmmImageWidth;
    const int mmmImageHeight;
    double mmmX{0};
    double mmmY{0};
public:
    TextQmlWrappedItem(const QString &,int,int);
    ~TextQmlWrappedItem();

    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);

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
private:
    void updateQmlPos(QTextInlineObject item, int posInDocument, const QTextFormat &format);
protected:
    void positionInlineObject(QTextInlineObject item, int posInDocument, const QTextFormat &format) override;
    void resizeInlineObject(QTextInlineObject item, int posInDocument, const QTextFormat &format) override;
    void documentChanged(int position, int charsRemoved, int charsAdded) override;
private:
    sstd::map< 
        int, 
        std::shared_ptr< TextQmlWrappedItem  > 
    > mmmQmlItems;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TextDocumentLayout);
};




















