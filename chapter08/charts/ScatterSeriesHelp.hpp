#pragma once

#include <sstd_qt_and_qml_library.hpp>
#include <QtCharts/QtCharts>
#include <limits>

class ScatterSeriesHelp :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ScatterSeriesHelp) {
    Q_OBJECT
private:
    Q_PROPERTY(int flag READ getFlag WRITE setFlag NOTIFY flagChanged)
public:
    ScatterSeriesHelp(QScatterSeries * arg=nullptr);
public:
    static ScatterSeriesHelp *qmlAttachedProperties(QObject *object);
public:
    int getFlag() const ;
    void setFlag(int);
    Q_SIGNAL void flagChanged();
private:
    QScatterSeries * const super;
    int mmmFlag{ std::numeric_limits<int>::max() };
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ScatterSeriesHelp);
};

QML_DECLARE_TYPEINFO(ScatterSeriesHelp, QML_HAS_ATTACHED_PROPERTIES)
