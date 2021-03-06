﻿#include "sstd_runtime.hpp"
#include "../container/sstd_container.hpp"
#include "../new/sstd_new.hpp"
#include <shared_mutex>
#include <optional>
#include <variant>
#include "../log/sstd_log.hpp"
#include <string_view>
#include <cassert>

using namespace std::string_view_literals;

namespace {
    class data_sstd_virtual_basic_state {
    public:
        std::recursive_mutex mutex;
        bool isDestory{ false };
        sstd_virtual_basic * pointer{ nullptr };
        _1_SSTD_MEMORY_1_DEFINE
    };
}

void sstd_virtual_basic_state::lock() {
    if (mmm_sstd_data) {
        auto varData =
            std::static_pointer_cast<data_sstd_virtual_basic_state>(mmm_sstd_data);
        varData->mutex.lock();
    }
}

void sstd_virtual_basic_state::unlock() {
    if (mmm_sstd_data) {
        auto varData =
            std::static_pointer_cast<data_sstd_virtual_basic_state>(mmm_sstd_data);
        varData->mutex.unlock();
    }
}

bool sstd_virtual_basic_state::isDestoryed() const {
    if (mmm_sstd_data) {
        auto varData =
            std::static_pointer_cast<data_sstd_virtual_basic_state>(mmm_sstd_data);
        std::unique_lock varLock{ varData->mutex };
        return varData->isDestory;
    }
    return true;
}

sstd_virtual_basic * sstd_virtual_basic_state::getPointer() const {
    if (mmm_sstd_data) {
        auto varData =
            std::static_pointer_cast<data_sstd_virtual_basic_state>(mmm_sstd_data);
        std::unique_lock varLock{ varData->mutex };
        return varData->pointer;
    }
    return nullptr;
}

sstd_virtual_basic_state::sstd_virtual_basic_state(sstd_virtual_basic * arg) {
    auto varAns = sstd_make_shared<data_sstd_virtual_basic_state>();
    varAns->pointer = arg;
    mmm_sstd_data = std::move(varAns);
}

sstd_virtual_basic_state::sstd_virtual_basic_state(decltype(nullptr)) {
}

namespace {

    inline auto emptyCast(void *)->void * {
        return nullptr;
    }

    template<typename T, typename V>
    class this_map : public sstd::unordered_map<T, V> {
        using super_type_ = sstd::unordered_map<T, V>;
    public:
        this_map() : super_type_(1024 * 128) {
        }
    };

    typedef void*(*raw_type_cast_function)(void *);
    using type_cast_function = std::variant<
        decltype(nullptr),
        std::ptrdiff_t,
        raw_type_cast_function >;

    const static constexpr type_cast_function globalEmptyCast{ emptyCast };

    class private_type_cast_map : public sstd::map<
        sstd_type_index,
        type_cast_function > {
    public:
        private_type_cast_map() {
        }
    };

    class type_cast_map {
        private_type_cast_map mmmCastMap;
        std::shared_mutex mmmMutex;
    public:

        inline type_cast_function find(const sstd_type_index & arg) {
            std::shared_lock varReadLock{ mmmMutex };
            auto varPos = std::as_const(mmmCastMap).find(arg);
            if (std::as_const(mmmCastMap).end() != varPos) {
                return varPos->second;
            }
            return nullptr;
        }

