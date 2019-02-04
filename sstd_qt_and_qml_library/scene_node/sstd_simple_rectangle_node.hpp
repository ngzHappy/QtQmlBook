#pragma once

#include <QtQuick/QtQuick>
#include "../global/sstd_qt_and_qml_global.hpp"

class _0_sstd_simple_rectangle_node;
class EXPORT_SSTD_QT_AND_QML_LIBRARY _0_sstd_simple_rectangle_node :
    public QSGGeometryNode,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_0_sstd_simple_rectangle_node) {
public:
    _0_sstd_simple_rectangle_node(const QRectF &rect, const QColor &color);
    _0_sstd_simple_rectangle_node();

    void setRect(const QRectF &rect);
    inline void setRect(qreal x, qreal y, qreal w, qreal h) {
        setRect(QRectF(x, y, w, h));
    }

    QRectF rect() const;
    void setColor(const QColor &color);
    QColor color() const;

private:
    QSGFlatColorMaterial m_material;
    QSGGeometry m_geometry;
    SSTD_END_DEFINE_VIRTUAL_CLASS(_0_sstd_simple_rectangle_node);
};

namespace sstd {
    using SimpleRectangleNode = _0_sstd_simple_rectangle_node;
}/*namespace sstd*/
