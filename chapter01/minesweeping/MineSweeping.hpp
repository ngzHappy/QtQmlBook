#pragma once

#include <sstd_qt_and_qml_library.hpp>

class MineSweeping : public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MineSweeping) {
    Q_OBJECT
private:
    Q_PROPERTY(int sceneSize READ pppGetSceneSize WRITE pppSetSceneSize NOTIFY pppSceneSizeChanged)
private:
    Q_PROPERTY(QQmlComponent * maskItem READ pppGetMaskComponent WRITE pppSetMaskComponent NOTIFY pppMaskComponentChanged)
public:
    MineSweeping();
public:
    Q_SLOT QQuickItem * getLayoutItem(int);
    inline QQmlComponent * getMaskComponent() const;
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
private:
    QSGNode * mmmCurrentNode{ nullptr };
    QQmlComponent * mmmMaskComponent{ nullptr };
    inline QQmlComponent * pppGetMaskComponent() const;
    void pppSetMaskComponent(QQmlComponent *);
    Q_SIGNAL void pppMaskComponentChanged();
    Q_SIGNAL void pppSceneSizeChanged();
    Q_SLOT   void pppSlotCreateObjets();
    int mmmRowCout{ -1 };
    int mmmColumnCount{ -1 };
    inline int pppGetSceneSize() const ;
    void pppSetSceneSize(int);

    void componentComplete() override;
public:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MineSweeping);
};

inline QQmlComponent * MineSweeping::pppGetMaskComponent() const {
    return mmmMaskComponent;
}

inline QQmlComponent * MineSweeping::getMaskComponent() const {
    return pppGetMaskComponent();
}

inline int MineSweeping::pppGetSceneSize() const {
    return mmmRowCout;
}



