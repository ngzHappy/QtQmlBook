#include "TextAreaHelper.hpp"

TextAreaHelper::TextAreaHelper(QQuickItem * arg) :
    Super(arg) {
    this->setFlag(QQuickItem::ItemHasContents, true);
}

QQuickItem * TextAreaHelper::getFlickable() const {
    return mmmFlickAble;
}

QQuickItem * TextAreaHelper::getTextArea() const {
    return mmmTextArea;
}

void TextAreaHelper::setTextArea(QQuickItem *arg) {
    assert(nullptr == mmmTextArea);
    mmmTextArea = arg;
    textAreaChanged();
}

void TextAreaHelper::setFlickable(QQuickItem *arg) {
    assert(nullptr == mmmFlickAble);
    mmmFlickAble = arg;
    flickableChanged();
}

static inline void register_this() {
    qmlRegisterType<TextAreaHelper>(
        "sstd.textarea.help",
        1, 0,
        "TextAreaHelper");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)










