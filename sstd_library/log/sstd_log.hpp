#pragma once

#include <string_view>
#include "../global/sstd_basic_library_global.hpp"

namespace sstd {
    enum class LogLevel : std::size_t {
        log,
        error,
        debug,
    };

    class _1_SSTD_CORE_EXPORT LogFunction {
    public:
        virtual void log(
            sstd::LogLevel,
            std::string_view/*data*/,
            int line,
            std::string_view/*func*/,
            std::string_view/*filename*/)=0;
        virtual ~LogFunction();
    };

}/*namespace sstd*/

_1_SSTD_CORE_EXPORT void _1_sstd_log(
    sstd::LogLevel,
    std::string_view/*data*/,
    int line,
    std::string_view/*func*/,
    std::string_view/*filename*/);

using sstd_log_function_type = decltype(&_1_sstd_log);

_1_SSTD_CORE_EXPORT sstd::LogFunction * sstd_set_log_function(sstd::LogFunction *);


#ifndef sstd_log
#define sstd_log(...) _1_sstd_log( sstd::LogLevel::log , __VA_ARGS__ , __LINE__ ,__func__, __FILE__ )
#endif

#ifndef sstd_error
#define sstd_error(...) _1_sstd_log( sstd::LogLevel::error , __VA_ARGS__ , __LINE__ ,__func__, __FILE__ )
#endif

#ifndef sstd_debug
#define sstd_debug(...) _1_sstd_log( sstd::LogLevel::debug , __VA_ARGS__ , __LINE__ ,__func__, __FILE__ )
#endif













