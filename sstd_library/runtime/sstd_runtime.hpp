#pragma once

#include <cassert>
#include <typeinfo>
#include <typeindex>
#include <functional>
#include "../global/sstd_basic_library_global.hpp"
#include "../memory/sstd_memory.hpp"

class sstd_type_index;
class _1_SSTD_CORE_EXPORT sstd_virtual_basic {
public:
    virtual ~sstd_virtual_basic();
    virtual bool sstd_is_polymorphic() const noexcept = 0;
    virtual const std::type_info & sstd_get_type_info() const noexcept = 0;
    virtual const std::type_index & sstd_get_type_index() const noexcept = 0;
    virtual void * sstd_get_this_void() const noexcept = 0;
    virtual const sstd_type_index & sstd_get_sstd_type_index() const noexcept = 0;
};

class _1_SSTD_CORE_EXPORT _1_sstd_runtime_static_basic :
    public _1_sstd_memory_static_class_basic {
public:
    _1_sstd_runtime_static_basic(bool, const std::type_info &);
    _1_sstd_runtime_static_basic(const std::type_info &);
    inline _1_sstd_runtime_static_basic() = delete;
    inline _1_sstd_runtime_static_basic&operator=(_1_sstd_runtime_static_basic &&) = delete;
    inline _1_sstd_runtime_static_basic&operator=(const _1_sstd_runtime_static_basic &) = delete;
    inline _1_sstd_runtime_static_basic(_1_sstd_runtime_static_basic &&) = delete;
    inline _1_sstd_runtime_static_basic(const _1_sstd_runtime_static_basic &) = default;
    const std::type_info & mmmTypeInfo;
    const std::type_index mmmTypeIndex;
    const std::size_t mmmHashCode;
    const _1_sstd_runtime_static_basic *mmmUnique;
    unsigned char mmmIsDynamic/*0 not dynamic,1 is dynamic 2 unknow*/;
};

template<typename Tt>
class _2_sstd_runtime_static_basic :
    public _1_sstd_memory_static_class_basic {
    using sstd_super = _1_sstd_memory_static_class_basic;
public:
    inline static bool sstd_is_polymorphic() noexcept;
    inline static const std::type_info & sstd_get_type_info() noexcept;
    inline static const std::type_index & sstd_get_type_index() noexcept;
    inline static const sstd_type_index & sstd_get_sstd_type_index() noexcept;
    const static _1_sstd_runtime_static_basic mmmData;
};

class _1_SSTD_CORE_EXPORT sstd_type_index :
    public _1_sstd_memory_static_class_basic {
public:
    sstd_type_index(const _1_sstd_runtime_static_basic *);
    inline sstd_type_index(const sstd_type_index &) = default;
    inline sstd_type_index(sstd_type_index &&) = default;
    inline sstd_type_index&operator=(const sstd_type_index &) = default;
    inline sstd_type_index&operator=(sstd_type_index &&) = default;
    inline const char * name() const {
        return mmmData->mmmTypeIndex.name();
    }
    inline std::size_t hash_code() const {
        return mmmData->mmmHashCode;
    }
    inline bool sstd_is_polymorphic() const {
        return (mmmData->mmmIsDynamic == static_cast<unsigned char>(true));
    }
    inline friend bool operator<(const sstd_type_index &l, const sstd_type_index &r) {
        if (l.mmmData == r.mmmData) {
            return false;
        }
        if (l.hash_code() < r.hash_code()) {
            return true;
        }
        if (r.hash_code() < l.hash_code()) {
            return false;
        }
        return l.mmmData->mmmTypeIndex < r.mmmData->mmmTypeIndex;
    }
    inline friend bool operator>(const sstd_type_index &l, const sstd_type_index &r) {
        return r < l;
    }
    inline friend bool operator==(const sstd_type_index &l, const sstd_type_index &r) {
        if (l.mmmData == r.mmmData) {
            return true;
        }
        if (l.hash_code() != r.hash_code()) {
            return false;
        }
        return l.mmmData->mmmTypeIndex == r.mmmData->mmmTypeIndex;
    }
    inline friend bool operator!=(const sstd_type_index &l, const sstd_type_index &r) {
        return !(r == l);
    }
    inline friend bool operator<=(const sstd_type_index &l, const sstd_type_index &r) {
        if (l.mmmData == r.mmmData) {
            return true;
        }
        if (l.hash_code() < r.hash_code()) {
            return true;
        }
        if (r.hash_code() < l.hash_code()) {
            return false;
        }
        return l.mmmData->mmmTypeIndex <= r.mmmData->mmmTypeIndex;
    }
    inline friend bool operator>=(const sstd_type_index &l, const sstd_type_index &r) {
        return r <= l;
    }
protected:
    const _1_sstd_runtime_static_basic * mmmData;
};

