#include "GifTextAreaHelper.hpp"
#include "PlaceHolderImageProvider.hpp"
#include "TextDocumentLayout.hpp"

template<bool IsFileName = true>
inline static QQuickItem * createItem(const QString & argFileName,
    QQuickItem * argParent) {

    QByteArray varFileData;

    if constexpr (IsFileName) {
        QFile varFile{ argFileName };
        if (!varFile.open(QIODevice::ReadOnly)) {
            qWarning()
                << QStringLiteral("can not open : ")
                << argFileName;
            return nullptr;
        }

        {
            auto varAllFile = varFile.readAll();
            if (varAllFile.startsWith(QByteArrayLiteral("\xEF\xBB\xBF"))) {
                varFileData = std::move(varAllFile);
            } else {
                varFileData = QByteArrayLiteral("\xEF\xBB\xBF")
                    + std::move(varAllFile);
            }
        }
    } else {
        varFileData = QByteArrayLiteral("\xEF\xBB\xBF")
            + argFileName.toUtf8();
    }

    auto varEngine = qmlEngine(argParent);
    assert(varEngine);
    QQmlComponent varComponent{ varEngine };
    const auto varFileName = IsFileName ?
        QUrl::fromLocalFile(argFileName) :
        QStringLiteral("memory.raw.qml");
    varComponent.setData(varFileData, varFileName);
    auto varRawAns =
        varComponent.beginCreate(qmlContext(argParent));
    if (varRawAns == nullptr) {
        qWarning()
            << QStringLiteral("error building : ")
            << varFileName;
        return nullptr;
    }
    auto varAns = qobject_cast<QQuickItem *>(varRawAns);
    assert(varAns);
    varAns->setParent(argParent);
    varAns->setParentItem(argParent);
    varComponent.completeCreate();
    return varAns;

}

GifTextAreaHelper::GifTextAreaHelper() {

}

void GifTextAreaHelper::classBegin() {
    Super::classBegin();
    auto varEngine = qmlEngine(this);
    assert(varEngine);
    if (!varEngine->imageProvider(PlaceHolderImageProvider::providerName())) {
        varEngine->addImageProvider(PlaceHolderImageProvider::providerName(),
            new PlaceHolderImageProvider);
    }
}

QQuickItem * GifTextAreaHelper::getFlickable() const {
    return mmmFlickAble;
}

QQuickItem * GifTextAreaHelper::getTextArea() const {
    return mmmTextArea;
}

