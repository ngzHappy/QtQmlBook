#include "TexBuilder.hpp"
#include "OutPutStream.hpp"
#include <optional>
#include <list>
#include <set>
#include <iterator>
#include <limits>

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
            TypeFunctionOp,
            TypeFunctionStart,
            TypeFunctionEnd,
            TypeFunctionName,
            TypeTextString,
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

        inline void clear(){
            state.reset() ;
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
        inline KeyTextSring(int deepthx, item_list_pos p, std::shared_ptr<ParseState> s)
            :FunctionOp(deepthx, p, std::move(s)) {
        }
        virtual Type getType() const override {
            return Type::TypeTextString ;
        }
        bool toRawString(item_list_pos * arg) override {
            *arg = this->pos;
            ++(*arg);
            return true;
        }
        bool isKeyFunction() const override {
             return true ;
        }
    };

    class RawString :
        public Item {
    public:
        const QString data;
        inline RawString(QString arg, item_list_pos p, std::shared_ptr<ParseState> s) :
             Item(p, std::move(s)) ,data(std::move(arg)) {
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
             Item(p, std::move(s)),data(std::move(arg)) {
        }

        virtual Type getType() const {
            return Type::TypeProgramString;
        }

        bool toRawString(item_list_pos * arg) override {
            /*TODO:*/
            auto v = state->data.emplace(this->pos);
            *v = std::make_shared<RawString>("---" + data + "---", v, state);
            state->data.erase(this->pos);
            *arg = v;
            return true;
        }

    };

    class ParseState {
    public:
        Item::item_list data;
        int line_number{ 0 };
        int current_deepth{-1};
    };
    std::shared_ptr<ParseState> currentParseState;

    inline void clean(){

        if(inputStream){
            inputStream.reset();
        }

        if(outputStream){
            outputStream.reset();
        }

        if(inputFile){
            inputFile.reset();
        }

        if(outputFile){
            outputFile.reset();
        }

        if( currentParseState ){
            for(auto & varI:currentParseState->data){
                varI->clear();
            }
            currentParseState->data.clear();
            currentParseState.reset() ;
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
        varAns->emplace(qsl(":the_book_chapter"), 1);
        varAns->emplace(qsl(":the_book_text"), 1);
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

            if (varPos->get()->getType() == Item::Type::TypeProgramString) {

                auto varItemRaw = *varPos;
                auto varProgram =
                    static_cast<ProgramString *>(varItemRaw.get());

                auto varString = varProgram->data;
                assert(false == varString.isEmpty());

                const static auto varLeftExp = QRegularExpression(qsl(R"(\s\[=*\[)"));
                const static auto varRightExp = QRegularExpression(qsl(R"(\s\]=*\])"));

                bool hasOp = false;

                do {
                    auto varLeftIndex = varString.indexOf(varLeftExp);
                    auto varRightIndex = varString.indexOf(varRightExp);
                    if ((varLeftIndex < 0) && (varRightIndex < 0)) {
                        hasOp = false;
                        if (varString.isEmpty() && varNewPos) {
                            varData.erase(varPos);
                            varPos = *varNewPos;
                        } else {
                            if (varProgram->data != varString) {
                                varData.erase(varPos);
                                auto v = varData.emplace(varPos);
                                *v = std::make_shared< ProgramString >(varString,
                                    v,
                                    varState);
                                varPos = v;
                            } else {
                                ++varPos;
                            }
                        }
                    } else {
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

    inline Item::item_list_pos insertKey(
            const FunctionKeys  & varKey ,
            int varDeepth,
            Item::item_list_pos   varPos ){
        /*整个表*/
        auto & varData = currentParseState->data;

        auto varAns = varData.emplace(varPos);

        if( varKey.name == qsl(":the_book_chapter") ){

        }else if(varKey.name == qsl(":the_book_text")){
            auto varValue =
                std::make_shared< KeyTextSring >(varDeepth,
                                                 varAns,
                                                 currentParseState);
            *varAns = varValue;
        }

        return varAns ;

    }

    inline int get_function_deepth(  Item::item_list_pos arg ){
        /*整个表*/
        auto & varData = currentParseState->data;
        auto varEnd = std::make_reverse_iterator( varData.cbegin() );
        auto varBegin = std::make_reverse_iterator( arg );
        int varLeftCount =0 ;
        int varRightCount = 0;
        for(;varBegin!=varEnd;++varBegin){
            if(varBegin->get()->getType() == Item::Type::TypeFunctionEnd ){
                ++varLeftCount ;
            }else if(varBegin->get()->getType() == Item::Type::TypeFunctionStart ){
                ++varRightCount ;
            }
        }
        assert(varLeftCount>=varRightCount);
        return (varLeftCount-varRightCount);
    }

    /*获得argc...*/
    inline std::vector< std::pair< Item::item_list_pos,Item::item_list_pos > >
    getCallArgs(  Item::item_list_pos  argPos , int  argc,bool * ans){

        if(argc<1){
            *ans = true;
            return{};
        }

        const auto & varData =
        currentParseState->data;

        auto varEnd =varData.cend();

        auto varPos = argPos ;
        ++varPos;

        std::vector< std::pair< Item::item_list_pos,Item::item_list_pos > > varAns;

        auto argci = argc;
        while (argci>0) {
            --argci;

            std::pair< Item::item_list_pos,Item::item_list_pos >
                    varItem;
            bool isSetBegin=false;
            for(;varPos!= varEnd ; ++varPos ){
                if( varPos->get()->getType() == Item::Type::TypeFunctionStart ){
                    isSetBegin=true;
                    varItem.first = varPos;
                }else if(varPos->get()->getType() == Item::Type::TypeFunctionEnd ) {
                    varItem.second = varPos;
                    varAns.push_back( varItem );
                    ++varPos;
                    if(false==isSetBegin){
                        *ans=false;
                        return std::move(varAns);
                    }
                    break;
                }
            }

        }

    *ans = (argc == static_cast<int>( varAns.size()));

    return std::move(varAns);

    }

    inline std::vector<QString> argc_to_string(
            const std::vector<
            std::pair< Item::item_list_pos,
            Item::item_list_pos > > & args){
return {};
    }


    /*构建表(处理函数深度)*/
    inline bool parse_call_deepth(std::shared_ptr<ParseState> varState) {

        /*标记 [[ , ]]....*/
        const auto varMaxDeepth = _parse_op(varState);

        /*最大函数调用深度*/
        varState->current_deepth = varMaxDeepth;

        if(varMaxDeepth == 0){
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
            int varIndex ;

            do {

            varIndex = std::numeric_limits<int>::max();
            std::optional< FunctionKeys > varKey;

            /*本行keys计数器*/
            int varKeyCount= 0;
            /*搜索最左边的key*/
            for (const auto & varI : *keys_set()) {
                auto varThisKeyIndex =
                        varProgram->data.indexOf(varI.name);
                if (varThisKeyIndex < 0) {
                    continue ;
                }
                ++varKeyCount;
                if(varIndex>varThisKeyIndex){
                    varIndex = varThisKeyIndex ;
                }
                if(varKey){
                    varKey.reset();
                }
                varKey.emplace(varI);
            }

            /*没有key...*/
            if (varIndex == std::numeric_limits<int>::max()) {
                ++varPos;
                break ;
            }

            const auto varCurrentFunctionDeepth =
             get_function_deepth(varPos);

            if(varKey->argc > 0 ){
                assert(varKeyCount==1);
                Item::item_list_pos varNewPos;
                if(varIndex){/*插入左边的内容*/
                    auto v = varData.emplace(varPos);
                    auto varItem =
                            std::make_shared< ProgramString >(
                                varProgram->data.left(varIndex) ,
                                v,
                                varState);
                    *v = varItem ;
                }
                /*插入key...*/
                varNewPos =
                        this->insertKey( *varKey ,varCurrentFunctionDeepth , varPos );
                /*删除当前位置*/
                varData.erase(varPos);
                varPos = varNewPos;
                break ;
            }else{
                Item::item_list_pos varNewPos;
                if(varIndex){/*插入左边的内容*/
                    auto v = varData.emplace(varPos);
                    auto varItem =
                            std::make_shared< ProgramString >(
                                varProgram->data.left(varIndex) ,
                                v,
                                varState);
                    *v = varItem ;
                }
                /*插入key...*/
                varNewPos =
                        this->insertKey( *varKey  ,varCurrentFunctionDeepth, varPos );
                /*删除无用数据*/
                auto varDataString = varProgram->data;
                const auto varNewSize =
                        varDataString.size() -
                        varIndex -
                        varKey->name.size();
                assert(varNewSize>=0);
                varDataString = varDataString.right( varNewSize );
                if(varDataString.isEmpty()){
                    /*删除空节点*/
                    varData.erase( varPos );
                    varPos = varNewPos;
                    break;
                }else{
                    /*继续搜索...*/
                    varProgram->data = varDataString ;
                }
            }

            } while( varIndex!=std::numeric_limits<int>::max() );

        }

        return true;
    }

    inline bool call_all_functions(std::shared_ptr<ParseState> varState){
        if(varState->current_deepth<1){
            return true;
        }
        /*整个表*/
        auto & varData = varState->data;
        auto varPos = varData.cbegin();
        auto varCurrentDeepth = varState->current_deepth;
        do{
        while(varPos!=varData.cend()){
            if(varPos->get()->isKeyFunction()){
                auto varItem = *varPos;
                auto varCurrentDeepth1 =
                static_cast< FunctionOp * >(varItem.get())->deepth;
                assert( varCurrentDeepth >= varCurrentDeepth1 );
                if(varCurrentDeepth == varCurrentDeepth1){
                    if(false == varItem->toRawString( &varPos )){
                        return false;
                    }
                }
            }else{
                ++varPos;
            }
        }
        }while((--varCurrentDeepth)>-1);

        return true;
    }

    /*一个简单的parse
    第一遍扫描提取所有tex_raw
    第二次扫描函数执行深度
    第三步按照深度执行函数
    其余则为the_book_text
    */
    inline bool parse() {
        auto varParseState = std::make_shared<ParseState>();
        currentParseState = varParseState;
        if (false == parse_tex_raw(varParseState)) {
            return false;
        }
        if (false == parse_call_deepth(varParseState)) {
            return false;
        }
        if(false == call_all_functions(varParseState)){
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

    class CleanLock{
        TexBuilderPrivate * const data;
    private:
    public:
        inline CleanLock(TexBuilderPrivate * a):data(a){
            this->clean();
        }
        inline ~CleanLock(){
            this->clean();
        }
        inline void clean(){
            data->clean();
        }
    } varLock{thisp} ;

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











