#pragma once

#include "AudioFrame.hpp"
#include "AudioNumber.hpp"
#include "FFMPEGOpenCloseThread.hpp"

class _VideoReaderPirvate;
class VideoReader :
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(VideoReader)  {
public:
    VideoReader();
    ~VideoReader();
private:
    sstd$(thisp,const _VideoReaderPirvate *);
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(VideoReader);
};
















