#include "output_main_index.hpp"
#include "OutPutStream.hpp"
#include "TexBuilder.hpp"
#include <optional>

inline static void output_foreword(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("foreword/foreword.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("foreword/foreword.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(foreword/foreword.tex)"sv);
        }
    }
}

inline static void output_chapter_01(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/chapter01.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/chapter01.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/chapter01.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/section01_chapter01.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/section01_chapter01.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/section01_chapter01.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/setup_dev_env_on_windows.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/setup_dev_env_on_windows.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/setup_dev_env_on_windows.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/setup_dev_env_on_linux.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/setup_dev_env_on_linux.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/setup_dev_env_on_linux.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/introduce_qmake.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/introduce_qmake.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/introduce_qmake.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/first_application.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/first_application.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/first_application.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/hellow_world.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/hellow_world.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/hellow_world.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/defaultstyle.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/defaultstyle.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/defaultstyle.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/use_shader_in_qt_quick.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/use_shader_in_qt_quick.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/use_shader_in_qt_quick.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/directdrawbyopengl.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/directdrawbyopengl.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/directdrawbyopengl.tex)"sv);
        }
    }
}

inline static void output_chapter_02(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter02/chapter02.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter02/chapter02.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter02/chapter02.tex)"sv);
        }
    }
}

inline static void output_chapter_03(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter03/chapter03.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter03/chapter03.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter03/chapter03.tex)"sv);
        }
    }
}

inline static void output_chapter_04(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter04/chapter04.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter04/chapter04.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter04/chapter04.tex)"sv);
        }
    }
}

inline static void output_chapter_05(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter05/chapter05.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter05/chapter05.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter05/chapter05.tex)"sv);
        }
    }
}

inline static void output_chapter_06(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter06/chapter06.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter06/chapter06.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter06/chapter06.tex)"sv);
        }
    }
}

inline static void output_chapter_07(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter07/chapter07.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter07/chapter07.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter07/chapter07.tex)"sv);
        }
    }
}

inline static void output_chapter_08(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter08/chapter08.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter08/chapter08.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter08/chapter08.tex)"sv);
        }
    }
}

inline static void output_chapter_09(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter09/chapter09.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter09/chapter09.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter09/chapter09.tex)"sv);
        }
    }
}

inline static void output_chapter_10(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter10/chapter10.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter10/chapter10.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter10/chapter10.tex)"sv);
        }
    }
}

inline static void output_main_index_this(GlobalTexBuilder * arg) {
    {
        auto varBuilder = std::make_shared<TexBuilder>(arg);
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("main_index.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("main_index.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(main_index.tex)"sv);
        }
    }
}

#ifdef _DEBUG
extern void test_this();
#endif

namespace {
    class ThisGlobalTexBuilder :
        public GlobalTexBuilder {
        mutable std::optional<OutPutFileStream> figureIndex;
        mutable std::optional<OutPutFileStream> sourceIndex;
        mutable std::optional<OutPutFileStream> dirTreeSourceIndex;
        mutable std::optional<OutPutFileStream> commandSourceIndex;
        QFile fileFigureIndex;
        QFile fileSourceIndex;
        QFile fileDirTreeSourceIndex;
        QFile fileCommandSourceIndex;
    public:
        ThisGlobalTexBuilder() {
            fileFigureIndex.setFileName(getOutPutFileFullPath(qsl("figureIndex.tex")));
            fileSourceIndex.setFileName(getOutPutFileFullPath(qsl("sourceIndex.tex")));
            fileDirTreeSourceIndex.setFileName(getOutPutFileFullPath(qsl("dirTreeSourceIndex.tex")));
            fileCommandSourceIndex.setFileName(getOutPutFileFullPath(qsl("commandSourceIndex.tex")));
            fileFigureIndex.open(QIODevice::WriteOnly);
            fileSourceIndex.open(QIODevice::WriteOnly);
            fileCommandSourceIndex.open(QIODevice::WriteOnly);
            fileDirTreeSourceIndex.open(QIODevice::WriteOnly);
            figureIndex.emplace(&fileFigureIndex);
            sourceIndex.emplace(&fileSourceIndex);
            dirTreeSourceIndex.emplace(&fileDirTreeSourceIndex);
            commandSourceIndex.emplace(&fileCommandSourceIndex);
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
        }
    };
        }

/*输出主文件目录*/
extern void output_main_index() try {

#ifdef _DEBUG
    test_this();
#endif

    ThisGlobalTexBuilder varGlobalTexBuilder;
    output_main_index_this(&varGlobalTexBuilder);
    output_foreword(&varGlobalTexBuilder);
    output_chapter_01(&varGlobalTexBuilder);
    output_chapter_02(&varGlobalTexBuilder);
    output_chapter_03(&varGlobalTexBuilder);
    output_chapter_04(&varGlobalTexBuilder);
    output_chapter_05(&varGlobalTexBuilder);
    output_chapter_06(&varGlobalTexBuilder);
    output_chapter_07(&varGlobalTexBuilder);
    output_chapter_08(&varGlobalTexBuilder);
    output_chapter_09(&varGlobalTexBuilder);
    output_chapter_10(&varGlobalTexBuilder);

} catch (...) {
    throw;
}





