#pragma once

#include <sstd_qt_and_qml_library.hpp>

class MineSweeping : public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MineSweeping) {
    Q_OBJECT
public:
    MineSweeping();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
public:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MineSweeping);
};








