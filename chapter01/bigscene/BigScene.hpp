
#include <sstd_qt_and_qml_library.hpp>

class BigScene :
    public QQuickItem , 
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(BigScene) {
    Q_OBJECT
private:
    using Super = sstd::DirectDrawImage;
public:
    BigScene();
protected:
    QSGNode * updatePaintNode(QSGNode *oldNode, QQuickItem::UpdatePaintNodeData *) override;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(BigScene);
};








