#pragma once

#include <QtCore/qurl.h>
#include <QtCore/qdir.h>
#include <QtCore/qstring.h>
#include <QtCore/qcoreapplication.h>
#include "../global/sstd_qt_and_qml_global.hpp"


namespace sstd{

#if defined(_DEBUG) && defined(CURRENT_DEBUG_PATH)
    EXPORT_SSTD_QT_AND_QML_LIBRARY QUrl getLocalFileFullPath(const QString &,const QString & = CURRENT_DEBUG_PATH );
#else
    EXPORT_SSTD_QT_AND_QML_LIBRARY QUrl getLocalFileFullPath(const QString &,const QString & = qApp->applicationDirPath() );
#endif

#if defined(_DEBUG) && defined(CURRENT_DEBUG_PATH)
    EXPORT_SSTD_QT_AND_QML_LIBRARY QString getLocalFileFullFilePath(const QString &, const QString & = CURRENT_DEBUG_PATH);
#else
    EXPORT_SSTD_QT_AND_QML_LIBRARY QString getLocalFileFullFilePath(const QString &, const QString & = qApp->applicationDirPath());
#endif

#if defined(_DEBUG) && defined(CURRENT_DEBUG_PATH)
    EXPORT_SSTD_QT_AND_QML_LIBRARY sstd::string getLocalFileFullFilePath(std::string_view, std::string_view = CURRENT_DEBUG_PATH);
#else
    EXPORT_SSTD_QT_AND_QML_LIBRARY sstd::string getLocalFileFullFilePath(std::string_view, std::string_view = {});
#endif

    EXPORT_SSTD_QT_AND_QML_LIBRARY QString getLocalPathFromApp(const QString &);

}/*namespace sstd*/




