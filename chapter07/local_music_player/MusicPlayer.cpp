#include "MusicPlayer.hpp"
#include <QtMultimedia/QtMultimedia>

namespace this_file {

    /*构造QAudioFormat*/
    inline QAudioFormat getAudioFormat(int rate = 44100) {
        /****************************************************************/
        /*统一将音频转为双声道，signed 16 整型，但采样频率不变*/
        static const auto varAnsConst = []() {
            QAudioFormat varFormat;
            varFormat.setSampleRate(44100);
            varFormat.setChannelCount(2);
            varFormat.setSampleSize(16);
            varFormat.setCodec(QStringLiteral("audio/pcm"));
#if (Q_BYTE_ORDER == Q_BIG_ENDIAN)
            varFormat.setByteOrder(QAudioFormat::BigEndian);
#else
            varFormat.setByteOrder(QAudioFormat::LittleEndian);
#endif
            varFormat.setSampleType(QAudioFormat::SignedInt);
            return varFormat;
        }();
        /****************************************************************/
        auto varAns = varAnsConst;
        varAns.setSampleRate(rate);
        return varAns;
    }

    /*构造QAudioDeviceInfo*/
    inline QAudioDeviceInfo getAudioDeveceInfo(int rate = 44100) {

        /*采用默认输出设备*/
        QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());

        if (!info.isFormatSupported(getAudioFormat(rate))) {
            qWarning() <<
                QStringLiteral(
                    "Raw audio format not supported "
                    "by backend, cannot play audio.");
            /* std::exit(-999); */
        }

