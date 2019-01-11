#include "GlobalObject.hpp"

inline static const auto & getStartTime() {
    const static auto varAns
        = std::chrono::steady_clock::now();
    return varAns;
}

std::int64_t GlobalObject::getTimeSinceProgramStart() const {
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
    static auto varAns = sstd_new<GlobalObject>();
    return varAns;
}










