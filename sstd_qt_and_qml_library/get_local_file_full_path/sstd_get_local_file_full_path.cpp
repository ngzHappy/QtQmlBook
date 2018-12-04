#include "sstd_get_local_file_full_path.hpp"

namespace sstd {

    EXPORT_SSTD_QT_AND_QML_LIBRARY QUrl getLocalFileFullPath(
            const QString & argFileName,
            const QString & argBase  ){

        const QDir varRootDir{ argBase };
        const auto varAns = varRootDir.absoluteFilePath(argFileName);
        if( varAns.startsWith(QChar('/')) ){
            return QStringLiteral(R"(file://)")+varAns;
        }else{
            return QStringLiteral(R"(file:///)")+varAns;
        }

    }

}









