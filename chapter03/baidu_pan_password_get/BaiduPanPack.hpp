#pragma once

#include "BaiduPanPasswordGet.hpp"
#include <QtCore/qobject.h>

class BaiduPanPack :
    public QObject {
    Q_OBJECT
public:
    Q_SIGNAL void finished(QString/*password*/,
        BaiduPanPasswordGet::ReturnState/*error code*/);
};







