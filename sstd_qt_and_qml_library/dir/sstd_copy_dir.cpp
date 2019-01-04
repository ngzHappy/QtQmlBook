#include "sstd_copy_dir.hpp"
#include <QtCore/QtCore>

#if __has_include(<filesystem>)
#include <filesystem>
using namespace std::filesystem;
#else

#endif

namespace sstd {

    EXPORT_SSTD_QT_AND_QML_LIBRARY bool copyDir(
        const QString & argFrom,
        const QString & argTo) {

        QFileInfo varFromInfo{ argFrom };
        QFileInfo varToInfo{ argTo };

        const auto varFromPathLocal =
            varFromInfo.absoluteFilePath().toLocal8Bit();

        const auto varToPathLocal =
            varToInfo.absoluteFilePath().toLocal8Bit();

        path varFrom{ varFromPathLocal.constData() };
        path varTo{ varToPathLocal.constData() };

        try {
            std::filesystem::copy(
                varFrom,
                varTo,
                copy_options::overwrite_existing);
            return true;
        } catch (...) {
            return false;
        }

    }

}/*namespace sstd*/
















