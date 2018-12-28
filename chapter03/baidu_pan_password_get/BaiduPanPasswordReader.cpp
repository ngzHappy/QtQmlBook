#include "BaiduPanPasswordReader.hpp"
#include <optional>

class _BaiduPanPasswordReader final :
    public sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_BaiduPanPasswordReader) {
public:
    QFile logFile;
    std::optional< QTextStream > logFileStream;
public:
    inline _BaiduPanPasswordReader(int argInput) {
        const auto varFileName = sstd::getLocalFileFullFilePath(
            QString("myqml/baidu_pan_password_get/%1keys.txt").arg(argInput, 8, 10, QChar('0')));
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
    thisp = sstd_make_intrusive_ptr<_BaiduPanPasswordReader>(0);

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
        varDocument->setMaximumBlockCount(128);
    }
}

void BaiduPanPasswordReader::openFile(int arg){
    thisp = sstd_make_intrusive_ptr<_BaiduPanPasswordReader>(arg);
}

static inline void register_this() {
    qmlRegisterType<BaiduPanPasswordReader>(
        "myqml.baidu",
        1, 0,
        "BaiduPanPasswordReader");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)






















