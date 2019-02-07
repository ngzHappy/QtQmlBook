#include "TextDocumentLayout.hpp"

TextDocumentLayout::TextDocumentLayout(QTextDocument * arg) :
    Super(arg) {

}

void TextDocumentLayout::documentChanged(int position, int charsRemoved, int charsAdded) {
    {/*更新索引*/
        decltype(mmmQmlItems) varNewQmlItems;

        const auto varDx = charsAdded - charsRemoved;
        for (const auto & varI : mmmQmlItems) {
            const auto varOldPos = varI.first;
            if (varOldPos < position) {/*索引没有变化*/
                varNewQmlItems.emplace(varOldPos, std::move(varI.second));
            } else if ((varOldPos - position) < charsRemoved) {/*删除了此元素*/
                continue;
            } else if (varDx == 0) {/*索引没有变化*/
                varNewQmlItems.emplace(
                    varOldPos,
                    std::move(varI.second));
            } else {/*>=position索引变化*/
                varNewQmlItems.emplace(
                    varDx + varOldPos,
                    std::move(varI.second));
            }
        }
        mmmQmlItems = std::move(varNewQmlItems);
    }

    if (charsAdded < 1) {
        return;
    }

    /*插入新的QMl*/
    for (int i = 0; i < charsAdded; ++i) {
        const auto varCurrentPos = position + i;
        auto varCharFormat = this->format(varCurrentPos);
        if (!varCharFormat.isImageFormat()) {
            continue;
        }
        const auto varImageFormat = varCharFormat.toImageFormat();
        const auto varImageName = varImageFormat.name();
        if (varImageName.endsWith(QStringLiteral(".qml"), Qt::CaseInsensitive)) {
            mmmQmlItems.insert({ varCurrentPos,
                sstd_make_shared<TextQmlWrappedItem>(
                    varImageName,
                    varImageFormat.width(),
                    varImageFormat.height()) });
        }
    }

    Super::documentChanged(position, charsRemoved, charsAdded);
}

void TextDocumentLayout::positionInlineObject(QTextInlineObject item,
    int posInDocument,
    const QTextFormat &format) {
    return Super::positionInlineObject(item, posInDocument, format);
}

void TextDocumentLayout::resizeInlineObject(QTextInlineObject item,
    int posInDocument,
    const QTextFormat &format) {
    return Super::resizeInlineObject(item, posInDocument, format);
}

TextQmlWrappedItem::TextQmlWrappedItem(
    const QString & arg, int w, int h) : mmmQmlPath(arg),
    mmmImageWidth(w),
    mmmImageHeight(h) {
}

TextQmlWrappedItem::~TextQmlWrappedItem() {

}











