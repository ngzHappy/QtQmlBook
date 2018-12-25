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
        bool mmmIsEndl{ false };
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
        std::size_t audio_index_flag{ 0 };
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(AudioStream);
    };

}/*this_file*/

using namespace this_file;

class _MusicPlayerPrivate {
public:
    inline _MusicPlayerPrivate(MusicPlayer * arg) :
        mmmParent(arg) {
    }
    MusicPlayer * const mmmParent;
    QUrl mmmFileName;
    sstd::intrusive_ptr< MusicReader > mmmMusicReader;
    sstd::intrusive_ptr< AudioPlayer > mmmAudioPlayer;
    sstd::intrusive_ptr< AudioStream > mmmAudioStream;
    sstd::vector< MusicFrame::AudioDataItem  > mmmLastData;
    qreal mmmVolume{ 1 };
    qreal mmmDuration{ 0.1 };
    qreal mmmStartTime{ 0 };
    std::atomic< std::size_t > mmmAudioIndexFlag{ 0 };
    bool mmmIsEndl{ true };
    inline void pppPlayEndl(std::size_t arg) {
        mmmParent->pppPlayEndl(arg);
    }
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
        {
            auto varIndex = ++(mmmPrivate->mmmAudioIndexFlag);
            mmmPrivate->mmmAudioStream->audio_index_flag = varIndex;
        }
        mmmPrivate->mmmMusicReader->start(argIndex);
        {/*利用第一帧更新数据*/
            auto varFirstData =
                mmmPrivate->mmmMusicReader->readNext();
            if (varFirstData) {
                mmmPrivate->mmmStartTime =
                    varFirstData->pts.getValue();
                mmmPrivate->mmmLastData =
                    std::move(varFirstData->data);
            }
        }
        /*设置音量*/
        mmmPrivate->mmmAudioPlayer->setVolume(
            mmmPrivate->mmmVolume);
        /*开始播放*/
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
    ++(mmmPrivate->mmmAudioIndexFlag);
    mmmPrivate->mmmIsEndl = true;
    if (mmmPrivate->mmmAudioPlayer) {
        mmmPrivate->mmmAudioPlayer->stop();
    }
    if (mmmPrivate->mmmMusicReader) {
        mmmPrivate->mmmMusicReader->close();
    }
    mmmPrivate->mmmAudioStream = {};
    mmmPrivate->mmmAudioPlayer = {};
    mmmPrivate->mmmMusicReader = {};
    mmmPrivate->mmmLastData.clear();
    mmmPrivate->mmmFileName = {};
    mmmPrivate->mmmDuration = 0.1;
    mmmPrivate->mmmStartTime = 0;
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
        mmmPrivate->mmmDuration =
            mmmPrivate
            ->mmmMusicReader
            ->information()
            ->duration.getValue();
        durationChanged();
        return true;
    }
    sstd_log("open file faild!"sv);
    return false;
}

void MusicPlayer::pppPlayEndl(std::size_t arg) {
    QTimer::singleShot(0, this, [this, varIndex = arg]() {
        if (mmmPrivate->mmmAudioIndexFlag.load() == varIndex) {
            this->stopPlay();
        }
    });
}

MusicPlayer::StatePlayer MusicPlayer::getState() const {
    if (mmmPrivate->mmmMusicReader) {
        if (mmmPrivate->mmmAudioPlayer) {
            switch (mmmPrivate->mmmAudioPlayer->state()) {
            case QAudio::ActiveState:return StatePlayer::Play;
            case QAudio::SuspendedState:return StatePlayer::Pause;
            case QAudio::StoppedState:return StatePlayer::Close;
            case QAudio::IdleState:return StatePlayer::Play;
            case QAudio::InterruptedState:return StatePlayer::Pause;
            }
        } else {
            return StatePlayer::Open;
        }
    }
    return StatePlayer::Close;
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

qreal MusicPlayer::getDuration() const {
    return mmmPrivate->mmmDuration;
}

qreal MusicPlayer::getVolume() const {
    return mmmPrivate->mmmVolume;
}

void MusicPlayer::setVolume(qreal arg) {
    if (arg > 1) {
        arg = 1;
        goto goto_set_value;
    }
    if (arg < 0) {
        arg = 0;
        goto goto_set_value;
    }
    if (std::isnan(arg)) {
        return;
    }
goto_set_value:
    if (arg == getVolume()) {
        return;
    }
    if (mmmPrivate->mmmAudioPlayer) {
        mmmPrivate->mmmAudioPlayer->setVolume(arg);
    }
    mmmPrivate->mmmVolume = arg;
    volumeChanged();
}

void MusicPlayer::seekPlay(qint64/*ms*/ arg) {

    /*opened but not play...*/
    if (mmmPrivate->mmmMusicReader) {
        if (!mmmPrivate->mmmAudioPlayer) {
            const auto varUS =
                static_cast<std::int64_t>(arg) * 1000;
            if (mmmPrivate->mmmMusicReader->seek({ varUS , 1'000'000 })) {
                mmmPrivate->mmmStartTime = arg / 1000.0;
            }
            return;
        }
    } else {
        sstd_log("can not seek file not opened!"sv);
        return;
    }

    sstd_log("can not seek file when playing !"sv);

}

double MusicPlayer::currentTime() {
    if (mmmPrivate->mmmMusicReader) {
        if (!mmmPrivate->mmmAudioPlayer) {
            return mmmPrivate->mmmStartTime;
        } else {
            return
                mmmPrivate->mmmStartTime +
                mmmPrivate->mmmAudioPlayer->processedUSecs() / 1'000'000.0;
        }
    }
    return 0;
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
                    if (varNext) {
                        if (varNext->isEndl) {
                            this->mmmIsEndl = true;
                        }
                    }
                    break;
                }
            }
        }

        if (mmmSuper->mmmLastData.empty()) {
            if (this->mmmIsEndl) {
                mmmSuper->pppPlayEndl(this->audio_index_flag);
            }
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
        using item_type = MusicFrame::AudioDataItem;
        constexpr const auto varItemSize = static_cast<qint64>(sizeof(item_type));
        if (mmmSuper->mmmIsEndl) {
            auto varAns = static_cast<qint64>(
                mmmSuper->mmmLastData.size())*
                varItemSize;
            return varAns;
        }
        return (1024 * 1024);
    }

}



