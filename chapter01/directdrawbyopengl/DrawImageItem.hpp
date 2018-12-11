#pragma once
#include <sstd_qt_and_qml_library.hpp>

class DrawImageItem :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(DrawImageItem) {
    Q_OBJECT
private:
    Q_PROPERTY(QVariant rawImage READ pppGetImage WRITE pppSetImage NOTIFY imageChanged)
private:
    using Super = QQuickItem;
public:
    DrawImageItem();
public:
    QImage getImage() const;
    inline void setImage(const QImage &);
    Q_SIGNAL void imageChanged();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
private:
    QImage mmmImage;
    bool mmmImageUpdate{true};
    void pppSetImage(const QVariant &);
    void pppSetImage1(const QImage &);
    QVariant pppGetImage() const {
        return QVariant::fromValue(getImage());
    }
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(DrawImageItem);
};

inline void DrawImageItem::setImage(const QImage & arg) {
    this->pppSetImage1(arg);
}

