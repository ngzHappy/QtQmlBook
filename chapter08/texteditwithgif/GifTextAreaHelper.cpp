#include "GifTextAreaHelper.hpp"
#include "PlaceHolderImageProvider.hpp"
#include "TextDocumentLayout.hpp"

inline static QQuickItem * createItem(const QString & argFileName,
    QQuickItem * argParent) {

    QFile varFile{ argFileName };
    if (!varFile.open(QIODevice::ReadOnly)) {
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
    varComponent.setData(varFileData,QUrl::fromLocalFile(argFileName));
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

void GifTextAreaHelper::setDocument(QQuickTextDocument * arg) {
    assert(nullptr == mmmDocument);
    mmmDocument = arg;
    assert(arg);
    auto varDocument = mmmDocument->textDocument();
    auto varDocumentLayout = sstd_new<TextDocumentLayout>(varDocument);
    mmmTextLayout = varDocumentLayout;
    varDocument->setDocumentLayout(varDocumentLayout);
    //connect(varDocumentLayout, &QAbstractTextDocumentLayout::documentSizeChanged,
    //    this, [this](const QSizeF &) {
    //    this->pppAboutUpdate();
    //});
    //connect(varDocument, &QTextDocument::contentsChanged,
    //    this, [this]() {
    //    this->pppAboutUpdate();
    //});
    documentChanged();
}

static inline void register_this() {
    qmlRegisterType<GifTextAreaHelper>(
        "sstd.giftextarea.help",
        1, 0,
        "GifTextAreaHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
