        /*如果当前值是empty cast，新值不是empty cast，更新当前值*/
        inline void insert(const sstd_type_index & arg, const type_cast_function & argv) {
            const type_cast_function & v{ argv };
            {
                std::shared_lock varReadLock{ mmmMutex };
                /********************************************************/
#if defined(_DEBUG)
                if (std::as_const(mmmCastMap).size() > 1024) {
                    sstd_log("bad_design"sv);
                }
#endif
                /********************************************************/
                auto varPos = std::as_const(mmmCastMap).find(arg);
                if (std::as_const(mmmCastMap).end() != varPos) {/*找到当前值*/
                    if (varPos->second != globalEmptyCast) {/*当存储前值不是empty cast*/
                        return;
                    }
                    if (v == globalEmptyCast) {/*当前值和要插入的值都是empty cast*/
                        return;
                    }
                    /*当前值是empty，要插入的值不是empty，更新当前值*/
                }
            }
            std::unique_lock varWriteLock{ mmmMutex };
            {
                auto varPos = mmmCastMap.find(arg);
                if (std::as_const(mmmCastMap).end() != varPos) {/*找到当前值*/
                    if (varPos->second != globalEmptyCast) {/*当存储前值不是empty cast*/
                        return;
                    }
                    if (v == globalEmptyCast) {/*当前值和要插入的值都是empty cast*/
                        return;
                    }
                    /*当前值是empty，要插入的值不是empty，更新当前值*/
                    varPos->second = v;
                    return;
                }
            }
            mmmCastMap.emplace(arg, v);
        }

    };

    class type_cast_item {
        void * a;
    public:
        type_cast_item(void * v) :a(v) {
        }
        void * operator()(const decltype(nullptr) &) {
            return nullptr;
        }
        void * operator()(const raw_type_cast_function & f) {
            if (a) {
                return f(a);
            }
            return nullptr;
        }
        void * operator()(const std::ptrdiff_t & f) {
            if (a&&f) {
                return reinterpret_cast<std::uint8_t *>(a) + f;
            }
            return a;
        }
    };

    class RuntimeStaticBasicItem {
    public:
        RuntimeStaticBasicItem(std::unique_ptr<_1_sstd_runtime_static_basic> &&a)
            :mmmIndex(std::move(a)) {
        }
        std::unique_ptr<_1_sstd_runtime_static_basic> mmmIndex;
        type_cast_map mmmTypeCastMap;
        operator const _1_sstd_runtime_static_basic *() const {
            return mmmIndex.get();
        }
    public:
        SSTD_DELETE_COPY_ASSIGN(RuntimeStaticBasicItem);
        SSTD_DEFINE_STATIC_CLASS(RuntimeStaticBasicItem);
    };

    template<std::size_t >
    class private_type_utility;

    template<>
    class private_type_utility<0> {
    public:
        using type = const _1_sstd_runtime_static_basic *;
    };

    template<>
    class private_type_utility<1> {
    public:
        using type = RuntimeStaticBasicItem & ;
    };

    class RuntimeStaticBasic {
        SSTD_DELETE_COPY_ASSIGN(RuntimeStaticBasic);
        SSTD_DEFINE_STATIC_CLASS(RuntimeStaticBasic);
    private:
        this_map< sstd_type_index, std::unique_ptr<RuntimeStaticBasicItem>  > mmmTypeSet;
        std::shared_mutex mmmTypeSetMutex;
    public:

        inline const _1_sstd_runtime_static_basic * find(const _1_sstd_runtime_static_basic & arg) {
            sstd_type_index varIndex{ &arg };
            std::shared_lock varReadLock{ mmmTypeSetMutex };
            auto varPos = std::as_const(mmmTypeSet).find(varIndex);
            if (varPos != std::as_const(mmmTypeSet).end()) {
                return varPos->second->mmmIndex.get();
            }
            return nullptr;
        }

        inline RuntimeStaticBasicItem & insert(const _1_sstd_runtime_static_basic * arg) {
            return insert<1>(*arg);
        }

