#include "sstd_simple_rectangle_node.hpp"

_0_sstd_simple_rectangle_node::_0_sstd_simple_rectangle_node(
    const QRectF &rect,
    const QColor &color)
    : m_geometry(QSGGeometry::defaultAttributes_Point2D(), 4) {
    QSGGeometry::updateRectGeometry(&m_geometry, rect);
    m_material.setColor(color);
    setMaterial(&m_material);
    setGeometry(&m_geometry);
}

_0_sstd_simple_rectangle_node::_0_sstd_simple_rectangle_node()
    : m_geometry(QSGGeometry::defaultAttributes_Point2D(), 4) {
    QSGGeometry::updateRectGeometry(&m_geometry, QRectF());
    setMaterial(&m_material);
    setGeometry(&m_geometry);
}

void _0_sstd_simple_rectangle_node::setRect(const QRectF &rect) {
    QSGGeometry::updateRectGeometry(&m_geometry, rect);
    markDirty(QSGNode::DirtyGeometry);
}

QRectF _0_sstd_simple_rectangle_node::rect() const {
    const QSGGeometry::Point2D *pts = m_geometry.vertexDataAsPoint2D();
    return QRectF(pts[0].x,
        pts[0].y,
        pts[3].x - pts[0].x,
        pts[3].y - pts[0].y);
}

void _0_sstd_simple_rectangle_node::setColor(const QColor &color) {
    if (color != m_material.color()) {
        m_material.setColor(color);
        markDirty(QSGNode::DirtyMaterial);
    }
}

QColor _0_sstd_simple_rectangle_node::color() const {
    return m_material.color();
}












