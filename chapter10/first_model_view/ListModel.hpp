﻿#pragma once

#include <sstd_qt_and_qml_library.hpp>

class ListModel :
    public QAbstractItemModel,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ListModel) {
    Q_OBJECT
private:
    using Super = QAbstractItemModel;
public:
    explicit ListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role = Qt::EditRole) override;

    // Basic functionality:
    QModelIndex index(int row, int column,
        const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
        int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool insertColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int column, int count, const QModelIndex &parent = QModelIndex()) override;

    virtual QHash<int, QByteArray> roleNames() const override;
private:
    class Item {
    public:
        
        QString rawString;

        enum class RoleOfItem : int {
            RawString = Qt::UserRole + 1,
        };

        inline QVariant getData(int argRole) const {
            const auto role = static_cast<RoleOfItem>(argRole);
            switch (role) {
                case RoleOfItem::RawString : return rawString;
            }
            return {};
        }

        inline bool setData(int argRole,const QVariant & arg) {
            const auto role = static_cast<RoleOfItem>(argRole);
            switch (role) {
                case RoleOfItem::RawString : {
                    rawString = arg.toString();
                    return true;
                }
            }
            return false;
        }

        inline static QHash<int, QByteArray> roleNames() {
            const static auto varAns = _roleNames();
            return varAns;
        }

    private:
        inline static QHash<int, QByteArray> _roleNames() {
            QHash<int, QByteArray> varAns;
            varAns.insert( static_cast<int>(RoleOfItem::RawString), 
                QByteArrayLiteral("rawString") );
            return std::move(varAns);
        }
    };
    sstd::vector<Item> mmmData;
    class HeadItem {
    public:
        inline operator QVariant() const {
            return data;
        }
        QString data;
        inline HeadItem() = default;
        inline HeadItem(const HeadItem &) = default;
        inline HeadItem(HeadItem&&) = default;
        inline HeadItem&operator=(const HeadItem &) = default;
        inline HeadItem&operator=(HeadItem&&) = default;
        inline HeadItem&operator=( const QVariant & arg ) {
            data = arg.toString();
            return *this;
        }
    };
    sstd::vector<HeadItem> mmmHead;
private:
    bool _insertRows(int row, int count, const QModelIndex &parent  ) ;
    bool _insertColumns(int column, int count, const QModelIndex &parent  ) ;
    bool _removeRows(int row, int count, const QModelIndex &parent  ) ;
    bool _removeColumns(int column, int count, const QModelIndex &parent  ) ;
private:
    SSTD_END_DEFINE_VIRTUAL_CLASS(ListModel);
};


