﻿#pragma once

#include <memory>
#if __has_include(<memory_resource>)
#include <memory_resource>
#else
#define _0_DO_NOT_HAVE_MEMORY_RESOURCE
#endif
#include "../global/sstd_basic_library_global.hpp"

class _1_SSTD_CORE_EXPORT _1_sstd_memory_static_class_basic{
public:
    inline constexpr _1_sstd_memory_static_class_basic()=default;
    inline ~_1_sstd_memory_static_class_basic()=default;
    inline constexpr _1_sstd_memory_static_class_basic(const _1_sstd_memory_static_class_basic &)=default;
    inline constexpr _1_sstd_memory_static_class_basic(_1_sstd_memory_static_class_basic &&)=default;
    inline constexpr _1_sstd_memory_static_class_basic&operator=(const _1_sstd_memory_static_class_basic &)=default;
    inline constexpr _1_sstd_memory_static_class_basic&operator=(_1_sstd_memory_static_class_basic &&)=default;
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
};

class _1_SSTD_CORE_EXPORT _1_sstd_memory_dynamic_class_basic :
        public _1_sstd_memory_static_class_basic {
public:
    virtual ~_1_sstd_memory_dynamic_class_basic();
    inline _1_sstd_memory_dynamic_class_basic()=default;
    inline _1_sstd_memory_dynamic_class_basic(const _1_sstd_memory_dynamic_class_basic &)=default;
    inline _1_sstd_memory_dynamic_class_basic(_1_sstd_memory_dynamic_class_basic &&)=default;
    inline _1_sstd_memory_dynamic_class_basic&operator=(const _1_sstd_memory_dynamic_class_basic &)=default;
    inline _1_sstd_memory_dynamic_class_basic&operator=(_1_sstd_memory_dynamic_class_basic &&)=default;
};







