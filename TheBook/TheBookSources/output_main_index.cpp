#include "output_main_index.hpp"
#include "OutPutStream.hpp"
#include "TexBuilder.hpp"
#include <optional>

namespace {

    inline bool build_make_files(GlobalTexBuilder * arg) {

        qWarning() << 
            qsl("---------------------------");

        class InputOutputItem {
        public:
            QString inputFileName;
            QString outputFileName;
            inline InputOutputItem(const QString & arg) :
                inputFileName(arg) {
                assert(arg.endsWith(qsl(".txt")));
                outputFileName = arg;
                outputFileName.chop(2);
                outputFileName += qsl("ex");
            }
        };

        std::list< InputOutputItem > varDutys;

        {
            QFile varFile{
                getOutPutFileFullPath(qsl("MakeFile.txt"))
            };
            if (false == varFile.open(QIODevice::ReadOnly)) {
                return false;
            }
            InputStream varInputStream{ &varFile };
            while (!varInputStream.atEnd()) {
                auto varLine =
                    varInputStream.readLine().trimmed();
                if (varLine.startsWith(QChar('%'))) {
                    continue;
                }
                if (varLine.isEmpty()) {
                    continue;
                }
                varDutys.emplace_back(varLine);
            }
        }

        if ( varDutys.empty() ) {
            return false;
        }

        bool varAns{true};

        for (const auto & varI : std::as_const( varDutys ) ) {
            auto varBuilder = std::make_shared<TexBuilder>(arg);
            varBuilder->setInputFileName(getOutPutFileFullPath(varI.inputFileName));
            varBuilder->setOutputFileName(getOutPutFileFullPath(varI.outputFileName));
            if (false == varBuilder->convert()) {
                qWarning() << 
                    varI.inputFileName << qsl("Error");
                varAns = false;
            } else {
                qWarning() << 
                    varI.inputFileName << qsl("Ok");
            }
        }

        return varAns;

    }

}/****/

#ifdef _DEBUG
extern void test_this();
#endif

namespace {
    class ThisGlobalTexBuilder final :
        public GlobalTexBuilder {
        mutable std::optional<OutPutFileStream> figureIndex;
        mutable std::optional<OutPutFileStream> sourceIndex;
        mutable std::optional<OutPutFileStream> dirTreeSourceIndex;
        mutable std::optional<OutPutFileStream> commandSourceIndex;
        mutable std::optional<OutPutFileStream> tableIndex;
        QFile fileFigureIndex;
        QFile fileSourceIndex;
        QFile fileDirTreeSourceIndex;
        QFile fileCommandSourceIndex;
        QFile fileTableIndex;
    public:
        ThisGlobalTexBuilder() {
            fileFigureIndex.setFileName(getOutPutFileFullPath(qsl("figureIndex.tex")));
            fileSourceIndex.setFileName(getOutPutFileFullPath(qsl("sourceIndex.tex")));
            fileDirTreeSourceIndex.setFileName(getOutPutFileFullPath(qsl("dirTreeSourceIndex.tex")));
            fileCommandSourceIndex.setFileName(getOutPutFileFullPath(qsl("commandSourceIndex.tex")));
            fileTableIndex.setFileName(getOutPutFileFullPath(qsl("tableIndex.tex")));
            fileFigureIndex.open(QIODevice::WriteOnly);
            fileSourceIndex.open(QIODevice::WriteOnly);
            fileCommandSourceIndex.open(QIODevice::WriteOnly);
            fileDirTreeSourceIndex.open(QIODevice::WriteOnly);
            fileTableIndex.open(QIODevice::WriteOnly);
            figureIndex.emplace(&fileFigureIndex);
            sourceIndex.emplace(&fileSourceIndex);
            dirTreeSourceIndex.emplace(&fileDirTreeSourceIndex);
            commandSourceIndex.emplace(&fileCommandSourceIndex);
            tableIndex.emplace(&fileTableIndex);
        }
        QTextStream & getFigureIndex() const override {
            return *figureIndex;
        }
        QTextStream & getSourceIndex() const override {
            return *sourceIndex;
        }
        QTextStream & getDirTreeSourceIndex() const override {
            return *dirTreeSourceIndex;
        }
        QTextStream & getCommandSourceIndex() const override {
            return *commandSourceIndex;
        }
        ~ThisGlobalTexBuilder() {
            commandSourceIndex.reset();
            dirTreeSourceIndex.reset();
            sourceIndex.reset();
            figureIndex.reset();
            tableIndex.reset();
        }
    };
}

/*输出主文件目录*/
extern void output_main_index() try {

#ifdef _DEBUG
    test_this();
#endif

    ThisGlobalTexBuilder varGlobalTexBuilder;
    if (false == build_make_files(&varGlobalTexBuilder)) {
        the_book_throw(u8R"(build error!)"sv);
    }

} catch (...) {
    throw;
}





