#include "ListModel.hpp"

ListModel::ListModel(QObject *parent)
    : Super(parent) {
}

/*get head ... */
QVariant ListModel::headerData(
    int section,
    Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        if (section < static_cast<int>(mmmHead.size())) {
            return mmmHead[section];
        }
    }
    return {};
    (void)orientation;
}

/*set head ...*/
bool ListModel::setHeaderData(
    int section,
    Qt::Orientation orientation,
    const QVariant &value,
    int role) {
    if ((section < static_cast<int>(mmmHead.size())) &&
        (role == Qt::DisplayRole) &&
        (value != headerData(section, orientation, role))) {
        mmmHead[section] = value;
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}

QModelIndex ListModel::index(
    int row,
    int column,
    const QModelIndex &parent) const {
    if (row < static_cast<int>(mmmData.size())) {
        return this->createIndex(row, column);
    }
    return {};
    (void)parent;
}

QModelIndex ListModel::parent(const QModelIndex &index) const {
    return {};
}

int ListModel::rowCount(const QModelIndex &parent) const {
    if (!parent.isValid()) {
        return 0;
    }
    return static_cast<int>(mmmData.size());
}

int ListModel::columnCount(const QModelIndex &parent) const {
    if (!parent.isValid()) {
        return 0;
    }
    return 1;
}

QVariant ListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) {
        return {};
    }
    if (index.row() < static_cast<int>(mmmData.size())) {
        return mmmData[index.row()].getData(role);
    }
    return {};
}

bool ListModel::setData(
    const QModelIndex &index,
    const QVariant &value,
    int role) {
    if (
        (role == Qt::EditRole) &&
        (index.row() < static_cast<int>(mmmData.size())) &&
        (data(index, role) != value)) {
        const bool varAns = mmmData[index.row()].setData(role, value);
        emit dataChanged(index, index, QVector<int>() << role);
        return varAns;
    }
    return false;
}

Qt::ItemFlags ListModel::flags(const QModelIndex &index) const {
    if (!index.isValid()) {
        return Qt::NoItemFlags;
    }
    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool ListModel::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(parent, row, row + count - 1);
    const auto varAns = _insertRows(row, count, parent);
    endInsertRows();
    return varAns;
}

bool ListModel::insertColumns(int column, int count, const QModelIndex &parent) {
    beginInsertColumns(parent, column, column + count - 1);
    const auto varAns = _insertColumns(column, count, parent);
    endInsertColumns();
    return varAns;
}

bool ListModel::removeRows(int row, int count, const QModelIndex &parent) {
    beginRemoveRows(parent, row, row + count - 1);
    const auto varAns = _removeRows(row, count, parent);
    endRemoveRows();
    return varAns;
}

bool ListModel::removeColumns(int column, int count, const QModelIndex &parent) {
    beginRemoveColumns(parent, column, column + count - 1);
    const auto varAns = _removeColumns(column, count, parent);
    endRemoveColumns();
    return varAns;
}


bool ListModel::_insertRows(int row, int count, const QModelIndex &parent) try {
    return true;
} catch (...) {
    return false;
}

bool ListModel::_insertColumns(int column, int count, const QModelIndex &parent)try {
    return true;
} catch (...) {
    return false;
}

bool ListModel::_removeRows(int row, int count, const QModelIndex &parent)try {
    return true;
} catch (...) {
    return false;
}

bool ListModel::_removeColumns(int column, int count, const QModelIndex &parent)try {
    return true;
} catch (...) {
    return false;
}

QHash<int, QByteArray> ListModel::roleNames() const {
    return Item::roleNames();
}

