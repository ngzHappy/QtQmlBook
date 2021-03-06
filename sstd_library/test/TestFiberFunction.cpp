﻿
#include"TestFiberFunction.hpp"

#include <iostream>

class TestAClass {
public:
    sstd::Fiber operator()(sstd::FiberFunction<void>* argF,sstd::Fiber&& argFB) {

        sstd_yield_return(argF,argFB);
    }
};

extern void testFiber1() {

    {
        auto f = sstd_make_fiber_function<int>(
            [](sstd::FiberFunction<int>* argF,sstd::Fiber&& argFB)->sstd::Fiber {
            std::cout << "yield 1" << std::endl;
            sstd_yield(argF,argFB);
            std::cout << "yield 2" << std::endl;
            sstd_yield_return(argF,argFB,12);
        });
        assert(f->sstd_intrusive_ptr_count() == 1);
        auto fu = f->getFuture();
        while(sstd_resume(f));
        std::cout << fu->get() <<std::endl ;
        assert(f->sstd_intrusive_ptr_count() == 1);
    }

    {
        auto f = sstd_make_fiber_function<void>(
            [](sstd::FiberFunction<void>* argF,sstd::Fiber&& argFB)->sstd::Fiber {
            std::cout << "yield 3" << std::endl;
            sstd_yield(argF,argFB);
            std::cout << "yield 4" << std::endl;
            sstd_yield_return(argF,argFB);
        });
        assert(f->sstd_intrusive_ptr_count() == 1);
        auto fu = f->getFuture();
        while(sstd_resume(f));
        fu->get();
        assert(f->sstd_intrusive_ptr_count() == 1);
    }

    {
        auto f = sstd_make_fiber_function<void>(
            [](sstd::FiberFunction<void>* argF,sstd::Fiber&& argFB)->sstd::Fiber {
            std::cout << "yield 5" << std::endl;
            sstd_yield(argF,argFB);
            throw 1;
            std::cout << "yield 6" << std::endl;
            sstd_yield_return(argF,argFB);
        });
        assert(f->sstd_intrusive_ptr_count() == 1);
        auto fu = f->getFuture();
        while(sstd_resume(f));
        try {
            fu->get();
        } catch(...) {
            std::cout << "get throw" << std::endl;
        }
        assert(f->sstd_intrusive_ptr_count() == 1);
    }

}
