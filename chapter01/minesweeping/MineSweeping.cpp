#include "MineSweeping.hpp"
#include "MineSweepingLineNode.hpp"
#include <random>
#include <algorithm>

namespace this_file {

    enum class ItemState : std::size_t {
        Mask,
        Flag,
        Open,
        Boom,
        AboutOpenMask,
    };

    inline constexpr qreal getBoomZValue_() {
        return 10;
    }

    inline constexpr qreal getFlagZValue_() {
        return 5;
    }

    inline constexpr qreal getMaskZValue_() {
        return 0;
    }

    inline constexpr qreal getErrorZValue_() {
        return 30;
    }

    inline constexpr qreal getMineZValue_() {
        return 20;
    }

    inline constexpr qreal getNumberZValue_() {
        return 25;
    }

    class Node;
    class LayoutItem :
        public QQuickItem,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(LayoutItem) {
        std::size_t const mmmRow/*当前行*/;
        std::size_t const mmmColumn/*当前列*/;
        Node * const mmmParent/*管理者*/;
        QQuickItem * mmmBoomItem{ nullptr };
        QQuickItem * mmmFlagItem{ nullptr };
        QQuickItem * mmmMaskItem{ nullptr };
        QQuickItem * mmmErrorItem{ nullptr };
        union {
            QQuickItem * mmmMineItem;
            QQuickItem * mmmOkMineItem;
        };
        QQuickItem * mmmNumberItem{ nullptr };
        QQmlProperty * mmmNumberTextPorperty{ nullptr };
        ItemState mmmState{ ItemState::Mask };
    public:
        static QMetaProperty mmmXProperty;
        static QMetaProperty mmmYProperty;
        static QMetaProperty mmmWidthProperty;
        static QMetaProperty mmmHeightProperty;
        inline const ItemState & getItemState() const {
            return mmmState;
        }
        inline bool isMine() const {
            return mmmIsMine;
        }

        inline bool event(QEvent* ev) override {
            if (ev->type() == sstd::RunEvent::getEventID()) {
                static_cast<sstd::RunEvent*>(ev)->run();
                return true;
            }
            return Super::event(ev);
        }

        template<typename TX>
        inline void call_function(TX && argFunction) {
            auto varEvent =
                sstd::RunEvent::createRunEvent(
                    std::forward<TX>(argFunction));
            QCoreApplication::postEvent(this, varEvent);
        }

    private:
        LayoutItem * mmmLeftItem{ nullptr };
        LayoutItem * mmmRightItem{ nullptr };
        LayoutItem * mmmBottomItem{ nullptr };
        LayoutItem * mmmTopItem{ nullptr };
        LayoutItem * mmmTopLeftItem{ nullptr };
        LayoutItem * mmmTopRightItem{ nullptr };
        LayoutItem * mmmBottomLeftItem{ nullptr };
        LayoutItem * mmmBottomRightItem{ nullptr };
        unsigned mmmNumberOfThis : 16;
        unsigned mmmIsMine : 16;
    private:
        using Super = QQuickItem;
    public:

        LayoutItem(std::size_t r, std::size_t c, Node * p) :
            mmmRow(r),
            mmmColumn(c),
            mmmParent(p) {
            mmmNumberOfThis = 0;
            mmmMineItem = nullptr;
            mmmIsMine = false;
            this->setWidth(128);
            this->setHeight(128);
            this->setAcceptedMouseButtons(Qt::AllButtons);
        }

        inline void setToMine() {
            mmmIsMine = true;
        }

        inline void updateMineCount() {
            mmmNumberOfThis = 0;
            if (mmmIsMine) {
                return;
            }
            if (mmmLeftItem&&mmmLeftItem->mmmIsMine) {
                ++mmmNumberOfThis;
            }
            if (mmmRightItem&&mmmRightItem->mmmIsMine) {
                ++mmmNumberOfThis;
            }
            if (mmmBottomItem&&mmmBottomItem->mmmIsMine) {
                ++mmmNumberOfThis;
            }
            if (mmmTopItem&&mmmTopItem->mmmIsMine) {
                ++mmmNumberOfThis;
            }
            if (mmmTopLeftItem&&mmmTopLeftItem->mmmIsMine) {
                ++mmmNumberOfThis;
            }
            if (mmmBottomLeftItem&&mmmBottomLeftItem->mmmIsMine) {
                ++mmmNumberOfThis;
            }
            if (mmmTopRightItem&&mmmTopRightItem->mmmIsMine) {
                ++mmmNumberOfThis;
            }
            if (mmmBottomRightItem&&mmmBottomRightItem->mmmIsMine) {
                ++mmmNumberOfThis;
            }
        }

        inline LayoutItem * setAboutOpenMask() {
            this->mmmState = ItemState::AboutOpenMask;
            return this;
        }

        inline void setNeighbor(
            LayoutItem * topleft,
            LayoutItem * top,
            LayoutItem * topright,
            LayoutItem * left,
            LayoutItem * right,
            LayoutItem * bottomleft,
            LayoutItem * bottom,
            LayoutItem * bottomright
        ) {
            mmmLeftItem = left;
            mmmRightItem = right;
            mmmBottomItem = bottom;
            mmmTopItem = top;
            mmmTopLeftItem = topleft;
            mmmTopRightItem = topright;
            mmmBottomLeftItem = bottomleft;
            mmmBottomRightItem = bottomright;
        }

        inline auto getTop() const {
            return mmmTopItem;
        }

        inline auto getTopLeft() const {
            return mmmTopLeftItem;
        }

        inline auto getTopRight() const {
            return mmmTopRightItem;
        }

        inline auto getBottom() const {
            return mmmBottomItem;
        }

        inline auto getBottomLeft() const {
            return mmmBottomLeftItem;
        }

        inline auto getBottomRight() const {
            return mmmBottomRightItem;
        }

        inline auto getLeft() const {
            return mmmLeftItem;
        }

        inline auto getRight() const {
            return mmmRightItem;
        }

        inline void setMask(QQuickItem * v) {
            mmmMaskItem = v;
        }
        inline void setFlag(QQuickItem * v) {
            mmmFlagItem = v;
        }
        inline void setError(QQuickItem * v) {
            mmmErrorItem = v;
        }
        inline void setMine(QQuickItem * v) {
            mmmMineItem = v;
        }
        inline void setOkMine(QQuickItem * v) {
            mmmOkMineItem = v;
        }
        inline void setNumber(QQuickItem * v) {
            mmmNumberItem = v;
        }
        inline void setBoom(QQuickItem * v) {
            mmmBoomItem = v;
        }
        inline void createFlag();
        inline void createError();
        inline void createNumber();
        inline void createNumber(int);
        inline void createMine();
        inline void createOkMine();
        inline void createBoom();
        inline void openItem();
        inline void openFlag();
        inline void gameOver();
        inline bool isGameOver() const;
        inline void rawOpen();
        inline void hideFlag() {
            mmmFlagItem->setVisible(false);
        }
    protected:
        inline void mousePressEvent(QMouseEvent *event) override;
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(LayoutItem);
    };

