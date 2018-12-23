#pragma once

#include <sstd_qt_and_qml_library.hpp>

class MusicFrame :
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MusicFrame) {
public:
    class AudioDataItem {
    public:
        std::uint16_t left;
        std::uint16_t right;
    };
    sstd::vector< AudioDataItem > data;
    std::int64_t pts{ 0 };
    std::int64_t num{ 1 };
    std::int64_t den{ 1'000'000 };
    bool isEndl{ false };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MusicFrame);
};