        template<std::size_t N = 0>
        inline typename private_type_utility<N>::type insert(const _1_sstd_runtime_static_basic & arg) {
            sstd_type_index varIndex{ &arg };
            {
                std::shared_lock varReadLock{ mmmTypeSetMutex };
                auto varPos = std::as_const(mmmTypeSet).find(varIndex);
                if (varPos != std::as_const(mmmTypeSet).end()) {
                    if constexpr (N == 0) {
                        return varPos->second->mmmIndex.get();
                    } else {
                        return *(varPos->second);
                    }
                }
            }
            std::unique_lock varWriteLock{ mmmTypeSetMutex };
            {
                auto varPos = std::as_const(mmmTypeSet).find(varIndex);
                if (varPos != std::as_const(mmmTypeSet).end()) {
                    if constexpr (N == 0) {
                        return varPos->second->mmmIndex.get();
                    } else {
                        return *(varPos->second);
                    }
                }
            }
            auto varIndexBasic = std::make_unique<_1_sstd_runtime_static_basic>(arg);
            auto varAns = varIndexBasic.get();
            varIndexBasic->mmmUnique = varAns;
            auto varPos = mmmTypeSet.emplace(sstd_type_index{ varAns },
                std::make_unique<RuntimeStaticBasicItem>(
                    std::move(varIndexBasic)));
            varAns->mmmCached = varPos.first->second.get();
            if constexpr (N == 0) {
                return varAns;
            } else {
                return *(varPos.first->second);
            }
        }

        RuntimeStaticBasic() = default;

    };

    inline RuntimeStaticBasic & getRuntimeStaticBasic() {
        static auto * varAns = new RuntimeStaticBasic/*never delete*/;
        return *varAns;
    }

}/**********/

_1_sstd_runtime_static_basic::_1_sstd_runtime_static_basic(
    bool isDynamic,
    const std::type_info & typeInfo) :
    _1_sstd_runtime_static_basic(typeInfo) {
    if (this->mmmUnique == nullptr) {
        this->mmmIsDynamic = isDynamic;
        this->mmmUnique = getRuntimeStaticBasic().insert(*this);
        this->mmmCached = this->mmmUnique->mmmCached;
    }
}

_1_sstd_runtime_static_basic::_1_sstd_runtime_static_basic(
    const std::type_info & typeInfo) :
    mmmTypeInfo(typeInfo),
    mmmTypeIndex(typeInfo),
    mmmHashCode(typeInfo.hash_code()) {
    this->mmmUnique = nullptr;
    this->mmmIsDynamic = 2;
    this->mmmUnique = getRuntimeStaticBasic().find(*this);
    if (this->mmmUnique) {
        this->mmmIsDynamic = this->mmmUnique->mmmIsDynamic;
        this->mmmCached = this->mmmUnique->mmmCached;
    }
}

sstd_virtual_basic_state sstd_virtual_basic::ppp_construct_this_state() {
    if (mmm_this_state) {
        return *(mmm_this_state.load());
    }
    std::unique_ptr varNewState =
        sstd_make_unique<sstd_virtual_basic_state>(this);
    sstd_virtual_basic_state * varOldState = nullptr;
    if (mmm_this_state.compare_exchange_strong(varOldState,
        varNewState.get())) {/*由当前线程设置值...*/
        return *varNewState.release();
    }
    /*由其他线程设置值*/
    return *(varOldState);
}

/*
此函数只应当被执行一遍...
此函数的设计是过安全的...
*/
void sstd_virtual_basic::ppp_destruct_this_state() {
    static sstd_virtual_basic_state varNull{ nullptr };
    sstd_virtual_basic_state * varOldState = nullptr;

    while(!mmm_this_state.
        compare_exchange_weak(varOldState, &varNull));
    assert(mmm_this_state.load()== &varNull);

    if (varOldState == nullptr) {
        return;
    }

#if defined(_DEBUG)
    if (varOldState == &varNull) {
        sstd_log("thre is may be a memory leak!"sv);
        return;
    }
#endif

    auto varData = varOldState->mmm_sstd_data;
    auto varTypedData =
        std::static_pointer_cast<data_sstd_virtual_basic_state>(varData);

    std::unique_lock varLock{ varTypedData->mutex };
#if defined(_DEBUG)
    if (varTypedData) {
#endif
        varTypedData->isDestory = true;
        varTypedData->pointer = nullptr;
#if defined(_DEBUG)
    }
#endif
    delete varOldState;
}

sstd_virtual_basic_state sstd_virtual_basic::sstd_get_class_state() const {
    return const_cast<sstd_virtual_basic*>(this)
        ->ppp_construct_this_state();
}

