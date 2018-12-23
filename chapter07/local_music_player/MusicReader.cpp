#include "MusicReader.hpp"
#include <mutex>

class _MusicReaderPrivate {
    MusicReader * const mmmParent;
    QString mmmLocalFileName;
    bool mmmIsFileOpen{ false };
public:
    inline _MusicReaderPrivate(MusicReader * argParent) :
        mmmParent(argParent) {
    }

    inline bool open(const QString & argFileName) {
        if (mmmIsFileOpen) {
            return false;
        }
        return mmmIsFileOpen;
    }

    inline ~_MusicReaderPrivate() {
        if (mmmIsFileOpen == false) {
            return;
        }
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

std::shared_ptr< const MusicInformation >
MusicReader::information() const {
    return {};
}

bool MusicReader::seek(std::int64_t /*ms*/) {
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

std::shared_ptr< const MusicFrame > MusicReader::readNext() {
    return {};
}

/**/

