#include "ListModel.hpp"

ListModel::ListModel(QObject *parent) : Super(parent) {
    {
        const constexpr auto varTestSize
            = 1024 * 1024;
        mmmData.reserve(varTestSize);
        for (int i = 0; i < varTestSize; ++i) {
            auto & varItem = mmmData.emplace_back();
            varItem.rawString =
                QString::number(i);
        }
    }
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

QModelIndex ListModel::parent(const QModelIndex &) const {
    return {};
}

int ListModel::rowCount(const QModelIndex &parent) const {
    if (!parent.isValid()) {
        return static_cast<int>(mmmData.size());
    }
    return 0;
}

int ListModel::columnCount(const QModelIndex &parent) const {
    if (!parent.isValid()) {
        return 1;
    }
    return 0;
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
        (index.row() < static_cast<int>(mmmData.size())) &&
        (data(index, role) != value)) {
        const bool varAns = mmmData[index.row()].setData(role, value);
        emit dataChanged(index, index, QVector<int>() << role);
        return varAns;
    }
    return false;
}

Qt::ItemFlags ListModel::flags(const QModelIndex &) const {
    return Qt::ItemIsEditable;
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

void ListModel::remove(const int & arg) {
    if (arg < 0) {
        return;
    }
    this->removeRows(arg, 1, {});
}

void ListModel::insert(const int & arg) {
    if (arg < 0) {
        return;
    }
    this->insertRows(arg, 1, {});
}

bool ListModel::_insertRows(int row, int count, const QModelIndex &) try {
    if ((row < static_cast<int>(mmmData.size())) && (count > 0)) {
        for (int i = 0; i < count; ++i) {
            auto varBegin = mmmData.cbegin() + row;
            auto varPos = mmmData.insert(varBegin, Item{});
            varPos->rawString = QStringLiteral("X");
        }
        return true;
    } else if (mmmData.empty() && (count > 0)) {
        mmmData.resize(static_cast<std::size_t>(count));
        for (auto & varI : mmmData) {
            varI.rawString = QStringLiteral("X");
        }
        return true;
    }
    return false;
} catch (...) {
    return false;
}

bool ListModel::_removeRows(int row, int count, const QModelIndex &)try {
    if ((row < static_cast<int>(mmmData.size())) && (count > 0)) {
        auto varBegin = mmmData.cbegin() + row;
        auto varEnd = varBegin + count;
        mmmData.erase(varBegin, varEnd);
        return true;
    }
    return false;
} catch (...) {
    return false;
}

bool ListModel::_insertColumns(int, int, const QModelIndex &)try {
    return true;
} catch (...) {
    return false;
}

bool ListModel::_removeColumns(int, int, const QModelIndex &)try {
    return true;
} catch (...) {
    return false;
}

QHash<int, QByteArray> ListModel::roleNames() const {
    return Item::roleNames();
}

static inline void register_this() {
    qmlRegisterType<ListModel>(
        "sstd.model",
        1, 0,
        "ListModel");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)
