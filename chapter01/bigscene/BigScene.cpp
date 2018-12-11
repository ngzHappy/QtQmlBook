#include "BigScene.hpp"

namespace this_file {

    inline constexpr const static qreal globalRectWidth = 64;
    inline constexpr const static qreal globalRectHeight = 64;
    inline constexpr const static int globalNumberRect = 100 ;
    inline constexpr const static qreal globalSceneWidth = globalNumberRect * globalRectWidth;
    inline constexpr const static qreal globalSceneHeight = globalNumberRect * globalRectHeight;

    class Node :
        public QSGNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Node) {
    public:
        inline Node(const QPointF &, const QPointF &, const QPointF &, const QPointF &);
        void updateAll(const QPointF &, const QPointF &, const QPointF &, const QPointF &);
        SSTD_END_DEFINE_VIRTUAL_CLASS(Node);
    };

    inline static int randomColor(int varK) {
        switch (varK & 3) {
        case 0:return (std::rand() & 127);
        case 1:return (std::rand() & 63);
        case 2:return (std::rand() & 255);
        }
    }

    class RectNode : public QSGSimpleRectNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(RectNode){
    public:
        RectNode(int nw, int nh) {
            this->setRect(
                nw * globalRectWidth,
                nh * globalRectHeight,
                globalRectWidth,
                globalRectHeight);
            this->setColor({ randomColor(nw), randomColor(nh), 200 , 255 });
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(RectNode);
    };

    void  Node::updateAll(
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
        std::remquo(varMinY, this_file::globalRectHeight, &varMinYN);
        std::remquo(varMaxY, this_file::globalRectHeight, &varMaxYN);
        std::remquo(varMinX, this_file::globalRectWidth, &varMinXN);
        std::remquo(varMaxX, this_file::globalRectWidth, &varMaxXN);

        for (int i = varMinXN-1; i <= varMaxXN; ++i) {
            for (int j = varMinYN-1 ; j <= varMaxYN; ++j) {
                this->appendChildNode(sstd_new<RectNode>(i, j));
            }
        }


    }

    inline Node::Node(
        const QPointF & a,
        const QPointF & b,
        const QPointF & c,
        const QPointF & d) {
        this->updateAll(a,b,c,d);
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

    if (varNode == nullptr) {
        QRectF varWindowScene{ {0,0}, varWindow->size() };
        return sstd_new<this_file::Node>(
            this->mapFromScene(varWindowScene.topLeft()),
            this->mapFromScene(varWindowScene.topRight()),
            this->mapFromScene(varWindowScene.bottomRight()),
            this->mapFromScene(varWindowScene.bottomLeft()));
    } else {
        varNode->removeAllChildNodes();
        QRectF varWindowScene{ {0,0}, varWindow->size() };
        varNode->updateAll(
            this->mapFromScene(varWindowScene.topLeft()),
            this->mapFromScene(varWindowScene.topRight()),
            this->mapFromScene(varWindowScene.bottomRight()),
            this->mapFromScene(varWindowScene.bottomLeft()));
    }
    return varNode;
}

static inline void register_this() {
    qmlRegisterType<BigScene>(
        "sstd.bigscene",
        1, 0,
        "BigScene");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)




