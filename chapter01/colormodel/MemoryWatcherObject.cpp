#include "MemoryWatcherObject.hpp"

namespace this_file {
    std::atomic<std::intmax_t> globalCount{ 0 };
}/**/

MemoryWatcherObject::MemoryWatcherObject() {
    qDebug() << __func__ << ++this_file::globalCount;
}

MemoryWatcherObject::~MemoryWatcherObject() {
    qDebug() << __func__ << --this_file::globalCount;
}

static inline void register_this() {
    qmlRegisterType<MemoryWatcherObject>(
        "sstd.color.model",
        1, 0,
        "MemoryWatcherObject");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
