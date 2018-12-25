#include "MusicPlayer.hpp"
#include <QtMultimedia/QtMultimedia>

namespace this_file {

    /*构造QAudioFormat*/
    inline QAudioFormat getAudioFormat(int rate = 44100) {
        /****************************************************************/
        /*统一将音频转为双声道，signed 16 整型，但采样频率不变*/
        static const auto varAns = []() {
            QAudioFormat varFormat;
            varFormat.setSampleRate(44100);
            varFormat.setChannelCount(2);
            varFormat.setSampleSize(16);
            varFormat.setCodec(QStringLiteral("audio/pcm"));
#if Q_BYTE_ORDER == Q_BIG_ENDIAN
            varFormat.setByteOrder(QAudioFormat::BigEndian);
#else
            varFormat.setByteOrder(QAudioFormat::LittleEndian);
#endif
            varFormat.setSampleType(QAudioFormat::SignedInt);
            return varFormat;
        }();
        /****************************************************************/
        auto var = varAns;
        var.setSampleRate(rate);
        return var;
    }

    /*构造QAudioDeviceInfo*/
    inline QAudioDeviceInfo getAudioDeveceInfo(int rate = 44100) {

        /*采用默认输出设备*/
        QAudioDeviceInfo info(QAudioDeviceInfo::defaultOutputDevice());

        if (!info.isFormatSupported(getAudioFormat(rate))) {
            qWarning() <<
                "Raw audio format not supported by backend, cannot play audio.";
            /* std::exit(-999); */
        }

        return info;
    }

    /*音频输出设备*/
    class AudioPlayer :
        public QAudioOutput,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(AudioPlayer) {
    public:
        AudioPlayer(int rate) :
            QAudioOutput(
                getAudioDeveceInfo(rate),
                getAudioFormat(rate)) {
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(AudioPlayer);
    };

    class AudioStream :
        public QIODevice,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(AudioStream){
        sstd::intrusive_ptr<MusicReader > mmmReader;
    public:
        inline void construct(sstd::intrusive_ptr<MusicReader > arg) {
            mmmReader = std::move(arg);
            this->open(QIODevice::ReadOnly);
        }
        inline qint64 readData(char *data, qint64 maxSize) override {
            return 0;
        }
        inline qint64 bytesAvailable() const override {
            return 0;
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(AudioStream);
    };

}/*this_file*/


class _MusicPlayerPrivate {
    MusicPlayer * const mmmParent;
public:
    inline _MusicPlayerPrivate(MusicPlayer * arg) :
        mmmParent(arg) {
    }
    sstd::intrusive_ptr< MusicReader > mmmMusicReader;
};

MusicPlayer::MusicPlayer() :
    mmmPrivate(sstd_new<_MusicPlayerPrivate>(this)) {

}

MusicPlayer::~MusicPlayer() {
    delete mmmPrivate;
}

void MusicPlayer::startPlay() {

}

void MusicPlayer::pausePlay() {

}

void MusicPlayer::stopPlay() {

}

void MusicPlayer::continuePlay() {

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
            << varInformation->duration.getValue();

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
            varStream << QStringLiteral(R"(音轨编号：)");
            varStream << QChar('\t');
            varStream << varI.streamIndex;
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








