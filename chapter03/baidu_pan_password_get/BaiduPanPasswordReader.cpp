#include "BaiduPanPasswordReader.hpp"
#include <optional>

class _BaiduPanPasswordReader final :
    public sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_BaiduPanPasswordReader) {
public:
    QFile logFile;
    std::optional< QTextStream > logFileStream;
public:
    inline _BaiduPanPasswordReader() {
        const auto varFileName = sstd::getLocalFileFullFilePath(
            QStringLiteral("myqml/baidu_pan_password_get/keys.txt"));
        logFile.setFileName(varFileName);
        if (false == logFile.open(QIODevice::Text | QIODevice::ReadOnly)) {
            return;
        }
        logFileStream.emplace(&logFile);
    }
    inline ~_BaiduPanPasswordReader() {

    }
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(_BaiduPanPasswordReader);
};

template<typename T>
inline static _BaiduPanPasswordReader * get_thisp(T && arg) {
    return static_cast<_BaiduPanPasswordReader *>(arg.get());
}

BaiduPanPasswordReader::BaiduPanPasswordReader() {
    thisp = sstd_make_intrusive_ptr<_BaiduPanPasswordReader>();

}

void BaiduPanPasswordReader::moveToStart() {
    auto varThisP = get_thisp(thisp);
    if (varThisP->logFileStream) {
        varThisP->logFileStream->seek(0);
    }
}

QString BaiduPanPasswordReader::getNext() {
    auto varThisP = get_thisp(thisp);
    if (varThisP->logFileStream) {
        return varThisP->logFileStream->readLine();
    }
    return{};
}

bool BaiduPanPasswordReader::isEndl() const {
    auto varThisP = get_thisp(thisp);
    if (varThisP->logFileStream) {
        return varThisP->logFileStream->atEnd();
    }
    return true;
}

void BaiduPanPasswordReader::setMaximumBlockCount(QQuickTextDocument * arg) {
    auto varDocument = arg->textDocument();
    if (varDocument) {
        varDocument->setMaximumBlockCount(16);
    }
}

static inline void register_this() {
    qmlRegisterType<BaiduPanPasswordReader>(
        "myqml.baidu",
        1, 0,
        "BaiduPanPasswordReader");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)






















