#include "TexBuilder.hpp"
#include "OutPutStream.hpp"
#include "ReadSource.hpp"
#include "GetTheBookConstexpr.hpp"
#include "ImageConvert.hpp"
#include "ReadTable.hpp"
#include <optional>
#include <list>
#include <set>
#include <iterator>
#include <limits>
#include <regex>
#include <string>
extern bool updateKeywords(const QString & argFullPath);

GlobalTexBuilder::~GlobalTexBuilder() {
}

/******
_keys_set()
_insertKey()
*****/

/*find max * between ( @ or @ )*/
static inline int getMaxStartCount(const QString & arg) {

    if (arg.size() < 3) {
        return 0;
    }

    const static QRegularExpression varRex{
        QStringLiteral(R"((\(\*+@)|(@\*+\)))") };

    auto varIt = varRex.globalMatch(arg);
    auto varMaxLength = 0;

    while (varIt.hasNext()) {
        auto varMatch = varIt.next();
        const auto varCurrentLength =
            varMatch.capturedLength() - 2;
        if (varCurrentLength > varMaxLength) {
            varMaxLength = varCurrentLength;
        }
    }

    return varMaxLength;

}

QString getMarginpar(const QString & argName, const QString & argThe) {
    const auto varPar1 =
        qsl(R"(\setlength\fboxsep{2pt}\fbox{\footnotesize{\kaishu\parbox{1em}{\setlength{\baselineskip}{2pt}%1}}\footnotesize{%2}})");
    const auto varPar2 = varPar1.arg(argName);
    const auto varPar = varPar2.arg(argThe);
    const auto varAns =
        qsl(R"(\marginpar[\hfill%1]{%1})").arg(varPar);
    return varAns;
}

static inline const QString & texRaw() {
    const static auto varAns = qsl(":tex_raw:");
    return varAns;
}

static inline const QString & theBookChapter() {
    const static auto varAns = qsl(":the_book_chapter:");
    return varAns;
}

static inline const QString & theBookSection() {
    const static auto varAns = qsl(":the_book_section:");
    return varAns;
}

static inline const QString & theBookSubSection() {
    const static auto varAns = qsl(":the_book_subsection:");
    return varAns;
}

static inline const QString & theBookSubSubSection() {
    const static auto varAns = qsl(":the_book_subsubsection:");
    return varAns;
}

static inline const QString & theBookText() {
    const static auto varAns = qsl(":the_book_text:");
    return varAns;
}

static inline const QString & theBookForeword() {
    const static auto varAns = qsl(":the_book_foreword:");
    return varAns;
}

static inline const QString & theBookImage() {
    const static auto varAns = qsl(":the_book_image:");
    return varAns;
}

static inline const QString & theBookReadFileSouce() {
    const static auto varAns = qsl(":the_book_file:");
    return varAns;
}

static inline const QString & theBookReadTreeFileSouce() {
    const static auto varAns = qsl(":the_book_tree_file:");
    return varAns;
}

static inline const QString & theBookReadCommandFileSouce() {
    const static auto varAns = qsl(":the_book_command_file:");
    return varAns;
}

static inline const QString & theBookTable() {
    const static auto varAns = qsl(":the_book_table:");
    return varAns;
}

/*将替换latex特殊字符*/
inline static std::string _replace_all(const std::string_view arg) {

    class ReplaceItem {
    public:
        std::regex regex;
        std::string data;
        ReplaceItem() = default;
        ReplaceItem(std::regex && a, std::string &&b) :
            regex(std::move(a)),
            data(std::move(b)) {
        }
    };

    /* regex : ^ $ \ . * + ? ( ) [ ] { } | */
    const static std::vector< ReplaceItem > varReplaceDutys = []() {
        constexpr const auto varRegexOption =
            std::regex_constants::ECMAScript |
            std::regex_constants::optimize;
        std::vector< ReplaceItem > ans;
        ans.emplace_back(std::regex(u8R"(\+)", varRegexOption), std::string(u8R"({\sourcefonttwo{}+})"sv));
        ans.emplace_back(std::regex(u8R"(\*)", varRegexOption), std::string(u8R"(\raisebox{-0.35ex}{\sourcefonttwo{}*})"sv));
        ans.emplace_back(std::regex(u8R"(-)", varRegexOption), std::string(u8R"(\hspace{0.05em}\rule[0.7ex]{0.4em}{0.65pt}\hspace{0.05em})"sv));
        ans.emplace_back(std::regex(u8R"(=)", varRegexOption), std::string(u8R"({\sourcefonttwo{}=})"sv));
        //ans.emplace_back(std::regex(u8R"(/)", varRegexOption), std::string(u8R"({\sourcefonttwo{}/})"sv));
        ans.emplace_back(std::regex(u8R"(~)", varRegexOption), std::string(u8R"(\raisebox{0.16ex}{\sourcefonttwo\~{}})"sv));
        ans.emplace_back(std::regex(u8R"(#)", varRegexOption), std::string(u8R"({\sourcefonttwo\#})"sv));
        ans.emplace_back(std::regex(u8R"(\$)", varRegexOption), std::string(u8R"({\sourcefonttwo\$})"sv));
        ans.emplace_back(std::regex(u8R"(%)", varRegexOption), std::string(u8R"({\sourcefonttwo\%})"sv));
        ans.emplace_back(std::regex(u8R"(\^)", varRegexOption), std::string(u8R"({\sourcefonttwo\^{}})"sv));
        ans.emplace_back(std::regex(u8R"(&)", varRegexOption), std::string(u8R"({\sourcefonttwo\&})"sv));
        ans.emplace_back(std::regex(u8R"(\{)", varRegexOption), std::string(u8R"({\sourcefonttwo\{})"sv));
        ans.emplace_back(std::regex(u8R"(\})", varRegexOption), std::string(u8R"({\sourcefonttwo\}})"sv));
        ans.emplace_back(std::regex(u8R"(_)", varRegexOption), std::string(u8R"(\underline{\hspace{0.5em}})"sv));
        ans.emplace_back(std::regex(u8R"(\\)", varRegexOption), std::string(u8R"(\textbackslash{})"sv));
        ans.emplace_back(std::regex(u8R"(°)", varRegexOption), std::string(u8R"(\textdegree{})"sv));
        ans.emplace_back(std::regex(u8R"(×)", varRegexOption), std::string(u8R"(\texttimes{})"sv));
        ans.emplace_back(std::regex(u8R"(♀)", varRegexOption), std::string(u8R"(\male{})"sv));
        ans.emplace_back(std::regex(u8R"(♂)", varRegexOption), std::string(u8R"(\female{})"sv));
        ans.emplace_back(std::regex(u8R"(★)", varRegexOption), std::string(u8R"(\ding{72})"sv));
        ans.emplace_back(std::regex(u8R"(☆)", varRegexOption), std::string(u8R"(\ding{73})"sv));
        return std::move(ans);
    }();

    std::string ans;

    class Replace {
    public:
        std::string_view data;
        bool is_replace = false;
        inline Replace(std::string_view a, bool b) :
            data(a),
            is_replace(b) {
        }
        inline Replace() = default;
    };
    std::vector<Replace> tmpReplacesInput;
    std::vector<Replace> tmpReplaces;

    tmpReplaces.emplace_back(arg, false);

    for (const auto & R : varReplaceDutys) {/*对于每一个正则表达式*/

        /*如果输入里面没有匹配此正则表达式则跳过*/
        if (false == std::regex_search(arg.data(), arg.data() + arg.size(), R.regex)) {
            continue;
        }

        tmpReplacesInput = std::move(tmpReplaces);

        for (const auto & varD : tmpReplacesInput) {

            if (varD.is_replace) { /*copy the replaced data to ans*/
                tmpReplaces.push_back(varD);
                continue;
            }

            if (varD.data.empty()) { /*skip the empty data  */
                //tmpReplaces.push_back(varD);
                continue;
            }

            std::regex_iterator varIt{
                varD.data.data(),
                varD.data.data() + varD.data.size(),
                R.regex };
            decltype(varIt) varE;

            if (varIt == varE) { /*if data do not match regex , copy it to ans*/
                tmpReplaces.push_back(varD);
                continue;
            }

            /*add a do not used data,it will be poped*/
            tmpReplaces.emplace_back(std::string_view{}, false);
            for (; varIt != varE; ++varIt) { /*replace the data*/
                tmpReplaces.pop_back();
                const auto varPreFix = varIt->prefix();
                const std::string_view varBeforeP(varPreFix.first, varPreFix.length());
                const auto varSubFix = varIt->suffix();
                const std::string_view varAfterP(varSubFix.first, varSubFix.length());
                tmpReplaces.emplace_back(varBeforeP, false);
                tmpReplaces.emplace_back(R.data, true);
                tmpReplaces.emplace_back(varAfterP, false);
            }

        }/*replace*/
    }/*regex*/

    {
        /*先计算返回元素大小...*/
        std::size_t varFinalSize = 4;
        for (const auto & varI : tmpReplaces) {
            varFinalSize += varI.data.size();
        }
        ans.reserve(varFinalSize);
    }

    for (const auto & varI : tmpReplaces) {
        if (varI.data.empty()) {
            continue;
        }
        ans.append(varI.data);
    }

    return std::move(ans);
}


