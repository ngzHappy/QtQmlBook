#pragma once

#include "../memory/sstd_memory.hpp"
#include "../allocator/sstd_allocator.hpp"

namespace abi_sstd_new_private {
    template<typename T, typename ... Args>
    class is_construct {
    public:
        constexpr const static bool value =
            (sizeof...(Args) != 0) &&
            (true == std::is_constructible_v<T, Args...>);
    };
}/*abi_sstd_new_private*/

template<typename T, typename ... Args>
inline T * sstd_new(Args && ... args) {
    using T1 = std::remove_cv_t< std::remove_reference_t<T> >;
    static_assert(false == std::is_array_v<T1>, "");
    if constexpr (abi_sstd_new_private::is_construct<T1, Args &&...>::value) {
        return new T1(std::forward<Args>(args)...);
    } else {
        return new T1{ std::forward<Args>(args)... };
    }
}

template<typename T, typename ... Args>
inline std::shared_ptr<T> sstd_make_shared(Args && ... args) {
    using T1 = std::remove_cv_t< std::remove_reference_t<T> >;
    static_assert(false == std::is_array_v<T1>, "");
    sstd::allocator<T1> varAllocator;
    T1 * varPointer = sstd_new<T1>(std::forward<Args>(args)...);
    return std::shared_ptr<T>(
        varPointer,
        [](auto * v) {delete v; },
        varAllocator);
}

template<typename T, typename ... Args>
inline std::unique_ptr<T> sstd_make_unique(Args && ... args) {
    using T1 = std::remove_cv_t< std::remove_reference_t<T> >;
    static_assert(false == std::is_array_v<T1>, "");
    T1 * varPointer = sstd_new<T1>(std::forward<Args>(args)...);
    return std::unique_ptr<T>{varPointer};
}
