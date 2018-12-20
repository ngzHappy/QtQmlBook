#pragma once

#include <sstd_qt_and_qml_library.hpp>

class LocalQmlWindowCreator :
        public QObject  , 
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(LocalQmlWindowCreator)  {
    Q_OBJECT
public:
    LocalQmlWindowCreator();
    static LocalQmlWindowCreator * instance();
    Q_SLOT QObject * createRootView(const QString & argName, const QUrl & argLocalPath) const;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(LocalQmlWindowCreator);
};