/*将文本转换为符合tex语法的文本*/
static inline QString plainStringToTexString(const QString & arg) {
    if (arg.isEmpty()) {
        return{};
    }
    std::string varString;
    {   /*转换为UTF8编码*/
        const auto argInput = arg.toUtf8();
        /*替换特殊字符*/
        varString = _replace_all({ argInput.constData(),
            static_cast<std::size_t>(argInput.size()) });
    }
    /*转换成QString*/
    return QString::fromUtf8(varString.c_str(),
        static_cast<int>(varString.size()));
}

class TexBuilderPrivate {
public:
    TexBuilder * const super;
    GlobalTexBuilder * const globalSuper;
    QString inputFileName;
    QString outputFileName;

    std::optional< QFile > inputFile;
    std::optional< QFile > outputFile;

    std::optional< InputStream > inputStream;
    std::optional< OutPutFileStream > outputStream;

    inline bool openInput() {
        if (inputFile) {
            return false;
        }
        if (inputStream) {
            return false;
        }
        inputFile.emplace(inputFileName);
        if (false == inputFile->open(QIODevice::ReadOnly)) {
            return false;
        }
        inputStream.emplace(inputFile.operator->());
        return true;
    }

    inline bool openOutput() {
        if (outputFile) {
            return false;
        }
        if (outputStream) {
            return false;
        }
        outputFile.emplace(outputFileName);
        if (false == outputFile->open(QIODevice::WriteOnly)) {
            return false;
        }
        outputStream.emplace(outputFile.operator->());
        return true;
    }

    class ParseState;
    class Item :
        public std::enable_shared_from_this<Item> {
    public:

        enum class Type {
            TypeRawString,
            TypeProgramString,
            TypeFunctionOp,
            TypeFunctionStart,
            TypeFunctionEnd,
            TypeFunctionName,
            TypeTextString,
            TypeChapterString,
            TypeForwordString,
            TypeSectionString,
            TypeSubSectionString,
            TypeSubSubSectionString,
            TypeFileSourceString,
            TypeTable,
            TypeImageString,
        };

        using item_list = std::list< std::shared_ptr<Item> >;
        using item_list_pos = item_list::const_iterator;

        item_list_pos pos;
        std::shared_ptr<ParseState> state;
        int line_number{ 1 };

        virtual ~Item() = default;
        virtual Type getType() const = 0;
        virtual bool toRawString(item_list_pos * next) = 0;
        virtual bool isKeyFunction() const {
            return false;
        }

        inline Item(item_list_pos p, std::shared_ptr<ParseState> s) :
            pos(p),
            state(std::move(s)) {
            line_number = state->line_number;
        }

        inline void clear() {
            state.reset();
        }

    };

    class FunctionOp :
        public Item {
    public:
        inline FunctionOp(int deepthx, item_list_pos p, std::shared_ptr<ParseState> s)
            :Item(p, std::move(s)), deepth(deepthx) {
        }
        int callDeepth{ 0 };
        virtual Type getType() const override {
            return Type::TypeFunctionOp;
        }
        bool toRawString(item_list_pos * arg) override {
            *arg = this->pos;
            ++(*arg);
            return true;
        }
        int const deepth;
    };

    class FunctionStart :
        public FunctionOp {
    public:
        inline FunctionStart(int deepthx, item_list_pos p, std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }
        virtual Type getType() const override {
            return Type::TypeFunctionStart;
        }
    };

    class FunctionEnd :
        public FunctionOp {
    public:
        inline FunctionEnd(int deepthx, item_list_pos p, std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }
        virtual Type getType() const override {
            return Type::TypeFunctionEnd;
        }
    };

