#include "PlaceHolderImageProvider.hpp"

PlaceHolderImageProvider::PlaceHolderImageProvider() :
    QQuickImageProvider(QQmlImageProviderBase::Image) {

}

inline static QImage getImage() {
    QImage varImage{ 1,1,QImage::Format_RGBA8888_Premultiplied };
    varImage.fill(QColor(0, 0, 0, 0));
    return std::move(varImage);
}

QImage PlaceHolderImageProvider::requestImage(const QString &, QSize * s, const QSize &) {
    const static auto varAns = getImage();
    if (s) {
        *s = varAns.size();
    }
    return varAns;
}






















