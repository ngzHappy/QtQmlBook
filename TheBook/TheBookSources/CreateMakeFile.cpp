#include "CreateMakeFile.hpp"
#include <list>

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
                this_file::CreateMakeFileState::createADuty( args->rootFileName ));
        }

        while (arg->dutys.empty() == false) {
            auto varDuty = std::move(arg->dutys.front());
            arg->dutys.pop_front();

            QFileInfo varInfo{ varDuty->filePath };
            {
                if (varInfo.exists() == false) {
                    continue;
                }
                if (varInfo.isFile() == false) {
                    continue;
                }
                if (!(varInfo.suffix().toLower() == QStringLiteral("txt"))) {
                    arg->ans.emplace_back(std::move(varInfo));
                    continue;
                }
            }

            QFile varReadFile{ varInfo.absoluteFilePath() };
            if (false == varReadFile.open(QIODevice::ReadOnly)) {
                continue;
            }

            this_file::CreateMakeFileState::DutysType varThisFileDutys;

            {
                InputStream varStream{ &varReadFile };
                const static QRegularExpression varR_{ QStringLiteral(
                    R"(^\s*\\input\s*\{([^}]+)\}.*)") };
                const auto & varR = varR_;

                while (false == varStream.atEnd()) {
                    auto varLine =
                        varStream.readLine().trimmed();
                    auto varMatched =
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
    return thisp->createMakeFile(varState.get());

}


