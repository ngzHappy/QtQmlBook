#pragma once

#include <QtGui/QtGui>
#include <QtQml/QtQml>
#include <QtCore/QtCore>
#include <QtQuick/QtQuick>
#include <QtQuickWidgets/QtQuickWidgets>
#include <sstd_library.hpp>
#include "../../global/sstd_qt_and_qml_global.hpp"

namespace _sstd1 {

    namespace _3_private_api {

        class ResizeQuickWidgetPrivate;
        class EXPORT_SSTD_QT_AND_QML_LIBRARY ResizeQuickWiget :
            public QQuickWidget ,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ResizeQuickWiget) {
            Q_OBJECT
        public:
            ResizeQuickWiget();
            virtual ~ResizeQuickWiget();
        private:
            using Super = QQuickWidget;
            friend class ResizeQuickWidgetPrivate;
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(ResizeQuickWiget);
        };

    }

}/*namespace sstd::private_api*/
