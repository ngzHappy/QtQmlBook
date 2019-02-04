#pragma once

#include <sstd_qt_and_qml_library.hpp>

class MineSweepingLineNode :
    public QSGGeometryNode,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MineSweepingLineNode) {
public:
    MineSweepingLineNode();
    void setBeginEndPoints(QPointF, QPointF);
    void setLineWidth(qreal);
    void setLineColor(QColor);
    inline QPointF getBeginPoint() const;
    inline QPointF getEndPoint() const;
    inline qreal getLineWidth() const;
    inline QColor getLineColor() const;
private:
    qreal mmmLineWidth{ 1 };
    QPointF mmmStartPoint{ 0 , 0 };
    QPointF mmmEndPoint{ 1 , 1 };
    QColor mmmLineColor;
    QSGFlatColorMaterial mmmMaterial;
    QSGGeometry mmmGeometry;
    bool mmmIsNull{ false };
private:
    void pppUpdateRect();
    void pppUpdateColor();
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MineSweepingLineNode);
};

inline QPointF MineSweepingLineNode::getBeginPoint() const {
    return mmmStartPoint;
}

inline QPointF MineSweepingLineNode::getEndPoint() const {
    return mmmEndPoint;
}

inline qreal MineSweepingLineNode::getLineWidth() const {
    return mmmLineWidth;
}

inline QColor MineSweepingLineNode::getLineColor() const {
    return mmmLineColor;
}
