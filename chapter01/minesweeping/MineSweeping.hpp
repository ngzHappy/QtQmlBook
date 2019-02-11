#pragma once

#include <sstd_qt_and_qml_library.hpp>

class MineSweeping :
    public QQuickItem,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(MineSweeping) {
    Q_OBJECT
private:
    Q_PROPERTY(int rowSize READ getRowSize NOTIFY rowSizeChanged)
private:
    Q_PROPERTY(int columnSize READ getColumnSize NOTIFY columnSizeChanged)
private:
    Q_PROPERTY(int mineSize READ getMineSize NOTIFY mineSizeChanged)
private:
    Q_PROPERTY(bool isGameOver READ isGameOver NOTIFY gameOverChanged)
private:
    Q_PROPERTY(bool isGameWin READ isGameWin)
private:
    Q_PROPERTY(QQmlComponent * okMineItem READ pppGetOkMineItemItem WRITE pppSetOkMineItem NOTIFY pppOkMineChanged)
private:
    Q_PROPERTY(QQmlComponent * boomItem READ pppGetBoomItem WRITE pppSetBoomItem NOTIFY pppBoomChanged)
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
private:
    Q_PROPERTY(QQmlComponent * winItem READ getWinComponent WRITE pppSetWinItem NOTIFY pppWinChanged)
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
    inline QQmlComponent * getBoomComponent() const;
    inline QQmlComponent * getOkMineComponent() const;
    inline QQmlComponent * getWinComponent() const;
    Q_SLOT void setSizeScene(int row_size, int column_size, int mine_count);
    inline bool isGameOver() const;
    void setGameOver(bool);
    Q_SIGNAL void gameOverChanged();
    inline bool isGameWin() const;
    void setGameWin(bool);
    inline int getRowSize() const;
    inline int getColumnSize() const;
    inline int getMineSize() const;
    Q_SIGNAL void rowSizeChanged();
    Q_SIGNAL void columnSizeChanged();
    Q_SIGNAL void mineSizeChanged();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
private:
    QSGNode * mmmCurrentNode{ nullptr };
    QQmlComponent * mmmMaskComponent{ nullptr };
    QQmlComponent * mmmFlagComponent{ nullptr };
    QQmlComponent * mmmNumberItem{ nullptr };
    QQmlComponent * mmmErrorItem{ nullptr };
    QQmlComponent * mmmMineItem{ nullptr };
    QQmlComponent * mmmBoomItem{ nullptr };
    QQmlComponent * mmmOkMineItem{ nullptr };
    QQmlComponent * mmmWinItem{ nullptr };
    inline QQmlComponent * pppGetMaskComponent() const;
    inline QQmlComponent *pppGetNumberItem() const;
    inline QQmlComponent *pppGetErrorItem() const;
    inline QQmlComponent *pppGetMineItem() const;
    inline QQmlComponent *pppGetFlagComponent() const;
    inline QQmlComponent *pppGetBoomItem() const;
    inline QQmlComponent *pppGetOkMineItemItem() const;
    void pppSetMaskComponent(QQmlComponent *);
    void pppSetFlagComponent(QQmlComponent *);
    void pppSetNumberItem(QQmlComponent *);
    void pppSetErrorItem(QQmlComponent *);
    void pppSetMineItem(QQmlComponent *);
    void pppSetBoomItem(QQmlComponent *);
    void pppSetOkMineItem(QQmlComponent *);
    void pppSetWinItem(QQmlComponent *);
    Q_SIGNAL void pppMaskComponentChanged();
    Q_SIGNAL void pppFlagComponentChanged();
    Q_SIGNAL void pppMineItemChanged();
    Q_SIGNAL void pppErrorItemChanged();
    Q_SIGNAL void pppNumberItemChanged();
    Q_SIGNAL void pppBoomChanged();
    Q_SIGNAL void pppOkMineChanged();
    Q_SIGNAL void pppWinChanged();
    Q_SLOT   void pppSlotCreateObjets();
    int mmmRowCount{ -1 };
    int mmmColumnCount{ -1 };
    int mmmMineCount{ 1 };
    bool mmmIsGameOver{ false };
    bool mmmIsGameWin{ true };
protected:
    void componentComplete() override;
public:
    SSTD_END_DEFINE_VIRTUAL_CLASS(MineSweeping);
};

inline int MineSweeping::getRowSize() const {
    return mmmRowCount;
}

inline int MineSweeping::getColumnSize() const {
    return mmmColumnCount;
}

inline int MineSweeping::getMineSize() const {
    return mmmMineCount;
}

inline bool MineSweeping::isGameWin() const {
    return mmmIsGameWin;
}

inline QQmlComponent * MineSweeping::pppGetOkMineItemItem() const {
    return mmmOkMineItem;
}

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

inline bool MineSweeping::isGameOver() const {
    return mmmIsGameOver;
}

inline QQmlComponent *MineSweeping::pppGetBoomItem() const {
    return mmmBoomItem;
}

inline QQmlComponent * MineSweeping::getBoomComponent() const {
    return pppGetBoomItem();
}

inline QQmlComponent * MineSweeping::getOkMineComponent() const {
    return pppGetOkMineItemItem();
}

inline QQmlComponent * MineSweeping::getWinComponent() const {
    return mmmWinItem;
}
