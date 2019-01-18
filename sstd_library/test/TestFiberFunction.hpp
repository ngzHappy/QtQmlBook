#pragma once

#include <sstd_library.hpp>
#include <future>
#include <exception>
#include <boost/context/fiber.hpp>
#include <boost/context/protected_fixedsize_stack.hpp>

namespace sstd {

    using Fiber = boost::context::fiber;

    template<typename ReturnType_>
    class FiberFunction :
        public virtual sstd_intrusive_ptr_basic {
    private:
        sstd_optional< Fiber > mmmFiber;

        class Promise :
            public std::enable_shared_from_this<Promise> {
        private:
            std::promise<ReturnType_> mmmPromise;
            sstd_bool mmmIsSetValue sstd$a(false);
            std::future<ReturnType_> mmmFuture;
        public:
            inline Promise() {
                mmmFuture = mmmPromise.get_future();
            }
            inline std::shared_ptr< std::future<ReturnType_> > getFuture() const {
                return { this->shared_from_this(),
                    &(const_cast<Promise *>(this)->mmmFuture) };
            }
            inline void set_exception() {
                if(mmmIsSetValue) {
                    return;
                }
                mmmIsSetValue = true;
                mmmPromise.set_exception(std::current_exception());
            }
            inline void set_value() {
                if(mmmIsSetValue) {
                    return;
                }
                mmmIsSetValue = true;
                if constexpr(std::is_same_v<void,
                    std::remove_cv_t< std::remove_reference_t<ReturnType_>>>) {
                    mmmPromise.set_value();
                } else {
                    mmmPromise.set_value({});
                }
            }
            template<typename TV>
            inline void set_value(TV && v) {
                if(mmmIsSetValue) {
                    return;
                }
                mmmIsSetValue = true;
                mmmPromise.set_value(std::forward<TV>(v));
            }
        private:
            SSTD_DEFINE_STATIC_CLASS(Promise);
        };
        std::shared_ptr<Promise> mmmPromise;

        class ThisCall {
            FiberFunction * mmmElement;
        public:
            inline ThisCall(FiberFunction * arg) :
                mmmElement(arg) {
            }
            inline Fiber operator()(Fiber && arg) const {
                try {
                    return
                        mmmElement->do_call(mmmElement,std::move(arg));
                } catch(...) {
                    mmmElement->mmmPromise->set_exception();
                    return std::move(arg);
                }
            }
            ThisCall(ThisCall &&) = default;
            ThisCall(const ThisCall &) = default;
            ThisCall&operator=(ThisCall &&) = default;
            ThisCall&operator=(const ThisCall &) = default;
        private:
            SSTD_DEFINE_STATIC_CLASS(ThisCall);
        };
    public:
        inline FiberFunction() {
            mmmPromise = sstd_make_shared<Promise>();
            mmmFiber.emplace(
                std::allocator_arg_t{},
                boost::context::protected_fixedsize_stack{ 1024 * 1024 * 10 },
                ThisCall{ this });
        }
        inline bool resume() {
            if(mmmFiber) {
                if(ppp_checked_fiber()) {
                    ppp_unchecked_resume();
                    return ppp_checked_fiber();
                }
                return false;
            }
            return false;
        }
        inline bool canResume() const {
            if(mmmFiber) {
                return ppp_checked_fiber();
            }
            return false;
        }
        inline void setValue() {
            mmmPromise->set_value();
        }
        template<typename TV>
        inline void setValue(TV && arg) {
            mmmPromise->set_value(std::forward<TV>(arg));
        }
        inline std::shared_ptr< std::future<ReturnType_> > getFuture() const {
            return mmmPromise->getFuture();
        }
    protected:
        virtual Fiber do_call(FiberFunction*,Fiber && f) = 0;
    private:
        inline void ppp_unchecked_resume() {
            *mmmFiber = std::move(*mmmFiber).resume();
        }
        inline bool ppp_checked_fiber() const {
            if(bool(*mmmFiber) == false) {
                const_cast<FiberFunction*>(this)
                    ->mmmFiber.reset();
                const_cast<FiberFunction*>(this)
                    ->setValue();
                return false;
            }
            return true;
        }
    private:
    };

    namespace _12_private_ {

        template<
            typename FunctionType_,
            typename ReturnType_ = void
        > class TypedFiberFunction final :
            public FiberFunction<ReturnType_>,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(
            TypedFiberFunction< FunctionType_,ReturnType_>) {
            using FunctionType =
                std::remove_cv_t<
                std::remove_reference_t<FunctionType_>>;
            sstd$(mmmFunction,FunctionType);
        public:
            template<typename U>
            inline TypedFiberFunction(U && u) :
                mmmFunction(std::forward<U>(u)) {
            }
            inline virtual Fiber do_call(FiberFunction * a,Fiber && f) override {
                return mmmFunction(a,std::move(f));
            }
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(TypedFiberFunction);
        };

    }/*_12_private_*/

    template<typename ReturnType_ = void,typename FunctionType_>
    sstd::intrusive_ptr< FiberFunction<ReturnType_> >
        make_fiber_function(FunctionType_ && f) {
        using F =
            _12_private_::TypedFiberFunction<FunctionType_,ReturnType_>;
        return sstd_make_intrusive_ptr<F>(std::forward<FunctionType_>(f));
    }

}/*namespace sstd*/


#ifndef sstd_yield_return
#define sstd_yield_return(argSSTDF,argSSTDFi,...)  { \
    argSSTDF->setValue( __VA_ARGS__ ); \
    return std::move(argSSTDFi); \
} 
#endif

#ifndef sstd_yield
#define sstd_yield(argSSTDFi) { \
    argSSTDFi = std::move(argSSTDFi).resume(); \
}
#endif 


