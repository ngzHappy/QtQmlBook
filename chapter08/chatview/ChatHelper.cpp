#include "ChatHelper.hpp"
#include "CreateLeftTextDocumentLayout.hpp"
#include "CreateRightTextDocumentLayout.hpp"

ChatHelper::ChatHelper() {
}

void ChatHelper::setTextArea(QQuickItem * arg) {
    if (arg == mmmTextView) {
        return;
    }
    assert(mmmTextView == nullptr);
    mmmTextView = arg;
    assert(mmmTextView);

    mmmTextDocument = arg->property("textDocument")
        .value<QQuickTextDocument *>();
    assert(mmmTextDocument);

    auto varTextDocument =
        mmmTextDocument->textDocument();

    bool isLeft =
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

static inline void register_this() {
    qmlRegisterType<ChatHelper>(
        "sstd.chat.help",
        1, 0,
        "ChatHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
