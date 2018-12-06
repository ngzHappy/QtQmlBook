#include "sstd_log.hpp"
#include "../new/sstd_new.hpp"
#include "../container/sstd_container.hpp"
#include <iostream>
#include <atomic>
#if __has_include(<charconv>)
#include <charconv>
#else
#define _F_NO_CHAR_CONV
#endif
#include <mutex>
using namespace std::string_view_literals;

namespace sstd {
    LogFunction::~LogFunction() {
    }
}/*namespace sstd*/

namespace {

    using atomic_sstd_log_function_type = std::atomic< sstd::LogFunction * >;

    inline sstd::string int_to_string(int arg) {
        switch (arg) {
        case 0:return sstd::string("0"sv);
        case 1:return sstd::string("1"sv);
        case 2:return sstd::string("2"sv);
        case 3:return sstd::string("3"sv);
        case 4:return sstd::string("4"sv);
        case 5:return sstd::string("5"sv);
        case 6:return sstd::string("6"sv);
        case 7:return sstd::string("7"sv);
        case 8:return sstd::string("8"sv);
        case 9:return sstd::string("9"sv);
        case 10:return sstd::string("10"sv);
        }
        sstd::string varAns;
        constexpr const auto varMaxSize = 256;
#ifdef _F_NO_CHAR_CONV
        varAns.resize(varMaxSize, char(0));
        char * pos = &( * varAns.rbegin() );
        char * varLast = pos + 1 ;
        int num = 0 ;
        bool isN = arg < 0;
        int den = isN ? (-arg) : arg ;
        const static constexpr char
                varCast[]{'0','1','2','3','4','5','6','7','8','9'};
        do {
            num = den % 10 ;
            den /= 10 ;
            *pos = varCast[num];
            --pos;
        } while( den );
        if(isN){
            *pos = '-';
        }else{
            ++pos;
        }
        std::copy(pos,varLast,varAns.data());
        varAns.resize( static_cast<std::size_t>( varLast - pos ) );
        return std::move(varAns);
#else
        varAns.resize(varMaxSize, char(0));
        const auto varResult = std::to_chars(varAns.data(), varAns.data() + varMaxSize, arg);
        varAns.resize(varResult.ptr - varAns.data());
        return std::move(varAns);
#endif
    }

    inline void build_in_log_function(
        sstd::LogLevel argLogError,
        std::string_view/*data*/argLogData,
        int argLogLine,
        std::string_view/*func*/argLogFunction,
        std::string_view/*filename*/argLogFileName) {
        sstd::string varAns;
        switch (argLogError) {
        case sstd::LogLevel::log:
            varAns += "log : "sv;
            break;
        case sstd::LogLevel::error:
            varAns += "error : "sv;
            break;
        case sstd::LogLevel::debug:
            varAns += "debug : "sv;
            break;
        default:
            break;
        }
        varAns += argLogData;
        varAns += "@line : "sv;
        varAns += int_to_string(argLogLine);
        varAns += "@func : "sv;
        varAns += argLogFunction;
        varAns += "@filename : "sv;
        varAns += argLogFileName;
        varAns += u8R"(
)"sv;
        std::cout << varAns << std::flush;
    }

    class BuildInLogFunction :
        public sstd::LogFunction,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(BuildInLogFunction){
    public:
        void log(
            sstd::LogLevel a,
            std::string_view/*data*/b,
            int c,
            std::string_view/*func*/d,
            std::string_view/*filename*/e) override {
            build_in_log_function(a, b, c, d, e);
        }
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(BuildInLogFunction);
    };

    inline atomic_sstd_log_function_type & getSSTDLogFunction() {
        static atomic_sstd_log_function_type varAns{
            sstd_new<BuildInLogFunction>() };
        return varAns;
    }

    class Mutex {
        std::atomic_flag mmmFlag{ ATOMIC_FLAG_INIT };
    public:
        inline void lock() {
            while (mmmFlag.test_and_set(std::memory_order_acquire)) {
            }
        }
        inline void unlock() {
            mmmFlag.clear(std::memory_order_release);
        }
    public:
        SSTD_DEFINE_STATIC_CLASS(Mutex);
    };

    Mutex & getMutex() {
        static auto * varAns = sstd_new<Mutex>();
        return *varAns;
    }

}/**/

_1_SSTD_CORE_EXPORT void _1_sstd_log(
    sstd::LogLevel a,
    std::string_view/*data*/ b,
    int c,
    std::string_view/*func*/d,
    std::string_view/*filename*/e) {
    auto f = getSSTDLogFunction().load();
    std::unique_lock varLock{ getMutex() };
    if (f) {
        f->log(a, b, c, d, e);
    } else {
        build_in_log_function(a, b, c, d, e);
    }
}

_1_SSTD_CORE_EXPORT sstd::LogFunction * sstd_set_log_function(sstd::LogFunction * a) {
    auto & varValue = getSSTDLogFunction();
    sstd::LogFunction * varAns = nullptr;
    while (!varValue.compare_exchange_weak(varAns, a)) {
    }
    return varAns;
}















