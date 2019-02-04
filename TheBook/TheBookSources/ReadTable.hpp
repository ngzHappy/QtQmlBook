#pragma once

#include <memory>
#include "the_book_global.hpp"

class ReadTablePrivate;
class ReadTable {
public:
    ReadTable();
    ~ReadTable();
public:
    const QString & getTableDirName();
    void setTableDirName(const QString &);
    bool open();
    QString readHead() const;
    QString readBody() const;
    QString readHeadControl() const;
private:
    ReadTablePrivate * const thisp;
};