sstd_virtual_basic::sstd_virtual_basic() : mmm_this_state(nullptr) {
}

sstd_virtual_basic::~sstd_virtual_basic() {
    ppp_destruct_this_state();
}

sstd_type_index::sstd_type_index(const _1_sstd_runtime_static_basic *a)
    :mmmData(a->mmmUnique ? a->mmmUnique : a) {
}

/*runtime dynamic cast*/
namespace sstd {
    extern void * private_runtime_dynamic_cast(
        void * argInput/*dynamic_cast<void *>*/,
        const std::type_info * argInputType/*type_id(remove_cvr)*/,
        const std::type_info * argOutputType/*type_id(remove_cvr)*/);
}/*namespace sstd*/

_1_SSTD_CORE_EXPORT void * _sstd_runtime_dynamic_cast(
    void * arg,
    const sstd_type_index & argType,
    const sstd_type_index & outPutType) {

    if (argType == outPutType) {
        return arg;
    }

    if (arg == nullptr) {
        return nullptr;
    }

    RuntimeStaticBasicItem* varInformation = nullptr;
    {
        auto varCached = argType.operator const _1_sstd_runtime_static_basic *()->mmmCached;
        if (varCached) {
            varInformation = reinterpret_cast<RuntimeStaticBasicItem*>(varCached);
        } else {
            auto & varCast = getRuntimeStaticBasic();
            varInformation = &varCast.insert(argType);
        }
    }

    auto varCastFunction = varInformation->mmmTypeCastMap.find(outPutType);
    if (0 != varCastFunction.index()) {
        type_cast_item varCastItem{ arg };
        return std::visit(varCastItem, varCastFunction);
    }

    /*在已经注册的函数中未找到转型方法，
    并且不包含虚函数，
    转型失败*/
    if (false == argType.sstd_is_polymorphic()) {
        return nullptr;
    }

    auto varAns = sstd::private_runtime_dynamic_cast(arg,
        &argType.sstd_get_type_info(),
        &outPutType.sstd_get_type_info());

    /*转型成功，注册此转型函数*/
    if (varAns) {
        varInformation->mmmTypeCastMap.insert(outPutType,
            reinterpret_cast<std::uint8_t *>(varAns) -
            reinterpret_cast<std::uint8_t *>(arg));
        return varAns;
    } else {
        /*注册转型失败*/
        varInformation->mmmTypeCastMap.insert(outPutType, globalEmptyCast);
    }

    /*转型失败*/
    return nullptr;
}

_1_SSTD_CORE_EXPORT void _sstd_add_runtime_dynamic_cast(const sstd_type_index & fromType/* from ... */,
    const sstd_type_index & toType/* to ... */,
    void*(*function)(void *) /* function ... */) {

    if (function == nullptr) {
        return;
    }

    RuntimeStaticBasicItem * varInformation = nullptr;
    {
        void * varCatched = fromType.operator const _1_sstd_runtime_static_basic *()->mmmCached;
        if (varCatched) {
            varInformation = reinterpret_cast<RuntimeStaticBasicItem*>(varCatched);
        } else {
            auto & varCast = getRuntimeStaticBasic();
            varInformation = &varCast.insert(fromType);
        }
    }
    varInformation->mmmTypeCastMap.insert(toType, function);
}

/*禁止编译器优化*/
_1_SSTD_CORE_EXPORT void _sstd_add_runtime_dynamic_cast(const void *) {
}

#if defined(_DEBUG)
#include <cstdlib>
static inline void static_test() {

    /*this function will never called*/

    class AClass {
    private:
        SSTD_DEFINE_STATIC_CLASS(AClass);
    } aClass;

    class BClass : SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(BClass) {
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(BClass);
    } bClass;

    assert(false);
    assert(sizeof(AClass) == sizeof(BClass));
    ::atexit(&static_test);
    (void)aClass;
    (void)bClass;

}
#endif
