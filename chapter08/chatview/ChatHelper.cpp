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
    textAreaChanged();
}

void ChatHelper::setDocument(QQuickTextDocument * arg) {
    if (arg == mmmDocument) {
        return;
    }
    assert(mmmDocument == nullptr);
    mmmDocument = arg;
    assert(mmmDocument);
    documentChanged();
}

static inline void register_this() {
    qmlRegisterType<ChatHelper>(
        "sstd.chat.help",
        1, 0,
        "ChatHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
