﻿#pragma once

#include "../memory/sstd_memory.hpp"
#include "../allocator/sstd_allocator.hpp"

#include <vector>
namespace sstd {
    template<typename T>
    using vector = std::vector<T, sstd::allocator<T>>;
    template<typename T>
    class Vector : public vector<T> {
        using super_type_ = vector<T>;
    public:
        template<typename ... Args>
        Vector(Args && ... args) :super_type_(std::forward<Args>(args)...) {
        }
    private:
        SSTD_DELETE_COPY_ASSIGN(Vector);
        SSTD_DEFINE_STATIC_CLASS(Vector);
    };
}/*namespace sstd*/

#include <map>
namespace sstd {
    template<typename K, typename V, typename L = std::less<void>>
    using map = std::map<K, V, L,
        sstd::allocator<std::pair<const K, V>>>;
    template<typename K, typename V, typename L = std::less<void>>
    class Map : public map<K, V, L> {
        using super_type_ = map<K, V, L>;
    public:
        template<typename ... Args>
        Map(Args && ... args) :super_type_(std::forward<Args>(args)...) {
        }
    private:
        SSTD_DELETE_COPY_ASSIGN(Map);
        SSTD_DEFINE_STATIC_CLASS(Map);
    };
}/*namespace sstd*/















