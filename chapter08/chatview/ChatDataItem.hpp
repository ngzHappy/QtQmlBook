#pragma once

#include <sstd_qt_and_qml_library.hpp>

class ChatDataItem :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ChatDataItem) {
    Q_OBJECT
public:
    ChatDataItem();
    template<typename T>
    inline ChatDataItem(bool,const QString &, T &&);
    Q_SLOT QString getItem(int) const;
    Q_SLOT int getLength() const;
    Q_SLOT bool isLeftItem() const;
    Q_SLOT QString title() const ;
private:
    sstd_bool mmmIsLeft{ true };
    QString mmmTitle;
    sstd::vector< QString > mmmData;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ChatDataItem);
};

template<typename T>
inline ChatDataItem::ChatDataItem(bool argIsLeft, 
    const QString & argTitle, T && arg) :
    mmmIsLeft{ argIsLeft } , 
    mmmTitle(argTitle) {
    mmmData.reserve(static_cast<std::size_t>(arg.size()));
    mmmData.assign(arg.cbegin(), arg.cend());
}













