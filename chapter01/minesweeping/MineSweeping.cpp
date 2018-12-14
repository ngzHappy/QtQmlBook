#include "MineSweeping.hpp"
#include "MineSweepingLineNode.hpp"

namespace this_file {

    class Node :
        public QSGNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Node) {
    public:

        inline Node() {
            this->setFlag(QSGNode::OwnedByParent);
        }

        inline void update_data() {

            auto varLine = sstd_new< MineSweepingLineNode >();
            varLine->setBeginEndPoints({ 0,0 }, { 512,512 });
            varLine->setLineWidth(10);
            varLine->setLineColor(QColor(255,0,0,255));
            this->appendChildNode(varLine);
        }

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
        varNode = sstd_new<Node>();
    } else {
        varNode = static_cast<Node*>(oldNode);
    }

    varNode->update_data();

    return varNode;

}

MineSweeping::MineSweeping() {
    this->setFlag(QQuickItem::ItemHasContents, true);
    this->setWidth(512);
    this->setHeight(512);
}

static inline void register_this() {
    qmlRegisterType<MineSweeping>(
        "sstd.minesweeping",
        1, 0,
        "MineSweeping");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)












