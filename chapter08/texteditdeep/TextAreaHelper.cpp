#include "TextAreaHelper.hpp"

TextAreaHelper::TextAreaHelper( QQuickItem * arg ) :
    Super(arg) {

}

QObject * TextAreaHelper::getFlickable() const{
    return mmmFlickAble;
}

QObject * TextAreaHelper::getTextArea() const{
    return mmmTextArea;
}

void TextAreaHelper::setTextArea(QObject *arg){
    assert( nullptr == mmmTextArea );
    mmmTextArea = arg;
    textAreaChanged();
}

void TextAreaHelper::setFlickable(QObject *arg){
    assert( nullptr==mmmFlickAble );
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










