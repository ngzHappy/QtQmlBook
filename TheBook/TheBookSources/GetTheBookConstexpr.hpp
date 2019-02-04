#pragma once

#include "the_book_global.hpp"
#include <map>
#include <memory>


class GetTheBookConstexpr {
public:
    using data_type = std::shared_ptr<
        std::map< QString, std::vector<QString> > >;
private:
    data_type data;
public:
    GetTheBookConstexpr();
public:
    std::vector<QString> getValues(const QString &) const;
};
