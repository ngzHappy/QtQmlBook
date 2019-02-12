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

    textAreaChanged();
}

void ChatHelper::componentComplete() {
    auto varContex = QQmlEngine::contextForObject(this);
    assert(varContex);
    auto varExp = QQmlExpression(varContex, this, QStringLiteral(R"(
              x = Qt.binding( function() { checkVisible(); return -flickable.contentX } )
              y = Qt.binding( function() { checkVisible(); return -flickable.contentY } )
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

void ChatHelper::checkVisible() {
}

static inline void register_this() {
    qmlRegisterType<ChatHelper>(
        "sstd.chat.help",
        1, 0,
        "ChatHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