    QMetaProperty LayoutItem::mmmXProperty = []() {
        auto varIndex =
            LayoutItem::staticMetaObject.indexOfProperty("x");
        return  LayoutItem::staticMetaObject.property(varIndex);
    }();

    QMetaProperty LayoutItem::mmmYProperty = []() {
        auto varIndex =
            LayoutItem::staticMetaObject.indexOfProperty("y");
        return  LayoutItem::staticMetaObject.property(varIndex);
    }();

    QMetaProperty LayoutItem::mmmWidthProperty = []() {
        auto varIndex =
            LayoutItem::staticMetaObject.indexOfProperty("width");
        return  LayoutItem::staticMetaObject.property(varIndex);
    }();

    QMetaProperty LayoutItem::mmmHeightProperty = []() {
        auto varIndex =
            LayoutItem::staticMetaObject.indexOfProperty("height");
        return  LayoutItem::staticMetaObject.property(varIndex);
    }();

    class Node :
        public QObject,
        public QSGNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Node) {
    public:
        MineSweeping * const mmmMineSweeping;
    public:

        inline bool event(QEvent* ev) override {
            if (ev->type() == sstd::RunEvent::getEventID()) {
                static_cast<sstd::RunEvent*>(ev)->run();
                return true;
            }
            return QObject::event(ev);
        }

        template<typename TX>
        inline void call_function(TX && argFunction) {
            auto varEvent =
                sstd::RunEvent::createRunEvent(
                    std::forward<TX>(argFunction));
            QCoreApplication::postEvent(this, varEvent);
        }

        inline Node(MineSweeping * v) :
            mmmMineSweeping(v) {
            this->setFlag(QSGNode::OwnedByParent);
        }

        std::vector< LayoutItem * > mmmLayoutItem;

        inline bool isGameOver() {
            return mmmMineSweeping->isGameOver();
        }

        inline void setGameOver() {
            mmmMineSweeping->setGameOver(true);
            for (auto i : mmmLayoutItem) {
                auto varFunction = [i]() {
                    if (i->getItemState() == ItemState::Open) {
                        return;
                    } else if (i->getItemState() == ItemState::Mask) {
                        if (i->isMine()) {
                            i->rawOpen();
                            i->createMine();
                            return;
                        } else {
                            i->rawOpen();
                            return;
                        }
                    } else if (i->getItemState() == ItemState::Boom) {
                        i->rawOpen();
                        i->createMine();
                        i->createBoom();
                        return;
                    } else if (i->getItemState() == ItemState::Flag) {
                        i->hideFlag();
                        if (i->isMine()) {
                            i->rawOpen();
                            i->createOkMine();
                            return;
                        } else {
                            i->rawOpen();
                            i->createError();
                            return;
                        }
                    }
                };
                i->call_function(std::move(varFunction));
            }
        }

        inline void clear_objects() {
            for (auto i : mmmLayoutItem) {
                delete i;
            }
            mmmLayoutItem.clear();
        }

        inline std::size_t & add_one(
            std::size_t & a,
            const int & b) {
            if (b == 0) {
                return a;
            }
            if (b > 0) {
                assert(b == 1);
                return ++a;
            }
            assert(b == -1);
            return --a;
        }

        inline void create_objects_and_mask() {

            MineSweeping * argParent = mmmMineSweeping;

            const auto & argRow = mmmRowSize;
            const auto & argColumn = mmmColumnSize;

            /*计算总个数*/
            const auto varCount = static_cast<std::size_t>(
                argRow * argColumn);
            auto varContex = QQmlEngine::contextForObject(argParent);
            /*删除所有元素*/
            clear_objects();

            mmmLayoutItem.reserve(varCount);
            std::size_t r = 0;
            std::size_t c = 0;

            /*重新创建元素*/
            while (mmmLayoutItem.size() < varCount) {
                auto varItem = sstd_new<LayoutItem>(r, c, this);
                {
                    ++c;
                    if (!(c < argColumn)) {
                        c = 0;
                        ++r;
                    }
                }
                {/*创建layout item*/
                    varItem->setParent(argParent);
                    varItem->setParentItem(argParent);
                    mmmLayoutItem.emplace_back(varItem);
                }
                {/*创建遮罩*/
                    auto varMaskComponent = argParent->getMaskComponent();
                    assert(varMaskComponent);
                    auto varMaskItem = sstd_runtime_cast<QQuickItem>(
                        varMaskComponent->beginCreate(varContex));
                    assert(varMaskItem);
                    varMaskItem->setParent(varItem);
                    varMaskItem->setParentItem(varItem);
                    varMaskComponent->completeCreate();
                    varItem->setMask(varMaskItem);
                    varMaskItem->setZ(getMaskZValue_());
                }
            }

            auto getItem = [this](
                std::size_t r, std::size_t c,
                int dr, int dc) -> LayoutItem * {
                if ((r == 0) && (dr < 0)) {
                    return nullptr;
                }
                if ((c == 0) && (dc < 0)) {
                    return nullptr;
                }
                add_one(r, dr);
                add_one(c, dc);
                if (r >= this->mmmRowSize) {
                    return nullptr;
                }
                if (c >= this->mmmColumnSize) {
                    return nullptr;
                }
                auto i =
                    r * (this->mmmColumnSize) + c;
                return mmmLayoutItem[i];
            };

            /*更新邻居*/
            std::size_t i = 0;
            for (r = 0; r < argRow; ++r) {
                for (c = 0; c < argColumn; ++c, ++i) {

                    LayoutItem * item = mmmLayoutItem[i];

                    LayoutItem * topleft = getItem(r, c, -1, -1);
                    LayoutItem * left = getItem(r, c, 0, -1);
                    LayoutItem * bottomleft = getItem(r, c, 1, -1);

                    LayoutItem * top = getItem(r, c, -1, 0);
                    LayoutItem * bottom = getItem(r, c, 1, 0);

                    LayoutItem * topright = getItem(r, c, -1, 1);
                    LayoutItem * right = getItem(r, c, 0, 1);
                    LayoutItem * bottomright = getItem(r, c, 1, 1);

                    assert(item == getItem(r, c, 0, 0));

                    item->setNeighbor(
                        topleft,
                        top,
                        topright,
                        left,
                        right,
                        bottomleft,
                        bottom,
                        bottomright
                    );

                }
            }

            /*更新地图*/
            std::vector< std::uint8_t > varMap;
            if (varCount == mmmMineCount) {
                varMap.resize(varCount, static_cast<std::uint8_t>(1));
            } else {
                varMap.resize(varCount, static_cast<std::uint8_t>(0));
                for (std::size_t i = 0; i < mmmMineCount; ++i) {
                    varMap[i] = static_cast<std::uint8_t>(1);
                }
            }

            if (varCount > 8) {
                int varBegin = 0;
                int varEnd = static_cast<int>(varCount - 1);
                while (varEnd > varBegin) {
                    std::swap(
                        varMap[static_cast<std::size_t>(varEnd)],
                        varMap[static_cast<std::size_t>(varBegin)]);
                    varBegin += 2;
                    varEnd -= 2;
                }
            }

            /*地雷随机化*/
            {
                std::random_device varDevice;
                std::mt19937 varGenerator(varDevice());
                for (i = 0; i < 3; ++i) {
                    std::shuffle(varMap.begin(), varMap.end(), varGenerator);
                    std::shuffle(varMap.begin(), varMap.end(), varGenerator);
                    std::shuffle(varMap.begin(), varMap.end(), varGenerator);
                }
            }

            i = 0;

            /*更新数据*/
            for (; i < varCount; ++i) {
                if (varMap[i]) {
                    mmmLayoutItem[i]->setToMine();
                }
            }

            for (auto varI : mmmLayoutItem) {
                varI->updateMineCount();
            }

        }

        inline void update_data(
            double argWidth,
            double argHeight) {

            const auto & argRow = mmmRowSize;
            const auto & argColumn = mmmColumnSize;

            argWidth /= argColumn;
            argHeight /= argRow;

            std::size_t i = 0;
            for (std::size_t r = 0; r < argRow; ++r) {
                auto varRow = mmmRowLines[r];
                for (std::size_t c = 0; c < argColumn; ++c) {
                    auto varColumne = mmmColumnLines[c];
                    const auto & varItem = mmmLayoutItem[i];
                    const auto varCPoint = varColumne->getBeginPoint();
                    const auto varRPoint = varRow->getBeginPoint();
                    auto varFunction = [varItem,
                        x = varCPoint.x(),
                        y = varRPoint.y(),
                        width = argWidth,
                        height = argHeight
                    ]() {
                        varItem->mmmXProperty.write(varItem, x);
                        varItem->mmmYProperty.write(varItem, y);
                        varItem->mmmWidthProperty.write(varItem, width);
                        varItem->mmmHeightProperty.write(varItem, height);
                    };
                    varItem->call_function(std::move(varFunction));
                    ++i;
                }
            }

        }

        std::size_t mmmRowSize{ 1 };
        std::size_t mmmColumnSize{ 1 };
        std::size_t mmmMineCount{ 1 };

        void reset_size(
            std::size_t argRow,
            std::size_t argColumn,
            std::size_t argMineCount) {
            mmmRowSize = argRow;
            mmmColumnSize = argColumn;
            mmmMineCount = argMineCount;
        }

        inline void rebuild_scene(
            double argWidth,
            double argHeight) {

            const auto & argRow = mmmRowSize;
            const auto & argColumn = mmmColumnSize;

            const auto varItemHeight = argHeight / argRow;
            const auto varItemWidth = argWidth / argColumn;

            resize_lines(argRow, argColumn);

            {
                double varHeight = 0;
                for (auto varI : mmmRowLines) {
                    varI->setBeginEndPoints({ 0,varHeight }, { argWidth,varHeight });
                    varHeight += varItemHeight;
                }
            }

            {
                double varWidth = 0;
                for (auto varI : mmmColumnLines) {
                    varI->setBeginEndPoints({ varWidth,0 }, { varWidth,argHeight });
                    varWidth += varItemWidth;
                }
            }

        }

        sstd::vector< MineSweepingLineNode * > mmmRowLines;
        sstd::vector< MineSweepingLineNode * > mmmColumnLines;

    private:

        inline void resize_lines(
            std::size_t argRow,
            std::size_t argColumn) {

            ++argColumn;
            ++argRow;

            while (mmmRowLines.size() > argRow) {
                this->removeChildNode(*mmmRowLines.rbegin());
                mmmRowLines.pop_back();
            }

            while (mmmColumnLines.size() > argColumn) {
                this->removeChildNode(*mmmColumnLines.rbegin());
                mmmColumnLines.pop_back();
            }

            mmmRowLines.reserve(argRow);
            while (mmmRowLines.size() < argRow) {
                auto var = sstd_new< MineSweepingLineNode >();
                this->appendChildNode(var);
                mmmRowLines.push_back(var);
            }
            mmmColumnLines.reserve(argColumn);
            while (mmmColumnLines.size() < argColumn) {
                auto var = sstd_new< MineSweepingLineNode >();
                this->appendChildNode(var);
                mmmColumnLines.push_back(var);
            }
        }

    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Node);
    };

    inline void  LayoutItem::createFlag() {
        if (mmmFlagItem) {
            return;
        }
        mmmState = ItemState::Flag;
        auto varContex = QQmlEngine::contextForObject(mmmParent->mmmMineSweeping);
        auto varFlag = mmmParent->mmmMineSweeping->getFlagComponent();
        assert(varFlag);
        auto varFlagObject =
            sstd_runtime_cast<QQuickItem>(
                varFlag->beginCreate(varContex));
        assert(varFlagObject);
        varFlagObject->setParent(this);
        varFlagObject->setParentItem(this);
        varFlag->completeCreate();
        this->setFlag(varFlagObject);
        varFlagObject->setZ(getFlagZValue_());
    }

    inline void LayoutItem::createError() {
        if (mmmErrorItem) {
            return;
        }
        mmmState = ItemState::Open;
        auto varContex = QQmlEngine::contextForObject(mmmParent->mmmMineSweeping);
        auto varComponent = mmmParent->mmmMineSweeping->getErrorComponent();
        assert(varComponent);
        auto varObject =
            sstd_runtime_cast<QQuickItem>(
                varComponent->beginCreate(varContex));
        assert(varObject);
        varObject->setParent(this);
        varObject->setParentItem(this);
        varComponent->completeCreate();
        this->setError(varObject);
        varObject->setZ(getErrorZValue_());
    }

    inline void LayoutItem::createNumber() {
        if (mmmNumberItem) {
            return;
        }
        mmmState = ItemState::Open;
        auto varContex = QQmlEngine::contextForObject(mmmParent->mmmMineSweeping);
        auto varComponent = mmmParent->mmmMineSweeping->getNumberComponent();
        assert(varComponent);
        auto varObject =
            sstd_runtime_cast<QQuickItem>(
                varComponent->beginCreate(varContex));
        assert(varObject);
        varObject->setParent(this);
        varObject->setParentItem(this);
        varComponent->completeCreate();
        this->setNumber(varObject);
        varObject->setZ(getNumberZValue_());
        mmmNumberTextPorperty =
            this->sstd_create_data_in_this_class<QQmlProperty>(
                varObject,
                QStringLiteral("text"));
    }

    inline void LayoutItem::createBoom() {
        if (mmmBoomItem) {
            return;
        }
        mmmState = ItemState::Open;
        auto varContex = QQmlEngine::contextForObject(mmmParent->mmmMineSweeping);
        auto varComponent = mmmParent->mmmMineSweeping->getBoomComponent();
        assert(varComponent);
        auto varObject =
            sstd_runtime_cast<QQuickItem>(
                varComponent->beginCreate(varContex));
        assert(varObject);
        varObject->setParent(this);
        varObject->setParentItem(this);
        varComponent->completeCreate();
        this->setBoom(varObject);
        varObject->setZ(getBoomZValue_());
    }

    inline void LayoutItem::createOkMine() {
        if (mmmOkMineItem) {
            return;
        }
        mmmState = ItemState::Open;
        auto varContex = QQmlEngine::contextForObject(mmmParent->mmmMineSweeping);
        auto varComponent = mmmParent->mmmMineSweeping->getOkMineComponent();
        assert(varComponent);
        auto varObject =
            sstd_runtime_cast<QQuickItem>(
                varComponent->beginCreate(varContex));
        assert(varObject);
        varObject->setParent(this);
        varObject->setParentItem(this);
        varComponent->completeCreate();
        this->setOkMine(varObject);
        varObject->setZ(getMineZValue_());
    }

    inline void LayoutItem::createMine() {
        if (mmmMineItem) {
            return;
        }
        mmmState = ItemState::Open;
        auto varContex = QQmlEngine::contextForObject(mmmParent->mmmMineSweeping);
        auto varComponent = mmmParent->mmmMineSweeping->getMineComponent();
        assert(varComponent);
        auto varObject =
            sstd_runtime_cast<QQuickItem>(
                varComponent->beginCreate(varContex));
        assert(varObject);
        varObject->setParent(this);
        varObject->setParentItem(this);
        varComponent->completeCreate();
        this->setMine(varObject);
        varObject->setZ(getMineZValue_());
    }

    inline void LayoutItem::createNumber(int n) {
        this->createNumber();
        this->mmmNumberTextPorperty->write(n);
    }

    inline void LayoutItem::gameOver() {
        mmmParent->setGameOver();
    }

    inline bool LayoutItem::isGameOver() const {
        return mmmParent->isGameOver();
    }

    inline void LayoutItem::openFlag() {

        if (mmmState == ItemState::Flag) {
            this->mmmFlagItem->setVisible(false);
            mmmState = ItemState::Mask;
            return;
        } else  if (mmmState == ItemState::Mask) {
            this->createFlag();
            this->mmmFlagItem->setVisible(true);
            mmmState = ItemState::Flag;
        }

    }

    inline void LayoutItem::openItem() {

        /*只处理遮罩*/
        if (mmmState != ItemState::Mask) {
            return;
        }

        /*当前是雷*/
        if (mmmIsMine) {
            this->mmmState = ItemState::Boom;
            this->gameOver();
            return;
        }

        sstd::vector< LayoutItem * > varAboutToOpen;

        {
            sstd::vector< LayoutItem * > varDoList;
            varDoList.push_back(this);
            /*加入搜索队列...*/
            auto varPushBack = [&varDoList](LayoutItem * arg) {
                if (arg == nullptr) {
                    return;
                }
                if (arg->mmmState != ItemState::Mask) {
                    return;
                }
                varDoList.push_back(arg);
            };

            while (varDoList.empty() == false) {
                auto varCurrent = varDoList.back();
                varDoList.pop_back();
                if (varCurrent == nullptr) {
                    continue;
                }
                if (varCurrent->mmmState != ItemState::Mask) {
                    continue;
                }
                /*将当前网格标记为将要打开，并加入打开队列...*/
                varAboutToOpen.push_back(varCurrent->setAboutOpenMask());
                /*如果当前网格周围有雷，停止本次搜索...*/
                if (varCurrent->mmmNumberOfThis) {
                    continue;
                }
                /*如果当前网格周围没有雷，将邻居加入搜索...*/
                varPushBack(varCurrent->getBottom());
                varPushBack(varCurrent->getBottomRight());
                varPushBack(varCurrent->getBottomLeft());
                varPushBack(varCurrent->getTop());
                varPushBack(varCurrent->getTopLeft());
                varPushBack(varCurrent->getTopRight());
                varPushBack(varCurrent->getLeft());
                varPushBack(varCurrent->getRight());
            }

        }

        /*打开网格...*/
        for (auto varItem : varAboutToOpen) {
            /*隐藏遮罩*/
            varItem->rawOpen();
        }

    }

    inline void LayoutItem::rawOpen() {
        this->mmmMaskItem->setProperty("opacity", 0);
        if (this->mmmNumberOfThis) {
            this->createNumber(this->mmmNumberOfThis);
        }
        this->mmmState = ItemState::Open;
    }

    inline void LayoutItem::mousePressEvent(QMouseEvent *event) {
        QQuickItem::mousePressEvent(event);

        /*游戏结束忽略此函数调用*/
        if (isGameOver()) {
            return;
        }

        if (event->buttons()&Qt::LeftButton) {
            /*左键...*/
            this->openItem();
        } else if (event->buttons()&Qt::RightButton) {
            /*右键...*/
            this->openFlag();
        }
    }

}/********/

