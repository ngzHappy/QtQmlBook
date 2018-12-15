#pragma once

#include <mutex>
#include <atomic>
#include <cassert>
#include <typeinfo>
#include <typeindex>
#include <functional>
#include "../global/sstd_basic_library_global.hpp"
#include "../memory/sstd_memory.hpp"
#include "../new/sstd_new.hpp"

#if __has_include(<tr2/type_traits>)
#include <tr2/type_traits>
#define _0_SSTD_HAS_GET_BASES (1u)
#endif

class sstd_type_index;

/* dynamic cast at runtime */
_1_SSTD_CORE_EXPORT void * _sstd_runtime_dynamic_cast(void * /* dynamic_cast< void * > */,
    const sstd_type_index & /* typeid(value) */,
    const sstd_type_index & /* out put id */);
/* register dynamic cast function */
_1_SSTD_CORE_EXPORT void _sstd_add_runtime_dynamic_cast(const sstd_type_index & /* from ... */,
    const sstd_type_index & /* to ... */,
    void*(*)(void *) /* function ... */);
/* never used */
_1_SSTD_CORE_EXPORT void _sstd_add_runtime_dynamic_cast(const void *);


class _1_SSTD_CORE_EXPORT _wrap_data_sstd_virtual_basic {
public:
    virtual ~_wrap_data_sstd_virtual_basic();
    _SSTD_MEMORY_1_DFINE
};

class _1_SSTD_CORE_EXPORT _named_wrap_data_sstd_virtual_basic :
    public _wrap_data_sstd_virtual_basic {
    _wrap_data_sstd_virtual_basic * const mmmItem;
public:
    virtual ~_named_wrap_data_sstd_virtual_basic();
    _named_wrap_data_sstd_virtual_basic();
    std::string_view setName(const std::string_view &);
    void setData(const std::pair<void *, sstd_type_index > &);
    const std::pair<void *, sstd_type_index > * getData() const;
    _SSTD_MEMORY_1_DFINE
};

class sstd_virtual_basic;
class _1_SSTD_CORE_EXPORT sstd_virtual_basic_state {
    std::shared_ptr<void> mmm_sstd_data;
    friend class sstd_virtual_basic;
public:
    void lock();
    void unlock();
    bool isDestoryed() const;
    sstd_virtual_basic * getPointer() const;
private:
    sstd_virtual_basic_state(sstd_virtual_basic *);
    sstd_virtual_basic_state(decltype(nullptr));
    _SSTD_MEMORY_1_DFINE
};

class _1_SSTD_CORE_EXPORT _data_sstd_virtual_basic {
    _wrap_data_sstd_virtual_basic * const mmmData;
public:
    virtual ~_data_sstd_virtual_basic();
    _data_sstd_virtual_basic();
    SSTD_DELETE_COPY_ASSIGN(_data_sstd_virtual_basic);
public:
    template<typename T, typename ... Args>
    inline T * sstd_create_data_in_this_class(Args && ...);
    template<typename T, typename ... Args >
    inline T * sstd_create_named_data_in_this_class(std::string_view, Args && ...);
    template<typename T>
    inline T * sstd_find_named_data_in_this_class(std::string_view) const;
private:
    void _append(_wrap_data_sstd_virtual_basic *);
    void _append(std::string_view, _named_wrap_data_sstd_virtual_basic *);
    const std::pair<void *, sstd_type_index> * _find(std::string_view) const;
    _SSTD_MEMORY_1_DFINE
};

class _1_SSTD_CORE_EXPORT sstd_virtual_basic :
    public _1_sstd_memory_dynamic_class_basic,
    public _data_sstd_virtual_basic {
    std::atomic< sstd_virtual_basic_state * > mmm_this_state;
    sstd_virtual_basic_state ppp_construct_this_state();
    void ppp_destruct_this_state();
    SSTD_DELETE_COPY_ASSIGN(sstd_virtual_basic);
public:
    virtual ~sstd_virtual_basic();
    sstd_virtual_basic();
    virtual bool sstd_is_polymorphic() const noexcept = 0;
    virtual const std::type_info & sstd_get_type_info() const noexcept = 0;
    virtual const std::type_index & sstd_get_type_index() const noexcept = 0;
    virtual void * sstd_get_this_void() const noexcept = 0;
    virtual const sstd_type_index & sstd_get_sstd_type_index() const noexcept = 0;
    sstd_virtual_basic_state sstd_get_class_state() const;
    template<typename T, typename ... Args>
    inline T * sstd_create_data_in_this_class_thread_safe(Args && ...);
    template<typename T, typename ... Args >
    inline T * sstd_create_named_data_in_this_class_thread_safe(std::string_view, Args && ...);
    template<typename T>
    inline T * sstd_find_named_data_in_this_class_thread_safe(std::string_view) const;
    _SSTD_MEMORY_1_DFINE
};

