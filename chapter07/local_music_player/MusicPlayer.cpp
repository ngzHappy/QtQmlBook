#include "MusicPlayer.hpp"

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
            << u8R"(时长：)"_qstr8
            << varInformation->duration.getValue();

        varStream << varOP;

        varStream << u8R"(音频信息：)"_qstr8;
        varStream << endl;

        for (const auto & varI : varInformation->metaData) {
            varStream 
                << varI.first 
                << QChar('\t') 
                << varI.second 
                << endl;
        }

        varStream << varOP;

        varStream << u8R"(音轨信息：)"_qstr8;
        varStream << endl;
        for (const auto & varI : varInformation->streamInfo) {
            varStream << u8R"(音轨编号：)"_qstr8;
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

        varStream << u8R"(音频封面：)"_qstr8;
        varStream << endl;
        varStream 
            << varInformation->image.width() 
            << QChar('\t') 
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