QSGNode * MineSweeping::updatePaintNode(
    QSGNode *oldNode,
    QQuickItem::UpdatePaintNodeData *) {
    using namespace this_file;

    Node * varNode;
    if (oldNode == nullptr) {
        varNode = static_cast<this_file::Node*>(mmmCurrentNode);
    } else {
        varNode = static_cast<Node*>(oldNode);
    }

    if (mmmRowCout > 0) {
        varNode->rebuild_scene(this->width(), this->height());
        varNode->update_data(this->width(), this->height());
    }

    return varNode;

}

MineSweeping::MineSweeping() {
    this->setFlag(QQuickItem::ItemHasContents, true);
    this->setWidth(512);
    this->setHeight(512);
}

QQuickItem * MineSweeping::getLayoutItem(int arg) {
    auto varNode = static_cast<this_file::Node*>(mmmCurrentNode);
    return varNode->mmmLayoutItem[static_cast<std::size_t>(arg)];
}

void MineSweeping::pppSetMaskComponent(QQmlComponent * arg) {
    assert(mmmMaskComponent == nullptr);
    mmmMaskComponent = arg;
    pppMaskComponentChanged();
}

void MineSweeping::pppSetFlagComponent(QQmlComponent * arg) {
    assert(mmmFlagComponent == nullptr);
    mmmFlagComponent = arg;
    pppFlagComponentChanged();
}

