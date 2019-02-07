#include "TextAreaHelper.hpp"

TextAreaHelper::TextAreaHelper() {
    this->setFlag(QQuickItem::ItemHasContents, false);
}

QQuickItem * TextAreaHelper::getFlickable() const {
    return mmmFlickAble;
}

QQuickItem * TextAreaHelper::getTextArea() const {
    return mmmTextArea;
}

void TextAreaHelper::setTextArea(QQuickItem *arg) {
    assert(nullptr == mmmTextArea);
    mmmTextArea = arg;
    assert(arg);

    textAreaChanged();
}

void TextAreaHelper::setFlickable(QQuickItem *arg) {
    assert(nullptr == mmmFlickAble);
    mmmFlickAble = arg;
    assert(arg);
    flickableChanged();
}

QQuickTextDocument * TextAreaHelper::getDocument() const {
    return mmmDocument;
}

void TextAreaHelper::setDocument(QQuickTextDocument * arg) {
    assert(nullptr == mmmDocument);
    mmmDocument = arg;
    assert(arg);
    auto varDocument = mmmDocument->textDocument();
    auto varDocumentLayout = varDocument->documentLayout();
    connect(varDocumentLayout, &QAbstractTextDocumentLayout::documentSizeChanged,
        this, [this](const QSizeF &) {
        this->pppAboutUpdate();
    });
    connect(varDocument,&QTextDocument::contentsChanged, 
        this, [this]() {
        this->pppAboutUpdate();
    });
    documentChanged();
}

namespace {
    class BlockUserData :
        public QTextBlockUserData,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(BlockUserData) {
        QPointer<QQuickItem> mmmItem;
    public:
        QQuickItem * const item;

        inline BlockUserData(QQuickItem * v) : item(v) {
            mmmItem = v;
        }

        inline ~BlockUserData() {
            auto varItem = mmmItem.data();
            if (varItem) {
                varItem->setVisible(false);
                delete varItem;
            }
        }

    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(BlockUserData);
    };
}

void TextAreaHelper::pppOnDoMainChange() {

    if (mmmDocument == nullptr) {
        return;
    }

    if (mmmFlickAble == nullptr) {
        return;
    }

    if (mmmBackGround == nullptr) {
        return;
    }

    auto varDocument = mmmDocument->textDocument();
    auto varDocumentLayout = varDocument->documentLayout();

    auto varBlock = varDocument->firstBlock();
    auto varContex = QQmlEngine::contextForObject(mmmBackGround);
    assert(varContex);

    auto varLeft = mmmTextArea->property("leftPadding").toDouble();
    auto varTop = mmmTextArea->property("topPadding").toDouble();

    while (varBlock.isValid()) {
        auto varCurrentBlock = varBlock;
        varBlock = varBlock.next();

        BlockUserData * varUserData = nullptr;

        {/*create backitem ... */
            auto varRawUserData = varCurrentBlock.userData();
            varUserData =
                static_cast<BlockUserData *>(varRawUserData);
            if (varUserData == nullptr) {
                auto varItem =
                    qobject_cast<QQuickItem *>(mmmBackGround->beginCreate(varContex));
                assert(varItem);
                varItem->setParent(this);
                varItem->setParentItem(this);
                varItem->setVisible(true);
                mmmBackGround->completeCreate();
                varUserData = sstd_new< BlockUserData >(varItem);
                varCurrentBlock.setUserData(varUserData);
            }
        }


        auto varBackGroundRect =
            varDocumentLayout->blockBoundingRect(varCurrentBlock);

        double varBlockWidth = varBackGroundRect.width();
        {
            auto varBlockLayout = varCurrentBlock.layout();
            qreal varMaxLineWidth = 1;
            if (varBlockLayout) {
                const auto varLineCount = varBlockLayout->lineCount();
                for (int i = 0; i < varLineCount; ++i) {
                    const auto &varLine = varBlockLayout->lineAt(i);
                    varMaxLineWidth = std::max(varLine.naturalTextWidth(), varMaxLineWidth);
                }
                varBlockWidth = varMaxLineWidth;
            }
        }

        auto varBackGroundItem = varUserData->item;

        varBackGroundItem->setX(varBackGroundRect.x() + varLeft);
        varBackGroundItem->setY(varBackGroundRect.y() + varTop);
        varBackGroundItem->setWidth(varBlockWidth);
        varBackGroundItem->setHeight(varBackGroundRect.height());

    }

    checkVisible();

}

void TextAreaHelper::checkVisible() {

    if (mmmDocument == nullptr) {
        return;
    }

    if (mmmFlickAble == nullptr) {
        return;
    }

    if (mmmBackGround == nullptr) {
        return;
    }

    auto varLeft = mmmTextArea->property("leftPadding").toDouble();
    auto varTop = mmmTextArea->property("topPadding").toDouble();
    auto varBottom = mmmTextArea->property("bottomPadding").toDouble();
    auto varRight = mmmTextArea->property("rightPadding").toDouble();

    auto varCX = mmmFlickAble->property("contentX").toDouble();
    auto varCY = mmmFlickAble->property("contentY").toDouble();

    auto varX = varCX + varLeft;
    auto varY = varCY + varTop;

    auto varWidth = mmmFlickAble->width();
    auto varHeight = mmmFlickAble->height();

    QRectF varCheckRect{ varX,varY,
        varWidth - varLeft - varRight,
        varHeight - varTop - varBottom };

    auto varDocument = mmmDocument->textDocument();
    auto varBlock = varDocument->firstBlock();
    while (varBlock.isValid()) {
        auto varCurrentBlock = varBlock;
        varBlock = varBlock.next();
        auto * varUserData =
            static_cast<BlockUserData *>(varCurrentBlock.userData());
        if (varUserData == nullptr) {
            continue;
        }
        auto varItem = varUserData->item;
        QRectF varItemRect{
            varItem->x() ,
            varItem->y() ,
            varItem->width() ,
            varItem->height() };
        if (varItemRect.width() <
            (1.0 + std::numeric_limits<double>::epsilon())) {
            varItem->setVisible(false);
        } else if (varItemRect.intersected(varCheckRect).height() < 5.1) {
            varItem->setVisible(false);
        } else {
            varItem->setVisible(true);
        }
    }

}

void TextAreaHelper::componentComplete() {
    auto varContex = QQmlEngine::contextForObject(this);
    assert(varContex);
    auto varExp = QQmlExpression(varContex, this, QStringLiteral(R"(
              x = Qt.binding( function() { checkVisible(); return -flickable.contentX } )
              y = Qt.binding( function() { checkVisible(); return -flickable.contentY } )
)"));
    auto varAns = varExp.evaluate();
    qDebug() << varAns.toString();
    Super::componentComplete();
}

void TextAreaHelper::pppAboutUpdate() {
    pppOnDoMainChange();
}

TextAreaHelper::~TextAreaHelper() {
}

QQmlComponent * TextAreaHelper::getBlockBackground() const {
    return mmmBackGround;
}

void TextAreaHelper::setBlockBackground(QQmlComponent * arg) {
    assert(nullptr == mmmBackGround);
    mmmBackGround = arg;
    blockBackgroundChanged();
}

static inline void register_this() {
    qmlRegisterType<TextAreaHelper>(
        "sstd.textarea.help",
        1, 0,
        "TextAreaHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)



