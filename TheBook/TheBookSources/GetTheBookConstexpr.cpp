#include "GetTheBookConstexpr.hpp"

inline static GetTheBookConstexpr::data_type _get_data() {
    GetTheBookConstexpr::data_type varAns =
        std::make_shared<GetTheBookConstexpr::data_type::element_type>();

    QFile varFile{ getOutPutFileFullPath(
        qsl("TheBookSources/the_book_constexpr.txt")) };
    if (false == varFile.open(QIODevice::ReadOnly)) {
        the_book_throw("can not open the file"sv);
    }
    QTextStream varStream{ &varFile };

    while (false == varStream.atEnd()) {
        auto const varLine =
            varStream.readLine().trimmed();

        if (varLine.isEmpty()) {
            continue;
        }

        if (varLine.startsWith(QChar('%'))) {
            continue;
        }

        auto varParts = varLine.split(qsl("::::"));
        if (varParts.size() < 1) {
            continue;
        }

        auto varKey = varParts[0];
        std::vector<QString> varValues{ ++varParts.cbegin(),varParts.cend() };
        varAns->emplace(std::move(varKey), std::move(varValues));
    }

    return std::move(varAns);
}

inline static GetTheBookConstexpr::data_type get_data() {
    const static auto varAns = _get_data();
    return varAns;
}

GetTheBookConstexpr::GetTheBookConstexpr() {
    this->data = get_data();
}

std::vector<QString> GetTheBookConstexpr::getValues(const QString & arg) const {
    auto varPos = data->find(arg.trimmed());
    if (varPos == data->cend()) {
        return{};
    }
    return varPos->second;
}








