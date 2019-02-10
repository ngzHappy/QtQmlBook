#pragma once

#include <sstd_qt_and_qml_library.hpp>

class ChatHelper : 
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ChatHelper) {
    Q_OBJECT
public:
    ChatHelper();
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ChatHelper);
};