namespace std {
    template<>
    class hash<sstd_type_index> {
    public:
        inline std::size_t operator()(const sstd_type_index & a) const {
            return a.hash_code();
        }
    };
}/*std*/

template<typename T>
sstd_type_index sstd_type_id() {
    using Tt = std::remove_reference_t<T>;
    using Ttt = std::remove_cv_t<Tt>;
    const static _2_sstd_runtime_static_basic<Ttt> var;
    return sstd_type_index(&var.mmmData);
}

namespace abi_sstd_get_sstd_index_private {

    class get_sstd_type_index_bypointer {
    };
    class get_sstd_type_index_byvalue {
    };
    class get_sstd_type_index_none {
    };

    template<typename T, typename = get_sstd_type_index_none >
    class get_sstd_type_index {
    public:
        template<typename U>
        inline static sstd_type_index get_index(const U & arg) {
            using Tt = std::remove_reference_t<T>;
            using Ttt = std::remove_cv_t<Tt>;
            _1_sstd_runtime_static_basic varAns{ std::is_polymorphic_v<Ttt>,
                typeid(arg) };
            return sstd_type_index(varAns.mmmUnique);
        }
    };

    template<typename T >
    class get_sstd_type_index<T, get_sstd_type_index_byvalue> {
    public:
        template<typename U>
        inline static sstd_type_index get_index(const U & arg) {
            return arg.sstd_get_sstd_type_index();
        }
    };

    template<typename T >
    class get_sstd_type_index<T, get_sstd_type_index_bypointer> {
    public:
        template<typename U>
        inline static sstd_type_index get_index(const U & arg) {
            return arg->sstd_get_sstd_type_index();
        }
    };

    template<typename T, typename = void >
    class is_by_value : public std::false_type {
    };

    template<typename T>
    class is_by_value<T, std::void_t<
        decltype(std::declval<T>().sstd_get_sstd_type_index())
    > > : public std::true_type {
    };

    template<typename T, typename = void >
    class is_by_pointer : public std::false_type {
    };

    template<typename T>
    class is_by_pointer<T, std::void_t<
        decltype(std::declval<T>()->sstd_get_sstd_type_index())
    > > : public std::true_type {
    };

}/****/

template<typename T>
inline sstd_type_index sstd_type_id(const T & arg) {
    using Tt = std::remove_reference_t<T>;
    using Ttt = std::remove_cv_t<Tt>;
    if constexpr (abi_sstd_get_sstd_index_private::is_by_value<Ttt>::value) {
        using G = abi_sstd_get_sstd_index_private::get_sstd_type_index<Ttt,
            abi_sstd_get_sstd_index_private::get_sstd_type_index_byvalue>;
        return G::get_index(arg);
    } else if constexpr (abi_sstd_get_sstd_index_private::is_by_pointer<Ttt>::value) {
        using G = abi_sstd_get_sstd_index_private::get_sstd_type_index<Ttt,
            abi_sstd_get_sstd_index_private::get_sstd_type_index_bypointer>;
        return G::get_index(arg);
    } else {
        using G = abi_sstd_get_sstd_index_private::get_sstd_type_index<Ttt,
            abi_sstd_get_sstd_index_private::get_sstd_type_index_none>;
        return G::get_index(arg);
    }
}

