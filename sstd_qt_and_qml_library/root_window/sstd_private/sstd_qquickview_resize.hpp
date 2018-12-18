#pragma once

#include <QtGui/QtGui>
#include <QtQml/QtQml>
#include <QtCore/QtCore>
#include <QtQuick/QtQuick>
#include <sstd_library.hpp>
#include "../../global/sstd_qt_and_qml_global.hpp"

namespace _sstd1 {

    namespace _3_private_api {

        class ResizeQuickViewPrivate;
        class EXPORT_SSTD_QT_AND_QML_LIBRARY ResizeQuickView :
            public QQuickView,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ResizeQuickView) {
            Q_OBJECT
        public:
            ResizeQuickView();
            ~ResizeQuickView();
        private:
            void pppDoResize();
            QResizeEvent mmmResizeEventFinal;
            bool mmmIsFirstResize{ true };
            bool mmmIsResize{ false };
            void pppBeginResize();
            void pppEndResize();
            void resizeEvent(QResizeEvent *ev) override;
            void showEvent(QShowEvent *) override;
            QSize pppGetSize() const;
        private:
            using Super = QQuickView;
            friend class ResizeQuickViewPrivate;
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(ResizeQuickView);
        };

    }

}/*namespace sstd::private_api*/











