﻿#pragma once

#include <sstd_library.hpp>
#ifndef QT_NO_CSSPARSER
#define QT_NO_CSSPARSER 1
#endif

#if defined(CHAT_VIEW_LEFT_LIBRARY) && defined(CHAT_VIEW_RIGHT_LIBRARY)
static_assert(false, "can not defined both of them ...");
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
        inline void positionInlineObject(QTextInlineObject item,
            int posInDocument,
            const QTextFormat &format) override {
            updateQmlPos(item, posInDocument, format);
            return Super::positionInlineObject(item, posInDocument, format);
        }
        inline void resizeInlineObject(QTextInlineObject item,
            int posInDocument,
            const QTextFormat &format) override {
            updateQmlPos(item,posInDocument,format);
            return Super::resizeInlineObject(item, posInDocument, format);
        }
        inline void updateQmlPos(QTextInlineObject item,
            int posInDocument,
            const QTextFormat &format) {
            auto & varItems = Basic::getQmlItems();
            auto varQmlPos = varItems.find(posInDocument);
            if (varQmlPos == varItems.cend()) {
                return;
            }
            if (varQmlPos->second) {
                varQmlPos->second->setNeedUpdatePos(true);
            }
            (void)item;
            (void)format;
        }
        inline void documentChanged(int argPosition,
            int argCharsRemoved,
            int argCharsAdded) override {

            auto thisReturn = [argPosition,
                argCharsRemoved,
                argCharsAdded,
                this]() {
                return Super::documentChanged(argPosition,
                    argCharsRemoved,
                    argCharsAdded);
            };

            if (Basic::getDocument() == document()) {

                const auto varLogicalDocumentLength =
                    Basic::getLastDocumentLength()
                    - argCharsRemoved
                    + argCharsAdded;

                Basic::setLastDocumentLength(document()->characterCount());

                if (varLogicalDocumentLength != Basic::getLastDocumentLength()) {

                    if (argCharsAdded) {
                        assert((argCharsAdded == Basic::getLastDocumentLength()) || (0 == argCharsRemoved));
                        return thisReturn();
                    } else {
                        assert((argCharsAdded == 0) || (Basic::getLastDocumentLength() == argCharsRemoved));
                        Basic::getQmlItems().clear();
                        Basic::setDocument(nullptr);
                        return thisReturn();
                    }

                }

                assert((argPosition - argCharsRemoved + argCharsAdded) <= Basic::getLastDocumentLength());

            } else {
                Basic::setDocument(document());
                Basic::getQmlItems().clear();
                Basic::setLastDocumentLength(document()->characterCount());
            }

            {/*更新索引*/
                TextDocumentLayoutBasic::QmlItemsMap varNewQmlItems;
                const auto varDx = argCharsAdded - argCharsRemoved;
                for (const auto & varI : Basic::getQmlItems()) {
                    const auto varOldPos = varI.first;
                    if (varOldPos < argPosition) {
                        varNewQmlItems.emplace(varOldPos, std::move(varI.second));
                    } else if ((varOldPos - argPosition) < argCharsRemoved) {
                        continue;
                    } else if (varDx == 0) {
                        varNewQmlItems.emplace(
                            varOldPos,
                            std::move(varI.second));
                    } else {
                        varNewQmlItems.emplace(
                            varDx + varOldPos,
                            std::move(varI.second));
                    }
                }
                Basic::getQmlItems() = std::move(varNewQmlItems);
            }

            if (argCharsAdded < 1) {
                return thisReturn();
            }

            for (int i = 0; i < argCharsAdded; ++i) {
                const auto varCurrentPos = argPosition + i;
                auto varCharFormat = this->format(varCurrentPos);
                if (!varCharFormat.isImageFormat()) {
                    continue;
                }
                const auto varImageFormat = varCharFormat.toImageFormat();
                const auto varImageName = varImageFormat.name();
                if (varImageName.endsWith(QStringLiteral(".qml"), Qt::CaseInsensitive)) {
                    Basic::getQmlItems().insert({ varCurrentPos,
                        sstd_make_shared<TextDocumentLayoutQmlItem>(
                            varImageName,
                            varImageFormat.width(),
                            varImageFormat.height()) });
                }
            }

            return thisReturn();

        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Layout);
    };

}/**/
