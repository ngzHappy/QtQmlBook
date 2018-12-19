#include "MineSweepingLineNode.hpp"
#include <cmath>

void MineSweepingLineNode::setBeginEndPoints(QPointF argS, QPointF argE) {

    auto varChanged{ false };

    if (argS != mmmStartPoint) {
        mmmStartPoint = argS;
        varChanged = true;
    }

    if (argE != mmmEndPoint) {
        mmmEndPoint = argE;
        varChanged = true;
    }

    if (false == varChanged) {
        return;
    }

    pppUpdateRect();

}

void MineSweepingLineNode::setLineWidth(qreal argLineWidth) {
    if (argLineWidth == mmmLineWidth) {
        return;
    }
    mmmLineWidth = argLineWidth;
    pppUpdateRect();
}

void MineSweepingLineNode::setLineColor(QColor argColor) {
    if (mmmLineColor == argColor) {
        return;
    }
    mmmLineColor = argColor;
    pppUpdateColor();
}

/*考虑到某些显卡不支持特定线宽，所以用矩形代替*/
void MineSweepingLineNode::pppUpdateRect() {

    this->markDirty(DirtyGeometry);

    auto dx = mmmEndPoint.x() - mmmStartPoint.x();
    auto dy = mmmEndPoint.y() - mmmStartPoint.y();
    auto varLength = std::hypot(dx, dy);
    /*检查数学库*/
    assert(std::hypot(3., 4.) == 5.);

    if ((varLength < static_cast<qreal>(
        std::numeric_limits<GLfloat>::epsilon())) ||
        (mmmLineWidth < static_cast<qreal>(
            std::numeric_limits<GLfloat>::epsilon()))) {
        mmmIsNull = true;
        auto varPoint = mmmGeometry.vertexDataAsPoint2D();
        varPoint[0].set(0, 0);
        varPoint[1].set(0, 0);
        varPoint[2].set(0, 0);
        varPoint[3].set(0, 0);
        return;
    }

    mmmIsNull = false;
    auto varStarPoint = mmmStartPoint;
    auto varEndPoint = mmmEndPoint;
    if (dx < 0) {
        dx *= -1;
        dy *= -1;
        std::swap(varStarPoint, varEndPoint);
    }

    varLength = 0.5 * mmmLineWidth / varLength;
    dx *= varLength;
    dy *= varLength;

    /*法向量 */
    /*-dy, dx*/
    /* dy,-dx*/

    auto varPoint = mmmGeometry.vertexDataAsPoint2D();
    varPoint[0].set(
        static_cast<GLfloat>(varStarPoint.x() - dy),
        static_cast<GLfloat>(varStarPoint.y() + dx));
    varPoint[1].set(
        static_cast<GLfloat>(varStarPoint.x() + dy),
        static_cast<GLfloat>(varStarPoint.y() - dx));
    varPoint[3].set(
        static_cast<GLfloat>(varEndPoint.x() + dy),
        static_cast<GLfloat>(varEndPoint.y() - dx));
    varPoint[2].set(
        static_cast<GLfloat>(varEndPoint.x() - dy),
        static_cast<GLfloat>(varEndPoint.y() + dx));

}

void MineSweepingLineNode::pppUpdateColor() {
    this->markDirty(DirtyMaterial);
    mmmMaterial.setColor(mmmLineColor);
}

MineSweepingLineNode::MineSweepingLineNode() :
    mmmMaterial(),
    mmmGeometry(QSGGeometry::defaultAttributes_Point2D(), 4) {
    pppUpdateRect();
    pppUpdateColor();
    this->setMaterial(&mmmMaterial);
    this->setGeometry(&mmmGeometry);
    this->setFlag(QSGNode::OwnedByParent);
    mmmGeometry.setDrawingMode(QSGGeometry::DrawTriangleStrip);
}















