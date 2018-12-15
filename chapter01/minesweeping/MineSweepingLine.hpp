#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include "MineSweepingLineNode.hpp"

class MineSweepingLine :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MineSweepingLine){
    Q_OBJECT
private:
    Q_PROPERTY(QColor lineColor READ getLineColor WRITE setLineColor NOTIFY lineColorChanged)
private:
    Q_PROPERTY(qreal lineWidth READ getLineWidth WRITE setLineWidth NOTIFY lineWidthChanged)
private:
    Q_PROPERTY(QPointF endPoint READ getEndPoint WRITE setEndPoint NOTIFY endPointChanged)
private:
    Q_PROPERTY(QPointF beginPoint READ getBeginPoint WRITE setBeginPoint NOTIFY beginPointChanged)
public:
    MineSweepingLine();
    ~MineSweepingLine();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
    void componentComplete() override;
public:
    inline QColor getLineColor() const;
    inline qreal getLineWidth() const;
    inline QPointF getEndPoint() const;
    inline QPointF getBeginPoint() const;
public:
    Q_SIGNAL void lineColorChanged();
    Q_SIGNAL void endPointChanged();
    Q_SIGNAL void beginPointChanged();
    Q_SIGNAL void lineWidthChanged();
public:
    void setLineColor(const QColor &);
    void setLineWidth(qreal);
    void setEndPoint(const QPointF &);
    void setBeginPoint(const QPointF &);
private:
    MineSweepingLineNode * mmmLineNode{ nullptr };
    MineSweepingLineNode * getLineNode() const;
    using Super = QQuickItem;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MineSweepingLine);
};

inline QColor MineSweepingLine::getLineColor() const {
    return getLineNode()->getLineColor();
}

inline qreal MineSweepingLine::getLineWidth() const {
    return getLineNode()->getLineWidth();
}

inline QPointF MineSweepingLine::getEndPoint() const {
    return getLineNode()->getEndPoint();
}

inline QPointF MineSweepingLine::getBeginPoint() const {
    return getLineNode()->getBeginPoint();
}















