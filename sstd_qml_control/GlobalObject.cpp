#include "GlobalObject.hpp"

inline static const auto & getStartTime() {
    const static auto varAns
        = std::chrono::steady_clock::now();
    return varAns;
}

qint64 GlobalObject::getTimeSinceProgramStart() const {
    const auto varCurrentTime
        = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<
        std::chrono::milliseconds>(
        (varCurrentTime - mmmStartTime)).count();
}

GlobalObject::GlobalObject() :
    mmmStartTime(getStartTime()) {
    QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
}

QObject * GlobalObject::instance(QQmlEngine *, QJSEngine *) {
    return instanceRaw();
}

GlobalObject * GlobalObject::instanceRaw(){
    static auto varAns = sstd_new<GlobalObject>();
    return varAns;
}