class _1_SSTD_CORE_EXPORT _1_sstd_runtime_static_basic {
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
    void * mmmCached{ nullptr };
    unsigned char mmmIsDynamic/*0 not dynamic,1 is dynamic 2 unknow*/;
    _SSTD_MEMORY_1_DFINE
};

template<typename T>
class _2_1_sstd_runtime_static_basic {
public:
    inline _2_1_sstd_runtime_static_basic();
    _SSTD_MEMORY_1_DFINE
};

template<typename Tt>
class _2_sstd_runtime_static_basic {
public:
    inline static bool sstd_is_polymorphic() noexcept;
    inline static const std::type_info & sstd_get_type_info() noexcept;
    inline static const std::type_index & sstd_get_type_index() noexcept;
    inline static const sstd_type_index & sstd_get_sstd_type_index() noexcept;
    const static _1_sstd_runtime_static_basic mmmData;
    inline _2_sstd_runtime_static_basic();
private:
    const static _2_1_sstd_runtime_static_basic<Tt> mmmDataRegisterBases;
    _SSTD_MEMORY_1_DFINE
};

class _1_SSTD_CORE_EXPORT sstd_type_index {
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
    inline operator const _1_sstd_runtime_static_basic *() const {
        return mmmData;
    }
    inline const std::type_info & sstd_get_type_info() const noexcept {
        return mmmData->mmmTypeInfo;
    }
    inline const std::type_index & sstd_get_type_index() const noexcept {
        return mmmData->mmmTypeIndex;
    }
protected:
    const _1_sstd_runtime_static_basic * mmmData;
    _SSTD_MEMORY_1_DFINE
};

