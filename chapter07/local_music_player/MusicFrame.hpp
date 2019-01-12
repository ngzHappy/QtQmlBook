#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "MusicNumber.hpp"

class MusicFrame :
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(MusicFrame) {
public:
    class AudioDataItem {
    public:
        std::uint16_t left;
        std::uint16_t right;
    };
    sstd::vector< AudioDataItem > data;
    MusicNumber pts;
    bool isEndl{ false };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MusicFrame);
};







