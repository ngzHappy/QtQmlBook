#include "TextDocumentLayoutBasic.hpp"

TextDocumentLayoutBasic::~TextDocumentLayoutBasic() {
}

TextDocumentLayoutBasic::TextDocumentLayoutBasic() {
}

TextDocumentLayoutBasic::QmlItemsMap & TextDocumentLayoutBasic::getQmlItems(){
    return mmmQmlItems;
}

const TextDocumentLayoutBasic::QmlItemsMap & TextDocumentLayoutBasic::getQmlItems() const{
    return mmmQmlItems;
}

QAbstractTextDocumentLayout * TextDocumentLayoutBasic::getLayout() const{
    return mmmLayout;
}

void TextDocumentLayoutBasic::setLayout(QAbstractTextDocumentLayout * arg){
    mmmLayout=arg;
}

QTextDocument * TextDocumentLayoutBasic::getDocument() const{
    return mmmDocument;
}

void TextDocumentLayoutBasic::setDocument( QTextDocument * arg){
    mmmDocument=arg;
}

int TextDocumentLayoutBasic::getLastDocumentLength() const {
    return mmmLastDocumentLength;
}

void TextDocumentLayoutBasic::setLastDocumentLength(int arg){
    mmmLastDocumentLength=arg;
}

TextDocumentLayoutQmlItem::TextDocumentLayoutQmlItem( const QString & p,
                                                      int w,
                                                      int h) : mmmQMlItemPath(p),
    mmmItemWidth(w),mmmItemHeight(h) {

}



