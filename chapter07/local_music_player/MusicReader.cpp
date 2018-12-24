#include "MusicReader.hpp"
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

namespace {

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
        AVFormatContext * contex{ nullptr };
        bool isOk{ false };
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(callpack_this_file_ffmpge_open_file);
    };

    using av_error_tmp_buffer_type = std::array<char, 1024 * 1024>;
    inline static av_error_tmp_buffer_type & getStringTmpBuffer() {
        static av_error_tmp_buffer_type varAns;
        return varAns;
    }

    /*ffmpeg打开和关闭文档不是线程安全的，因而将其强制到一个线程...*/
    /*打开文档*/
    inline static bool this_file_ffmpge_open_file(
        const QString & arg,
        AVFormatContext ** argContex) {
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
    inline static void this_file_ffmpeg_close_file(AVFormatContext ** argContex) {
        FFMPEGOpenCloseThread varThread;
        varThread.call([varContex = *argContex]() mutable {
            ffmpeg::avformat_close_input(&varContex);
        })/*关闭文件无需同步等待*/;
        *argContex = nullptr;
    }

    inline static sstd::intrusive_ptr< MusicInformation >
        this_file_ffmpge_read_information(AVFormatContext * argContex) {

    }

}/*namespace*/

namespace {

    template<typename T>
    class Thread final : public T {
        std::thread mmmThread;
        std::atomic_bool mmmIsQuit{ false };
    public:

        inline Thread() {
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
                std::unique_lock varLock{ this->getMutex() };
                this->getWait().wait_for(varLock, 100ms, [this]() ->bool {
                    if (mmmIsQuit.load()) {
                        return true;
                    }
                    return this->hasData();
                });
                if (this->hasData()) {
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
        SSTD_END_DEFINE_VIRTUAL_CLASS(FFMPEGPack);
    };

    class PackPool final {
        std::shared_mutex mmmMutex;
        using packes_type = sstd::list< sstd::intrusive_ptr< FFMPEGPack > >;
        packes_type mmmPacks;
        packes_type::const_iterator mmmPos;
    public:

        inline PackPool() {
            mmmPos = mmmPacks.cbegin();
        }

        inline sstd::intrusive_ptr< FFMPEGPack > getAPack() {

            for (;;) {

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

                if (varPackSize < 256) {
                    std::unique_lock varLock{ mmmMutex };
                    FFMPEGPack * varAns;
                    for (auto varI = 0; varI < 8; ++varI) {
                        varAns = sstd_new<FFMPEGPack>();
                        mmmPacks.emplace_back(varAns);
                    }
                    mmmPos = --mmmPacks.end();
                    return varAns;
                }

                std::this_thread::sleep_for(1ms);

            }

        }

    private:
        SSTD_DEFINE_STATIC_CLASS(PackPool);
    };

    class _PackThread :
        public _ThreadDataBasic {

        sstd::list< sstd::intrusive_ptr< FFMPEGPack > > mmmPacks;

    public:

        inline void run() {

        }

    protected:
        inline bool hasData() const {
            return !mmmPacks.empty();
        }

    };

    class _AudioThread :
        public _ThreadDataBasic {
        sstd::list< sstd::intrusive_ptr< FFMPEGPack > > mmmPacks;
    public:

        inline void run() {

        }

    protected:

        inline bool hasData() const {
            return !mmmPacks.empty();
        }

    };

    using PackThread = Thread<_PackThread>;
    using AudioThread = Thread<_AudioThread>;

}/*namespace*/

class _MusicReaderPrivate {
    MusicReader * const mmmParent;
    QString mmmLocalFileName;
    int mmmAudioStream{ -1 };
    bool mmmIsFileOpen{ false };
    AVFormatContext * mmmContex{ nullptr };
public:
    inline _MusicReaderPrivate(MusicReader * argParent) :
        mmmParent(argParent) {
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
        return mmmIsFileOpen;
    }

    inline void close() {
        if (mmmIsFileOpen == false) {
            return;
        }
        this_file_ffmpeg_close_file(&mmmContex);
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

void MusicReader::start(std::int64_t) {

}

sstd::intrusive_ptr< const MusicFrame > MusicReader::readNext() {
    return {};
}

/**/

