#include "VideoReader.hpp"

class _VideoReaderPirvate {
public:
    VideoReader* const super;
    _VideoReaderPirvate (VideoReader* s) : super (s) {
    }
};

VideoReader::VideoReader () :
    thisp (sstd_new<_VideoReaderPirvate> (this)) {
}

VideoReader::~VideoReader () {
}



