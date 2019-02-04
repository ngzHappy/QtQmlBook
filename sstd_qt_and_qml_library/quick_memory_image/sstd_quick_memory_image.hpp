#pragma once

#include <QtGui/qimage.h>
#include <QtCore/qobject.h>
#include <QtQuick/qquickimageprovider.h>
#include <chrono>
#include <atomic>
#include "../global/sstd_qt_and_qml_global.hpp"

class EXPORT_SSTD_QT_AND_QML_LIBRARY _0_sstd_quick_memory_image :
    public QObject {
    Q_OBJECT
private:
    Q_PROPERTY(QString imageName READ getImageName NOTIFY imageNameChanged)
public:
    _0_sstd_quick_memory_image();
    QString getImageName() const;
    void setImage(const QImage &);
    QImage getImage();
    ~_0_sstd_quick_memory_image();
public:
    static std::pair<QString, QQuickImageProvider *> getQuickImageProvider();
public:
    Q_SIGNAL void imageNameChanged();
private:
    void remove_the_image();
    QString mmmImageName;
    QImage mmmImage;
};

namespace sstd {

    using QuickMemoryImage = _0_sstd_quick_memory_image;

}/*namespace sstd*/
