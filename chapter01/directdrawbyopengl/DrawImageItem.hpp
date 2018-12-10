#pragma once
#include <sstd_qt_and_qml_library.hpp>

class DrawImageItem :
        public QQuickItem ,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(DrawImageItem) {
    Q_OBJECT
private:
    using Super = QQuickItem;
public:
    DrawImageItem();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData * ) override;
private:
    QImage mmmImage;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(DrawImageItem);
};

