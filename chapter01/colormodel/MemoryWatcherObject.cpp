#include "MemoryWatcherObject.hpp"

MemoryWatcherObject::MemoryWatcherObject() {

}

static inline void register_this() {
    qmlRegisterType<MemoryWatcherObject>(
        "sstd.color.model",
        1, 0,
        "MemoryWatcherObject");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)



