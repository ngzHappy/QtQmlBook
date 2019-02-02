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

    inline void updateKeywords(this_file::CreateMakeFileState * arg) {
        for (const auto & varAns : arg->ans) {

            std::vector< QString > varAllLines;
            using cit =
                std::vector< QString >::const_iterator;
            cit varCurrentDeletePos = varAllLines.cend();

            {
                QFile varFile{ varAns.data.absoluteFilePath() };
                if (!varFile.open(QIODevice::ReadOnly)) {
                    continue;
                }
                InputStream varReadStream{ &varFile };
                while (!varReadStream.atEnd()) {
                    varAllLines.push_back(varReadStream.readLine());
                }
            }

            {
                /*从后向前搜索______all_key_words*/
                bool varNeedUpdateHelp = false;
                auto varPos = varAllLines.crbegin();
                const auto varEnd = varAllLines.crend();
                for (; varPos != varEnd; ++varPos) {
                    if (varPos->trimmed() == QStringLiteral(R"(% ______all_key_words)")) {
                        auto varNextPos = varPos + 1;
                        if (varNextPos == varEnd) {
                            break;
                        } else {
                            if (varNextPos->trimmed() == QStringLiteral(R"(:tex_raw:[[)")) {
                                varNeedUpdateHelp = true;
                                varCurrentDeletePos = varNextPos.base() - 1;
                                break;
                            }
                        }
                    }
                }
                if (false == varNeedUpdateHelp) {
                    varCurrentDeletePos = varAllLines.cend();
                }
            }

            do {/*更新非空项目...*/
                if (varAllLines.empty()) {
                    break;
                }
                auto varPos = std::make_reverse_iterator( varCurrentDeletePos );
                auto varEnd = varAllLines.crend();
                for (;varPos!=varEnd;++varPos) {
                    if (!varPos->trimmed().isEmpty()) {
                        varCurrentDeletePos = varPos.base();
                        break;
                    }
                }
            } while (false);

            {
                QFile varFile{ varAns.data.absoluteFilePath() };
                if (!varFile.open(QIODevice::WriteOnly)) {
                    continue;
                }
                QTextStream varWriteStream{ &varFile };
                varWriteStream.setCodec(QTextCodec::codecForName("UTF-8"));
                varWriteStream.setGenerateByteOrderMark(true);
                auto varPos = varAllLines.cbegin();
                for (; varPos != varCurrentDeletePos; ++varPos) {
                    varWriteStream << *varPos << endl;
                }

                varWriteStream << QStringLiteral(R"!(
:tex_raw:[[
% ______all_key_words
% the_book_chapter the_book_subsection the_book_subsubsection
% the_book_section the_book_image the_book_table
% the_book_file the_book_tree_file the_book_command_file
% littlelongworld tabbing ref
% figurename tablename filesourcenumbernameone
% treeindexnumbernameone commandnumbernameone footnote 
% item itemize comment textbullet
% \hspace*{\parindent}
]]

)!");

            }


        }
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
    auto varAns = thisp->createMakeFile(varState.get());
    thisp->updateKeywords(varState.get());
    return varAns;
}


