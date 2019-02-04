#include "MineSweepingLine.hpp"

MineSweepingLine::MineSweepingLine() {
    this->setFlag(QQuickItem::ItemHasContents, true);
}

QSGNode * MineSweepingLine::updatePaintNode(
    QSGNode *,
    QQuickItem::UpdatePaintNodeData *) {
    return getLineNode();
}

MineSweepingLine::~MineSweepingLine() {
    if (mmmLineNode) {
        if (nullptr == mmmLineNode->parent()) {
            delete mmmLineNode;
        }
    }
}

void MineSweepingLine::componentComplete() {
    Super::componentComplete();
    getLineNode();
}

MineSweepingLineNode * MineSweepingLine::getLineNode() const {
    if (mmmLineNode) {
        return mmmLineNode;
    }
    const_cast<MineSweepingLine *>(this)->mmmLineNode =
        sstd_new<MineSweepingLineNode>();
    return mmmLineNode;
}

void MineSweepingLine::setLineColor(const QColor & arg) {
    if (arg == getLineColor()) {
        return;
    }
    getLineNode()->setLineColor(arg);
    lineColorChanged();
}

void MineSweepingLine::setLineWidth(qreal arg) {
    if (arg == getLineWidth()) {
        return;
    }
    getLineNode()->setLineWidth(arg);
    lineWidthChanged();
}

void MineSweepingLine::setEndPoint(const QPointF & arg) {
    if (arg == getEndPoint()) {
        return;
    }
    getLineNode()->setBeginEndPoints(
        getLineNode()->getBeginPoint(), arg);
    endPointChanged();
}

void MineSweepingLine::setBeginPoint(const QPointF & arg) {
    if (arg == getBeginPoint()) {
        return;
    }
    getLineNode()->setBeginEndPoints(
        arg, getLineNode()->getEndPoint());
    beginPointChanged();
}

static inline void register_this() {
    qmlRegisterType<MineSweepingLine>(
        "sstd.minesweeping",
        1, 0,
        "MineSweepingLine");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