void GifTextAreaHelper::setTextArea(QQuickItem *arg) {
    assert(nullptr == mmmTextArea);
    mmmTextArea = arg;
    assert(arg);
    {
        assert(mmmForeGroundItem == nullptr);
        mmmForeGroundItem = createItem<false>(QStringLiteral(R"_(
import QtQuick 2.11
Item{ 
    visible: true ;
    anchors.fill: parent;
    z : 666 ;
}
)_"), arg);
        assert(mmmForeGroundItem);
    }
    textAreaChanged();
}

void GifTextAreaHelper::setFlickable(QQuickItem *arg) {
    assert(nullptr == mmmFlickAble);
    mmmFlickAble = arg;
    assert(arg);
    flickableChanged();
}

QQuickTextDocument * GifTextAreaHelper::getDocument() const {
    return mmmDocument;
}

void GifTextAreaHelper::pppAboutUpdate() {
    checkVisible();
}

void GifTextAreaHelper::checkVisible() {
    if (!mmmTextLayout) {
        return;
    }
    if (!mmmFlickAble) {
        return;
    }
    if (!mmmForeGroundItem) {
        return;
    }

    const auto varCX =
        mmmFlickAble->property("contentX").toDouble();
    const auto varCY =
        mmmFlickAble->property("contentY").toDouble();

    const auto varWidth =
        mmmFlickAble->width();
    const auto varHeight =
        mmmFlickAble->height();

    if (varWidth < 1) {
        return;
    }
    if (varHeight < 1) {
        return;
    }

    const auto varBegin =
        mmmTextLayout->hitTest({ varCX ,varCY },
            Qt::FuzzyHit);
    const auto varEnd =
        mmmTextLayout->hitTest({ varCX + varWidth,varCY + varHeight },
            Qt::FuzzyHit);

    assert(varEnd >= varBegin);

    const QDir varDir{ sstd::getLocalFileFullFilePath(
        QStringLiteral("myqml/texteditwithgif")) };

    for (const auto & varI : mmmTextLayout->getQmlItems()) {
        if ((varI.first < varBegin) || (varI.first > varEnd)) {/*不可见...*/
            if (varI.second) {
                auto varItem = varI.second->getItem();
                if (varItem) {
                    varItem->setVisible(false);
                }
            }
        } else {/*可见...*/
            if (varI.second) {
                auto varItem = varI.second->getItem();
                if (!varItem) {
                    const auto varHead =
                        QStringLiteral("image://placeholderimageprovider/");
                    auto varImageName =
                        varI.second->getQmlPathName()
                        .replace(QChar('\\'), QChar('/'));
                    assert(varImageName.startsWith(varHead, Qt::CaseInsensitive));
                    varImageName =
                        varImageName.right(varImageName.size() - varHead.size());
                    varItem = createItem(
                        varDir.absoluteFilePath(
                            varImageName),
                        mmmForeGroundItem);
                    if (varItem == nullptr) {
                        continue;
                    }
                    varI.second->setItem(varItem);
                }
                if (varI.second->needUpdatePos()) {
                    varI.second->setNeedUpdatePos(false);
                    auto varDoc = mmmTextLayout->document();
                    auto varBlock = varDoc->findBlock(varI.first);
                    if (!varBlock.isValid()) {
                        varItem->setVisible(false);
                        continue;
                    }
                    auto varBlockLayout = varBlock.layout();
                    if (!varBlockLayout) {
                        varItem->setVisible(false);
                        continue;
                    }
                    const auto varBlockPosition =
                        varBlockLayout->position();
                    auto varPosInCurrentBlock = varI.first - varBlock.position();
                    auto varTextLine = varBlockLayout->lineForTextPosition(
                        varPosInCurrentBlock);
                    if (!varTextLine.isValid()) {
                        varItem->setVisible(false);
                        continue;
                    }
                    auto varPosInCurrentLine =
                        varPosInCurrentBlock - varTextLine.textStart();
                    varI.second->setX(
                        varTextLine.cursorToX(varPosInCurrentLine));
                    varI.second->setY(
                        varTextLine.descent() /*图像对齐底线*/ +
                        varTextLine.y() + varBlockPosition.y()
                    );
                }
                varItem->setX(varI.second->getX());
                varItem->setY(varI.second->getY());
                varItem->setWidth(varI.second->getWidth());
                varItem->setHeight(varI.second->getHeight());
                varItem->setVisible(true);
            }
        }
    }

}

void GifTextAreaHelper::setDocument(QQuickTextDocument * arg) {
    assert(nullptr == mmmDocument);
    mmmDocument = arg;
    assert(arg);
    auto varDocument = mmmDocument->textDocument();
    auto varDocumentLayout = sstd_new<TextDocumentLayout>(varDocument);
    mmmTextLayout = varDocumentLayout;
    varDocument->setDocumentLayout(varDocumentLayout);
    connect(varDocumentLayout, &QAbstractTextDocumentLayout::documentSizeChanged,
        this, [this](const QSizeF &) {
        this->pppAboutUpdate();
    });
    connect(varDocument, &QTextDocument::contentsChanged,
        this, [this]() {
        this->pppAboutUpdate();
    });
    documentChanged();
}

void GifTextAreaHelper::componentComplete() {
    auto varContex = QQmlEngine::contextForObject(this);
    assert(varContex);
    auto varExp = QQmlExpression(varContex, this, QStringLiteral(R"(
              x = Qt.binding( function() { checkVisible(); return -flickable.contentX } )
              y = Qt.binding( function() { checkVisible(); return -flickable.contentY } )
)"));
    varExp.evaluate();
    Super::componentComplete();
}

static inline void register_this() {
    qmlRegisterType<GifTextAreaHelper>(
        "sstd.giftextarea.help",
        1, 0,
        "GifTextAreaHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
















