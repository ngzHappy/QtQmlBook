#pragma once

#include <sstd_qt_and_qml_library.hpp>

class ColorModel :
    public QAbstractListModel,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ColorModel){
    Q_OBJECT
public:
    ColorModel();
public:
    int rowCount(const QModelIndex &) const override;
    QVariant data(const QModelIndex &, int) const override;
    QHash<int, QByteArray> roleNames() const override;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ColorModel);
};








