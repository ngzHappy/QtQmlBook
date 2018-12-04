#pragma once

#include <QtQuick/qquickview.h>
#include "../../global/sstd_qt_and_qml_global.hpp"

namespace sstd {

    class EXPORT_SSTD_QT_AND_QML_LIBRARY QuickViewWindow :
            public QQuickView,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(QuickViewWindow){
        Q_OBJECT
    public:
        QuickViewWindow();
        QQuickWindow * getQuickWindow() const;
    private:
        using Super = QQuickView;
        SSTD_END_DEFINE_VIRTUAL_CLASS(QuickViewWindow);
    };

}/*namespace sstd*/





















