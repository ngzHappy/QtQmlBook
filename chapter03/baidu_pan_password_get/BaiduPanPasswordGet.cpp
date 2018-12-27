#include "BaiduPanPasswordGet.hpp"
#include "NetworkAccessManager.hpp"

inline const static QString loginIdJS = QStringLiteral( R"_js__(

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

p();

)_js__" ) ;

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

class CallPack :
    public sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(CallPack) {
public:
    sstd::intrusive_ptr< _NetworkAccessManager > networkAccessManager;
    QJSEngine jsEngine;
public:
    inline CallPack() {
    }
    ~CallPack() {
    }

    inline QByteArray getLoginID() {
        return jsEngine.evaluate(loginIdJS).toString().toUtf8();
    }

private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(CallPack);
};

class _BaiduPanPasswordGetPrivate {
public:
    QUrl url;
    QString passWord;
    BaiduPanPasswordGet * const super;


    inline _BaiduPanPasswordGetPrivate(BaiduPanPasswordGet * arg)
        :super(arg) {

    }

    inline ~_BaiduPanPasswordGetPrivate() {

    }

    void start() {

        sstd::intrusive_ptr< _NetworkAccessManager > varNetworkAccessManager
            = sstd_make_intrusive_ptr< _NetworkAccessManager >();
        auto varCallPack =
            sstd_make_intrusive_ptr<CallPack>();
        varCallPack->networkAccessManager = varNetworkAccessManager;

        QNetworkRequest varRequest{};
        varRequest.setUrl(url);
        varRequest.setRawHeader(getUserAgent().first, getUserAgent().second);
        auto varReply = varNetworkAccessManager->get(varRequest);

        varReply->connect(
            varReply, &QNetworkReply::finished,
            varReply, [varCallPack, varReply]() {
            varReply->deleteLater();

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

QUrl BaiduPanPasswordGet::getUrl() const {
    return thisp->url;
}

void BaiduPanPasswordGet::setUrl(const QUrl & arg) {
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
    thisp->passWord = arg;
    passWordChanged();
}

void BaiduPanPasswordGet::start() {
}

