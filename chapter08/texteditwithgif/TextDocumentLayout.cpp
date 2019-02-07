#include "TextDocumentLayout.hpp"

TextDocumentLayout::TextDocumentLayout(QTextDocument * arg) :
    Super(arg) {

}

void TextDocumentLayout::documentChanged(
    int position,
    int charsRemoved,
    int charsAdded) {
    Super::documentChanged(position, charsRemoved, charsAdded);
}













