#include "ColorModel.hpp"

namespace this_file {
    constexpr const static inline int globalModelSize = 10 * 1024 * 1024;
    constexpr const static inline int globalTextRole = Qt::ItemDataRole::UserRole + 2;
    constexpr const static inline int globalColorRole = Qt::ItemDataRole::UserRole + 1;
    inline static QHash<int, QByteArray> roleNames() {
        QHash<int, QByteArray> varAns;
        {
            varAns.insert(globalColorRole, "color_role_");
        }
        {
            varAns.insert(globalTextRole, "text_role_");
        }
        return std::move(varAns);
    }

}/**/

ColorModel::ColorModel() {

}

int ColorModel::rowCount(const QModelIndex &) const {
    return this_file::globalModelSize;
}

QVariant ColorModel::data(const QModelIndex & varIndex, int role) const {
    if (!varIndex.isValid()) {
        return {};
    }

    auto varRow = varIndex.row();
    if (varRow < this_file::globalModelSize) {
        if (role == this_file::globalTextRole) {
            return QString::number(varRow);
        } else if (role == this_file::globalColorRole) {
            const auto varKey = varRow % 3;
            switch (varKey) {
            case 0:return QColor(255, (std::rand() & 127), (std::rand() & 127), 255);
            case 1:return QColor((std::rand() & 127), 255, (std::rand() & 127), 255);
            case 2:return QColor((std::rand() & 127), (std::rand() & 127), 255, 255);
            }
        }
    }

    return {};
}

QHash<int, QByteArray> ColorModel::roleNames() const {
    const static auto varAns = this_file::roleNames();
    return varAns;
}

static inline void register_this() {
    qmlRegisterType<ColorModel>(
        "sstd.color.model",
        1, 0,
        "ColorModel");
}
Q_COREAPP_STARTUP_FUNCTION(register_this)






