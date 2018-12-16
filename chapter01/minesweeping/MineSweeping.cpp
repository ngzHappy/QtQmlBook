#include "MineSweeping.hpp"
#include "MineSweepingLineNode.hpp"

namespace this_file {

    class Node;
    class LayoutItem : public QQuickItem,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(LayoutItem) {
        int const mmmRow;
        int const mmmColumn;
        Node * const mmmParent;
        QQuickItem * mmmFlagItem{ nullptr };
        QQuickItem * mmmMaskItem{ nullptr };
        QQuickItem * mmmErrorItem{ nullptr };
        QQuickItem * mmmMineItem{ nullptr };
        QQuickItem * mmmNumberItem{ nullptr };
        QQmlProperty * mmmNumberTextPorperty{ nullptr };
    private:
        using Super = QQuickItem;
    public:
        LayoutItem(int r, int c, Node * p) :
            mmmRow(r),
            mmmColumn(c),
            mmmParent(p) {
            this->setWidth(128);
            this->setHeight(128);
            this->setAcceptedMouseButtons(Qt::AllButtons);
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
        inline void setNumber(QQuickItem * v) {
            mmmNumberItem = v;
        }
        inline void createFlag();
        inline void createError();
        inline void createNumber();
        inline void createMine();
    protected:
        inline void mousePressEvent(QMouseEvent *event) override;
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(LayoutItem);
    };

    class Node :
        public QSGNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Node) {
    public:
        MineSweeping * const mmmMineSweeping;
    public:

        inline Node(MineSweeping * v) :
            mmmMineSweeping(v) {
            this->setFlag(QSGNode::OwnedByParent);
        }

        std::vector< LayoutItem * > mmmLayoutItem;

        inline void clear_objects() {
            for (auto i : mmmLayoutItem) {
                delete i;
            }
            mmmLayoutItem.clear();
        }

        inline void create_objects(
            std::size_t argRow,
            std::size_t argColumn,
            MineSweeping * argParent) {
            const auto varCount = static_cast<std::size_t>(
                        argRow * argColumn );
            auto varContex = QQmlEngine::contextForObject(argParent);
            clear_objects();
            mmmLayoutItem.reserve(varCount);
            std::size_t r = 0;
            std::size_t c = 0;
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
                }
            }
        }

        inline void update_data(
            std::size_t argRow,
            std::size_t argColumn,
            double argWidth,
            double argHeight) {

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
                    varItem->setX(varCPoint.x());
                    varItem->setY(varRPoint.y());
                    varItem->setWidth(argWidth);
                    varItem->setHeight(argHeight);
                    ++i;
                }
            }

        }

        inline void rebuild_scene(
            std::size_t argRow,
            std::size_t argColumn,
            double argWidth,
            double argHeight) {

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

        sstd::vector< MineSweepingLineNode * > mmmRowLines;
        sstd::vector< MineSweepingLineNode * > mmmColumnLines;

    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Node);
    };

    inline void  LayoutItem::createFlag() {
        if (mmmFlagItem) {
            return;
        }
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
        varFlagObject->setZ(9);
    }

    inline void LayoutItem::createError() {
        if (mmmErrorItem) {
            return;
        }
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
        varObject->setZ(10);
    }
    inline void LayoutItem::createNumber() {
        if (mmmNumberItem) {
            return;
        }
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
        varObject->setZ(0);
        mmmNumberTextPorperty =
            this->sstd_create_data_in_this_class<QQmlProperty>(
                varObject,
                QStringLiteral("text"));
    }
    inline void LayoutItem::createMine() {
        if (mmmMineItem) {
            return;
        }
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
        varObject->setZ(1);
    }

    inline void LayoutItem::mousePressEvent(QMouseEvent *event) {
        QQuickItem::mousePressEvent(event);

        createNumber();
        static int test = 1;
        mmmNumberTextPorperty->write(test);
        ++test;
        if (test > 8) {
            test = 1;
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
        const auto varRowCount = static_cast<std::size_t>(mmmRowCout);
        const auto varColumnCount = static_cast<std::size_t>(mmmColumnCount);
        varNode->rebuild_scene(varRowCount, varColumnCount, this->width(), this->height());
        varNode->update_data(varRowCount, varColumnCount, this->width(), this->height());
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
    return varNode->mmmLayoutItem[ static_cast<std::size_t>(arg) ];
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

void MineSweeping::pppSlotCreateObjets() {
    if (mmmMaskComponent == nullptr) {
        return;
    }
    mmmCurrentNode = sstd_new<this_file::Node>(this);
    auto varNode = static_cast<this_file::Node*>(mmmCurrentNode);
    const auto varRowCount = static_cast<std::size_t>(mmmRowCout);
    const auto varColumnCount = static_cast<std::size_t>(mmmColumnCount);
    varNode->rebuild_scene(varRowCount, varColumnCount, this->width(), this->height());
    varNode->create_objects(varRowCount, varColumnCount, this);
    varNode->update_data(varRowCount, varColumnCount, this->width(), this->height() );
}

void MineSweeping::pppSetSceneSize(int arg) {
    if (mmmRowCout == arg) {
        return;
    }
    mmmRowCout = arg;
    mmmColumnCount = arg;
    pppSlotCreateObjets();
    pppSceneSizeChanged();
}

void MineSweeping::componentComplete() {
    QQuickItem::componentComplete();
    pppSetSceneSize(10);
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












