#pragma once

#include <sstd_qt_and_qml_library.hpp>

class ChatDataItem :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ChatDataItem) {
    Q_OBJECT
private:
    Q_PROPERTY(QStringList bodyItems READ bodyItems WRITE setBodyItems NOTIFY bodyItemsChanged)
private:
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
private:
    Q_PROPERTY(bool isLeftItem READ isLeftItem WRITE setIsLeftItem NOTIFY isLeftItemChanged)
public:
    ChatDataItem();
public:
    void setIsLeftItem(bool);
    void setTitle(const QString &);
    void setBodyItems(const QStringList &);
public:
    bool isLeftItem()  const;
    QString getTitle() const;
    QStringList bodyItems() const;
public:
    Q_SIGNAL void bodyItemsChanged();
    Q_SIGNAL void titleChanged();
    Q_SIGNAL void isLeftItemChanged();
private:
    inline QString title() const {
        return getTitle();
    }
private:
    QString mmmTitle;
    QStringList mmmData;
    sstd_bool mmmIsLeft{ true };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ChatDataItem);
};














