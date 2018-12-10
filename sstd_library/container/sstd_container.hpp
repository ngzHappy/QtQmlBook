#pragma once

#include "../memory/sstd_memory.hpp"
#include "../runtime/sstd_runtime.hpp"
#include "../allocator/sstd_allocator.hpp"

#include <list>
namespace sstd {
    template<typename T>
    using list = std::list<T,sstd::allocator<T>>;
}/*namespace sstd*/

#include <vector>
namespace sstd {
    template<typename T>
    using vector = std::vector<T, sstd::allocator<T>>;
    template<typename T>
    class Vector : public sstd::vector<T> {
        using super_type_ = sstd::vector<T>;
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
    class Map : public sstd::map<K, V, L> {
        using super_type_ = sstd::map<K, V, L>;
    public:
        template<typename ... Args>
        Map(Args && ... args) :super_type_(std::forward<Args>(args)...) {
        }
    private:
        SSTD_DELETE_COPY_ASSIGN(Map);
        SSTD_DEFINE_STATIC_CLASS(Map);
    };
}/*namespace sstd*/

#include <unordered_map>
namespace sstd {
    template<typename K, typename V,
        typename H = std::hash<K>,
        typename E = std::equal_to<void>
    > using unordered_map = std::unordered_map < K, V, H, E,
        sstd::allocator<std::pair<const K, V> > >;
    template<typename K, typename V,
        typename H = std::hash<K>,
        typename E = std::equal_to<void>
    > class UnorderedMap : public sstd::unordered_map<K, V, H, E> {
        using super_type_ = sstd::unordered_map<K, V, H, E>;
    public:
        template<typename ... Args>
        UnorderedMap(Args && ... args) :super_type_(std::forward<Args>(args)...) {
        }
    private:
        SSTD_DELETE_COPY_ASSIGN(UnorderedMap);
        SSTD_DEFINE_STATIC_CLASS(UnorderedMap);
    };
}/*namespace sstd*/

#include <string>
#include <string_view>
namespace sstd {
    using string = std::basic_string<char, std::char_traits<char>, sstd::allocator<char>>;
    using wstring = std::basic_string<wchar_t, std::char_traits<wchar_t>, sstd::allocator<wchar_t>>;
    using u16string = std::basic_string<char16_t, std::char_traits<char16_t>, sstd::allocator<char16_t>>;
    using u32string = std::basic_string<char32_t, std::char_traits<char32_t>, sstd::allocator<char32_t>>;
}/*namespace sstd*/