        return info;
    }

    /*音频输出设备*/
    class AudioPlayer :
        public QAudioOutput,
        public sstd_intrusive_ptr_basic,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(AudioPlayer) {
    public:
        inline AudioPlayer(int rate) :
            QAudioOutput(
                getAudioDeveceInfo(rate),
                getAudioFormat(rate)) {
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(AudioPlayer);
    };

    class AudioStream :
        public QIODevice,
        public sstd_intrusive_ptr_basic,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(AudioStream){
        _MusicPlayerPrivate *mmmSuper;
    public:
        inline void construct(_MusicPlayerPrivate * arg) {
            mmmSuper = arg;
            this->open(QIODevice::ReadOnly);
        }
        inline qint64 readData(char *data, qint64 maxSize) override;
        inline qint64 bytesAvailable() const override;
        inline qint64 writeData(const char *, qint64) override {
            return 0;
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(AudioStream);
    };

}/*this_file*/

using namespace this_file;

class _MusicPlayerPrivate {
    MusicPlayer * const mmmParent;
public:
    inline _MusicPlayerPrivate(MusicPlayer * arg) :
        mmmParent(arg) {
    }
    sstd::intrusive_ptr< MusicReader > mmmMusicReader;
    sstd::intrusive_ptr< AudioPlayer > mmmAudioPlayer;
    sstd::intrusive_ptr< AudioStream > mmmAudioStream;
    sstd::vector< MusicFrame::AudioDataItem  > mmmLastData;
    bool mmmIsEndl{ true };
};

MusicPlayer::MusicPlayer() :
    mmmPrivate(sstd_new<_MusicPlayerPrivate>(this)) {

}

MusicPlayer::~MusicPlayer() {
    this->stopPlay();
    delete mmmPrivate;
}

void MusicPlayer::startPlay(int argIndex) {
    int varSampleRate{ -44100 };
    if (mmmPrivate->mmmMusicReader) {
        auto varInfor =
            mmmPrivate->mmmMusicReader->information();
        if (varInfor->streamInfo.empty()) {
            sstd_log("threre is no audio info!"sv);
            return;
        }
        if (argIndex < 0) {
            auto varPos = varInfor->streamInfo.begin();
            argIndex = varPos->streamIndex;
            varSampleRate = varPos->sample_rate;
        } else {
            for (const auto & varI : varInfor->streamInfo) {
                if (varI.streamIndex == argIndex) {
                    varSampleRate = varI.sample_rate;
                }
            }
        }
        if (varSampleRate < 0) {
            sstd_log("can not find audio stream index"sv);
            return;
        }
        if (!mmmPrivate->mmmAudioPlayer) {
            mmmPrivate->mmmAudioPlayer =
                sstd_make_intrusive_ptr<AudioPlayer>(varSampleRate);
            mmmPrivate->mmmAudioStream =
                sstd_make_intrusive_ptr<AudioStream>();
            mmmPrivate->mmmAudioStream->construct(mmmPrivate);
        } else {
            sstd_log("close the file first"sv);
            return;
        }
        mmmPrivate->mmmMusicReader->start(argIndex);
        mmmPrivate->mmmAudioPlayer->start(
            mmmPrivate->mmmAudioStream.get());
        return;
    }
    sstd_log("open the file first ..."sv);
}

void MusicPlayer::pausePlay() {
    if (mmmPrivate->mmmAudioPlayer) {
        mmmPrivate->mmmAudioPlayer->suspend();
    }
}

void MusicPlayer::stopPlay() {
    mmmPrivate->mmmIsEndl = true;
    if (mmmPrivate->mmmAudioPlayer) {
        mmmPrivate->mmmAudioPlayer->stop();
    }
    if (mmmPrivate->mmmAudioStream) {
        mmmPrivate->mmmAudioStream = {};
    }
    if (mmmPrivate->mmmAudioPlayer) {
        mmmPrivate->mmmAudioPlayer = {};
    }
    if (mmmPrivate->mmmMusicReader) {
        mmmPrivate->mmmMusicReader->close();
        mmmPrivate->mmmMusicReader = {};
    }
    mmmPrivate->mmmLastData.clear();
}

void MusicPlayer::continuePlay() {
    if (mmmPrivate->mmmAudioPlayer) {
        mmmPrivate->mmmAudioPlayer->resume();
    }
}

bool MusicPlayer::openFile(const QUrl & arg) {
    if (mmmPrivate->mmmMusicReader) {
        sstd_log("close the file first ..."sv);
        return false;
    }
    auto varReader =
        sstd_make_intrusive_ptr<MusicReader>();
    if (varReader->open(arg.toLocalFile())) {
        mmmPrivate->mmmMusicReader
            = std::move(varReader);
        mmmPrivate->mmmIsEndl = false;
        return true;
    }
    sstd_log("open file faild!"sv);
    return false;
}

QString MusicPlayer::fullFileInfo() const {
    if (mmmPrivate->mmmMusicReader) {
        auto varInformation =
            mmmPrivate->mmmMusicReader->information();
        QString varAns;
        QTextStream varStream{ &varAns };

        const static auto varOP =
            QStringLiteral(R"(
---------------------------
)");

        varStream
            << QStringLiteral(R"(时长：)")
            << varInformation->duration.getValue()
            << QStringLiteral(R"(秒)");

        varStream << varOP;

        varStream << QStringLiteral(R"(音频信息：)");
        varStream << endl;

        for (const auto & varI : varInformation->metaData) {
            varStream
                << varI.first
                << QChar('\t')
                << varI.second
                << endl;
        }

        varStream << varOP;

        varStream << QStringLiteral(R"(音轨信息：)");
        varStream << endl;
        for (const auto & varI : varInformation->streamInfo) {
            varStream << endl;
            varStream << endl;
            varStream << QStringLiteral(R"(音轨编号：)");
            varStream << QChar('\t');
            varStream << varI.streamIndex;
            varStream << endl;
            varStream << QStringLiteral(R"(采样频率：)");
            varStream << QChar('\t');
            varStream << varI.sample_rate;
            varStream << endl;
            for (const auto & varJ : varI.metaData) {
                varStream
                    << varJ.first
                    << QChar('\t')
                    << varJ.second
                    << endl;
            }
            varStream << varOP;
        }

        varStream << QStringLiteral(R"(音频封面：)");
        varStream << endl;
        varStream
            << QStringLiteral(R"(w:)")
            << varInformation->image.width()
            << QChar('\t')
            << QStringLiteral(R"(h:)")
            << varInformation->image.height();

        return std::move(varAns);
    }
    return {};
}

static inline void registerThis() {
    qmlRegisterType<MusicPlayer>(
        "sstd.audio",
        1, 0,
        "MusicPlayer");
}
Q_COREAPP_STARTUP_FUNCTION(registerThis)

namespace this_file {

    inline qint64 AudioStream::readData(char *data, qint64 maxSize) {
        if (!mmmSuper->mmmMusicReader) {
            return 0;
        }

        /*调整缓冲区大小，释放无用内存*/
        if (mmmSuper->mmmLastData.capacity() > (1024 * 1024)) {
            mmmSuper->mmmLastData.shrink_to_fit();
        }

        using item_type = MusicFrame::AudioDataItem;
        constexpr const auto varItemSize = sizeof(item_type);

        auto varDataSize = mmmSuper->mmmLastData.size() *varItemSize;

        if (static_cast<qint64>(varDataSize) >= maxSize) {
            auto varOutPut =
                reinterpret_cast<item_type *>(data);
            auto varInput =
                std::as_const(mmmSuper->mmmLastData).data();
            for (qint64 i = 0; i < maxSize; i += varItemSize) {
                *varOutPut++ = *varInput++;
            }
            mmmSuper->mmmLastData.erase(
                mmmSuper->mmmLastData.begin(),
                mmmSuper->mmmLastData.begin() +
                (varInput - std::as_const(
                    mmmSuper->mmmLastData).data())
            );
            return maxSize;
        }

        {
            auto varOutMax = maxSize / varItemSize;
            while (mmmSuper->mmmLastData.size() < varOutMax) {
                auto varNext = mmmSuper->mmmMusicReader->readNext();
                if (varNext && (!varNext->data.empty())) {
                    mmmSuper->mmmLastData.insert(
                        mmmSuper->mmmLastData.end(),
                        varNext->data.begin(),
                        varNext->data.end());
                } else {
                    break;
                }
            }
        }

        if (mmmSuper->mmmLastData.empty()) {
            return 0;
        }

        maxSize = std::min(maxSize, static_cast<qint64>(
            mmmSuper->mmmLastData.size() * varItemSize));
        auto varOutPut =
            reinterpret_cast<item_type *>(data);
        auto varInput =
            std::as_const(mmmSuper->mmmLastData).data();
        for (qint64 i = 0; i < maxSize; i += varItemSize) {
            *varOutPut++ = *varInput++;
        }
        mmmSuper->mmmLastData.erase(
            mmmSuper->mmmLastData.begin(),
            mmmSuper->mmmLastData.begin() +
            (varInput - std::as_const(
                mmmSuper->mmmLastData).data())
        );

        return maxSize;

    }

    inline qint64 AudioStream::bytesAvailable() const {
        if (mmmSuper->mmmIsEndl) {
            return 0;
        }
        return (1024 * 1024);
    }

}





