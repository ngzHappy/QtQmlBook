#include "GifTextAreaHelper.hpp"
#include "PlaceHolderImageProvider.hpp"
#include "TextDocumentLayout.hpp"

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
















