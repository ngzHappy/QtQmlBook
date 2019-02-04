#pragma once

#include <sstd_qt_and_qml_library.hpp>

class BigScene :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(BigScene) {
    Q_OBJECT
private:
    Q_PROPERTY(qreal visibleXPosition READ getVisibleXPosition WRITE setVisibleXPosition NOTIFY visibleXPositionChanged )
private:
    Q_PROPERTY(qreal visibleYPosition READ getVisibleYPosition WRITE setVisibleYPosition NOTIFY visibleYPositionChanged )
private:
    Q_PROPERTY(qreal visibleWidth     READ getVisibleWidth     WRITE setVisibleWidth     NOTIFY visibleWidthChanged )
private:
    Q_PROPERTY(qreal visibleHeight    READ getVisibleHeight    WRITE setVisibleHeight    NOTIFY visibleHeightChanged )
private:
    using Super = sstd::DirectDrawImage;
public:
    BigScene();
public:
    qreal getVisibleXPosition() const;
    qreal getVisibleYPosition() const;
    qreal getVisibleWidth()const;
    qreal getVisibleHeight()const;
public:
    void setVisibleXPosition(qreal ) ;
    void setVisibleYPosition(qreal);
    void setVisibleWidth(qreal);
    void setVisibleHeight(qreal);
public:
    Q_SIGNAL void visibleXPositionChanged();
    Q_SIGNAL void visibleYPositionChanged();
    Q_SIGNAL void visibleWidthChanged();
    Q_SIGNAL void visibleHeightChanged();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
    qreal mmmVisibleXPos{ 1 };
    qreal mmmVisibleYPos{ 1 };
    qreal mmmVisibleWidth{ 1 };
    qreal mmmVisibleHeight{ 1 };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(BigScene);
};
