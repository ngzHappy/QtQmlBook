#include "the_book_global.hpp"
#include <vector>
#include <list>

/*为每个可编译txt文件末尾增加关键字帮助，转为UTF-8 With Bom，并删除多余末尾空行*/
extern bool updateKeywords(const QString & argFullPath) {

    std::vector< QString > varAllLines;
    auto varCurrentDeletePos = varAllLines.cend();

    {
        QFile varFile{ argFullPath };
        if (!varFile.open(QIODevice::ReadOnly)) {
            return false;
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

    do {/*删除行位空行...*/
        if (varAllLines.empty()) {
            break;
        }
        auto varPos = std::make_reverse_iterator(varCurrentDeletePos);
        auto varEnd = varAllLines.crend();
        varCurrentDeletePos = varAllLines.cbegin();
        for (; varPos != varEnd; ++varPos) {
            if (!varPos->trimmed().isEmpty()) {
                varCurrentDeletePos = varPos.base();
                break;
            }
        }
    } while (false);

    {
        QFile varFile{ argFullPath };
        if (!varFile.open(QIODevice::WriteOnly)) {
            return false;
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
% FloatBarrier
]]

)!");

    }

    return true;

}
