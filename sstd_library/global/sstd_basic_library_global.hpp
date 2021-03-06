﻿#pragma once

#if defined(__cplusplus)/*__cplusplus*/
#include <cmath>
#include <limits>
#include <utility>
#include <optional>
#include <type_traits>
#endif/*__cplusplus*/

#include <boost/config.hpp>

/*just support dynamic library*/
#if defined(_1_SSTD_CORE_LIBRARY) /*_1_SSTD_CORE_LIBRARY*/
#define _1_SSTD_CORE_EXPORT BOOST_SYMBOL_EXPORT
#else
#define _1_SSTD_CORE_EXPORT BOOST_SYMBOL_IMPORT
#endif/*_1_SSTD_CORE_LIBRARY*/

#ifndef sstdg
#define sstdg
#endif

#if defined( _MSC_VER )
#pragma warning(disable:4251)
#endif

class sstd_friend_class;

/*用于定义变量，并规定最小内存对齐大小*/
namespace _8_sstd_private {

    template<std::size_t A, std::size_t B>
    class _8_Max {
    public:
        constexpr const static std::size_t value =
            A > B ? A : B;
    };

    template<typename A, typename B>
    class _8_Max_Align {
        using A_type = std::remove_cv_t<A>;
        using B_type = std::remove_cv_t<B>;
        static_assert(false == std::is_array_v<B>);
        static_assert(false == std::is_array_v<A>);
    public:
        constexpr const static std::size_t value =
            _8_Max< alignof(A_type),
            alignof(B_type) >::value;
    };

    using min_align_type = const volatile void *;

}/*_8_sstd_private*/

#ifndef sstd$
#define sstd$(cValueName,.../*cValueType*/)   \
alignas(_8_sstd_private::_8_Max_Align<_8_sstd_private::min_align_type, \
__VA_ARGS__>::value ) __VA_ARGS__ cValueName  \
/*--------------------------------------------*/
#endif

#ifndef sstd$a
#define sstd$a(...) {__VA_ARGS__}
#endif

#ifndef sstd_bool
#define sstd_bool alignas(_8_sstd_private::min_align_type) bool
#endif