void MineSweeping::pppSetNumberItem(QQmlComponent * arg) {
    assert(mmmNumberItem == nullptr);
    mmmNumberItem = arg;
    pppNumberItemChanged();
}

void MineSweeping::pppSetErrorItem(QQmlComponent * arg) {
    assert(mmmErrorItem == nullptr);
    mmmErrorItem = arg;
    pppErrorItemChanged();
}

void MineSweeping::pppSetMineItem(QQmlComponent * arg) {
    assert(mmmMineItem == nullptr);
    mmmMineItem = arg;
    pppMineItemChanged();
}

void MineSweeping::pppSetBoomItem(QQmlComponent * arg) {
    assert(mmmBoomItem == nullptr);
    mmmBoomItem = arg;
    pppBoomChanged();
}

void MineSweeping::pppSetOkMineItem(QQmlComponent * arg) {
    assert(mmmOkMineItem == nullptr);
    mmmOkMineItem = arg;
    pppOkMineChanged();
}

void MineSweeping::pppSlotCreateObjets() {
    if (mmmMaskComponent == nullptr) {
        return;
    }
    mmmCurrentNode = sstd_new<this_file::Node>(this);
    auto varNode = static_cast<this_file::Node*>(mmmCurrentNode);
    const auto varRowCount = static_cast<std::size_t>(mmmRowCout);
    const auto varColumnCount = static_cast<std::size_t>(mmmColumnCount);
    varNode->reset_size(varRowCount, varColumnCount,
        static_cast<std::size_t>(mmmMineCount));
    varNode->rebuild_scene(this->width(), this->height());
    varNode->create_objects_and_mask();
    varNode->update_data(this->width(), this->height());
}

void MineSweeping::setGameOver(bool arg) {
    if (arg == mmmIsGameOver) {
        return;
    }
    mmmIsGameOver = arg;
}

void MineSweeping::setSizeScene(int row_size, int column_size, int mine_count) {

    mmmRowCout = row_size;
    mmmColumnCount = column_size;
    mmmMineCount = mine_count;
    mmmIsGameOver = false;
    pppSlotCreateObjets();

}

void MineSweeping::componentComplete() {
    QQuickItem::componentComplete();
    setSizeScene(10, 10, 10);
}

MineSweeping::~MineSweeping() {
    if (mmmCurrentNode) {
        if (mmmCurrentNode->parent() == nullptr) {
            delete mmmCurrentNode;
        }
    }
}

static inline void register_this() {
    qmlRegisterType<MineSweeping>(
        "sstd.minesweeping",
        1, 0,
        "MineSweeping");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)












