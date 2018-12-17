#pragma once

#include <sstd_qt_and_qml_library.hpp>

class MineSweeping : public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MineSweeping) {
    Q_OBJECT
private:
    Q_PROPERTY(QQmlComponent * numberItem READ pppGetNumberItem WRITE pppSetNumberItem NOTIFY pppNumberItemChanged)
private:
    Q_PROPERTY(QQmlComponent * errorItem READ pppGetErrorItem WRITE pppSetErrorItem NOTIFY pppErrorItemChanged)
private:
    Q_PROPERTY(QQmlComponent * mineItem READ pppGetMineItem WRITE pppSetMineItem NOTIFY pppMineItemChanged)
private:
    Q_PROPERTY(QQmlComponent * flagItem READ pppGetFlagComponent WRITE pppSetFlagComponent NOTIFY pppFlagComponentChanged)
private:
    Q_PROPERTY(QQmlComponent * maskItem READ pppGetMaskComponent WRITE pppSetMaskComponent NOTIFY pppMaskComponentChanged)
public:
    MineSweeping();
    ~MineSweeping();
public:
    Q_SLOT QQuickItem * getLayoutItem(int);
    inline QQmlComponent * getMaskComponent() const;
    inline QQmlComponent * getFlagComponent() const;
    inline QQmlComponent * getMineComponent() const;
    inline QQmlComponent * getErrorComponent() const;
    inline QQmlComponent * getNumberComponent() const;
    Q_SLOT void setSizeScene( int row_size,int column_size, int mine_count);
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
private:
    QSGNode * mmmCurrentNode{ nullptr };
    QQmlComponent * mmmMaskComponent{ nullptr };
    QQmlComponent * mmmFlagComponent{ nullptr };
    QQmlComponent * mmmNumberItem{ nullptr };
    QQmlComponent * mmmErrorItem{ nullptr };
    QQmlComponent * mmmMineItem{nullptr};
    inline QQmlComponent * pppGetMaskComponent() const;
    inline QQmlComponent *pppGetNumberItem() const ;
    inline QQmlComponent *pppGetErrorItem() const;
    inline QQmlComponent *pppGetMineItem() const;
    inline QQmlComponent *pppGetFlagComponent() const;
    void pppSetMaskComponent(QQmlComponent *);
    void pppSetFlagComponent(QQmlComponent *);
    void pppSetNumberItem(QQmlComponent *)  ;
    void pppSetErrorItem (QQmlComponent *)  ;
    void pppSetMineItem  (QQmlComponent *)  ;
    Q_SIGNAL void pppMaskComponentChanged();
    Q_SIGNAL void pppFlagComponentChanged();
    Q_SIGNAL void pppMineItemChanged();
    Q_SIGNAL void pppErrorItemChanged();
    Q_SIGNAL void pppNumberItemChanged();
    Q_SLOT   void pppSlotCreateObjets();
    int mmmRowCout{ -1 };
    int mmmColumnCount{ -1 };
    int mmmMineCount{ 1 };
protected:
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

inline QQmlComponent * MineSweeping::pppGetFlagComponent() const {
    return mmmFlagComponent;
}

inline QQmlComponent * MineSweeping::getFlagComponent() const {
    return pppGetFlagComponent();
}

inline QQmlComponent *MineSweeping::pppGetNumberItem() const {
    return mmmNumberItem;
}

inline QQmlComponent *MineSweeping::pppGetErrorItem() const {
    return mmmErrorItem;
}

inline QQmlComponent *MineSweeping::pppGetMineItem() const {
    return mmmMineItem;
}

inline QQmlComponent * MineSweeping::getMineComponent() const {
    return pppGetMineItem();
}

inline QQmlComponent * MineSweeping::getErrorComponent() const {
    return pppGetErrorItem();
}

inline QQmlComponent * MineSweeping::getNumberComponent() const {
    return pppGetNumberItem();
}


