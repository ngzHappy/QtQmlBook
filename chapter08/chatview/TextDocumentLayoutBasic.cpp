#include "TextDocumentLayoutBasic.hpp"

TextDocumentLayoutBasic::~TextDocumentLayoutBasic(){

}

TextDocumentLayoutBasic::TextDocumentLayoutBasic(){

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

