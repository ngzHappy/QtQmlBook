#include "ReadTable.hpp"
#include "TexBuilder.hpp"
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

    inline bool build_tex() {

        using T = std::pair<QString, QString>;
        const static std::array< T, 3 > varNames{
                T{qsl(R"(body.txt)"),qsl(R"(body.tex)")},
                T{qsl(R"(head.txt)"),qsl(R"(head.tex)")},
                T{qsl(R"(headcontrol.txt)"),qsl(R"(headcontrol.tex)")}
        };

        const QDir varDir(tableDirName);
        for (const auto & varI : varNames) {
            TexBuilder varBuilder;
            varBuilder.setInputFileName(
                varDir.absoluteFilePath(varI.first));
            varBuilder.setOutputFileName(
                varDir.absoluteFilePath(varI.second));
            if (!varBuilder.convert()) {
                return false;
            }
        }

        return true;

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
    if (!thisp->build_tex()) {
        return false;
    }
    const QDir varDir(getTableDirName());
    if (!thisp->bodyReader.open(
        varDir.absoluteFilePath(QStringLiteral(
            "body.tex")))) {
        return false;
    }
    if (!thisp->headReader.open(
        varDir.absoluteFilePath(QStringLiteral(
            "head.tex")))) {
        return false;
    }
    if (!thisp->headControlReader.open(
        varDir.absoluteFilePath(QStringLiteral(
            "headcontrol.tex")))) {
        return false;
    }
    return true;
}

static inline QString readAndTrimmed(QTextStream & arg) {
    std::list<QString> varAnsLines;

    while (false == arg.atEnd()) {
        varAnsLines.push_back(arg.readLine());
    }

    while (varAnsLines.empty() == false) {
        const auto varJudge =
            varAnsLines.front().trimmed();
        if (varJudge.isEmpty() ||
            (varJudge[0] == QChar('%'))) {
            varAnsLines.pop_front();
            continue;
        } else {
            break;
        }
    }

    while (varAnsLines.empty() == false) {
        const auto varJudge =
            varAnsLines.back().trimmed();
        if (varJudge.isEmpty() ||
            (varJudge[0] == QChar('%'))) {
            varAnsLines.pop_back();
            continue;
        } else {
            break;
        }
    }

    QString varAns;
    for (const auto & varI : varAnsLines) {
        varAns += varI;
        varAns += QChar('\n');
    }

    return varAns.trimmed();

}

QString ReadTable::readHead()const {
    if (!thisp->headReader.stream) {
        return {};
    }
    return
        readAndTrimmed(*thisp->headReader.stream);
}

QString ReadTable::readBody()const {
    if (!thisp->bodyReader.stream) {
        return{};
    }
    return
        readAndTrimmed(*thisp->bodyReader.stream);
}

QString ReadTable::readHeadControl() const {
    if (!thisp->headControlReader.stream) {
        return{};
    }
    return
        readAndTrimmed(*thisp->headControlReader.stream);
}
