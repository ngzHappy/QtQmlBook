#pragma once

#include <QtNetwork/QtNetwork>
#include <sstd_qt_and_qml_library.hpp>

class NetworkAccessManager :
    public QNetworkAccessManager ,
    public sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(NetworkAccessManager) {
    Q_OBJECT
public:
    NetworkAccessManager(QObject * var = nullptr);
private:
    using Super = QNetworkAccessManager;
    SSTD_END_DEFINE_VIRTUAL_CLASS(NetworkAccessManager);
};
