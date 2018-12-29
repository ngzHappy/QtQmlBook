#include "ExternByCplusplus.hpp"

ExternByCplusplus::ExternByCplusplus() {
    setData(trUtf8(u8R"(你好世界!)"));
}

ExternByCplusplus::~ExternByCplusplus() {
}

QString ExternByCplusplus::getData() const {
    return mmmData;
}

void ExternByCplusplus::setData(const QString & arg) {
    if (arg == mmmData) {
        return;
    }
    mmmData = arg;
    dataChanged();
}

static inline void register_this() {
    qmlRegisterType<ExternByCplusplus>(
        "sstd.externbycplusplus",
        1, 0,
        "ExternByCplusplus");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)


