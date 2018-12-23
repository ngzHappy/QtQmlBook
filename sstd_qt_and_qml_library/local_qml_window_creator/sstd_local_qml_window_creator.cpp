#include "sstd_local_qml_window_creator.hpp"
#include "../root_window/sstd_root_window.hpp"

namespace {
    class CloseEventFilter :
        public QObject,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(CloseEventFilter) {
        sstd::DefaultRoowWindow * mmmParent ;
    public:
        inline CloseEventFilter(sstd::DefaultRoowWindow * arg) :
            QObject(arg),
            mmmParent(arg) {
            arg->installEventFilter(this);
        }
        inline bool eventFilter(QObject *obj, QEvent *event) override {
            if (obj == mmmParent) {
                if (event->type() == QEvent::Close) {
                    obj->removeEventFilter(this);
                    obj->deleteLater();
                    mmmParent = nullptr;
                }
            }
            return QObject::eventFilter(obj, event);
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(CloseEventFilter);
    };
}/*********/

_1_sstd_local_qml_window_creator::_1_sstd_local_qml_window_creator(){

}

_1_sstd_local_qml_window_creator * _1_sstd_local_qml_window_creator::instance(){
    auto static varAns = sstd_make_unique<_1_sstd_local_qml_window_creator>();
    return varAns.get();
}

QObject * _1_sstd_local_qml_window_creator::createRootView(
        const QString & argName,
        const QUrl & argLocalPath) const{
    auto varAns = sstd_new< sstd::DefaultRoowWindow >();
    varAns->load(argLocalPath);
    varAns->setTitle(argName);
    sstd_new<CloseEventFilter>(varAns);
    return varAns;
}


static inline void registerThis() {
    qmlRegisterSingletonType<_1_sstd_local_qml_window_creator>("sstd.quick",
        1, 0,
        "LocalQmlWindowCreator",
        [](QQmlEngine *engine, QJSEngine *scriptEngine)->QObject * {
        auto varAns = _1_sstd_local_qml_window_creator::instance();
        return varAns;
        (void)engine;
        (void)scriptEngine;
    });
}
Q_COREAPP_STARTUP_FUNCTION(registerThis)



