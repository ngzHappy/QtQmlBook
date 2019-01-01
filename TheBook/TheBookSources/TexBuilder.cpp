#include "TexBuilder.hpp"
#include "OutPutStream.hpp"
#include <optional>
#include <list>

static inline const QString & texRaw() {
    const static auto varAns = QStringLiteral(":tex_raw");
    return varAns;
}

class TexBuilderPrivate {
public:
    TexBuilder * const super;
    QString inputFileName;
    QString outputFileName;

    std::optional< QFile > inputFile;
    std::optional< QFile > outputFile;

    std::optional< QTextStream > inputStream;
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
        };

        using item_list = std::list< std::shared_ptr<Item> >;
        using item_list_pos = item_list::const_iterator;
        item_list_pos pos;
        std::shared_ptr<ParseState> state;

        virtual ~Item() = default;
        virtual Type getType() const = 0;
        virtual bool toRawString(item_list_pos * next) = 0;

        inline Item(item_list_pos p, std::shared_ptr<ParseState> s) :
            pos(p),
            state(std::move(s)) {
        }

    };

    class RawString :
        public Item {
    public:
        const QString data;
        inline RawString(QString arg, item_list_pos p, std::shared_ptr<ParseState> s) :
            data(std::move(arg)), Item(p, std::move(s)) {
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
        const QString data;

        inline ProgramString(
            QString arg,
            item_list_pos p,
            std::shared_ptr<ParseState> s) :
            data(std::move(arg)), Item(p, std::move(s)) {
        }

        virtual Type getType() const {
            return Type::TypeProgramString;
        }

        bool toRawString(item_list_pos * arg) override {
            /*TODO:*/
            auto v = state->data.emplace(this->pos);
            *v = std::make_shared<RawString>("---"+data+"---", v, state);
            state->data.erase(this->pos);
            *arg = v;
            return true;
        }

    };

    class ParseState {
    public:
        Item::item_list data;
        int line_number{0};
    };
    std::shared_ptr<ParseState> currentParseState;

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
                        varSize -=  varIndex + varOpSize;
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
                        assert(varLine.size()==varNewSize);
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

    /*一个简单的parse
    第一遍扫描提取所有tex_raw
    之后进行多次扫描，直至所有元素变为tex_raw为止
    */
    inline bool parse() {
        auto varParseState = std::make_shared<ParseState>();
        currentParseState = varParseState;
        if (false == parse_tex_raw(varParseState)) {
            return false;
        }
        bool isAllRaw = false;
        while (false == isAllRaw) {
            isAllRaw = true;
            auto varPos = varParseState->data.cbegin();
            while (varPos != varParseState->data.cend()) {
                auto varI = *varPos;
                if (varI->getType() != Item::Type::TypeRawString) {
                    isAllRaw = false;
                }
                if (varI->toRawString(&varPos) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    inline void write_output() {
        auto & varStream = *outputStream;
        for (const auto & varI : currentParseState->data) {
            varStream << static_cast<const RawString *>(
                varI.get())->data;
        }
    }

public:
    TexBuilderPrivate(TexBuilder * arg) :super(arg) {
    }
};

TexBuilder::TexBuilder() :
    thisp(new TexBuilderPrivate(this)) {

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

    if (false == thisp->openInput()) {
        return false;
    }

    if (false == thisp->openOutput()) {
        return false;
    }

    if (false == thisp->parse()) {
        return false;
    }

    thisp->write_output();

    return true;
}











