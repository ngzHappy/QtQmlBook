#include "ReadTable.hpp"
#include <optional>

class Reader {
public:
    std::optional< InputStream > stream;
    std::optional< QFile > file;
    inline bool open(const QString & arg) {
        file.emplace(arg);
        if (false == file->open(QIODevice::ReadOnly)) {
            return false;
        }
        stream.emplace(&(*file));
        return true;
    }
    inline Reader() {
    }
    inline ~Reader() {
        stream.reset();
        file.reset();
    }
};

class ReadTablePrivate {
public:
    QString tableDirName;
    Reader headReader;
    Reader bodyReader;
    Reader headControlReader;
    inline ReadTablePrivate() {
    }

    inline ~ReadTablePrivate() {
    }

};

ReadTable::ReadTable() :
    thisp(new ReadTablePrivate) {
}

ReadTable::~ReadTable() {
    delete thisp;
}

const QString & ReadTable::getTableDirName() {
    return thisp->tableDirName;
}

void ReadTable::setTableDirName(const QString & arg) {
    thisp->tableDirName = arg;
}

bool ReadTable::open() {
    if (getTableDirName().isEmpty()) {
        return false;
    }
    {
        QFileInfo varInfor{ getTableDirName() };
        if (!varInfor.exists()) {
            return false;
        }
        if (!varInfor.isDir()) {
            return false;
        }
    }
    const QDir varDir(getTableDirName());
    if (!thisp->bodyReader.open(
        varDir.absoluteFilePath(QStringLiteral(
            "body.txt")))) {
        return false;
    }
    if (!thisp->headReader.open(
        varDir.absoluteFilePath(QStringLiteral(
            "head.txt")))) {
        return false;
    } 
    if (!thisp->headControlReader.open(
        varDir.absoluteFilePath(QStringLiteral(
            "headcontrol.txt")))) {
        return false;
    }
    return true;
}

QString ReadTable::readHead()const {
    if (!thisp->headReader.stream) {
        return {};
    }
    return
        thisp->headReader.stream
        ->readAll().trimmed();
}

QString ReadTable::readBody()const {
    if (!thisp->bodyReader.stream) {
        return{};
    }
    return
        thisp->bodyReader.stream
        ->readAll().trimmed();
}

QString ReadTable::readHeadControl() const {
    if (!thisp->headControlReader.stream) {
        return{};
    }
    return
        thisp->headControlReader.stream
        ->readAll().trimmed();
}



