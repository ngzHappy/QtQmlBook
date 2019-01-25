#pragma once

#include <memory>
#include "the_book_global.hpp"

class ReadTablePrivate;
class ReadTable{
public:
    ReadTable();
public:
    const QString & getTableDirName();
    void setTableDirName(const QString &);
private:
    ReadTablePrivate * const thisp;
};


















