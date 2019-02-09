#include "GifTextAreaHelper.hpp"
#include "PlaceHolderImageProvider.hpp"
#include "TextDocumentLayout.hpp"

namespace this_file {
    class Item :
        public QQuickItem,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Item) {
    public:
        inline Item() {
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Item);
    };
}/**/

inline static QQuickItem * createItem(const QString & argFileName,
    QQuickItem * argParent) {

    QFile varFile{ argFileName };
    if (!varFile.open(QIODevice::ReadOnly)) {
        qWarning()
            << QStringLiteral("can not open : ")
            << argFileName;
        return nullptr;
    }

    QByteArray varFileData;

    {
        auto varAllFile = varFile.readAll();
        if (varAllFile.startsWith(QByteArrayLiteral("\xEF\xBB\xBF"))) {
            varFileData = std::move(varAllFile);
        } else {
            varFileData = QByteArrayLiteral("\xEF\xBB\xBF") + std::move(varAllFile);
        }
    }

    QQmlComponent varComponent{ qmlEngine(argParent) };
    varComponent.setData(varFileData, QUrl::fromLocalFile(argFileName));
    auto varAns = qobject_cast<QQuickItem *>(
        varComponent.beginCreate(qmlContext(argParent)));
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
        mmmForeGroundItem = sstd_new<this_file::Item>();
        mmmForeGroundItem->setParent(arg);
        mmmForeGroundItem->setParentItem(arg);
        connect(this, &QQuickItem::xChanged,
            mmmForeGroundItem, [this]() {
            mmmForeGroundItem->setX(this->x());
        });
        connect(this, &QQuickItem::yChanged,
            mmmForeGroundItem, [this]() {
            mmmForeGroundItem->setY(this->y());
        });
        mmmForeGroundItem->setX(this->x());
        mmmForeGroundItem->setY(this->y());
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

    const auto varCX =
        mmmFlickAble->property("contentX").toDouble();
    const auto varCY =
        mmmFlickAble->property("contentY").toDouble();

    const auto varWidth =
        mmmFlickAble->width();
    const auto varHeight =
        mmmFlickAble->height();

    const auto varBegin =
        mmmTextLayout->hitTest({ varCX ,varCY }, Qt::FuzzyHit);
    const auto varEnd =
        mmmTextLayout->hitTest({ varCX + varWidth,varCY + varHeight }, Qt::FuzzyHit);

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
                    varItem = createItem(
                        varDir.absoluteFilePath(
                            varI.second->getQmlPathName()),
                        mmmForeGroundItem);
                    if (varItem == nullptr) {
                        continue;
                    }
                    varI.second->setItem(varItem);
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
















