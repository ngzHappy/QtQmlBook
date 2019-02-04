#include "BigScene.hpp"

namespace this_file {

    inline constexpr const static qreal globalRectWidth = 64;
    inline constexpr const static qreal globalRectHeight = 64;
    inline constexpr const static int globalNumberRect = 1024 * 1024;
    inline constexpr const static qreal globalSceneWidth = globalNumberRect * globalRectWidth;
    inline constexpr const static qreal globalSceneHeight = globalNumberRect * globalRectHeight;
    std::atomic< std::intmax_t > globalCount{ 0 };

    class Node :
        public QSGNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Node) {
    public:
        inline Node(const QPointF &, const QPointF &, const QPointF &, const QPointF &);
        inline void updateAll(const QPointF &, const QPointF &, const QPointF &, const QPointF &);
        sstd::map< std::pair<int, int>, sstd::SimpleRectangleNode * > mmmHasNode;
        SSTD_END_DEFINE_VIRTUAL_CLASS(Node);
    };

    inline static int randomColor(int varK) {
        switch (varK & 3) {
        case 0:return (std::rand() & 127);
        case 1:return (std::rand() & 63);
        case 2:return (std::rand() & 255);
        }
        return (std::rand() & 63);
    }

    class RectNode : public sstd::SimpleRectangleNode ,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(RectNode){
    public:
        RectNode(int nw, int nh) {

            this->setFlag(QSGNode::OwnedByParent);

            this->setRect(
                nw * globalRectWidth,
                nh * globalRectHeight,
                globalRectWidth,
                globalRectHeight);

            this->setColor({
                randomColor(nw),
                randomColor(nh),
                randomColor(nw + nh) , 255 });
#if defined(_DEBUG)
            qDebug() << __func__ << ++globalCount;
#endif
        }

        virtual ~RectNode() {
#if defined(_DEBUG)
            qDebug() << __func__ << --globalCount;
#endif
        }

    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(RectNode);
    };

    void Node::updateAll(
        const QPointF & a,
        const QPointF & b,
        const QPointF & c,
        const QPointF & d) {

        std::array<QPointF, 4> varRotatedRectangle{ a,b,c,d };
        qreal varMinX, varMinY;
        qreal varMaxX, varMaxY;

        {
            auto var = std::minmax_element(
                varRotatedRectangle.begin(),
                varRotatedRectangle.end(), [](const auto &l, const auto &r) {
                return l.x() < r.x();
            });

            varMaxX = var.second->x();
            varMinX = var.first->x();

            var = std::minmax_element(
                varRotatedRectangle.begin(),
                varRotatedRectangle.end(), [](const auto &l, const auto &r) {
                return l.y() < r.y();
            });

            varMaxY = var.second->y();
            varMinY = var.first->y();

        }

        int varMinYN, varMaxYN, varMinXN, varMaxXN;

        const constexpr auto varRH=1.0/this_file::globalRectHeight;
        const constexpr auto varRW=1.0/this_file::globalRectWidth;

        varMinYN = static_cast<int>( std::fma( varMinY , varRH ,0.5 ) ) ;
        varMaxYN = static_cast<int>( std::fma( varMaxY , varRH ,0.5 ) ) ;
        varMinXN = static_cast<int>( std::fma( varMinX , varRW ,0.5 ) ) ;
        varMaxXN = static_cast<int>( std::fma( varMaxX , varRW ,0.5 ) ) ;

        {
            constexpr const auto varMargin = 5 +
                this_file::globalRectHeight +
                this_file::globalRectWidth;

            constexpr const auto varMargin2 =
                2 * varMargin;

            const QRectF varCheckedRect{
               varMinX - varMargin ,
               varMinY - varMargin ,
               varMaxX - varMinX + varMargin2 ,
               varMaxY - varMinY + varMargin2
            };

            const auto varEnd = mmmHasNode.end();
            for (auto varPos = mmmHasNode.begin(); varPos != varEnd; ) {
                if (varPos->second->rect().intersects(varCheckedRect)) {
                    ++varPos;
                    continue;
                }
                this->removeChildNode(varPos->second);
                delete varPos->second;
                varPos = mmmHasNode.erase(varPos);
            }

        }

        for (int i = std::max(0, varMinXN - 1); i <= varMaxXN; ++i) {
            for (int j = std::max(0, varMinYN - 1); j <= varMaxYN; ++j) {
                if (mmmHasNode.count({ i, j })) {
                    continue;
                }
                auto varElement = sstd_new<RectNode>(i, j);
                mmmHasNode.emplace(std::pair<int, int>{ i, j }, varElement);
                this->appendChildNode(varElement);
            }
        }


    }

    inline Node::Node(
        const QPointF & a,
        const QPointF & b,
        const QPointF & c,
        const QPointF & d) {
        this->updateAll(a, b, c, d);
        this->setFlag(QSGNode::OwnedByParent);
    }

}/*this_file*/


BigScene::BigScene() {
    this->setFlag(QQuickItem::ItemHasContents, true);
    using namespace this_file;
    this->setWidth(globalSceneWidth);
    this->setHeight(globalSceneHeight);
}

QSGNode * BigScene::updatePaintNode(
    QSGNode *oldNode,
    QQuickItem::UpdatePaintNodeData *) {

    auto varWindow = this->window();
    if (varWindow == nullptr) {
        return nullptr;
    }

    this_file::Node * varNode = static_cast<this_file::Node*>(oldNode);

    QRectF varWindowScene{
           mmmVisibleXPos , mmmVisibleYPos ,
           mmmVisibleWidth ,mmmVisibleHeight };

    if (varNode == nullptr) {
        return sstd_new<this_file::Node>(
            varWindowScene.topLeft(),
            varWindowScene.topRight(),
            varWindowScene.bottomRight(),
            varWindowScene.bottomLeft());

    } else {
        varNode->updateAll(
            varWindowScene.topLeft(),
            varWindowScene.topRight(),
            varWindowScene.bottomRight(),
            varWindowScene.bottomLeft());
    }
    return varNode;
}

qreal BigScene::getVisibleXPosition() const {
    return mmmVisibleXPos;
}

qreal BigScene::getVisibleYPosition() const {
    return mmmVisibleYPos;
}

qreal BigScene::getVisibleWidth()const {
    return mmmVisibleWidth;
}

qreal BigScene::getVisibleHeight()const {
    return mmmVisibleHeight;
}

void BigScene::setVisibleXPosition(qreal v) {
    if (std::isnan(v) || std::isinf(v)) {
        return;
    }
    if (v == mmmVisibleXPos) {
        return;
    }
    mmmVisibleXPos = v;
    visibleXPositionChanged();
    this->update();
}

void BigScene::setVisibleYPosition(qreal v) {
    if (std::isnan(v) || std::isinf(v)) {
        return;
    }
    if (v == mmmVisibleYPos) {
        return;
    }
    mmmVisibleYPos = v;
    visibleYPositionChanged();
    this->update();
}

void BigScene::setVisibleWidth(qreal v) {
    if (std::isnan(v) || std::isinf(v)) {
        return;
    }
    if (v == mmmVisibleWidth) {
        return;
    }
    mmmVisibleWidth = v;
    visibleWidthChanged();
    this->update();
}

void BigScene::setVisibleHeight(qreal v) {
    if (std::isnan(v) || std::isinf(v)) {
        return;
    }
    if (v == mmmVisibleHeight) {
        return;
    }
    mmmVisibleHeight = v;
    visibleHeightChanged();
    this->update();
}

static inline void register_this() {
    qmlRegisterType<BigScene>(
        "sstd.bigscene",
        1, 0,
        "BigScene");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
