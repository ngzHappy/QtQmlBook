#pragma once

#include <sstd_qt_and_qml_library.hpp>

class MemoryWatcherObject :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MemoryWatcherObject) {
    Q_OBJECT
public:
    MemoryWatcherObject();
    ~MemoryWatcherObject();
    std::array<char, 1024 * 4> data;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MemoryWatcherObject);
};
