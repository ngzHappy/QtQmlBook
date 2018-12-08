#include "sstd_quick_memory_image.hpp"
#include <QtCore/qcoreapplication.h>
#include <shared_mutex>

namespace {

    inline static QString getImageProviderName() {
        return QStringLiteral("sstd_image_proveder");
    }

    inline static QString getNullName() {
        return QStringLiteral("null");
    }

    inline static QImage _0_getNullImage() {
        return {};
    }

    inline static QImage getNullImage() {
        const static auto varAns = _0_getNullImage();
        return varAns;
    }

    class QStringHash {
    public:
        std::size_t operator()(const QString & arg) const {
            return qHash(arg);
        }
    };

    class GlobalImageProvider {
    public:
        std::shared_mutex mmmMutex;
        sstd::UnorderedMap< QString, QImage, QStringHash > mmmMap;

        QImage getImage(const QString & k) {
            std::shared_lock varReadLock{ mmmMutex };
            auto varPos = std::as_const(mmmMap).find(k);
            if (varPos == std::as_const(mmmMap).cend()) {
                return getNullImage();
            }
            return varPos->second;
        }

        void eraseImage(const QString & k) {
            std::unique_lock varWriteLock{ mmmMutex };
            mmmMap.erase(k);
        }

        QString insertImage(QImage varImage) {
            const auto varCode2 = QString::number((std::chrono::steady_clock::now() -
                mmmStartTime).count());
            std::unique_lock varWriteLock{ mmmMutex };
            const auto varName = getNextName(varCode2);
            mmmMap[varName] = varImage;
            return varName;
        }

        GlobalImageProvider() {
            mmmStartTime = std::chrono::steady_clock::now();
            mmmMap[getNullName()] = getNullImage();
        }

        QString getNextName(const QString & varCode2) {
            const auto varCode1 = QString::number(++mmmCode1);
            return varCode1 + QChar('/') + varCode2;
        }

        std::uint64_t mmmCode1{ 0 };
        std::chrono::steady_clock::time_point mmmStartTime;
    public:
        SSTD_DEFINE_STATIC_CLASS(GlobalImageProvider);
    };

    inline static GlobalImageProvider * getImageProvider() {
        static auto varAns = sstd_new<GlobalImageProvider>();
        return varAns;
    }

    class ImageProvider :
        public QQuickImageProvider,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ImageProvider) {
    public:

        ImageProvider() :
            QQuickImageProvider(QQmlImageProviderBase::Image) {

        }

        virtual QImage requestImage(const QString &id,
            QSize *size,
            const QSize &requestedSize) {
            auto varAns = getImageProvider()->getImage(id);
            if (varAns.isNull()) {
                if (size) {
                    *size = getNullImage().size();
                }
                return getNullImage();
            }
            if (size) {
                *size = varAns.size();
            }
            return std::move(varAns);
            (void)requestedSize;
        }

    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(ImageProvider);
    };

}/**/

_0_sstd_quick_memory_image::_0_sstd_quick_memory_image() {
    mmmImageName = getNullName();
}

QString _0_sstd_quick_memory_image::getImageName() const {
    const static auto varPreName = QStringLiteral("image://")
        + getImageProviderName()
        + QStringLiteral("/");
    return varPreName + mmmImageName;
}

void _0_sstd_quick_memory_image::setImage(const QImage & arg) {
    mmmImage = arg;
    class RemoveImage {
        _0_sstd_quick_memory_image * thisp;
        QString imageName;
    public:
        RemoveImage(_0_sstd_quick_memory_image * a) :thisp(a) {
            imageName = thisp->mmmImageName;
        }
        ~RemoveImage() {
            getImageProvider()->eraseImage(imageName);
        }
    } varLock{ this };
    mmmImageName = getImageProvider()->insertImage(mmmImage);
    this->imageNameChanged();
}

QImage _0_sstd_quick_memory_image::getImage() {
    return mmmImage;
}

std::pair<QString, QQuickImageProvider *>
_0_sstd_quick_memory_image::getQuickImageProvider() {
    return { getImageProviderName() , sstd_new<ImageProvider>() };
}

_0_sstd_quick_memory_image::~_0_sstd_quick_memory_image() {
    this->remove_the_image();
}

void _0_sstd_quick_memory_image::remove_the_image() {
    getImageProvider()->eraseImage(this->mmmImageName);
}

static inline void register_this() {
    qmlRegisterType<_0_sstd_quick_memory_image>(
        "sstd.quick",
        1, 0,
        "QuickMemoryImage");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)

