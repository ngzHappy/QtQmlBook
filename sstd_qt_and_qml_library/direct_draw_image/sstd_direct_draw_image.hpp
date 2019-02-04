#pragma once

#include "../sstd_qt_and_qml_library.hpp"

class EXPORT_SSTD_QT_AND_QML_LIBRARY _0_sstd_direct_draw_image :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_0_sstd_direct_draw_image) {
    Q_OBJECT
private:
    Q_PROPERTY(QVariant rawImage READ pppGetImage WRITE pppSetImage NOTIFY imageChanged)
private:
    using Super = QQuickItem;
public:
    _0_sstd_direct_draw_image();
public:
    QImage getImage() const;
    inline void setImage(const QImage &);
    Q_SIGNAL void imageChanged();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
private:
    QImage mmmImage;
    bool mmmImageUpdate{ true };
    void pppSetImage(const QVariant &);
    void pppSetImage1(const QImage &);
    inline QVariant pppGetImage() const {
        return QVariant::fromValue(getImage());
    }
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(_0_sstd_direct_draw_image);
};

inline void _0_sstd_direct_draw_image::setImage(const QImage & arg) {
    this->pppSetImage1(arg);
}

namespace sstd {

    using DirectDrawImage = _0_sstd_direct_draw_image;

}/*namespace sstd*/
