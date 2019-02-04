#include "GetTheBookConstexpr.hpp"

class LastReturn {
public:
    GetTheBookConstexpr::data_type data;
    QDateTime lastModified;
};

inline static GetTheBookConstexpr::data_type _get_data() {

    const static auto varFileName =
        getOutPutFileFullPath(
            qsl("TheBookSources/the_book_constexpr.txt"));

    thread_local LastReturn varLastReturn;

    do {
        /*如果文件被修改则更新值...*/
        QFileInfo varFileInfo{ varFileName };
        if (varFileInfo.exists() == false) {
            the_book_throw("can not find the file"sv);
        }

        if (!varLastReturn.data) {
            break;
        }

        if (varLastReturn.lastModified == varFileInfo.lastModified()) {
            return varLastReturn.data;
        } else {
            varLastReturn.lastModified = varFileInfo.lastModified();
        }

    } while (false);

    QFile varFile{ varFileName };
    if (false == varFile.open(QIODevice::ReadOnly)) {
        the_book_throw("can not open the file"sv);
    }
    InputStream varStream{ &varFile };

    GetTheBookConstexpr::data_type varAns =
        std::make_shared<GetTheBookConstexpr::data_type::element_type>();

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

    varLastReturn.data = varAns;

    return std::move(varAns);
}

inline static GetTheBookConstexpr::data_type get_data() {
    const auto varAns = _get_data();
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