template<typename Tt,
    bool = std::is_polymorphic_v<
    std::remove_cv_t <
    std::remove_reference_t<Tt> > > >
    class _3_sstd_runtime_basic :
    public _1_sstd_memory_static_class_basic {
    public:
        using sstd_this_type = std::remove_cv_t< std::remove_reference_t<Tt> >;
        static inline bool sstd_is_polymorphic() noexcept {
            static_assert (false == std::is_polymorphic_v<sstd_this_type>, "");
            const static _2_sstd_runtime_static_basic<sstd_this_type> var;
            return var.sstd_is_polymorphic();
        }
        static inline const std::type_info & sstd_get_type_info() noexcept {
            const static _2_sstd_runtime_static_basic<sstd_this_type> var;
            return var.sstd_get_type_info();
        }
        static inline const std::type_index & sstd_get_type_index() noexcept {
            const static _2_sstd_runtime_static_basic<sstd_this_type> var;
            return var.sstd_get_type_index();
        }
        static inline const sstd_type_index & sstd_get_sstd_type_index() {
            const static _2_sstd_runtime_static_basic<sstd_this_type> var;
            return var.sstd_get_sstd_type_index();
        }
};

template<typename Tt>
class _3_sstd_runtime_basic<Tt, true> :
    public _1_sstd_memory_dynamic_class_basic,
    public virtual sstd_virtual_basic {
protected:
    using sstd_this_type = std::remove_cv_t< std::remove_reference_t<Tt> >;
    inline static bool _sstd_is_polymorphic() noexcept {
        static_assert (true == std::is_polymorphic_v<sstd_this_type>, "");
        const static _2_sstd_runtime_static_basic<sstd_this_type> var;
        return var.sstd_is_polymorphic();
    }
    inline static const std::type_info & _sstd_get_type_info() noexcept {
        const static _2_sstd_runtime_static_basic<sstd_this_type> var;
        return var.sstd_get_type_info();
    }
    inline static const std::type_index & _sstd_get_type_index() noexcept {
        const static _2_sstd_runtime_static_basic<sstd_this_type> var;
        return var.sstd_get_type_index();
    }
    inline const static sstd_type_index & _sstd_get_sstd_type_index() noexcept {
        const static _2_sstd_runtime_static_basic<sstd_this_type> var;
        return var.sstd_get_sstd_type_index();
    }
    inline void * _sstd_get_this_void() const noexcept {
        return static_cast<sstd_this_type *>(
            const_cast<_3_sstd_runtime_basic *>(this));
    }
};

template<typename T,
    bool IsVirtual = std::is_polymorphic_v<
    std::remove_cv_t <
    std::remove_reference_t<T> > > >
    class sstd_runtime_basic : public _3_sstd_runtime_basic<T, IsVirtual> {
    private:
        using sstd_super_ = _3_sstd_runtime_basic<T, IsVirtual>;
    public:
        using sstd_this_type = typename sstd_super_::sstd_this_type;
};

#ifndef SSTD_BEGIN_DEFINE_VIRTUAL_CLASS
#define SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_SSTD_T_) \
    private sstd_runtime_basic<_SSTD_T_ , true>
/**************************************************/
#endif

#ifndef _1_SSTD_END_DEFINE_CLASS
#define _1_SSTD_END_DEFINE_CLASS(_SSTD_B_,_SSTD_T_) \
    private : \
    using _sstd_this_type_ = sstd_runtime_basic<_SSTD_T_ , _SSTD_B_> ; \
    public : \
    using sstd_this_type = typename _sstd_this_type_::sstd_this_type ; \
    static constexpr inline void* operator new  (std::size_t argA, void* argB) noexcept { \
    return _sstd_this_type_::operator new(argA,argB); \
    } \
    static constexpr inline void* operator new[](std::size_t argA, void* argB) noexcept { \
    return _sstd_this_type_::operator new[](argA,argB); \
    } \
    static constexpr inline void operator delete(void * argA, void * argB) noexcept { \
    return _sstd_this_type_::operator delete(argA,argB); \
    } \
    static constexpr inline void operator delete[](void * argA, void * argB) noexcept { \
    return _sstd_this_type_::operator delete[](argA,argB); \
    } \
    static inline void* operator new (std::size_t argA){ \
    return _sstd_this_type_::operator new(argA);\
    } \
    static inline void operator delete(void * argA){ \
    return _sstd_this_type_::operator delete(argA); \
    } \
    static inline void* operator new[](std::size_t argA){ \
    return _sstd_this_type_::operator new[](argA);\
    } \
    static inline void operator delete[](void * argA){ \
    return _sstd_this_type_::operator delete[](argA) ;\
    } \
    static inline void* operator new(std::size_t argA, std::align_val_t argB){ \
    return _sstd_this_type_::operator new(argA,argB);\
    } \
    static inline void operator delete(void* argA, std::align_val_t argB){ \
    return _sstd_this_type_::operator delete(argA,argB);\
    } \
    static inline void* operator new[](std::size_t argA, std::align_val_t argB){ \
    return _sstd_this_type_::operator new[](argA,argB);\
    } \
    static inline void operator delete[](void* argA, std::align_val_t argB){ \
    return _sstd_this_type_:: operator delete[](argA,argB);\
    } 
