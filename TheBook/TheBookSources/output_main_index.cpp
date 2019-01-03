#include "output_main_index.hpp"
#include "OutPutStream.hpp"
#include "TexBuilder.hpp"

inline static void output_foreword() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("foreword/foreword.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("foreword/foreword.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(foreword/foreword.tex)"sv);
        }
    }
}

inline static void output_chapter_01() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/chapter01.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/chapter01.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/chapter01.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/section01_chapter01.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/section01_chapter01.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/section01_chapter01.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/setup_dev_env_on_linux.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/setup_dev_env_on_linux.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/setup_dev_env_on_linux.tex)"sv);
        }
    }
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter01/setup_dev_env_on_windows.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter01/setup_dev_env_on_windows.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter01/setup_dev_env_on_windows.tex)"sv);
        }
    }
}

inline static void output_chapter_02() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter02/chapter02.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter02/chapter02.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter02/chapter02.tex)"sv);
        }
    }
}

inline static void output_chapter_03() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter03/chapter03.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter03/chapter03.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter03/chapter03.tex)"sv);
        }
    }
}

inline static void output_chapter_04() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter04/chapter04.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter04/chapter04.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter04/chapter04.tex)"sv);
        }
    }
}

inline static void output_chapter_05() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter05/chapter05.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter05/chapter05.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter05/chapter05.tex)"sv);
        }
    }
}

inline static void output_chapter_06() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter06/chapter06.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter06/chapter06.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter06/chapter06.tex)"sv);
        }
    }
}

inline static void output_chapter_07() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter07/chapter07.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter07/chapter07.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter07/chapter07.tex)"sv);
        }
    }
}

inline static void output_chapter_08() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter08/chapter08.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter08/chapter08.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter08/chapter08.tex)"sv);
        }
    }
}

inline static void output_chapter_09() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter09/chapter09.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter09/chapter09.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter09/chapter09.tex)"sv);
        }
    }
}

inline static void output_chapter_10() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("chapter10/chapter10.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("chapter10/chapter10.tex")));
        if (false == varBuilder->convert()) {
            the_book_throw(u8R"(chapter10/chapter10.tex)"sv);
        }
    }
}

inline static void output_main_index_this() {
    {
        auto varBuilder = std::make_shared<TexBuilder>();
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

/*输出主文件目录*/
extern void output_main_index() try {

#ifdef _DEBUG
    test_this();
#endif

    output_main_index_this();
    output_foreword();
    output_chapter_01();
    output_chapter_02();
    output_chapter_03();
    output_chapter_04();
    output_chapter_05();
    output_chapter_06();
    output_chapter_07();
    output_chapter_08();
    output_chapter_09();
    output_chapter_10();

} catch (...) {
    throw;
}





