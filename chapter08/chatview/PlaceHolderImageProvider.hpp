#pragma once

#include <sstd_qt_and_qml_library.hpp>

class PlaceHolderImageProvider :
    public QQuickImageProvider,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(PlaceHolderImageProvider) {
public:
    PlaceHolderImageProvider();
    QImage requestImage(const QString &, QSize *, const QSize &)override;
    static inline QString providerName() {
        return QStringLiteral("placeholderimageprovider");
    }
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(PlaceHolderImageProvider);
};
