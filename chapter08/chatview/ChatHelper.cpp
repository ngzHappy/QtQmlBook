#include "ChatHelper.hpp"
#include "CreateLeftTextDocumentLayout.hpp"
#include "CreateRightTextDocumentLayout.hpp"

ChatHelper::ChatHelper() {
}













static inline void register_this() {
    qmlRegisterType<ChatHelper>(
        "sstd.chat.help",
        1, 0,
        "ChatHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
