#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "MusicNumber.hpp"

class MusicInformation :
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MusicInformation) {
public:
    class StreamInfo {
    public:
        int streamIndex{0};
        QString streamName;

    };
    std::int64_t duration{ 0 };
    sstd::vector< StreamInfo > streamInfo;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MusicInformation);
};






















