#pragma once

#include <sstd_qt_and_qml_library.hpp>

class AudioFrame :
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(AudioFrame) {
public:
    class AudioDataItem {
    public:
        std::uint16_t left;
        std::uint16_t right;
    };
    sstd$(data,sstd::vector< AudioDataItem >);
    sstd$(isEndl,bool) sstd$a(false);
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(AudioFrame);
};








