#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "MusicNumber.hpp"

class MusicInformation :
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MusicInformation) {
public:
    class StreamInfo {
    public:
        int streamIndex{ -1 };
        int sample_rate{ -44100 };
        sstd::map<QString, QByteArray> metaData;
    };
    MusicNumber duration;
    sstd::vector< StreamInfo > streamInfo;
    sstd::map<QString, QByteArray> metaData;
    QImage image;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MusicInformation);
};
