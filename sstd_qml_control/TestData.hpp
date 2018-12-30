#pragma once

#include "sstd_qml_control_global.hpp"

class EXPORT_SSTD_QML_CONTROL TestData :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(TestData) {
    Q_OBJECT
private:
    Q_PROPERTY(QString data READ getData WRITE setData NOTIFY dataChanged)
public:
    TestData();
public:
    QString getData() const;
    void setData(const QString &);
    Q_SIGNAL void dataChanged();
private:
    QString mmmData;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(TestData);
};







