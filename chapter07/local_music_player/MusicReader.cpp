﻿#include "MusicReader.hpp"
#include "FFMPEGOpenCloseThread.hpp"

#include <mutex>
#include <shared_mutex>
#include <condition_variable>

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
    using av_error_tmp_buffer_type = std::array<char, 1024 * 1024>;
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
            if (isOk) {
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

            varError = ffmpeg::avformat_open_input(
                &(varCallPack->contex),
                varCallPack->getLocalFileName().constData(),
                nullptr,
                nullptr);

            if ((varError != 0) || (varCallPack->contex == nullptr)) {
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

            if (varError != 0) {
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

        if (varCallPack->isOk) {
            *argContex = varCallPack->contex;
            return true;
        }

        *argContex = nullptr;
        return false;
    }

    /*关闭文档*/
    inline static void this_file_ffmpeg_close_file(ffmpeg::AVFormatContext ** argContex) {
        FFMPEGOpenCloseThread varThread;
        varThread.call([varContex = *argContex]() mutable {
            ffmpeg::avformat_close_input(&varContex);
        })/*关闭文件无需同步等待*/;
        *argContex = nullptr;
    }

    template<typename T>
    class Thread final :
        public T,
        public sstd_intrusive_ptr_basic {
        std::thread mmmThread;
        std::atomic_bool mmmIsQuit{ false };
    public:

        template<typename ... U>
        inline Thread(U && ... u) :T(std::forward<U>(u)...) {
            mmmThread = std::thread([this]() {
                run_this();
            });
        }

        inline ~Thread() {
            quit();
        }

        inline void quit() {
            if (mmmIsQuit.load()) {
                return;
            }
            mmmIsQuit.store(true);
            this->wake_up();
            if (mmmThread.joinable()) {
                mmmThread.join();
            }
        }
    private:
        inline void run_this() {
            while (false == mmmIsQuit.load()) {
                bool varHasData = false;
                {
                    std::unique_lock varLock{ this->getMutex() };
                    this->getWait().wait_for(varLock, 100ms, [this]() ->bool {
                        if (mmmIsQuit.load()) {
                            return true;
                        }
                        return this->needRunNext();
                    });
                    varHasData = this->hasData() && this->needRunNext();
                }
                if (varHasData) {
                    this->run();
                }
            }
        }
    private:
        SSTD_DEFINE_STATIC_CLASS(Thread);
    };

    class _ThreadDataBasic {
        std::mutex mmmMutex;
        std::condition_variable mmmWait;
    public:
        inline std::mutex & getMutex() {
            return mmmMutex;
        }
        inline std::condition_variable & getWait() {
            return mmmWait;
        }
        inline void wake_up() {
            mmmWait.notify_all();
        }
    };

    class FFMPEGPack final :
        public sstd_intrusive_ptr_basic,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(FFMPEGPack) {
        ffmpeg::AVPacket * mmmPacket{ nullptr };
    public:
        inline FFMPEGPack() {
            mmmPacket = ffmpeg::av_packet_alloc();
            ffmpeg::av_init_packet(mmmPacket);
        }
        inline void unref() {
            ffmpeg::av_packet_unref(mmmPacket);
        }
        inline ~FFMPEGPack() {
            this->unref();
            ffmpeg::av_packet_free(&mmmPacket);
        }
        inline ffmpeg::AVPacket * get() const {
            return mmmPacket;
        }
        inline ffmpeg::AVPacket * data() const {
            return this->get();
        }
        inline operator ffmpeg::AVPacket *() const {
            return this->get();
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(FFMPEGPack);
    };

    /*avpack对象池,
    因为某些解码器会对avpack做cache,
    导致在关闭文件前一些资源无法释放,
    因而用对象池限制avpack数量*/
    class PackPool final {
        std::shared_mutex mmmMutex;
        using packes_type = sstd::list< sstd::intrusive_ptr< FFMPEGPack > >;
        packes_type mmmPacks;
        packes_type::const_iterator mmmPos;
    public:

        inline PackPool() {
            mmmPos = mmmPacks.cend();
        }

        inline void clear() {
            std::unique_lock varLock{ mmmMutex };
            mmmPacks.clear();
            mmmPos = mmmPacks.cend();
        }

        inline sstd::intrusive_ptr< FFMPEGPack > getAPack() {

            std::size_t varPackSize = 1;
            do {
                const auto varLastPos = mmmPos;
                std::shared_lock varLock{ mmmMutex };
                varPackSize = mmmPacks.size();
                if (varPackSize == 0) {
                    break;
                }
                const auto varEnd = mmmPacks.cend();
                for (; mmmPos != varEnd; ++mmmPos) {
                    if ((*mmmPos)->sstd_intrusive_ptr_count() == 1) {
                        return *mmmPos++;
                    }
                }
                mmmPos = mmmPacks.cbegin();
                for (; mmmPos != varLastPos; ++mmmPos) {
                    if ((*mmmPos)->sstd_intrusive_ptr_count() == 1) {
                        return *mmmPos++;
                    }
                }
            } while (false);

            if (varPackSize < 256/*constexpr*/) {
                std::unique_lock varLock{ mmmMutex };
                FFMPEGPack * varAns;
                for (auto varI = 0; varI < 8; ++varI) {
                    varAns = sstd_new<FFMPEGPack>();
                    mmmPacks.emplace_back(varAns);
                }
                mmmPos = --mmmPacks.end();
                return varAns;
            }

            return{};

        }

    private:
        SSTD_DEFINE_STATIC_CLASS(PackPool);
    };

    class _PackThread :
        public _ThreadDataBasic {
        PackPool mmmPacksPool;
        _MusicReaderPrivate * const mmmPrivate;
    public:

        inline void run() {
            call_this_once_run();
        }

        _PackThread(_MusicReaderPrivate * arg) :
            mmmPrivate(arg) {
        }

    private:
        inline void call_this_once_run();
    protected:
        inline bool hasData() const;
        inline bool needRunNext() const;
    };

    class _AudioThread :
        public _ThreadDataBasic {
        sstd::list< sstd::intrusive_ptr< FFMPEGPack > > mmmPacks;
        _MusicReaderPrivate * const mmmPrivate;
    public:

        inline void run() {
            call_this_once_run();
        }

        _AudioThread(_MusicReaderPrivate * arg) :
            mmmPrivate(arg) {
        }

        inline void appendData(sstd::intrusive_ptr< FFMPEGPack >);

    private:
        inline void call_this_once_run();
    protected:
        inline bool hasData() const;
        inline bool needRunNext() const;
    };

    using PackThread = Thread<_PackThread>;
    using AudioThread = Thread<_AudioThread>;


    class AudioFrames {
        sstd::list< sstd::intrusive_ptr< const MusicFrame > > mmmReadFrame;
        std::shared_mutex mmmMutex;
        _MusicReaderPrivate * const mmmPrivate;
    public:
        inline AudioFrames(_MusicReaderPrivate * arg) :mmmPrivate(arg) {
        }
        inline bool needData() {
            std::shared_lock varLock{ mmmMutex };
            return mmmReadFrame.size() < 16;
        }
        inline void appendData(sstd::intrusive_ptr< const MusicFrame >);
        inline sstd::intrusive_ptr< const MusicFrame > popData();
        inline void clear();
    };

}/*namespace*/

using namespace this_file;

class _MusicReaderPrivate {
public:
    MusicReader * const mmmParent;
    QString mmmLocalFileName;
    int mmmAudioStream{ -1 };
    bool mmmIsFileOpen{ false };
    ffmpeg::AVFormatContext * mmmContex{ nullptr };
    class AudioStreamCodecInfo {
    public:
        ffmpeg::AVCodecContext * contex{ nullptr };
    };
    AudioStreamCodecInfo * mmmCurrentStream{ nullptr };
    sstd::map< int, AudioStreamCodecInfo > mmmAudioStreamContex;
    sstd::intrusive_ptr< MusicInformation > mmmMusicInformation;
    sstd::intrusive_ptr< PackThread > mmmReadPackThread;
    sstd::intrusive_ptr< AudioThread > mmmAudioThread;
    AudioFrames mmmAudioFrames;
public:

    inline _MusicReaderPrivate(MusicReader * argParent) :
        mmmParent(argParent),
        mmmAudioFrames(this) {
    }

    inline bool isStarted() const {
        if (mmmAudioStream > -1) {
            return true;
        }
        return false;
    }

    inline bool start(int varIndex) {
        if (isStarted()) {
            return false;
        }
        auto varInfo = mmmAudioStreamContex.find(varIndex);
        if (varInfo != mmmAudioStreamContex.end()) {
            mmmCurrentStream = &(varInfo->second);
            mmmAudioStream = varIndex;
            mmmAudioThread =
                sstd_make_intrusive_ptr<AudioThread>(this);
            mmmReadPackThread =
                sstd_make_intrusive_ptr<PackThread>(this);
            return true;
        }
        return false;
    }

    inline bool open(const QString & argFileName) {
        if (mmmIsFileOpen) {
            return false;
        }
        if (argFileName.isEmpty()) {
            return false;
        }
        mmmIsFileOpen =
            this_file_ffmpge_open_file(argFileName, &mmmContex);
        if (mmmIsFileOpen) {
            mmmIsFileOpen = openStream();
            if (false == mmmIsFileOpen) {
                this->close();
                return false;
            }
            buildStreamInfo();
        }
        return mmmIsFileOpen;
    }

    inline void buildStreamInfo() {
        mmmMusicInformation =
            sstd_make_intrusive_ptr<MusicInformation >();
        mmmMusicInformation->streamInfo.reserve(mmmAudioStreamContex.size());
        for (const auto & varInfor : mmmAudioStreamContex) {
            auto & info =
                mmmMusicInformation->streamInfo.emplace_back();
            info.streamIndex = varInfor.first;

        }
    }

    inline bool openStream() {

        for (
            decltype(mmmContex->nb_streams) i = 0;
            mmmContex->nb_streams;
            ++i) {
            /*获得解码环境*/
            auto * codec_contex = mmmContex->streams[i]->codec;
            /*找到解码器*/
            auto varCodec = ffmpeg::avcodec_find_decoder(codec_contex->codec_id);
            if (varCodec == nullptr) {
                continue;
            }
            /*在当前环境打开解码器*/
            if (ffmpeg::avcodec_open2(codec_contex, varCodec, nullptr) < 0) {
                continue;
            }
            /*记录音频解码器*/
            if (codec_contex->codec_type == AVMEDIA_TYPE_AUDIO) {
                mmmAudioStreamContex.emplace(
                    static_cast<int>(i),
                    AudioStreamCodecInfo{ codec_contex });
            }
        }

        return !mmmAudioStreamContex.empty();

    }

    inline void close() {
        if (mmmIsFileOpen == false) {
            return;
        }
        mmmAudioFrames.clear();
        mmmAudioThread = {};
        mmmReadPackThread = {};
        mmmAudioStream = -1;
        mmmAudioStreamContex.clear();
        mmmLocalFileName = QString{};
        mmmMusicInformation = {};
        this_file_ffmpeg_close_file(&mmmContex);
        mmmCurrentStream = nullptr;
        mmmIsFileOpen = false;
    }

    inline ~_MusicReaderPrivate() {
        this->close();
    }

private:
    SSTD_DEFINE_STATIC_CLASS(_MusicReaderPrivate);
};

MusicReader::MusicReader() {
    mmmPrivate = sstd_new<_MusicReaderPrivate>(this);
}

bool MusicReader::open(const QString & arg) {
    if (mmmPrivate) {
        return mmmPrivate->open(arg);
    }
    return false;
}

sstd::intrusive_ptr< const MusicInformation >
MusicReader::information() const {
    return {};
}

bool MusicReader::seek(MusicNumber /*ms*/) {
    return false;
}

void MusicReader::pppDestoryThisPrivate() {
    delete mmmPrivate;
    mmmPrivate = nullptr;
}

MusicReader::~MusicReader() {
    pppDestoryThisPrivate();
}

void MusicReader::close() {
    pppDestoryThisPrivate();
}

void MusicReader::start(std::int64_t arg) {
    mmmPrivate->start(arg);
}

sstd::intrusive_ptr< const MusicFrame > MusicReader::readNext() {
    return this->mmmPrivate->mmmAudioFrames.popData();
}

namespace this_file {

    inline bool _PackThread::hasData() const {
        return true;
    }

    inline bool _PackThread::needRunNext() const {
        return mmmPrivate->mmmAudioFrames.needData();
    }

    inline bool _AudioThread::hasData() const {
        return !this->mmmPacks.empty();
    }

    inline bool _AudioThread::needRunNext() const {
        return mmmPrivate->mmmAudioFrames.needData();
    }

    inline void _PackThread::call_this_once_run() {
        auto varContex = mmmPrivate->mmmContex;
        auto varPack = this->mmmPacksPool.getAPack();
        if (!varPack) {
            return;
        }
        bool isReadNoError = (ffmpeg::av_read_frame(varContex, varPack->data()) == 0);
        if (isReadNoError) {
            if (varPack->data()->stream_index == mmmPrivate->mmmAudioStream) {
                mmmPrivate
                    ->mmmAudioThread
                    ->appendData(std::move(varPack));
            } else {
                /*标记为不使用*/
                varPack->unref();
            }
        }
    }

    inline void _AudioThread::call_this_once_run() {

        sstd::intrusive_ptr< FFMPEGPack > varPack;
        {
            std::unique_lock varLock{ this->getMutex() };
            if (this->mmmPacks.empty()) {
                return;
            }
            varPack = std::move(mmmPacks.front());
            mmmPacks.pop_front();
        }

        

    }

    inline void _AudioThread::appendData(sstd::intrusive_ptr< FFMPEGPack > arg) {
        {
            std::unique_lock varLock{ this->getMutex() };
            mmmPacks.push_back(std::move(arg));
        }
        this->wake_up();
    }

    inline void AudioFrames::appendData(sstd::intrusive_ptr< const MusicFrame > arg) {
        std::unique_lock varLock{ mmmMutex };
        mmmReadFrame.push_back(arg);
    }

    inline sstd::intrusive_ptr< const MusicFrame > AudioFrames::popData() {
        sstd::intrusive_ptr< const MusicFrame > varAns;
        {
            std::unique_lock varLock{ mmmMutex };
            if (mmmReadFrame.empty()) {
                return std::move(varAns);
            }
            varAns = std::move(mmmReadFrame.front());
            mmmReadFrame.pop_front();
        }
        mmmPrivate->mmmReadPackThread->wake_up();
        mmmPrivate->mmmAudioThread->wake_up();
        return std::move(varAns);
    }

    inline void AudioFrames::clear() {
        {
            std::unique_lock varLock{ mmmMutex };
            mmmReadFrame.clear();
        }
        mmmPrivate->mmmReadPackThread->wake_up();
        mmmPrivate->mmmAudioThread->wake_up();
    }


}/*this_file*/

/**/

