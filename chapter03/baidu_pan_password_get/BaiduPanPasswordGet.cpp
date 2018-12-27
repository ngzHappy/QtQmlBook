﻿#include "BaiduPanPasswordGet.hpp"
#include "NetworkAccessManager.hpp"
#include "BaiduPanPack.hpp"

inline const static QString loginIdJS = QStringLiteral(R"_js__(

var u = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/~！@#￥%……&" ;
var l = String.fromCharCode ;
var d = function (e) {
    if (e.length < 2) {
        var n = e.charCodeAt(0);
        return 128 > n ? e : 2048 > n ? l(192 | n >>> 6) + l(128 | 63 & n) : l(224 | n >>> 12 & 15) + l(128 | n >>> 6 & 63) + l(128 | 63 & n)
    }
    var n = 65536 + 1024 * (e.charCodeAt(0) - 55296) + (e.charCodeAt(1) - 56320);
    return l(240 | n >>> 18 & 7) + l(128 | n >>> 12 & 63) + l(128 | n >>> 6 & 63) + l(128 | 63 & n)
} ;
var f = /[\uD800-\uDBFF][\uDC00-\uDFFFF]|[^\x00-\x7F]/g ;
var g = function (e) {
    return (e + "" + Math.random()).replace(f, d)
} ;
var h = function (e) {
    var n = [0, 2, 1][e.length % 3],
        t = e.charCodeAt(0) << 16 | (e.length > 1 ? e.charCodeAt(1) : 0) << 8 | (e.length > 2 ? e.charCodeAt(2) : 0),
        o = [u.charAt(t >>> 18), u.charAt(t >>> 12 & 63), n >= 2 ? "=" : u.charAt(t >>> 6 & 63), n >= 1 ? "=" : u.charAt(63 & t)];
    return o.join("")
} ;
var m = function (e) {
    return e.replace(/[\s\S]{1,3}/g, h)
} ;
var p = function () {
    return m(g((new Date).getTime()))
} ;

)_js__");

inline static QByteArray getCurrentTime() {
    return QByteArray::number(QDateTime::currentMSecsSinceEpoch());
}

class _NetworkAccessManager final :
    public NetworkAccessManager,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_NetworkAccessManager) {
public:

    _NetworkAccessManager() {
    }

    ~_NetworkAccessManager() {
    }



private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(_NetworkAccessManager);
};

inline static const std::pair<QByteArray, QByteArray>& getUserAgent() {
    const static std::pair<QByteArray, QByteArray> varAns{
        "User-Agent"_qbya,
        "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36"_qbya,
    };
    return varAns;
}

class _CallPack :
    public BaiduPanPack,
    public sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_CallPack) {
public:
    const QString url;
    const QString passWord;
    sstd::intrusive_ptr< _NetworkAccessManager > networkAccessManager;
    QJSEngine  jsEngine;
    QByteArray baiduIDValue;
public:
    inline _CallPack(const QString &u, const QString &p) :
        url(u),
        passWord(p) {
        jsEngine.evaluate(loginIdJS);
    }

    ~_CallPack() {
    }

    inline QByteArray getLoginID() {
        return jsEngine
            .evaluate(QStringLiteral("p(\"")
                + QString::fromLatin1(baiduIDValue)
                + QStringLiteral("\")"))
            .toString()
            .toUtf8();
    }

    void setBaiduIDValue(const QByteArray & arg) {
        baiduIDValue = arg;
    }

private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(_CallPack);
};

class GetCookieAllJarFunction : public QNetworkCookieJar {
public:
    inline static auto getFunction() {
        return &QNetworkCookieJar::allCookies;
    }
};

class _BaiduPanPasswordGetPrivate {
public:
    QString url;
    QString passWord;
    BaiduPanPasswordGet * const super;

    inline _BaiduPanPasswordGetPrivate(BaiduPanPasswordGet * arg)
        :super(arg) {

    }

    inline ~_BaiduPanPasswordGetPrivate() {

    }

