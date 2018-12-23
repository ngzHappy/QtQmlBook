#pragma once

#include "../global/sstd_qt_and_qml_global.hpp"
#include <sstd_library.hpp>
#include <QtCore/qobject.h>

class EXPORT_SSTD_QT_AND_QML_LIBRARY _1_sstd_local_qml_window_creator :
        public QObject ,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_1_sstd_local_qml_window_creator){
    Q_OBJECT
    public:
    _1_sstd_local_qml_window_creator();
    static _1_sstd_local_qml_window_creator * instance();
    Q_SLOT QObject * createRootView(const QString & argName, const QUrl & argLocalPath) const;
    private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(_1_sstd_local_qml_window_creator);
};

namespace sstd {
    using LocalQmlWindowCreator = _1_sstd_local_qml_window_creator ;
}









