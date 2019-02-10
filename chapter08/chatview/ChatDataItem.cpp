#include "ChatDataItem.hpp"






static inline void register_this() {
    qmlRegisterType<ChatDataItem>(
        "sstd.chat.help",
        1, 0,
        "ChatDataItem");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