/**************************************************/
#endif

#ifndef SSTD_END_DEFINE_VIRTUAL_CLASS
#define SSTD_END_DEFINE_VIRTUAL_CLASS(_SSTD_T_) \
    _1_SSTD_END_DEFINE_CLASS(true,_SSTD_T_) \
    public : \
    inline bool sstd_is_polymorphic() const noexcept override { \
    return _sstd_this_type_::_sstd_is_polymorphic(); \
    }\
    inline const std::type_info & sstd_get_type_info()const noexcept override { \
    return _sstd_this_type_::_sstd_get_type_info(); \
    } \
    inline const std::type_index & sstd_get_type_index()const noexcept override { \
    return _sstd_this_type_::_sstd_get_type_index(); \
    } \
    void * sstd_get_this_void() const noexcept override { \
    return _sstd_this_type_::_sstd_get_this_void(); \
    } \
    const sstd_type_index & sstd_get_sstd_type_index() const noexcept override{ \
    return _sstd_this_type_::_sstd_get_sstd_type_index(); \
    } \
    template<typename , bool > friend class ::sstd_runtime_basic; \
    template<typename , bool > friend class ::_3_sstd_runtime_basic; \
static_assert(true,"")
/**************************************************/
#endif

#ifndef SSTD_DEFINE_STATIC_CLASS
#define SSTD_DEFINE_STATIC_CLASS(_SSTD_T_) \
    _1_SSTD_END_DEFINE_CLASS(false,_SSTD_T_) \
    public : \
    inline static bool sstd_is_polymorphic() noexcept { \
    return _sstd_this_type_::sstd_is_polymorphic(); \
    } \
    inline static const std::type_info & sstd_get_type_info() noexcept { \
    return _sstd_this_type_::sstd_get_type_info(); \
    } \
    inline static const std::type_index & sstd_get_type_index() noexcept { \
    return _sstd_this_type_::sstd_get_type_index(); \
    } \
    inline constexpr void * sstd_get_this_void() const noexcept { \
    return const_cast<sstd_this_type *>(this); \
    } \
    static inline const sstd_type_index & sstd_get_sstd_type_index() noexcept { \
             return _sstd_this_type_::sstd_get_sstd_type_index(); \
    } \
static_assert(true,"")
/**************************************************/
#endif

/*detail ...*/

template<typename Tt>
const _1_sstd_runtime_static_basic
_2_sstd_runtime_static_basic<Tt>::mmmData{
    std::is_polymorphic_v<Tt>,
            typeid(Tt)
};

template<typename Tt>
inline bool _2_sstd_runtime_static_basic<Tt>::sstd_is_polymorphic() noexcept {
    return mmmData.mmmIsDynamic == static_cast<unsigned char>(true);
}

template<typename Tt>
inline const std::type_info & _2_sstd_runtime_static_basic<Tt>::sstd_get_type_info() noexcept {
    return mmmData.mmmTypeInfo;
}

template<typename Tt>
inline const std::type_index & _2_sstd_runtime_static_basic<Tt>::sstd_get_type_index() noexcept {
    return mmmData.mmmTypeIndex;
}

template<typename Tt>
inline const sstd_type_index & _2_sstd_runtime_static_basic<Tt>::sstd_get_sstd_type_index() noexcept {
    static const sstd_type_index varAns{ &mmmData };
    return varAns;
}


