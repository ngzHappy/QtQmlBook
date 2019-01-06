﻿#include "ReadSource.hpp"
#include "InputStream.hpp"
#include <optional>
#include <limits>

namespace this_file {

    class SourceLine {
    public:
        int lineNumber{ 0 }     /*行号*/;
        int lineLeftSpace{ 0 }  /*左侧空格*/;
        QString data            /*内容*/;
        inline operator const QString &() const {
            return data;
        }
        inline SourceLine(int a, int c, const QString &b) :
            lineNumber(a),
            lineLeftSpace(c),
            data(b) {
        }
    };

    class ReadSouce {
    public:
        QString fileName;
        std::list<SourceLine> lines;
        std::optional<QFile> file;
        std::optional<InputStream> stream;
        inline void readfile() {
            file.emplace(fileName);
            if (false == file->open(QIODevice::ReadOnly)) {
                return;
            }
            stream.emplace(&file.value());
            int varLineNumber = 0;
            int varMinLeftSpace = std::numeric_limits<int>::max();
            while (false == stream->atEnd()) {
                const auto varLine = stream->readLine();
                int varSpaceLeftOfThisLine = 0;
                for (const auto & varC : varLine) {
                    if (varC.isSpace()) {
                        ++varSpaceLeftOfThisLine;
                    } else {
                        break;
                    }
                }
                varMinLeftSpace =
                    std::min(varMinLeftSpace, varSpaceLeftOfThisLine);
                lines.emplace_back(
                    ++varLineNumber,
                    varSpaceLeftOfThisLine,
                    varLine.trimmed());
            }
            /*调整左侧空格*/
            for (auto & varI : lines) {
                if (varI.data.isEmpty()) {
                    continue;
                }
                const auto varLeftSpaceSize =
                    varI.lineLeftSpace - varMinLeftSpace;
                assert(varLeftSpaceSize >= 0);
                assert(varLeftSpaceSize < 65536);
                varI.data = QString(varLeftSpaceSize, QChar(' '))
                    + varI.data;
            }
            /*删除头空行*/
            while (false == lines.empty()) {
                if (lines.cbegin()->data.isEmpty()) {
                    lines.pop_front();
                } else {
                    break;
                }
            }
            /*删除尾空行*/
            while(false ==lines.empty()){
                if (lines.crbegin()->data.isEmpty()) {
                    lines.pop_back();
                } else {
                    break;
                }
            }
        }

        inline std::vector<QString> read() {
            readfile();
            return { lines.cbegin(),lines.cend() };
        }

    };

}/******/

extern std::vector<QString> readFileSource(const QString & arg) {
    auto varReader =
        std::make_unique<this_file::ReadSouce>();
    varReader->fileName = arg;
    return varReader->read();
}



















