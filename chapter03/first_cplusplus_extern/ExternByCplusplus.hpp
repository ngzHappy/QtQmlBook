#pragma once

#include <sstd_qt_and_qml_library.hpp>

class ExternByCplusplus :
    public QObject,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ExternByCplusplus) {
    Q_OBJECT
private:
    Q_PROPERTY(QString data READ getData WRITE setData NOTIFY dataChanged)
public:
    ExternByCplusplus();
    virtual ~ExternByCplusplus() override;
public:
    QString getData() const ;
    void setData(const QString &);
    Q_SIGNAL void dataChanged();
private:
    QString mmmData;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ExternByCplusplus);
};




