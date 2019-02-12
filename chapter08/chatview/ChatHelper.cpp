#include "ChatHelper.hpp"
#include "CreateLeftTextDocumentLayout.hpp"
#include "CreateRightTextDocumentLayout.hpp"
#include "PlaceHolderImageProvider.hpp"

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

ChatHelper::ChatHelper() {
}

void ChatHelper::setNativeTextWidth(qreal arg){
    if( std::abs( arg - mmmNativeTextWidth ) < 0.05 /*精度要求较低*/ ){
        return;
    }
    mmmNativeTextWidth = arg;
    nativeTextWidthChanged();
}

void ChatHelper::setTextArea(QQuickItem * arg) {
    if (arg == mmmTextView) {
        return;
    }
    assert(mmmTextView == nullptr);
    mmmTextView = arg;
    assert(mmmTextView);

    {
        assert(mmmForeGroundItem == nullptr);
        mmmForeGroundItem = createItem<false>(QStringLiteral(R"_(
import QtQuick 2.11
Item{
    visible: true ;
    x : 0 ;
    y : 0 ;
    z : 666 ;
}
)_"), arg);
        assert(mmmForeGroundItem);
    }

    mmmTextDocument = arg->property("textDocument")
        .value<QQuickTextDocument *>();
    assert(mmmTextDocument);

    auto varTextDocument =
        mmmTextDocument->textDocument();

    const bool isLeft =
        arg->property("isLeftChat").value<bool>();

    if (isLeft) {
        mmmTextLayout =
            createLeftTextDocumentLayout(varTextDocument);
    } else {
        mmmTextLayout =
            createRightTextDocumentLayout(varTextDocument);
    }
    assert(mmmTextLayout);

    varTextDocument->setDocumentLayout(mmmTextLayout->getLayout());

    connect(mmmTextLayout->getLayout(),
        &QAbstractTextDocumentLayout::documentSizeChanged,
        this, &ChatHelper::checkVisible);

    connect(varTextDocument,
        &QTextDocument::contentsChanged,
        this, &ChatHelper::checkVisible);

    checkVisible();
    textAreaChanged();
}

void ChatHelper::componentComplete() {
    auto varContex = QQmlEngine::contextForObject(this);
    assert(varContex);
    auto varExp = QQmlExpression(varContex, this, QStringLiteral(R"(
              x = 0 ;
              y = 0 ;
)"));
    varExp.evaluate();
    Super::componentComplete();
}

void ChatHelper::classBegin() {
    Super::classBegin();
    auto varEngine = qmlEngine(this);
    assert(varEngine);
    if (!varEngine->imageProvider(PlaceHolderImageProvider::providerName())) {
        varEngine->addImageProvider(PlaceHolderImageProvider::providerName(),
            new PlaceHolderImageProvider);
    }
}

static inline qreal getDocumentMaxWidth( QTextDocument * arg ){
    auto varPosBlock = arg->firstBlock();
    auto varTextWidth = arg->textWidth();
    if(varTextWidth < 0 ){
        varTextWidth = std::numeric_limits< qreal >::max();
    }
    qreal varAns = 0.0;
    while( varPosBlock.isValid() ){
        auto varBlock = varPosBlock;
        varPosBlock=varPosBlock.next();
        if(!varBlock.isVisible()){
            continue;
        }
        auto varTextLayout = varBlock.layout();
        if(varTextLayout){
            auto varLineAllCount = varTextLayout->lineCount();
            for(int i =0;i<varLineAllCount;++i){
                auto varLine = varTextLayout->lineAt(i);
                if(!varLine.isValid()){
                    continue;
                }
                auto varThisLineWidth = varLine.naturalTextWidth();
                if( varThisLineWidth > varAns ){
                    varAns = varThisLineWidth;
                    if( varThisLineWidth >= varTextWidth ){
                        return varTextWidth ;
                    }
                }
            }
        }
    }
    return varAns;
}

void ChatHelper::checkVisible() {
    if (!mmmTextView) {
        return;
    }
    if (!mmmForeGroundItem) {
        return;
    }
    auto varDocument = mmmTextDocument->textDocument();
    if (!varDocument) {
        return;
    }

    {
        auto varDocumentWidth = getDocumentMaxWidth(varDocument);
        setNativeTextWidth( varDocumentWidth );
    }

    const QDir varDir{ sstd::getLocalFileFullFilePath(
        QStringLiteral("myqml/chatview")) };

    for (const auto & varI : mmmTextLayout->getQmlItems()) {
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
            if (varI.second->getNeedUpdatePos()) {
                varI.second->setNeedUpdatePos(false);
                auto varDoc = mmmTextLayout->getDocument();
                auto varBlock = varDoc->findBlock(varI.first);
                if (!varBlock.isValid()) {
                    continue;
                }
                auto varBlockLayout = varBlock.layout();
                if (!varBlockLayout) {
                    continue;
                }
                const auto varBlockPosition =
                    varBlockLayout->position();
                auto varPosInCurrentBlock = varI.first - varBlock.position();
                auto varTextLine = varBlockLayout->lineForTextPosition(
                    varPosInCurrentBlock);
                if (!varTextLine.isValid()) {
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
            varItem->setWidth(varI.second->getItemWidth());
            varItem->setHeight(varI.second->getItemHeight());
            varItem->setVisible(true);
        }
    }

}

static inline void register_this() {
    qmlRegisterType<ChatHelper>(
        "sstd.chat.help",
        1, 0,
        "ChatHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