    class KeyTextSring :
        public FunctionOp {
    public:

        inline KeyTextSring(
            int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }

        virtual Type getType() const override {
            return Type::TypeTextString;
        }

        bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto v = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgs1 = getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgs = argc_to_string(varArgs1);
            /*将args转换为string*/
            *v = std::make_shared<RawString>(varArgs[0], v, state);
            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgs1[0].second);
            /*更新表数据*/
            *arg = v;
            return true;
        }

        bool isKeyFunction() const override {
            return true;
        }

    };

    class KeyTableString :
        public FunctionOp {
    public:

        inline KeyTableString(
            int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            : FunctionOp(deepthx, p, std::move(s)) {
        }

        virtual Type getType() const override {
            return Type::TypeTable;
        }

        bool isKeyFunction() const override {
            return true;
        }

        bool toRawString(item_list_pos * arg) override {
            QString varTableFullPath;
            /*将ans插入表*/
            auto varAnsPos = state->data.emplace(this->pos);

            bool isOk = false;
            /*获得args*/
            auto varArgsFull1 = getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }

            auto varArgsKey =
                argc_to_string(varArgsFull1);

            {
                const GetTheBookConstexpr varConstexpr;
                /*获得label*/
                auto varString = varArgsKey[0];
                const auto varKeyLabel =
                    varString.trimmed();
                auto varArgs2 =
                    varConstexpr.getValues(varKeyLabel);
                /*caption , dir */
                if (varArgs2.size() != 2) {
                    return false;
                }

                {/*...index*/
                    auto & varIndexStream = state
                        ->texBuilderPrivate
                        ->globalSuper
                        ->getTableIndex();
                    varIndexStream << qsl(R"++++(\noindent\tablename\ \ref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(},\dotfill\pageref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(}%)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << endl << endl;
                }

                const auto & varCaptionRaw = varArgs2[0];
                const auto & varDirRaw = varArgs2[1];

                const auto varDirPath =
                    getOutPutFileFullPath(varDirRaw);

                const auto varCaption =
                    theBookPlainTextToTexText(varCaptionRaw);

                QString varTableString;
                {
                    ReadTable varReader;
                    varReader.setTableDirName(varDirPath);
                    if (!varReader.open()) {
                        return false;
                    }
                    const QString varHeadData =
                        varReader.readHead();
                    const QString varBodyData =
                        varReader.readBody();
                    const auto varHeadControl =
                        varReader.readHeadControl();
                    varTableString += qsl(R"(%begin表
\FloatBarrier                                  %强制完成浮动体布局
\begin{longtable}{%1}

%表头....
\toprule{})").arg(varHeadControl);
                    varTableString += varHeadData;
                    {
                        QString varTableMarginnote = qsl(R"(%there must use marginnote ...
\marginnote{\setlength\fboxsep{2pt}\fbox{\footnotesize{\kaishu\tablename\,}\footnotesize{\ref{)");
                        varTableMarginnote += varKeyLabel;
                        varTableMarginnote += QStringLiteral(R"(}}}})");
                        varTableString += varTableMarginnote;
                    }
                    varTableString += qsl(R"(
\\ \midrule
\endfirsthead
)");
                    varTableString += qsl(R"(
%表尾...
\endlastfoot
)");

                    varTableString += qsl(R"(
%重复表头
\toprule{})");
                    varTableString += varHeadData;
                    varTableString += qsl(R"(
\\ \midrule
\endhead)");

                    varTableString += qsl(R"(
%重复表尾
\midrule
\endfoot
)");
                    varTableString += varBodyData;

                    if (!varTableString.endsWith(qsl(R"(\\)"))) {
                        varTableString += qsl(R"(\\)");
                    }

                    varTableString += qsl(R"(
\bottomrule            %表底部线
\caption{%1}\label{%2} %表标题
\end{longtable}
%end表
)").arg(varCaption).arg(varKeyLabel) ;
                    {
                        const QDir varDir{ varDirPath };
                        varTableFullPath =
                            varDir.absoluteFilePath(qsl("table.tex"));
                        QFile varFile{ varTableFullPath };
                        if (!varFile.open(QIODevice::WriteOnly)) {
                            return false;
                        }
                        OutPutFileStream varStream{ &varFile };
                        varStream << varTableString;
                    }
                }

                varString = qsl(R"(\input{%1})")
                    .arg(getOutPutFileDir()
                        .relativeFilePath(varTableFullPath));

                /*写入Ans*/
                *varAnsPos = std::make_shared<RawString>(varString, varAnsPos, state);

            }

            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgsFull1[0].second);
            /*更新表数据*/
            *arg = varAnsPos;
            return true;
        }

    };

    class KeyForewordString :
        public FunctionOp {
        using ThisType = KeyForewordString;
    public:

        inline KeyForewordString(
            int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }

        virtual Type getType() const override {
            return Type::TypeForwordString;
        }

        bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto v = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgs1 = getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgs = argc_to_string(varArgs1);
            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgs[0];
                const auto varKeyLabel = varString.trimmed();
                auto varArgs2 = varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 1) {
                    return false;
                }
                varString = qsl(R"(
\cleardoublepage                              %增加空白页
\setcounter{secnumdepth}{-2}                  %暂停编号，但加入目录
\chapter{
)") + theBookPlainTextToTexText(varArgs2[0])
+ qsl(R"(
}\label{)")
+ varKeyLabel
+ qsl(R"(}
\setcounter{secnumdepth}{4}                   %恢复编号，目录深度为4
)");
                *v = std::make_shared<RawString>(varString, v, state);
            }
            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgs1[0].second);
            /*更新表数据*/
            *arg = v;
            return true;
        }

        bool isKeyFunction() const override {
            return true;
        }

    };

    class KeyFileSouceString : public FunctionOp {
    public:

        inline bool isKeyFunction() const override {
            return true;
        }

        inline Type getType() const override {
            return Type::TypeFileSourceString;
        }

        inline KeyFileSouceString(int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }

        inline bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto varAnsPos = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgsKeyPart =
                getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgsKey =
                argc_to_string(varArgsKeyPart);

            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgsKey[0];
                const auto varKeyLabel =
                    varString.trimmed();
                auto varArgs2 =
                    varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 2) {
                    return false;
                }

                /***********************************************/

                QString varFullFile;
                QString varLeftKey = QStringLiteral(R"((%1@)");
                QString varRightKey = QStringLiteral(R"(@%1))");
                {
                    const auto varSources =
                        readFileSource(getOutPutFileFullPath(varArgs2[0]));
                    for (const auto & varLine : varSources) {
                        varFullFile += varLine;
                        varFullFile += QChar('\n');
                    }
                    if (!varFullFile.isEmpty()) {
                        varFullFile.chop(1);
                    }
                    const auto varStarSize = 1 + getMaxStartCount(varFullFile);
                    const QString varStars{ varStarSize,QChar('*') };
                    varLeftKey = varLeftKey.arg(varStars);
                    varRightKey = varRightKey.arg(varStars);
                }

                {/*index ...*/
                    auto & varIndexStream = state
                        ->texBuilderPrivate
                        ->globalSuper
                        ->getSourceIndex();
                    varIndexStream << qsl(R"++++(\noindent\filesourcenumbernameone\ \ref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(}\dotfill\pageref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(}%)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << endl << endl;
                }

                varString = qsl(R"(%\begin{spacing}{1.0}
\refstepcounter{filesourcenumber}\label{%1}    %增加源代码编号
\FloatBarrier                                  %强制完成浮动体布局
\begin{thebookfilesourceone}[escapeinside={%3}{%4},
caption=GoodLuck,
title=\filesourcenumbernameone \thefilesourcenumber
%2
)").arg(varKeyLabel).arg(varArgs2[1]).arg(varLeftKey).arg(varRightKey);
                varString += varFullFile;
                varString += varLeftKey;
                varString += getMarginpar(qsl(R"(\filesourcenumbernameone)"), qsl(R"(\thefilesourcenumber)"));
                varString += varRightKey;
                varString += qsl(R"(\end{thebookfilesourceone}          %抄录环境
\addtocounter{lstlisting}{-1}   %sub lstlisting counter ...
%\end{spacing}
)");

                /***********************************************/

                *varAnsPos = std::make_shared<RawString>(varString, varAnsPos, state);
            }

            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgsKeyPart[0].second);
            /*更新表数据*/
            *arg = varAnsPos;
            return true;
        }

    };

    class KeyTreeFileSouceString :
        public KeyFileSouceString {
    public:
        using KeyFileSouceString::KeyFileSouceString;
        inline bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto varAnsPos = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgsKeyPart =
                getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgsKey =
                argc_to_string(varArgsKeyPart);

            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgsKey[0];
                const auto varKeyLabel =
                    varString.trimmed();
                auto varArgs2 =
                    varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 2) {
                    return false;
                }

                /***********************************************/

                QString varFullFile;
                QString varLeftKey = QStringLiteral(R"((%1@)");
                QString varRightKey = QStringLiteral(R"(@%1))");
                {
                    const auto varSources =
                        readFileSource(getOutPutFileFullPath(varArgs2[0]));
                    for (const auto & varLine : varSources) {
                        varFullFile += varLine;
                        varFullFile += QChar('\n');
                    }
                    if (!varFullFile.isEmpty()) {
                        varFullFile.chop(1);
                    }
                    const auto varStarSize = 1 + getMaxStartCount(varFullFile);
                    const QString varStars{ varStarSize,QChar('*') };
                    varLeftKey = varLeftKey.arg(varStars);
                    varRightKey = varRightKey.arg(varStars);
                }

                {
                    auto & varIndexStream = state
                        ->texBuilderPrivate
                        ->globalSuper
                        ->getDirTreeSourceIndex();
                    varIndexStream << qsl(R"++++(\noindent\treeindexnumbernameone\ \ref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(}\dotfill\pageref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(}%)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << endl << endl;
                }

                varString = qsl(R"(%\begin{spacing}{1.0}
%\FloatBarrier
\refstepcounter{treeindexnumber}\label{%1}    %增加目录树编号
\begin{thebookfilesourceonepathtree}[escapeinside={%3}{%4},
caption=GoodLuck,
numbers=none,
title=\treeindexnumbernameone \thetreeindexnumber
%2
)").arg(varKeyLabel).arg(varArgs2[1]).arg(varLeftKey).arg(varRightKey);
                varString += varFullFile;
                varString += varLeftKey;
                varString += getMarginpar(qsl(R"(\treeindexnumbernameone)"), qsl(R"(\thetreeindexnumber)"));
                varString += varRightKey;
                varString += qsl(R"(\end{thebookfilesourceonepathtree}          %抄录环境
\addtocounter{lstlisting}{-1}   %sub lstlisting counter ...
%\end{spacing}
)");

                /***********************************************/

                *varAnsPos = std::make_shared<RawString>(varString, varAnsPos, state);
            }

            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgsKeyPart[0].second);
            /*更新表数据*/
            *arg = varAnsPos;
            return true;
        }
    };

    class KeyCommandFileSouceString :
        public KeyFileSouceString {
    public:
        using KeyFileSouceString::KeyFileSouceString;
        inline bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto varAnsPos = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgsKeyPart =
                getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgsKey =
                argc_to_string(varArgsKeyPart);

            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgsKey[0];
                const auto varKeyLabel =
                    varString.trimmed();
                auto varArgs2 =
                    varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 2) {
                    return false;
                }

                /***********************************************/

                QString varFullFile;
                QString varLeftKey = QStringLiteral(R"((%1@)");
                QString varRightKey = QStringLiteral(R"(@%1))");
                {
                    const auto varSources =
                        readFileSource(getOutPutFileFullPath(varArgs2[0]));
                    for (const auto & varLine : varSources) {
                        varFullFile += varLine;
                        varFullFile += QChar('\n');
                    }
                    if (!varFullFile.isEmpty()) {
                        varFullFile.chop(1);
                    }
                    const auto varStarSize = 1 + getMaxStartCount(varFullFile);
                    const QString varStars{ varStarSize,QChar('*') };
                    varLeftKey = varLeftKey.arg(varStars);
                    varRightKey = varRightKey.arg(varStars);
                }

                {
                    auto & varIndexStream = state
                        ->texBuilderPrivate
                        ->globalSuper
                        ->getCommandSourceIndex();
                    varIndexStream << qsl(R"++++(\noindent\commandnumbernameone\ \ref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(}\dotfill\pageref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(}%)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << endl << endl;
                }

                varString = qsl(R"(%\begin{spacing}{1.0}
%\FloatBarrier
\refstepcounter{commandnumber}\label{%1}    %增加命令行编号
\begin{thebookfilesourceonecommand}[escapeinside={%3}{%4},
caption=GoodLuck,
title=\commandnumbernameone \thecommandnumber
%2
)").arg(varKeyLabel).arg(varArgs2[1]).arg(varLeftKey).arg(varRightKey);
                varString += varFullFile;
                varString += varLeftKey;
                varString += getMarginpar(qsl(R"(\commandnumbernameone)"), qsl(R"(\thecommandnumber)"));
                varString += varRightKey;
                varString += qsl(R"(\end{thebookfilesourceonecommand}          %抄录环境
\addtocounter{lstlisting}{-1}   %sub lstlisting counter ...
%\end{spacing}
)");
                /***********************************************/

                *varAnsPos = std::make_shared<RawString>(varString, varAnsPos, state);
            }

            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgsKeyPart[0].second);
            /*更新表数据*/
            *arg = varAnsPos;
            return true;
        }
    };

    class KeyImageString : public FunctionOp {
    public:
        inline KeyImageString(int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }

        Type getType() const override {
            return Type::TypeImageString;
        }

        bool isKeyFunction() const override {
            return true;
        }

        bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto varAnsPos = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgsKeyPart =
                getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgsKey =
                argc_to_string(varArgsKeyPart);

            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgsKey[0];
                const auto varKeyLabel =
                    varString.trimmed();
                auto varArgs2 =
                    varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 4) {
                    return false;
                }

                auto varImagePathRaw = varArgs2[1];
                const bool varDoNotPutFrame =
                    varImagePathRaw.startsWith(QChar('&'));
                if (varDoNotPutFrame) {
                    varImagePathRaw.remove(0,1);
                }

                /*进行图片转换...*/
                ImageConvert varImageConvert{
                    varKeyLabel,
                    getOutPutFileFullPath(varImagePathRaw)
                };
                bool varIsImageConverted = false;
                if (varImageConvert.needConvert()) {
                    varIsImageConverted =
                    varImageConvert.convert();
                }

                {
                    auto & varIndexStream = state
                        ->texBuilderPrivate
                        ->globalSuper
                        ->getFigureIndex();
                    varIndexStream << qsl(R"++++(\noindent\figurename\ \ref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(}\dotfill\pageref{)++++");
                    varIndexStream << varKeyLabel;
                    varIndexStream << qsl(R"++++(})++++");
                    varIndexStream << endl << endl;
                }

                QString varFigureMarginnote = qsl(R"(%there must use marginnote ...
\marginnote{\setlength\fboxsep{2pt}\fbox{\footnotesize{\kaishu\figurename\,}\footnotesize{\ref{)");
                varFigureMarginnote += varKeyLabel;
                varFigureMarginnote += QStringLiteral(R"(}}}})");

                varString = qsl(R"(%begin图片
)");
                varString += qsl(R"(\begin{figure}%1 %浮动体 here and top ...
)").arg(varArgs2[2]);
                varString += varFigureMarginnote;
                varString += qsl(R"(\centering %中心对齐
)");
                if (!varDoNotPutFrame) {
                    varString += qsl(R"(\setlength\fboxsep{0pt}\fcolorbox[rgb]{0,0,0}{0.97,0.98,0.99}{)")/*1*/;
                }
                varString += qsl(R"(\includegraphics%1{)").arg(varArgs2[3]);
                varString += varIsImageConverted? varImageConvert.getRelativePath() : varImagePathRaw ;
                if (!varDoNotPutFrame) {
                    varString += qsl(R"(})")/*1*/;
                }
                varString += qsl(R"(} %图片路径
\caption{)");
                varString += theBookPlainTextToTexText(varArgs2[0]);
                varString += qsl(R"(} %标题
\label{)");
                varString += varKeyLabel;
                varString += qsl(R"(} %索引
\end{figure}
%end图片
)");
                *varAnsPos = std::make_shared<RawString>(varString, varAnsPos, state);
            }

            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgsKeyPart[0].second);
            /*更新表数据*/
            *arg = varAnsPos;
            return true;
        }

    };

    class KeyChapterString :
        public FunctionOp {
        using ThisType = KeyChapterString;
    public:

        inline KeyChapterString(
            int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }

        virtual Type getType() const override {
            return Type::TypeChapterString;
        }

        bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto v = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgs1 = getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgs = argc_to_string(varArgs1);
            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgs[0];
                const auto varKeyLabel = varString.trimmed();
                auto varArgs2 = varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 1) {
                    return false;
                }
                varString = qsl(R"(%\FloatBarrier
\cleardoublepage
\chapter{
)") + theBookPlainTextToTexText(varArgs2[0]) + qsl(R"(
}\label{)") + varKeyLabel
+ qsl(R"(}
)");
                *v = std::make_shared<RawString>(varString, v, state);
            }
            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgs1[0].second);
            /*更新表数据*/
            *arg = v;
            return true;
        }

        bool isKeyFunction() const override {
            return true;
        }

    };

    class KeySectionString :
        public FunctionOp {
        using ThisType = KeySectionString;
    public:

        inline KeySectionString(
            int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }

        virtual Type getType() const override {
            return Type::TypeSectionString;
        }

        bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto v = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgs1 = getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgs = argc_to_string(varArgs1);
            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgs[0];
                const auto varKeyLabel = varString.trimmed();
                auto varArgs2 = varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 1) {
                    return false;
                }
                varString = qsl(R"(\FloatBarrier
\section{
)") + theBookPlainTextToTexText(varArgs2[0]) + qsl(R"(
}\label{)") + varKeyLabel
+ qsl(R"(}
)");
                *v = std::make_shared<RawString>(varString, v, state);
            }
            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgs1[0].second);
            /*更新表数据*/
            *arg = v;
            return true;
        }

        bool isKeyFunction() const override {
            return true;
        }

    };

    class KeySubSectionString :
        public FunctionOp {
        using ThisType = KeySubSectionString;
    public:

        inline KeySubSectionString(
            int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }

        virtual Type getType() const override {
            return Type::TypeSubSectionString;
        }

        bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto v = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgs1 = getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgs = argc_to_string(varArgs1);
            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgs[0];
                const auto varKeyLabel = varString.trimmed();
                auto varArgs2 = varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 1) {
                    return false;
                }
                varString = qsl(R"(\FloatBarrier
\subsection{
)") + theBookPlainTextToTexText(varArgs2[0]) + qsl(R"(
}\label{)") + varKeyLabel
+ qsl(R"(}
)");
                *v = std::make_shared<RawString>(varString, v, state);
            }
            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgs1[0].second);
            /*更新表数据*/
            *arg = v;
            return true;
        }

        bool isKeyFunction() const override {
            return true;
        }

    };

    class KeySubSubSectionString :
        public FunctionOp {
        using ThisType = KeySubSubSectionString;
    public:

        inline KeySubSubSectionString(
            int deepthx,
            item_list_pos p,
            std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }

        virtual Type getType() const override {
            return Type::TypeSubSubSectionString;
        }

        bool toRawString(item_list_pos * arg) override {
            /*将ans插入表*/
            auto v = state->data.emplace(this->pos);
            bool isOk = false;
            /*获得args*/
            auto varArgs1 = getCallArgs(this->pos, 1, &isOk, this->state);
            if (isOk == false) {
                return false;
            }
            auto varArgs = argc_to_string(varArgs1);
            /*将args转换为string*/
            {
                const GetTheBookConstexpr varConstexpr;
                auto varString = varArgs[0];
                const auto varKeyLabel = varString.trimmed();
                auto varArgs2 = varConstexpr.getValues(varKeyLabel);
                if (varArgs2.size() != 1) {
                    return false;
                }
                varString = qsl(R"(\FloatBarrier
\subsubsection{
)") + theBookPlainTextToTexText(varArgs2[0]) + qsl(R"(
}\label{)") + varKeyLabel
+ qsl(R"(}
)");
                *v = std::make_shared<RawString>(varString, v, state);
            }
            /*删除整个函数*/
            state->data.erase(this->pos, ++varArgs1[0].second);
            /*更新表数据*/
            *arg = v;
            return true;
        }

        bool isKeyFunction() const override {
            return true;
        }

    };

    class RawString :
        public Item {
    public:
        const QString data;
        inline RawString(QString arg, item_list_pos p, std::shared_ptr<ParseState> s) :
            Item(p, std::move(s)), data(std::move(arg)) {
        }
        virtual Type getType() const override {
            return Type::TypeRawString;
        }
        bool toRawString(item_list_pos * arg) override {
            *arg = this->pos;
            ++(*arg);
            return true;
        }
    };

    class ProgramString :
        public Item {
    public:
        QString data;
        int callDeepth{ 0 };

        inline ProgramString(
            QString arg,
            item_list_pos p,
            std::shared_ptr<ParseState> s) :
            Item(p, std::move(s)), data(std::move(arg)) {
        }

        virtual Type getType() const {
            return Type::TypeProgramString;
        }

        bool toRawString(item_list_pos * arg) override {
            auto v = state->data.emplace(this->pos);
            *v = std::make_shared<RawString>(
                plainStringToTexString(data), v, state);
            state->data.erase(this->pos);
            *arg = v;
            return true;
        }

    };

    class ParseStateSuper {
    public:
        TexBuilderPrivate * texBuilderPrivate;
        ParseStateSuper(TexBuilderPrivate * arg) :texBuilderPrivate(arg) {
        }
    };
    class ParseState :
        public ParseStateSuper {
    public:
        Item::item_list data;
        int line_number{ 0 };
        int current_deepth{ -1 };
        ParseState(TexBuilderPrivate * v) :
            ParseStateSuper(v) {
        }
    };
    std::shared_ptr<ParseState> currentParseState;

    inline void clean() {

        if (inputStream) {
            inputStream.reset();
        }

        if (outputStream) {
            outputStream.reset();
        }

        if (inputFile) {
            inputFile.reset();
        }

        if (outputFile) {
            outputFile.reset();
        }

        if (currentParseState) {
            for (auto & varI : currentParseState->data) {
                if (varI) {
                    varI->clear();
                }
            }
            currentParseState->data.clear();
            currentParseState.reset();
        }

    }

    class FunctionKeys {
    public:
        QString name;
        int argc{ 1 };
        friend inline bool operator<(const FunctionKeys &l, const FunctionKeys & r) {
            return l.name < r.name;
        }
        inline FunctionKeys(const QString & a, int b) :
            name(a),
            argc(b) {
        }
        FunctionKeys(const FunctionKeys &) = default;
        FunctionKeys(FunctionKeys &&) = default;
        FunctionKeys&operator=(const FunctionKeys &) = default;
        FunctionKeys&operator=(FunctionKeys &&) = default;
    };

    static inline std::shared_ptr< std::set<FunctionKeys> > _keys_set() {
        auto varAns = std::make_shared<std::set<FunctionKeys>>();
        varAns->emplace(theBookChapter(), 1);
        varAns->emplace(theBookText(), 1);
        varAns->emplace(theBookForeword(), 1);
        varAns->emplace(theBookSection(), 1);
        varAns->emplace(theBookSubSection(), 1);
        varAns->emplace(theBookImage(), 1);
        varAns->emplace(theBookSubSubSection(), 1);
        varAns->emplace(theBookReadFileSouce(), 1);
        varAns->emplace(theBookReadTreeFileSouce(), 1);
        varAns->emplace(theBookReadCommandFileSouce(), 1);
        varAns->emplace(theBookTable(), 1);
        return std::move(varAns);
    }

    static inline std::shared_ptr< const std::set<FunctionKeys> > keys_set() {
        const static std::shared_ptr< const std::set<FunctionKeys> > varAns = _keys_set();
        return varAns;
    }

    /*构建表(处理宏)*/
    inline bool parse_tex_raw(std::shared_ptr<ParseState> varState) {

        auto & varStream = *inputStream;
        QString varLine;
        std::optional<const QString> varOp;
        while (false == varStream.atEnd()) {
            varLine = varStream.readLine();
            ++(varState->line_number);
        pass_next_l:
            if (varOp) {/*find end of tex_raw ... */
                auto varIndex = varLine.indexOf(*varOp);
                if (varIndex > -1) {
                    {/*将左面部分加入列表*/
                        if (varIndex) {
                            auto v = varState->data.emplace(varState->data.end());
                            auto varData =
                                std::make_shared<RawString>(varLine.left(varIndex), v, varState);
                            *v = varData;
                        }
                    }
                    auto varOpSize = varOp->size();
                    varOp.reset();
                    {/*将右边部分加入列表*/
                        auto varSize = varLine.size();
                        varSize -= varIndex + varOpSize;
                        if (varSize > 0) {
                            varLine = varLine.right(varSize);
                            goto pass_next_l;
                        }
                    }
                    {/*加入换行符*/
                        auto v = varState->data.emplace(varState->data.end());
                        auto varData =
                            std::make_shared<RawString>(qsl("\n"), v, varState);
                        *v = varData;
                    }

                } else {/*将当前行加入raw string*/
                    {/*将当前行加入列表...*/
                        auto v = varState->data.emplace(varState->data.end());
                        auto varData =
                            std::make_shared<RawString>(varLine, v, varState);
                        *v = varData;
                    }
                    {/*加入换行符*/
                        auto v = varState->data.emplace(varState->data.end());
                        auto varData =
                            std::make_shared<RawString>(qsl("\n"), v, varState);
                        *v = varData;
                    }
                }
            } else {
                auto varIndex = varLine.indexOf(texRaw());
                if (varIndex > -1) {/*find start of tex_raw ...*/
                    int varEqCount = 0;
                    auto varPos = varIndex + texRaw().size();

                    if (varIndex > 0) {/*将:raw_tex[===[左边的值加入列表*/
                        auto v = varState->data.emplace(varState->data.end());
                        auto varData =
                            std::make_shared<ProgramString>(varLine.left(varIndex), v, varState);
                        *v = varData;
                    }

                    {/*寻找非空元素...*/
                        bool isFindLeftStart = false;
                        while (false == isFindLeftStart) {
                            if (varPos >= varLine.size()) {
                                while (false == varStream.atEnd()) {
                                    varLine = varStream.readLine();
                                    ++(varState->line_number);
                                    if (varLine.trimmed().isEmpty()) {/*删除空行*/
                                        /*bad format ??? */
                                        continue;
                                    } else {
                                        break;
                                    }
                                }/*while*/
                                if (false == varStream.atEnd()) {
                                    varPos = 0;
                                } else {
                                    return false;
                                }
                            } else if (std::as_const(varLine)[varPos].isSpace()) {
                                ++varPos;
                                continue;
                            } else {
                                isFindLeftStart = true;
                            }
                        }
                    }

                    if (std::as_const(varLine)[varPos] != QChar('[')) {
                        return false;
                    }

                    ++varPos;
                    if (varPos > varLine.size()) {
                        return false;
                    }

                    while (varPos < varLine.size()) {
                        if (std::as_const(varLine)[varPos] == QChar('[')) {
                            break;
                        } else {
                            if (std::as_const(varLine)[varPos] == QChar('=')) {
                                ++varEqCount;
                                ++varPos;
                            } else {
                                return false;
                            }
                        }
                    }

                    if (varEqCount == 0) {
                        varOp.emplace(qsl("]]"));
                    } else {
                        QString varString(varEqCount, QChar('='));
                        varOp.emplace(qsl("]") + varString + qsl("]"));
                    }

                    if ((++varPos) >= varLine.size()) {
                        auto v = varState->data.emplace(varState->data.end());
                        auto varData =
                            std::make_shared<RawString>(qsl("\n"), v, varState);
                        *v = varData;
                    } else {/*将剩余部分加入列表*/

                        const auto varNewSize = varLine.size() - varPos;
                        varLine = varLine.right(varNewSize);
                        assert(varLine.size() == varNewSize);
                        goto pass_next_l;

                    }


                } else {
                    if (false == varLine.isEmpty()) {/*将当前行加入列表...*/
                        auto v = varState->data.emplace(varState->data.end());
                        auto varData =
                            std::make_shared<ProgramString>(varLine, v, varState);
                        *v = varData;
                    }
                    {/*加入换行符*/
                        auto v = varState->data.emplace(varState->data.end());
                        auto varData =
                            std::make_shared<RawString>(qsl("\n"), v, varState);
                        *v = varData;
                    }
                }
            }
        }

        if (varOp) {
            return false;
        }

        return true;
    }

    /*标记[[,]]*/
    inline int _parse_op(std::shared_ptr<ParseState> varState) {

        auto & varData = varState->data;
        auto varPos = varData.cbegin();
        int varMaxDeepth = 0;

        int varStartOpCount = 0;
        int varEndOpCount = 0;
        std::optional< Item::item_list_pos > varNewPos;

        while (varPos != varData.cend()) {

            const auto varCurrentType2 = varPos->get()->getType();
            if (varCurrentType2 == Item::Type::TypeProgramString) {

                auto varItemRaw = *varPos;
                auto varProgram =
                    static_cast<ProgramString *>(varItemRaw.get());

                auto varString = varProgram->data;
                assert(false == varString.isEmpty());

                const static auto varLeftExp = QRegularExpression(qsl(R"(\s*\[=*\[)"));
                const static auto varRightExp = QRegularExpression(qsl(R"(\]=*\])"));

                bool hasOp = false;

                do {
                    auto varLeftIndex = varString.indexOf(varLeftExp);
                    auto varRightIndex = varString.indexOf(varRightExp);

                    if ((varLeftIndex < 0) && (varRightIndex < 0)) {
                        /*没有[[或]]*/
                        hasOp = false;
                        if (varString.isEmpty() && varNewPos) {
                            /*字符串为空...*/
                            varData.erase(varPos);
                            varPos = *varNewPos;
                        } else {
                            if (varProgram->data != varString) {
                                /*如果字符串改变了,加入新的搜索节点*/
                                auto v = varData.emplace(varPos);
                                varData.erase(varPos);
                                *v = std::make_shared< ProgramString >(varString,
                                    v,
                                    varState);
                                varPos = v;
                            } else {
                                ++varPos;
                            }
                        }
                    } else {

                        /*分辨是[[还是]]*/
                        hasOp = true;
                        bool isLeft = false;
                        int varIndex = -1;
                        if (varLeftIndex < 0) {
                            varIndex = varRightIndex;
                            isLeft = false;
                        } else if (varRightIndex < 0) {
                            varIndex = varLeftIndex;
                            isLeft = true;
                        } else {
                            if (varRightIndex < varLeftIndex) {
                                isLeft = false;
                                varIndex = varRightIndex;
                            } else {
                                isLeft = true;
                                varIndex = varLeftIndex;
                            }
                        }
                        if (varIndex > -1) {

                            /*将index的左边加入搜索*/
                            if (varIndex) {
                                auto v = varData.emplace(varPos);
                                auto varLeftString = varString.left(varIndex);
                                *v = std::make_shared< ProgramString >(varLeftString,
                                    v,
                                    varState);
                            }

                            /*加入op...*/
                            if (isLeft) {
                                ++varStartOpCount;
                                auto v = varData.emplace(varPos);
                                auto varDeepth = varStartOpCount - varEndOpCount;
                                assert(varDeepth >= 0);
                                *v = std::make_shared< FunctionStart >(varDeepth,
                                    v,
                                    varState);
                                if (varNewPos) {
                                    varNewPos.reset();
                                }
                                varNewPos.emplace(v);
                                if (varEndOpCount) {
                                    varStartOpCount = varDeepth;
                                    varEndOpCount = 0;
                                }
                                varMaxDeepth = std::max(varMaxDeepth, varDeepth);
                            } else {
                                auto v = varData.emplace(varPos);
                                auto varDeepth = varStartOpCount - varEndOpCount;
                                assert(varDeepth >= 0);
                                *v = std::make_shared< FunctionEnd >(varDeepth,
                                    v,
                                    varState);
                                if (varNewPos) {
                                    varNewPos.reset();
                                }
                                varNewPos.emplace(v);
                                ++varEndOpCount;
                                if (varEndOpCount) {
                                    varStartOpCount = varDeepth;
                                    varEndOpCount = 0;
                                }
                            }

                            /*将右边加入搜索...*/
                            {
                                int varOpCount = 0;
                                auto varCIndex = varIndex;
                                for (; varCIndex < varString.size(); ++varCIndex) {
                                    if (isLeft) {
                                        if (varString[varCIndex] == QChar('[')) {
                                            ++varOpCount;
                                        }
                                    } else {
                                        if (varString[varCIndex] == QChar(']')) {
                                            ++varOpCount;
                                        }
                                    }
                                    if (varOpCount == 2) {
                                        break;
                                    }
                                }
                                auto varNewSize = varString.size() - varCIndex - 1;
                                assert(varNewSize >= 0);
                                varString = varString.right(varNewSize);
                            }

                        }
                    }

                } while (hasOp);

            } else {
                ++varPos;
            }
        }
        return varMaxDeepth;
    }

    inline Item::item_list_pos _insertKey(
        const FunctionKeys  & varKey,
        int varDeepth,
        Item::item_list_pos   varPos) {
        /*整个表*/
        auto & varData = currentParseState->data;

        auto varAns = varData.emplace(varPos);

        if (varKey.name == theBookReadCommandFileSouce()) {
            auto varValue =
                std::make_shared< KeyCommandFileSouceString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (varKey.name == theBookChapter()) {
            auto varValue =
                std::make_shared< KeyChapterString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (varKey.name == theBookForeword()) {
            auto varValue =
                std::make_shared< KeyForewordString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (theBookSection() == varKey.name) {
            auto varValue =
                std::make_shared< KeySectionString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (theBookSubSection() == varKey.name) {
            auto varValue =
                std::make_shared< KeySubSectionString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (theBookSubSubSection() == varKey.name) {
            auto varValue =
                std::make_shared< KeySubSubSectionString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (theBookImage() == varKey.name) {
            auto varValue =
                std::make_shared< KeyImageString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (theBookReadFileSouce() == varKey.name) {
            auto varValue =
                std::make_shared< KeyFileSouceString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (theBookTable() == varKey.name) {
            auto varValue =
                std::make_shared< KeyTableString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (theBookReadTreeFileSouce() == varKey.name) {
            auto varValue =
                std::make_shared< KeyTreeFileSouceString >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        } else if (varKey.name == theBookText()) {
            auto varValue =
                std::make_shared< KeyTextSring >(varDeepth,
                    varAns,
                    currentParseState);
            *varAns = varValue;
        }

        assert(*varAns);
        return varAns;

    }

    inline int get_function_deepth(Item::item_list_pos arg) {
        /*整个表*/
        auto & varData = currentParseState->data;
        auto varEnd = std::make_reverse_iterator(varData.cbegin());
        auto varBegin = std::make_reverse_iterator(arg);
        int varLeftCount = 0;
        int varRightCount = 0;
        for (; varBegin != varEnd; ++varBegin) {
            if (varBegin->get()->getType() == Item::Type::TypeFunctionEnd) {
                ++varRightCount;
            } else if (varBegin->get()->getType() == Item::Type::TypeFunctionStart) {
                ++varLeftCount;
            }
        }
        assert(varLeftCount >= varRightCount);
        return (varLeftCount - varRightCount);
    }

    /*获得argc...*/
    static inline std::vector< std::pair< Item::item_list_pos, Item::item_list_pos > >
        getCallArgs(
            Item::item_list_pos argPos,
            int  argc,
            bool * ans,
            std::shared_ptr<ParseState> currentParseState) {

        if (argc < 1) {
            *ans = true;
            return{};
        }

        const auto & varData =
            currentParseState->data;

        auto varEnd = varData.cend();

        auto varPos = argPos;
        ++varPos;

        std::vector< std::pair< Item::item_list_pos, Item::item_list_pos > > varAns;

        auto argci = argc;
        while (argci > 0) {
            --argci;

            std::pair< Item::item_list_pos, Item::item_list_pos >
                varItem;
            bool isSetBegin = false;
            for (; varPos != varEnd; ++varPos) {
                if (varPos->get()->getType() == Item::Type::TypeFunctionStart) {
                    isSetBegin = true;
                    varItem.first = varPos;
                } else if (varPos->get()->getType() == Item::Type::TypeFunctionEnd) {
                    varItem.second = varPos;
                    varAns.push_back(varItem);
                    ++varPos;
                    if (false == isSetBegin) {
                        *ans = false;
                        return std::move(varAns);
                    }
                    break;
                }
            }

        }

        *ans = (argc == static_cast<int>(varAns.size()));

        return std::move(varAns);

    }

    static inline std::vector<QString> argc_to_string(
        const std::vector<
        std::pair< Item::item_list_pos,
        Item::item_list_pos > > & args) {
        std::vector<QString> varAns;
        varAns.resize(args.size());
        std::size_t i = 0;
        for (; i < args.size(); ++i) {
            auto varItem = args[i];
            auto & varAnsI = varAns[i];
            auto varPos = varItem.first;
            for (; varPos != varItem.second; ++varPos) {
                if (varPos->get()->getType() == Item::Type::TypeRawString) {
                    varAnsI +=
                        static_cast<RawString *>(varPos->get())->data;
                } else if (varPos->get()->getType() == Item::Type::TypeProgramString) {
                    varAnsI += plainStringToTexString(
                        static_cast<ProgramString *>(varPos->get())->data);
                }
            }
        }
        return std::move(varAns);
    }


    /*构建表(处理函数深度)*/
    inline bool parse_call_deepth(std::shared_ptr<ParseState> varState) {

        /*标记 [[ , ]]....*/
        const auto varMaxDeepth = _parse_op(varState);

        /*最大函数调用深度*/
        varState->current_deepth = varMaxDeepth;

        if (varMaxDeepth == 0) {
            return true;
        }

        /*标记函数*/

        /*整个表*/
        auto & varData = varState->data;
        /*当前位置*/
        auto varPos = varData.cbegin();
        /*遍历整个表*/
        while (varPos != varData.cend()) {

            /*当前元素*/
            auto varItemRaw = *varPos;

            /*已经处理过...*/
            if (varItemRaw->getType() != Item::Type::TypeProgramString) {
                ++varPos;
                continue;
            }

            /*当前元素*/
            auto varProgram =
                static_cast<ProgramString *>(varItemRaw.get());

            /*搜索当前key的起始位置...*/
            int varIndex;

            do {

                varIndex = std::numeric_limits<int>::max();
                std::optional< FunctionKeys > varKey;

                /*本行keys计数器*/
                int varKeyCount = 0;
                /*搜索最左边的key*/
                for (const auto & varI : *keys_set()) {
                    auto varThisKeyIndex =
                        varProgram->data.indexOf(varI.name);
                    if (varThisKeyIndex < 0) {
                        continue;
                    }
                    ++varKeyCount;
                    if (varIndex > varThisKeyIndex) {
                        varIndex = varThisKeyIndex;
                    }
                    if (varKey) {
                        varKey.reset();
                    }
                    varKey.emplace(varI);
                }

                /*没有key...*/
                if (varIndex == std::numeric_limits<int>::max()) {
                    ++varPos;
                    break;
                }

                const auto varCurrentFunctionDeepth =
                    get_function_deepth(varPos);

                if (varKey->argc > 0) {
                    assert(varKeyCount == 1);
                    Item::item_list_pos varNewPos;
                    if (varIndex) {/*插入左边的内容*/
                        auto v = varData.emplace(varPos);
                        auto varItem =
                            std::make_shared< ProgramString >(
                                varProgram->data.left(varIndex),
                                v,
                                varState);
                        *v = varItem;
                    }
                    /*插入key...*/
                    varNewPos =
                        this->_insertKey(*varKey, varCurrentFunctionDeepth, varPos);
                    /*删除当前位置*/
                    varData.erase(varPos);
                    varPos = varNewPos;
                    break;
                } else {
                    Item::item_list_pos varNewPos;
                    if (varIndex) {/*插入左边的内容*/
                        auto v = varData.emplace(varPos);
                        auto varItem =
                            std::make_shared< ProgramString >(
                                varProgram->data.left(varIndex),
                                v,
                                varState);
                        *v = varItem;
                    }
                    /*插入key...*/
                    varNewPos =
                        this->_insertKey(*varKey, varCurrentFunctionDeepth, varPos);
                    /*删除无用数据*/
                    auto varDataString = varProgram->data;
                    const auto varNewSize =
                        varDataString.size() -
                        varIndex -
                        varKey->name.size();
                    assert(varNewSize >= 0);
                    varDataString = varDataString.right(varNewSize);
                    if (varDataString.isEmpty()) {
                        /*删除空节点*/
                        varData.erase(varPos);
                        varPos = varNewPos;
                        break;
                    } else {
                        /*继续搜索...*/
                        varProgram->data = varDataString;
                    }
                }

            } while (varIndex != std::numeric_limits<int>::max());

        }

        return true;
    }

    inline bool call_all_functions(std::shared_ptr<ParseState> varState) {
        if (varState->current_deepth < 1) {
            return true;
        }
        /*整个表*/
        auto & varData = varState->data;
        auto varPos = varData.cbegin();
        auto varCurrentDeepth = varState->current_deepth;
        do {
            varPos = varData.cbegin();
            while (varPos != varData.cend()) {
                if (varPos->get()->isKeyFunction()) {
                    auto varItem = *varPos;
                    auto varCurrentDeepth1 =
                        static_cast<FunctionOp *>(varItem.get())->deepth;
                    assert(varCurrentDeepth >= varCurrentDeepth1);
                    if (varCurrentDeepth == varCurrentDeepth1) {
                        if (false == varItem->toRawString(&varPos)) {
                            return false;
                        }
                    } else {
                        ++varPos;
                    }
                } else {
                    ++varPos;
                }
            }
        } while ((--varCurrentDeepth) > -1);

        return true;
    }

    /*一个简单的parse
    第一遍扫描提取所有tex_raw
    第二次扫描函数执行深度
    第三步按照深度执行函数
    第四步将其余节点转换为tex_raw
    其余则为the_book_text
    */
    inline bool parse() {
        auto varParseState = std::make_shared<ParseState>(this);
        currentParseState = varParseState;
        if (false == parse_tex_raw(varParseState)) {
            return false;
        }
        if (false == parse_call_deepth(varParseState)) {
            return false;
        }
        if (false == call_all_functions(varParseState)) {
            return false;
        }
        bool isAllRaw = false;
        int varCallCount = 16;
        while ((false == isAllRaw) && ((--varCallCount) > 0)) {
            isAllRaw = true;
            auto varPos = varParseState->data.cbegin();
            while (varPos != varParseState->data.cend()) {
                auto varI = *varPos;
                const auto varCurrentType1 = varI->getType();
                assert(varCurrentType1 != Item::Type::TypeFunctionEnd);
                assert(varCurrentType1 != Item::Type::TypeFunctionStart);
                if (varCurrentType1 != Item::Type::TypeRawString) {
                    isAllRaw = false;
                    if (varI->toRawString(&varPos) == false) {
                        return false;
                    }
                } else {
                    ++varPos;
                }
            }
        }
        return (varCallCount > 0);
    }

    inline void write_output() {
        auto & varStream = *outputStream;
        for (const auto & varI : currentParseState->data) {
            varStream << static_cast<const RawString *>(
                varI.get())->data;
        }
    }

public:
    TexBuilderPrivate(TexBuilder * arg, GlobalTexBuilder *argG)
        :super(arg)
        , globalSuper(argG) {
    }
};

TexBuilder::TexBuilder(GlobalTexBuilder * arg) :
    thisp(new TexBuilderPrivate(this, arg)) {

}

TexBuilder::~TexBuilder() {
    delete thisp;
}

void TexBuilder::setInputFileName(const QString & arg) {
    thisp->inputFileName = arg;
}

QString TexBuilder::getInputFileName() const {
    return thisp->inputFileName;
}

void TexBuilder::setOutputFileName(const QString & arg) {
    thisp->outputFileName = arg;
}

QString TexBuilder::getOutputFileName() const {
    return thisp->outputFileName;
}

bool TexBuilder::convert() {

    /*更新源文件...*/
    if (false == updateKeywords(thisp->inputFileName)) {
        return false;
    }

    /*由于shared_ptr循环引用，所以手动删除数据*/
    class CleanLock {
        TexBuilderPrivate * const data;
    private:
    public:
        inline CleanLock(TexBuilderPrivate * a) :data(a) {
            this->clean();
        }
        inline ~CleanLock() {
            this->clean();
        }
    private:
        inline void clean() {
            data->clean();
        }
    } varLock{ thisp };

    /*打开输入文件*/
    if (false == thisp->openInput()) {
        return false;
    }

    /*打开输出文件*/
    if (false == thisp->openOutput()) {
        return false;
    }

    /*进行转换*/
    if (false == thisp->parse()) {
        return false;
    }

    /*输出结果*/
    thisp->write_output();

    return true;
}


extern QString theBookPlainTextToTexText(const QString & arg) {
    return plainStringToTexString(arg);
}
