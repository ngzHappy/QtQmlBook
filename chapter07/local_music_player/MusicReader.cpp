#include "MusicReader.hpp"
#include <mutex>
#include <condition_variable>

namespace {

    template<typename T>
    class Thread : public T {
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
            wake_up();
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

    class _PackThread : 
        protected _ThreadDataBasic {
        
    public:
        inline void run() {

        }
        
    protected:
        inline bool hasData() const {
            return false;
        }
       
    };

    class _AudioThread : 
        protected _ThreadDataBasic {
    public:
        inline void run() {

        }
    protected:
        inline bool hasData() const {
            return false;
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
        mmmIsFileOpen = true;

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

