#include "VideoReader.hpp"

extern "C" {
#include <libavutil/avstring.h>
#include <libavutil/eval.h>
#include <libavutil/mathematics.h>
#include <libavutil/pixdesc.h>
#include <libavutil/imgutils.h>
#include <libavutil/dict.h>
#include <libavutil/parseutils.h>
#include <libavutil/samplefmt.h>
#include <libavutil/avassert.h>
#include <libavutil/time.h>
#include <libavformat/avformat.h>
#include <libavdevice/avdevice.h>
#include <libswscale/swscale.h>
#include <libavutil/opt.h>
#include <libavcodec/avfft.h>
#include <libswresample/swresample.h>
#include <libavfilter/avfilter.h>
#include <libavfilter/buffersink.h>
#include <libavfilter/buffersrc.h>
}

#ifndef ffmpeg
#define ffmpeg
#endif

namespace this_file {

    /*ffmpeg错误临时缓冲区*/
    using av_error_tmp_buffer_type = std::array<char,1024 * 1024>;
    inline static av_error_tmp_buffer_type & getStringTmpBuffer() {
        static av_error_tmp_buffer_type varAns;
        return varAns;
    }

    class callpack_this_file_ffmpge_open_file :
        public sstd_function_stack,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(callpack_this_file_ffmpge_open_file) {
        QByteArray mmmLocalFileName;
    public:
        inline callpack_this_file_ffmpge_open_file(const QString & arg) {
            mmmLocalFileName = arg.toLocal8Bit();
        }
        const auto & getLocalFileName() const {
            return mmmLocalFileName;
        }
        ~callpack_this_file_ffmpge_open_file() {
            if(isOk) {
                return;
            }
            ffmpeg::avformat_close_input(&contex);
        }
        ffmpeg::AVFormatContext * contex{ nullptr };
        bool isOk{ false };
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(callpack_this_file_ffmpge_open_file);
    };

    /*ffmpeg打开和关闭文档不是线程安全的，因而将其强制到一个线程...*/
    /*打开文档*/
    inline static bool this_file_ffmpge_open_file(
        const QString & arg,
        ffmpeg::AVFormatContext ** argContex) {
        FFMPEGOpenCloseThread varThread;
        auto varCallPack = sstd_make_intrusive_ptr<
            callpack_this_file_ffmpge_open_file>(arg);
        varThread.call([varCallPack]() {
            auto varError = -1;

            AVDictionary* opts = nullptr;
            ffmpeg::av_dict_set(&opts,"timeout","3000000",0)/*udp,http*/;
            ffmpeg::av_dict_set(&opts,"stimeout","3000000",0)/*rtsp*/;
            varError = ffmpeg::avformat_open_input(
                &(varCallPack->contex),
                varCallPack->getLocalFileName().constData(),
                nullptr,
                &opts);

            ffmpeg::av_dict_free(&opts);

            if((varError != 0) || (varCallPack->contex == nullptr)) {
                auto & varTmp = getStringTmpBuffer();
                ffmpeg::av_strerror(
                    varError,
                    varTmp.data(),
                    varTmp.size());
                sstd_log(varTmp.data());
                return;
            }

            varError = ffmpeg::avformat_find_stream_info(
                varCallPack->contex,
                nullptr);

            if(varError != 0) {
                auto & varTmp = getStringTmpBuffer();
                ffmpeg::av_strerror(
                    varError,
                    varTmp.data(),
                    varTmp.size());
                sstd_log(varTmp.data());
                return;
            }

            varCallPack->isOk = true;

        }).wait()/*打开文件时开启同步等待*/;

        if(varCallPack->isOk) {
            *argContex = varCallPack->contex;
            return true;
        }

        *argContex = nullptr;
        return false;
    }

}/*this_file*/

class _VideoReaderPirvate {
public:
    VideoReader* const super ;
    sstd_bool isFileOpen  sstd$a(false);
    ffmpeg::AVFormatContext * contex sstd$a(nullptr);
    _VideoReaderPirvate(VideoReader* s) : super(s) {
    }

    inline bool open(const QString & arg) {
        using namespace this_file;
        if(isFileOpen) {
            return false;
        }
        if(arg.isEmpty()) {
            return false;
        }
        isFileOpen =
            this_file_ffmpge_open_file(arg,&contex);
        if(isFileOpen) {
            //TODO:
        }
        return isFileOpen;
    }

};

VideoReader::VideoReader() :
    thisp(sstd_new<_VideoReaderPirvate>(this)) {
}

VideoReader::~VideoReader() {
    delete thisp;
}

bool VideoReader::open(const QString & arg) {
    return const_cast<_VideoReaderPirvate*>(thisp)
        ->open(arg);
}

