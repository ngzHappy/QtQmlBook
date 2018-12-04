#pragma once

#include <QtQuickWidgets/qquickwidget.h>
#include "../../global/sstd_qt_and_qml_global.hpp"

namespace sstd {
    class EXPORT_SSTD_QT_AND_QML_LIBRARY QuickViewWidget :
            public QQuickWidget ,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(QuickViewWidget){
        Q_OBJECT
    public:
        QuickViewWidget();
        QQuickWindow * getQuickWindow() const;
    private:
        using Super = QQuickWidget;
        SSTD_END_DEFINE_VIRTUAL_CLASS(QuickViewWidget);
    };
}/*namespace sstd*/




















