#include "ChatDataItem.hpp"

bool ChatDataItem::isLeftItem() const {
    return mmmIsLeft;
}

QStringList ChatDataItem::bodyItems() const {
    return mmmData;
}

QString ChatDataItem::getTitle() const {
    return mmmTitle;
}

ChatDataItem::ChatDataItem() {
}

void ChatDataItem::setIsLeftItem(bool arg) {
    if (arg == mmmIsLeft) {
        return;
    }
    mmmIsLeft = arg;
    isLeftItemChanged();
}

void ChatDataItem::setTitle(const QString & arg) {
    if (arg == mmmTitle) {
        return;
    }
    mmmTitle = arg;
    titleChanged();
}

void ChatDataItem::setBodyItems(const QStringList & arg) {
    if (arg.size() == mmmData.size()) {
        if (arg == mmmData) {
            return;
        }
    }
    mmmData = arg;
    bodyItemsChanged();
}

static inline void register_this() {
    qmlRegisterType<ChatDataItem>(
        "sstd.chat.help",
        1, 0,
        "ChatDataItem");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
