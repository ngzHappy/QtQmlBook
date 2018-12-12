#include "BigScene2DViewer.hpp"

namespace this_file {

    inline constexpr const static qreal globalRectWidth = 64;
    inline constexpr const static qreal globalRectHeight = 64;
    inline constexpr const static int globalNumberRect = 1024 * 1024;
    inline constexpr const static qreal globalSceneWidth = globalNumberRect * globalRectWidth;
    inline constexpr const static qreal globalSceneHeight = globalNumberRect * globalRectHeight;
    std::atomic< std::intmax_t > globalCount{ 0 };

    inline static int randomColor(int varK) {
        switch (varK & 3) {
        case 0:return (std::rand() & 127);
        case 1:return (std::rand() & 63);
        case 2:return (std::rand() & 255);
        }
        return (std::rand() & 63);
    }

    class RectNode : public sstd::SimpleRectangleNode,
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

            qDebug() << __func__ << ++globalCount;

        }

        virtual ~RectNode() {

            qDebug() << __func__ << --globalCount;

        }

    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(RectNode);
    };

    class Node :
        public QSGTransformNode,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Node) {
    public:
        inline Node();
        inline void update(const QMatrix &, const std::array<QPointF, 4> &);
        inline void addNode(int, int);
        inline void removeNode(RectNode *);
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Node);
    };

    inline Node::Node() {
        addNode(0, 0);
    }

    void Node::update(const QMatrix & varMatrix, const std::array<QPointF, 4> &) {
        this->setMatrix(varMatrix);
    }

    inline void Node::addNode(int argX, int argY) {
        auto t = sstd_new< RectNode >(argX, argY);
        t->setRect({ 0,0,100,100 });
        this->appendChildNode(t);
    }

    inline void Node::removeNode(RectNode *) {

    }

}/****/

void BigScene2DViewer::pppSetControlComponent(QQmlComponent * varComponent) {
    assert(varComponent);
    assert(this->mmmControl == nullptr);
    assert(this->mmmControlObject == nullptr);
    if (this->mmmControl == varComponent) {
        return;
    }
    this->mmmControl = varComponent;

    {
        auto varContex = QQmlEngine::contextForObject(this);
        mmmControlObject = sstd_runtime_cast<QQuickItem>(
            mmmControl->beginCreate(varContex));
        assert(mmmControlObject);
        mmmControlObject->setParent(this);
        mmmControlObject->setParentItem(this);
        mmmControl->completeCreate();
    }

    connect(mmmControlObject, &QQuickItem::xChanged,
        this, [this]() { pppRawSetCenterX(); });
    connect(mmmControlObject, &QQuickItem::yChanged,
        this, [this]() { pppRawSetCenterY(); });
    connect(mmmControlObject, &QQuickItem::widthChanged,
        this, [this]() { pppRawSetCenterX(); });
    connect(mmmControlObject, &QQuickItem::heightChanged,
        this, [this]() { pppRawSetCenterY(); });

    pppRawSetCenterX();
    pppRawSetCenterY();

    this->pppControlComponentChanged();
}

void BigScene2DViewer::pppRawSetCenterX() {
    const auto varX = mmmControlObject->mapToItem(this,
        { 0,0 }).x();
    const auto var = std::fma(
        mmmControlObject->width(), 0.5, varX);
    this->pppSetCenterX(var);
}

void BigScene2DViewer::pppRawSetCenterY() {
    const auto varY = mmmControlObject->mapToItem(this,
        { 0,0 }).y();
    const auto var = std::fma(
        mmmControlObject->height(), 0.5, varY);
    this->pppSetCenterY(var);
}

void BigScene2DViewer::runCommand(QString arg) {
    arg = arg.trimmed().toLower();
    if (arg.startsWith('r')) {
        this->rotateByAngle(arg.rightRef(arg.size() - 1).toDouble());
    } else if (arg.startsWith('x')) {
        this->moveByX(arg.rightRef(arg.size() - 1).toDouble());
    } else if (arg.startsWith('s')) {
        this->scaleByXY(arg.rightRef(arg.size() - 1).toDouble());
    } else if (arg.startsWith('y')) {
        this->moveByY(arg.rightRef(arg.size() - 1).toDouble());
    } else if ( arg=='0' ) {
        this->resetThisMatrix();
    }
}

void BigScene2DViewer::pppUpdate() {

}

void BigScene2DViewer::pppSetCenterX(qreal v) {
    if (v == mmmCenterX) {
        return;
    }
    mmmCenterX = v;
    pppCenterXUpdate();
}

void BigScene2DViewer::pppSetCenterY(qreal v) {
    if (v == mmmCenterY) {
        return;
    }
    mmmCenterY = v;
    pppCenterYUpdate();
}

BigScene2DViewer::BigScene2DViewer() {
    this->setFlag(QQuickItem::ItemHasContents, true);
    using namespace this_file;
    this->setWidth(globalSceneWidth);
    this->setHeight(globalSceneHeight);
    mmmUpdateTimer = this->sstd_create_data_in_this_class<QTimer>();
    mmmUpdateTimer->setInterval(500ms);
    connect(mmmUpdateTimer, &QTimer::timeout, this, [this]() {
        this->pppUpdate();
    });
    mmmUpdateTimer->start();
}

BigScene2DViewer::~BigScene2DViewer() {
    mmmUpdateTimer->stop();
}

QSGNode * BigScene2DViewer::updatePaintNode(
    QSGNode *oldNode,
    UpdatePaintNodeData *) {

    using namespace this_file;
    Node * varNode = static_cast<Node *>(oldNode);

    if (varNode == nullptr) {
        varNode = sstd_new<Node>();
    }

    varNode->update(this->mmmThisMatrix, {});

    return varNode;

}

void  BigScene2DViewer::rotateByAngle(qreal) {
}

void BigScene2DViewer::moveByX(qreal x) {
    mmmThisMatrix = QMatrix{ 1,0,0,1,x,0 } * mmmThisMatrix;
    pppUpdateMatrix();
}

void BigScene2DViewer::moveByY(qreal y) {
    mmmThisMatrix = QMatrix{ 1,0,0,1,0,y } * mmmThisMatrix;
    pppUpdateMatrix();
}

void BigScene2DViewer::scaleByXY(qreal) {
}

void BigScene2DViewer::resetThisMatrix() {
    mmmThisMatrix = QMatrix{};
    pppUpdateMatrix();
}

void BigScene2DViewer::pppUpdateMatrix() {
    mmmThisInvMatrix = std::as_const(mmmThisMatrix).inverted();
    this->update();
}

static inline void register_this() {
    qmlRegisterType<BigScene2DViewer>(
        "sstd.bigscene2dviewer",
        1, 0,
        "BigScene2DViewer");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)













