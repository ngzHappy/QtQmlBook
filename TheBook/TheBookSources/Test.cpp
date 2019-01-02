#ifdef _DEBUG

#include "the_book_global.hpp"
#include "TexBuilder.hpp"

static inline void test_0000() {
    auto varBuilder = std::make_shared<TexBuilder>();
    varBuilder->setInputFileName(getOutPutFileFullPath(qsl("test/test_0000.txt")));
    varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("test/test_0000.tex")));
    assert(varBuilder->convert());
}

static inline void test_0100() {
    auto varBuilder = std::make_shared<TexBuilder>();
    varBuilder->setInputFileName(getOutPutFileFullPath(qsl("test/test_0100.txt")));
    varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("test/test_0100.tex")));
    assert(varBuilder->convert());
}

static inline void test_0101() {
    auto varBuilder = std::make_shared<TexBuilder>();
    varBuilder->setInputFileName(getOutPutFileFullPath(qsl("test/test_0101.txt")));
    varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("test/test_0101.tex")));
    assert(varBuilder->convert());
}


extern void test_this() {
    test_0000();
    test_0100();
    test_0101();
}


#endif







