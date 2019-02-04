#include "CreateMakeFile.hpp"
#include "OutPutStream.hpp"
#include <list>
#include <vector>

namespace this_file {

    class CreateMakeFileState {
    public:

        class Duty {
        public:
            QString filePath;
        };

        class Ans {
        public:
            QFileInfo data;

            inline Ans(QFileInfo v)
                :data(std::move(v)) {
            }

        };

        using DutysType = std::list< std::shared_ptr< Duty > >;
        DutysType dutys;
        std::list< Ans > ans;

        inline static std::shared_ptr<Duty> createADuty(const QString & arg) {
            auto varAns = std::make_shared<Duty>();
            {
                const auto varOutPutDir = getOutPutFileDir();
                const auto varRootPath =
                    varOutPutDir.absoluteFilePath(arg);
                varAns->filePath = varRootPath;
            }
            return std::move(varAns);
        }

    };
}/*namespace this_fiel*/

class CreateMakeFilePrivate {
public:

    std::shared_ptr< const CreateMakeFileConstruct > args;

    inline CreateMakeFilePrivate(std::shared_ptr< const CreateMakeFileConstruct > && v) :
        args(std::move(v)) {
    }

    inline bool createMakeFile(this_file::CreateMakeFileState * arg) {
        {
            arg->dutys.push_front(
                this_file::CreateMakeFileState::createADuty(args->rootFileName));
        }

        while (arg->dutys.empty() == false) {
            auto varDuty = std::move(arg->dutys.front());
            arg->dutys.pop_front();

            QFileInfo varInfo{ varDuty->filePath };
            {
                if (varInfo.exists() == false) {/*忽略不存在的file...*/
                    continue;
                }
                if (varInfo.isFile() == false) {/*忽略文件夹...*/
                    continue;
                }
                if (!(varInfo.suffix().toLower() == QStringLiteral("txt"))) {/*只编译txt...*/
                    continue;
                }
                arg->ans.emplace_back(std::move(varInfo));
            }

            QFile varReadFile{ varInfo.absoluteFilePath() };
            if (false == varReadFile.open(QIODevice::ReadOnly)) {
                continue;
            }

            this_file::CreateMakeFileState::DutysType varThisFileDutys;

            {/*寻找符合\input{???} 的语句*/
                InputStream varStream{ &varReadFile };
                const static QRegularExpression varR_{ QStringLiteral(
                    R"(^(?::tex_raw:\[[=]*\[)?\s*\\input\s*\{([^}]+)\}.*)") };
                const auto & varR = varR_;

                while (false == varStream.atEnd()) {
                    const auto varLine =
                        varStream.readLine().trimmed();
                    if (varLine.size() < 6/*\input*/) {
                        continue;
                    }
                    const auto varMatched =
                        varR.match(varLine);
                    if (varMatched.hasMatch()) {
                        auto varFile = varMatched.captured(1);
                        if (varFile.endsWith(QStringLiteral(".tex"), Qt::CaseInsensitive)) {
                            varFile.chop(2);
                            varFile += QStringLiteral("xt");
                            varThisFileDutys.push_back(
                                this_file::CreateMakeFileState::createADuty(varFile)
                            );
                        }
                    }
                }
            }

            arg->dutys.splice(
                arg->dutys.cbegin(),
                std::move(varThisFileDutys));

        }

        QFile varFile{ getOutPutFileFullPath(
            QStringLiteral("MakeFile.txt"))
        };

        if (false == varFile.open(QIODevice::WriteOnly)) {
            return false;
        }

        OutPutFileStream varOutPut{ &varFile };

        for (const auto & varAns : arg->ans) {
            varOutPut <<
                getOutPutFileDir().relativeFilePath(
                    varAns.data.canonicalFilePath());
            varOutPut << endl;
        }

        return true;
    }

};

CreateMakeFile::CreateMakeFile(std::shared_ptr<const CreateMakeFileConstruct> arg)
    :thisp(std::make_shared<CreateMakeFilePrivate>(std::move(arg))) {

}

bool CreateMakeFile::createMakeFile() {

    if (!(thisp && (thisp->args) && (thisp->args->rootFileName.isEmpty() == false))) {
        return false;
    }

    auto varState = std::make_shared<this_file::CreateMakeFileState>();
    const auto varAns = thisp->createMakeFile(varState.get());
    return varAns;
}
