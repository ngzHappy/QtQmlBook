﻿#pragma once

#include <QtGui/QtGui>
#include <QtQml/QtQml>
#include <QtCore/QtCore>
#include <QtQuick/QtQuick>
#include <sstd_library.hpp>
#include "../../global/sstd_qt_and_qml_global.hpp"


namespace _sstd1 {

    namespace _3_private_api {

        class EXPORT_SSTD_QT_AND_QML_LIBRARY QmlApplicationEngine :
            public QQmlApplicationEngine,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(QmlApplicationEngine) {
        private:
            Q_OBJECT
        public:
            QmlApplicationEngine();
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(QmlApplicationEngine);
        };

    }
}
