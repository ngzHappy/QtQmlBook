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

static inline void test_0200() {
    auto varBuilder = std::make_shared<TexBuilder>();
    varBuilder->setInputFileName(getOutPutFileFullPath(qsl("test/test_0200.txt")));
    varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("test/test_0200.tex")));
    assert(varBuilder->convert());
}

#define ENABLE_TEST_00
#define ENABLE_TEST_01
#define ENABLE_TEST_02

extern void test_this() {
    /************************************************/
#if defined(ENABLE_TEST_00)
    test_0000();
#endif
    /************************************************/
#if defined(ENABLE_TEST_01)
    test_0100();
    test_0101();
#endif
    /************************************************/
#if defined(ENABLE_TEST_02)
    test_0200();
#endif
}

#endif
