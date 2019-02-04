#pragma once

#include <sstd_qt_and_qml_library.hpp>

class BigScene2DViewer :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(BigScene2DViewer){
    Q_OBJECT
private:
    Q_PROPERTY(QQmlComponent * controlItem READ pppGetControlComponent WRITE pppSetControlComponent NOTIFY pppControlComponentChanged)
private:
    Q_PROPERTY(qreal controlCenterY READ pppGetCenterY NOTIFY pppCenterYUpdate)
private:
    Q_PROPERTY(qreal controlCenterX READ pppGetCenterX NOTIFY pppCenterXUpdate)
private:
    QQmlComponent * mmmControl{ nullptr };
    QQuickItem * mmmControlObject{ nullptr };
    QTimer * mmmUpdateTimer{ nullptr };
    qreal mmmCenterX{ 0 };
    qreal mmmCenterY{ 0 };
    QMatrix mmmThisMatrix;
    QMatrix mmmThisInvMatrix;
public:
    BigScene2DViewer();
    ~BigScene2DViewer();
public:
    Q_SLOT void runCommand(QString);
    Q_SLOT void rotateByAngle(qreal/**/);
    Q_SLOT void moveByX(qreal/**/);
    Q_SLOT void moveByY(qreal/**/);
    Q_SLOT void scaleByXY(qreal);
    Q_SLOT void resetThisMatrix();
private:
    inline QQmlComponent * pppGetControlComponent() const;
    void pppSetControlComponent(QQmlComponent *);
    Q_SIGNAL void pppControlComponentChanged();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *) override;
private:
    Q_SLOT void pppUpdate();
    void pppSetCenterX(qreal);
    void pppSetCenterY(qreal);
    inline qreal pppGetCenterX() const;
    inline qreal pppGetCenterY() const;
    Q_SIGNAL void pppCenterXUpdate();
    Q_SIGNAL void pppCenterYUpdate();
    void pppRawSetCenterX();
    void pppRawSetCenterY();
    void pppUpdateMatrix();
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(BigScene2DViewer);
};

inline QQmlComponent * BigScene2DViewer::pppGetControlComponent() const {
    return mmmControl;
}

inline qreal BigScene2DViewer::pppGetCenterX() const {
    return mmmCenterX;
}

inline qreal BigScene2DViewer::pppGetCenterY() const {
    return mmmCenterY;
}
