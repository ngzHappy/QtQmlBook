#ifdef _DEBUG

#include "the_book_global.hpp"
#include "TexBuilder.hpp"

static inline void test_00(){

        auto varBuilder = std::make_shared<TexBuilder>();
        varBuilder->setInputFileName(getOutPutFileFullPath(qsl("test/test_00.txt")));
        varBuilder->setOutputFileName(getOutPutFileFullPath(qsl("test/test_00.tex")));
        assert(varBuilder->convert());

}

extern void test_this(){
    test_00();
}





#endif







