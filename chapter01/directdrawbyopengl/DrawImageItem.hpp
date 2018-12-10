#pragma once
#include <sstd_qt_and_qml_library.hpp>

class DrawImageItem :
        public QQuickItem ,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(DrawImageItem) {
    Q_OBJECT
private:
    Q_PROPERTY(QImage rawImage READ getImage WRITE setImage NOTIFY imageChanged)
private:
    using Super = QQuickItem;
public:
    DrawImageItem();
public:
    QImage getImage() const;
    void setImage(const QImage &);
    Q_SIGNAL void imageChanged();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData * ) override;
private:
    QImage mmmImage;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(DrawImageItem);
};