    void start() {

        const static auto varBaiduID = "BAIDUID"_qbya;

        sstd::intrusive_ptr< _NetworkAccessManager > varNetworkAccessManager
            = sstd_make_intrusive_ptr< _NetworkAccessManager >();
        auto varCallPack =
            sstd_make_intrusive_ptr<_CallPack>(url, passWord);
        varCallPack->networkAccessManager = varNetworkAccessManager;

        QObject::connect(
            varCallPack.get(), &_CallPack::finished,
            super, &BaiduPanPasswordGet::finished,
            Qt::QueuedConnection);

        QNetworkRequest varRequest{};
        varRequest.setUrl(url);
        varRequest.setRawHeader(getUserAgent().first, getUserAgent().second);
        auto varReply = varNetworkAccessManager->get(varRequest);

        /*保证包在reply之后删除*/
        QObject::connect(
            varReply, &QObject::destroyed,
            varCallPack.get(), [varCallPack]() {
            QTimer::singleShot(0, varCallPack.get(),
                [varCallPack]() {}); });

        varReply->connect(
            varReply, &QNetworkReply::finished,
            varReply, [varCallPack, varReply]() {
            varReply->deleteLater();

            {/*查询是否成功...*/
                auto varCookieJar =
                    varCallPack->networkAccessManager->cookieJar();

                const auto varCookies =
                    (varCookieJar->*GetCookieAllJarFunction::getFunction())();

                do {
                    bool isNotNull = false;
                    for (const auto & varC : varCookies) {
                        if (varC.name() == varBaiduID) {
                            varCallPack->setBaiduIDValue(varC.value());
                            isNotNull = true;
                            break;
                        }
                    }
                    if (isNotNull) {
                        break;
                    }
                    varCallPack->finished(
                        varCallPack->passWord,
                        BaiduPanPasswordGet::Unknow);
                    return;
                } while (false);
            }

            auto varUrl = varCallPack->url;
            varUrl.replace(
                QStringLiteral("/init?"),
                QStringLiteral("/verify?"));

            auto varPostData = "&t="_qbya + getCurrentTime();
            varPostData += "&channel=chunlei"
                "&web=1"
                "&app_id=250528"
                "&bdstoken=null"
                "&logid="_qbya;
            varPostData += varCallPack->getLoginID();
            varPostData += "&clienttype=0"_qbya;
            varPostData += "&pwd="_qbya + varCallPack->passWord.toLatin1();

            QNetworkRequest varRequest{};
            varRequest.setUrl(varUrl);
            varRequest.setRawHeader(getUserAgent().first, getUserAgent().second);
            varRequest.setRawHeader(
                u8R"(Content-Type)"_qbya,
                u8R"(application/x-www-form-urlencoded; charset=UTF-8)"_qbya);
            varRequest.setRawHeader(
                u8R"(Referer)"_qbya,
                varCallPack->url.toUtf8());

            auto varReply =
                varCallPack
                ->networkAccessManager
                ->post(varRequest, varPostData);

            /*保证包在reply之后删除*/
            QObject::connect(
                varReply, &QObject::destroyed,
                varCallPack.get(), [varCallPack]() {
                QTimer::singleShot(0, varCallPack.get(),
                    [varCallPack]() {}); });

            varReply->connect(
                varReply, &QNetworkReply::finished,
                varReply, [varCallPack, varReply]() {
                varReply->deleteLater();

                const auto varAns = QStringLiteral("var jf = function() {  var ansx = ") +
                    QString::fromLatin1(varReply->readAll())
                    + QStringLiteral(";return ansx.errno ; } ; jf() ");
                auto varValue =
                    varCallPack->jsEngine.evaluate(varAns);

                if (varValue.isError()) {
                    varCallPack->finished(varCallPack->passWord, BaiduPanPasswordGet::Unknow);
                } else {
                    auto varError = varValue.toInt();
                    if (varError == 0) {
                        varCallPack->finished(varCallPack->passWord, BaiduPanPasswordGet::Ok);
                    } else if (varError == -9) {
                        varCallPack->finished(varCallPack->passWord, BaiduPanPasswordGet::Error);
                    } else {
                        varCallPack->finished(varCallPack->passWord, BaiduPanPasswordGet::Unknow);
                    }
                }

            });

        });

    }

};

BaiduPanPasswordGet::BaiduPanPasswordGet() {
    thisp =
        sstd_new<_BaiduPanPasswordGetPrivate>(this);
}

BaiduPanPasswordGet::~BaiduPanPasswordGet() {
    delete thisp;
}

QString BaiduPanPasswordGet::getUrl() const {
    return thisp->url;
}

void BaiduPanPasswordGet::setUrl(const QString & arg) {
    if (arg == thisp->url) {
        return;
    }
    thisp->url = arg;
    urlChanged();
}

QString BaiduPanPasswordGet::getPassWord() const {
    return thisp->passWord;
}

void BaiduPanPasswordGet::setPassWord(const QString & arg) {
    if (arg == thisp->passWord) {
        return;
    }
    if (arg.isEmpty()) {
        return;
    }
    thisp->passWord = arg;
    passWordChanged();
}

void BaiduPanPasswordGet::start() {
    thisp->start();
}


static inline void register_this() {
    qmlRegisterType<BaiduPanPasswordGet>(
        "myqml.baidu",
        1, 0,
        "BaiduPanPasswordGet");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
