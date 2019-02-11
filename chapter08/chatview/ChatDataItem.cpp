#include "ChatDataItem.hpp"

QString ChatDataItem::getItem(int arg) const {
    return mmmData[arg];
}

int ChatDataItem::getLength() const {
    return static_cast<int>( mmmData.size() );
}

bool ChatDataItem::isLeftItem() const {
    return mmmIsLeft;
}

QString ChatDataItem::title() const {
    return mmmTitle;
}

ChatDataItem::ChatDataItem() {
}

static inline void register_this() {
    qmlRegisterType<ChatDataItem>(
        "sstd.chat.help",
        1, 0,
        "ChatDataItem");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
