#include "MyValueCreator.hpp"

MyValueCreator::MyValueCreator(){
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

QVariant MyValueCreator::create(double x,double y){
    return QVariant::fromValue<MyValue>({x,y});
}

QObject * MyValueCreator::instance(QQmlEngine *, QJSEngine *){
    static auto varAns = sstd_new<MyValueCreator>();
    return varAns;
}

static inline void register_this() {
    qmlRegisterSingletonType<MyValueCreator>(
        "example.myvalue",
         1,0,
        "MyValueCreator",
        &MyValueCreator::instance);
}
Q_COREAPP_STARTUP_FUNCTION(register_this)

