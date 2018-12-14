#include "MineSweeping.hpp"
#include "MineSweepingLineNode.hpp"

namespace this_file {

    class LayoutItem : public QQuickItem,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(LayoutItem) {
    public:
        LayoutItem() {
            this->setWidth(10);
            this->setHeight(10);
        }
        SSTD_END_DEFINE_VIRTUAL_CLASS(LayoutItem);
    };

    class Node :
        public QSGNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Node) {
    public:

        inline Node() {
            this->setFlag(QSGNode::OwnedByParent);
        }

        std::vector< LayoutItem * > mmmLayoutItem;

        inline void create_objects(
            int argRow,
            int argColumn,
            MineSweeping * argParent) {
            const auto varCount = argRow * argColumn;
            auto varContex = QQmlEngine::contextForObject(argParent);
            for (auto i : mmmLayoutItem) {
                delete i;
            }
            mmmLayoutItem.clear();
            mmmLayoutItem.reserve(varCount);
            while (mmmLayoutItem.size() < varCount) {
                auto varItem = sstd_new<LayoutItem>();
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
                }
            }
        }

        inline void update_data(
            int argRow,
            int argColumn,
            double argWidth,
            double argHeight,
            MineSweeping * argParent) {

            argWidth /= argColumn;
            argHeight /= argRow;

            int i = 0;
            for (int r = 0; r < argRow; ++r) {
                auto varRow = mmmRowLines[r];
                for (int c = 0; c < argColumn; ++c) {
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
            int argRow,
            int argColumn,
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
            int argRow,
            int argColumn) {

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
        varNode->rebuild_scene(mmmRowCout, mmmColumnCount, this->width(), this->height());
        varNode->update_data(mmmRowCout, mmmColumnCount, this->width(), this->height(), this);
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
    return varNode->mmmLayoutItem[arg] ;
}

void MineSweeping::pppSetMaskComponent(QQmlComponent * arg) {
    assert(mmmMaskComponent == nullptr);
    mmmMaskComponent = arg;
    pppMaskComponentChanged();
}

void MineSweeping::pppSlotCreateObjets() {
    if (mmmMaskComponent == nullptr) {
        return;
    }
    mmmCurrentNode = sstd_new<this_file::Node>();
    auto varNode = static_cast<this_file::Node*>(mmmCurrentNode);
    varNode->rebuild_scene(mmmRowCout, mmmColumnCount, this->width(), this->height());
    varNode->create_objects(mmmRowCout, mmmColumnCount, this);
    varNode->update_data(mmmRowCout, mmmColumnCount, this->width(), this->height(), this);
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

static inline void register_this() {
    qmlRegisterType<MineSweeping>(
        "sstd.minesweeping",
        1, 0,
        "MineSweeping");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)