namespace std {
    template<>
    class hash<sstd_type_index> {
    public:
        inline std::size_t operator()(const sstd_type_index & a) const {
            return a.hash_code();
        }
        _SSTD_MEMORY_1_DFINE
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
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T >
    class get_sstd_type_index<T, get_sstd_type_index_byvalue> {
    public:
        template<typename U>
        inline static sstd_type_index get_index(const U & arg) {
            return arg.sstd_get_sstd_type_index();
        }
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T >
    class get_sstd_type_index<T, get_sstd_type_index_bypointer> {
    public:
        template<typename U>
        inline static sstd_type_index get_index(const U & arg) {
            return arg->sstd_get_sstd_type_index();
        }
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T, typename = void >
    class is_by_value : public std::false_type {
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T>
    class is_by_value<T, std::void_t<
        decltype(std::declval<T>().sstd_get_sstd_type_index())
    > > : public std::true_type {
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T, typename = void >
    class is_by_pointer : public std::false_type {
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T>
    class is_by_pointer<T, std::void_t<
        decltype(std::declval<T>()->sstd_get_sstd_type_index())
    > > : public std::true_type {
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T, typename = void >
    class get_void_helper : public std::false_type {
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T>
    class get_void_helper<T, std::void_t<
        decltype(std::declval<T>()->sstd_get_this_void())
    > > : public std::true_type {
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T, bool = std::is_polymorphic_v<T>>
    class get_void_pointer {
    public:
        template<typename U>
        static inline const void * get_data(const U * arg) {
            if constexpr (get_void_helper<const U *>::value) {
                return arg->sstd_get_this_void();
            } else {
                return dynamic_cast<const void *>(arg);
            }
        }
        _SSTD_MEMORY_1_DFINE
    };

    template<typename T >
    class get_void_pointer<T, false> {
    public:
        template<typename U>
        static inline const void * get_data(const U * arg) {
            if constexpr (get_void_helper<const U *>::value) {
                return arg->sstd_get_this_void();
            } else {
                return arg;
            }
        }
        _SSTD_MEMORY_1_DFINE
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

template<typename T>
inline std::pair<void *, sstd_type_index> sstd_class_runtime_meta_data(const T * arg) {
    using T1 = std::remove_cv_t< std::remove_reference_t<T> >;
    using G = abi_sstd_get_sstd_index_private::get_void_pointer<T1>;
    return { const_cast<void *>(G::get_data(arg)) , sstd_type_id(*arg) };
}

inline void * sstd_runtime_cast(const std::pair<void *, sstd_type_index> & argInputMeta,
    const sstd_type_index & argOutPutType) {
    return _sstd_runtime_dynamic_cast(argInputMeta.first,
        argInputMeta.second,
        argOutPutType);
}

template<typename T, typename I>
inline T * sstd_runtime_cast(const I * arg) {
    return reinterpret_cast<T *>(sstd_runtime_cast(
        sstd_class_runtime_meta_data(arg),
        sstd_type_id<T>()));
}

template<typename Tt,
    bool = std::is_polymorphic_v<
    std::remove_cv_t <
    std::remove_reference_t<Tt> > > >
    class _3_sstd_runtime_basic {
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
        _SSTD_MEMORY_1_DFINE
};

template<typename Tt>
class _3_sstd_runtime_basic<Tt, true> {
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
    virtual ~_3_sstd_runtime_basic() = default;
    _SSTD_MEMORY_1_DFINE
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
        _SSTD_MEMORY_1_DFINE
};

#ifndef SSTD_BEGIN_DEFINE_VIRTUAL_CLASS
#define SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(_SSTD_T_) \
    private sstd_runtime_basic<_SSTD_T_ , true> , \
    public virtual sstd_virtual_basic
/**************************************************/
#endif

#ifndef _1_SSTD_END_DEFINE_CLASS
#define _1_SSTD_END_DEFINE_CLASS(_SSTD_B_,_SSTD_T_) \
    private : \
    using _sstd_this_type_ = sstd_runtime_basic<_SSTD_T_ , _SSTD_B_> ; \
    public : \
    using sstd_this_type = typename _sstd_this_type_::sstd_this_type ; \
    _SSTD_MEMORY_1_DFINE
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

class _1_SSTD_CORE_EXPORT sstd_function_stack :
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(sstd_function_stack) {
public:
    sstd_function_stack();
    virtual ~sstd_function_stack();
private:
    SSTD_DELETE_COPY_ASSIGN(sstd_function_stack);
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_function_stack);
};


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

template<typename Tt>
const _2_1_sstd_runtime_static_basic<Tt> _2_sstd_runtime_static_basic<Tt>::mmmDataRegisterBases;

namespace abi_sstd_private_2_sstd_runtime_static_basic {

    template<typename From, typename To>
    void add_once() {
        using From_ = std::remove_cv_t< std::remove_reference_t< From > >;
        using To_ = std::remove_cv_t< std::remove_reference_t< To > >;
        if constexpr (std::is_convertible_v<From_ *, To_ *>) {
            auto varFromTypePrivate =
                _1_sstd_runtime_static_basic(std::is_polymorphic_v<From_>, typeid(From_));
            auto varToTypePrivate =
                _1_sstd_runtime_static_basic(std::is_polymorphic_v<To_>, typeid(To_));
            auto varFromType = sstd_type_id(&varFromTypePrivate);
            auto varToType = sstd_type_id(&varToTypePrivate);
            _sstd_add_runtime_dynamic_cast(
                varFromType,
                varToType,
                [](void * arg)->void * {
                return static_cast<To_ *>(
                    reinterpret_cast<From_ *>(arg));
            });
        }
    }

    template<typename To,
        template<typename ...> class Wrap,
        typename ... Parents >
        void construct_add_upcast_functions(const Wrap<Parents...> &) {
        add_once<To, To>();
        if constexpr (sizeof...(Parents)) {
            (add_once<To, Parents>(), ...);
        }
    }

    template<typename ...>
    class empty {
    };


}/**/
template<typename Tt>
inline _2_1_sstd_runtime_static_basic<Tt>::_2_1_sstd_runtime_static_basic() {
    using CleanType = std::remove_cv_t< std::remove_reference_t< Tt > >;
#if defined(_0_SSTD_HAS_GET_BASES)
    using bases_ = typename std::tr2::bases<CleanType>::type;
    abi_sstd_private_2_sstd_runtime_static_basic
        ::construct_add_upcast_functions<CleanType>(bases_{});
#else
    using bases_ = abi_sstd_private_2_sstd_runtime_static_basic::empty<>;
    abi_sstd_private_2_sstd_runtime_static_basic
        ::construct_add_upcast_functions<CleanType>(bases_{});
#endif
}

template<typename T>
inline _2_sstd_runtime_static_basic<T>::_2_sstd_runtime_static_basic() {
    _sstd_add_runtime_dynamic_cast(&mmmDataRegisterBases);
}

namespace _1_private_sstd_class_wrap_2 {

    template<typename T, typename B>
    class _t_wrap_data_sstd_virtual_basic : public B {
        T mmmElement;
    public:
        inline T * getElement() const {
            return const_cast<T *>(&mmmElement);
        }
        _t_wrap_data_sstd_virtual_basic() : mmmElement{} {
        }
        template<typename A0, typename ... Args,
            typename = std::enable_if_t< true == std::is_constructible_v<T, A0&&, Args && ...> >
        > _t_wrap_data_sstd_virtual_basic(A0 && a0, Args && ... args) :
            mmmElement(std::forward<A0>(a0), std::forward<Args>(args)...) {
        }
        template<typename A0, typename ... Args,
            typename = void **********,
            typename = std::enable_if_t< false == std::is_constructible_v<T, A0&&, Args && ...> >
        > _t_wrap_data_sstd_virtual_basic(A0 && a0, Args && ... args) :
            mmmElement{ std::forward<A0>(a0), std::forward<Args>(args)... } {
        }
    private:
        _SSTD_MEMORY_1_DFINE
    };

}/****/

template<typename T, typename ... Args>
inline T * _data_sstd_virtual_basic::sstd_create_data_in_this_class(Args && ... args) {
    static_assert(false == std::is_reference_v<T>);
    static_assert(false == std::is_array_v<T>);
    using T1 = std::remove_cv_t< std::remove_reference_t<T> >;
    using R = _1_private_sstd_class_wrap_2::_t_wrap_data_sstd_virtual_basic<
        T1, _wrap_data_sstd_virtual_basic>;
    auto varAns = sstd_new<R>(std::forward<Args>(args)...);
    auto varElement = varAns->getElement();
    this->_append(varAns);
    return varElement;
}

template<typename T, typename ... Args >
inline T * _data_sstd_virtual_basic::sstd_create_named_data_in_this_class(
    std::string_view name,
    Args && ... args) {
    static_assert(false == std::is_reference_v<T>);
    static_assert(false == std::is_array_v<T>);
    using T1 = std::remove_cv_t< std::remove_reference_t<T> >;
    using R = _1_private_sstd_class_wrap_2::_t_wrap_data_sstd_virtual_basic<
        T1, _named_wrap_data_sstd_virtual_basic>;
    {
        auto varRunTime = this->_find(name);
        if (varRunTime) {
            return reinterpret_cast<T *>(
                sstd_runtime_cast(*varRunTime, sstd_type_id<T1>()));
        }
    }
    auto varAns = sstd_new<R>(std::forward<Args>(args)...);
    auto varElement = varAns->getElement();
    varAns->setData({ varElement,sstd_type_id<T1>() });
    this->_append(name, varAns);
    return varElement;
}

template<typename T>
inline T * _data_sstd_virtual_basic::sstd_find_named_data_in_this_class(std::string_view arg) const {
    static_assert(false == std::is_reference_v<T>);
    static_assert(false == std::is_array_v<T>);
    using T1 = std::remove_cv_t< std::remove_reference_t<T> >;
    auto varRunTime = this->_find(arg);
    if (varRunTime == nullptr) {
        return nullptr;
    }
    return reinterpret_cast<T *>(
        sstd_runtime_cast(*varRunTime, sstd_type_id<T1>()));
}

template<typename T, typename ... Args>
inline T * sstd_virtual_basic::sstd_create_data_in_this_class_thread_safe(Args && ... args) {

    auto varState = this->sstd_get_class_state();
    std::unique_lock varLock{ varState };
    if (varState.isDestoryed()) {
        return nullptr;
    }

    return
        this->sstd_create_data_in_this_class<T>(
            std::forward<Args>(args)...);
}
template<typename T, typename ... Args >
inline T * sstd_virtual_basic::sstd_create_named_data_in_this_class_thread_safe(std::string_view a, Args && ... b) {

    auto varState = this->sstd_get_class_state();
    std::unique_lock varLock{ varState };
    if (varState.isDestoryed()) {
        return nullptr;
    }

    return
        this->sstd_create_named_data_in_this_class<T>(
            a, std::forward<Args>(b)...);
}
template<typename T>
inline T * sstd_virtual_basic::sstd_find_named_data_in_this_class_thread_safe(std::string_view a) const {

    auto varState = this->sstd_get_class_state();
    std::unique_lock varLock{ varState };
    if (varState.isDestoryed()) {
        return nullptr;
    }

    return
        this->sstd_find_named_data_in_this_class<T>(
            a);
}

