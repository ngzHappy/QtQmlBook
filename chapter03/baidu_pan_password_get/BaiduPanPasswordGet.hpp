#pragma once

#include <sstd_qt_and_qml_library.hpp>

class _BaiduPanPasswordGetPrivate;
class BaiduPanPasswordGet :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(BaiduPanPasswordGet) {
    Q_OBJECT
private:
    Q_PROPERTY(int tryCount READ getTryCount NOTIFY tryCountChanged)
private:
    Q_PROPERTY(QString passWord READ getPassWord WRITE setPassWord NOTIFY passWordChanged)
private:
    Q_PROPERTY(QString url READ getUrl WRITE setUrl NOTIFY urlChanged)
public:
    enum ReturnState {
        Ok,
        Error,
        Unknow
    };
public:
    Q_ENUM(ReturnState)
public:
    BaiduPanPasswordGet();
    ~BaiduPanPasswordGet();
public:
    QString getUrl() const;
    void setUrl(const QString &);
    Q_SIGNAL void urlChanged();
public:
    QString getPassWord() const;
    void setPassWord(const QString &);
    Q_SIGNAL void passWordChanged();
public:
    Q_SLOT void start();
    Q_SLOT QString errorCodeString(ReturnState);
    Q_SIGNAL void finished(QString argUrl, QString argPassWord, ReturnState argErrorCode);
public:
    int getTryCount() const;
    Q_SIGNAL void tryCountChanged();
private:
    friend class ::_BaiduPanPasswordGetPrivate;
    _BaiduPanPasswordGetPrivate * thisp{ nullptr };
    void _finished(QString argUrl, QString argPassWord, ReturnState argErrorCode);
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(BaiduPanPasswordGet);
};












