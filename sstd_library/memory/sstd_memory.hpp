#pragma once

#include "../global/sstd_basic_library_global.hpp"
#include <memory>
#if __has_include(<memory_resource>)
#include <memory_resource>
#else
#define _0_DO_NOT_HAVE_MEMORY_RESOURCE (1u)
#endif

class _1_SSTD_CORE_EXPORT _1_sstd_memory_static_class_basic final {
public:
    inline constexpr _1_sstd_memory_static_class_basic() noexcept;
    inline ~_1_sstd_memory_static_class_basic() = default;
    inline constexpr _1_sstd_memory_static_class_basic(const _1_sstd_memory_static_class_basic &) = default;
    inline constexpr _1_sstd_memory_static_class_basic(_1_sstd_memory_static_class_basic &&) = default;
    inline constexpr _1_sstd_memory_static_class_basic&operator=(const _1_sstd_memory_static_class_basic &) = default;
    inline constexpr _1_sstd_memory_static_class_basic&operator=(_1_sstd_memory_static_class_basic &&) = default;
public:
    static void* operator new (std::size_t count);
    static void operator delete(void * ptr);
public:
    static void* operator new[](std::size_t count);
    static void operator delete[](void * ptr);
public:
    static void* operator new(std::size_t count, std::align_val_t al);
    static void operator delete(void* ptr, std::align_val_t al);
public:
    static void* operator new[](std::size_t count, std::align_val_t al);
    static void operator delete[](void* ptr, std::align_val_t al);
public:
    static inline void* operator new  (std::size_t, void* ptr) noexcept {
        return ptr;
    }
    static inline void* operator new[](std::size_t, void* ptr) noexcept {
        return ptr;
    }
public:
    static constexpr inline void operator delete  (void *, void *) noexcept {
    }
    static constexpr inline void operator delete[](void *, void *) noexcept {
    }
};

template<typename T_SSTD_X37627, typename ...T_SSTD_X37627_Args> \
inline T_SSTD_X37627 * sstd_new(T_SSTD_X37627_Args && ... args);
#ifndef _SSTD_MEMORY_1_DFINE
#define _SSTD_MEMORY_1_DFINE \
public : \
    static inline void* operator new  (std::size_t argA, void* argB) noexcept { \
    return _1_sstd_memory_static_class_basic::operator new(argA,argB); \
    } \
    static inline void* operator new[](std::size_t argA, void* argB) noexcept { \
    return _1_sstd_memory_static_class_basic::operator new[](argA,argB); \
    } \
    static constexpr inline void operator delete(void * argA, void * argB) noexcept { \
    return _1_sstd_memory_static_class_basic::operator delete(argA,argB); \
    } \
    static constexpr inline void operator delete[](void * argA, void * argB) noexcept { \
    return _1_sstd_memory_static_class_basic::operator delete[](argA,argB); \
    } \
    static inline void* operator new (std::size_t argA){ \
    return _1_sstd_memory_static_class_basic::operator new(argA);\
    } \
    static inline void operator delete(void * argA){ \
    return _1_sstd_memory_static_class_basic::operator delete(argA); \
    } \
    static inline void* operator new[](std::size_t argA){ \
    return _1_sstd_memory_static_class_basic::operator new[](argA);\
    } \
    static inline void operator delete[](void * argA){ \
    return _1_sstd_memory_static_class_basic::operator delete[](argA) ;\
    } \
    static inline void* operator new(std::size_t argA, std::align_val_t argB){ \
    return _1_sstd_memory_static_class_basic::operator new(argA,argB);\
    } \
    static inline void operator delete(void* argA, std::align_val_t argB){ \
    return _1_sstd_memory_static_class_basic::operator delete(argA,argB);\
    } \
    static inline void* operator new[](std::size_t argA, std::align_val_t argB){ \
    return _1_sstd_memory_static_class_basic::operator new[](argA,argB);\
    } \
    static inline void operator delete[](void* argA, std::align_val_t argB){ \
    return _1_sstd_memory_static_class_basic::operator delete[](argA,argB);\
    } \
    template<typename T_SSTD_X37627, typename ...T_SSTD_X37627_Args> \
    friend inline T_SSTD_X37627 * ::sstd_new(T_SSTD_X37627_Args && ... args);

#endif 

inline constexpr _1_sstd_memory_static_class_basic::_1_sstd_memory_static_class_basic() noexcept {
}

class _1_SSTD_CORE_EXPORT _1_sstd_memory_dynamic_class_basic {
public:
    virtual ~_1_sstd_memory_dynamic_class_basic();
    inline _1_sstd_memory_dynamic_class_basic() = default;
    inline _1_sstd_memory_dynamic_class_basic(const _1_sstd_memory_dynamic_class_basic &) = default;
    inline _1_sstd_memory_dynamic_class_basic(_1_sstd_memory_dynamic_class_basic &&) = default;
    inline _1_sstd_memory_dynamic_class_basic&operator=(const _1_sstd_memory_dynamic_class_basic &) = default;
    inline _1_sstd_memory_dynamic_class_basic&operator=(_1_sstd_memory_dynamic_class_basic &&) = default;
    _SSTD_MEMORY_1_DFINE
};

#ifndef SSTD_DELETE_COPY_ASSIGN
#define SSTD_DELETE_COPY_ASSIGN(_SSTD_T_) \
_SSTD_T_(const _SSTD_T_ &)=delete; \
_SSTD_T_(_SSTD_T_ &&)=delete; \
_SSTD_T_&operator=(const _SSTD_T_ &)=delete; \
_SSTD_T_&operator=(_SSTD_T_ &&)=delete; \
static_assert(true,"")
#endif





