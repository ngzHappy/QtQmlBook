#include "sstd_runtime.hpp"
#include "../container/sstd_container.hpp"
#include <shared_mutex>
#include <optional>

namespace {

    template<typename T, typename V>
    using this_map = sstd::map<T, V>;

    class RuntimeStaticBasicItem {
    public:
        RuntimeStaticBasicItem(std::unique_ptr<_1_sstd_runtime_static_basic> &&a)
            :mmmIndex(std::move(a)) {
        }
        std::unique_ptr<_1_sstd_runtime_static_basic> mmmIndex;
        SSTD_DELETE_COPY_ASSIGN(RuntimeStaticBasicItem);
        SSTD_DEFINE_STATIC_CLASS(RuntimeStaticBasicItem);
    };

    class RuntimeStaticBasic {
        SSTD_DELETE_COPY_ASSIGN(RuntimeStaticBasic);
        SSTD_DEFINE_STATIC_CLASS(RuntimeStaticBasic);
    public:
        this_map< sstd_type_index, std::unique_ptr<RuntimeStaticBasicItem>  > mmmTypeSet;
        std::shared_mutex mmmTypeSetMutex;

        inline const _1_sstd_runtime_static_basic * find(const _1_sstd_runtime_static_basic & arg) {
            sstd_type_index varIndex{ &arg };
            std::shared_lock varReadLock{ mmmTypeSetMutex };
            auto varPos = std::as_const(mmmTypeSet).find(varIndex);
            if (varPos != std::as_const(mmmTypeSet).end()) {
                return varPos->second->mmmIndex.get();
            }
            return nullptr;
        }

        inline const _1_sstd_runtime_static_basic * insert(const _1_sstd_runtime_static_basic & arg) {
            sstd_type_index varIndex{ &arg };
            {
                std::shared_lock varReadLock{ mmmTypeSetMutex };
                auto varPos = std::as_const(mmmTypeSet).find(varIndex);
                if (varPos != std::as_const(mmmTypeSet).end()) {
                    return varPos->second->mmmIndex.get();
                }
            }
            std::unique_lock varWriteLock{ mmmTypeSetMutex };
            {
                auto varPos = std::as_const(mmmTypeSet).find(varIndex);
                if (varPos != std::as_const(mmmTypeSet).end()) {
                    return varPos->second->mmmIndex.get();
                }
            }
            auto varIndexBasic = std::make_unique<_1_sstd_runtime_static_basic>(arg);
            auto varAns = varIndexBasic.get();
            varIndexBasic->mmmUnique = varAns;
            mmmTypeSet.emplace(sstd_type_index{ varAns },
                std::make_unique<RuntimeStaticBasicItem>(
                    std::move(varIndexBasic)));
            return varAns;
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
    }
}

sstd_virtual_basic::~sstd_virtual_basic() {

}

sstd_type_index::sstd_type_index(const _1_sstd_runtime_static_basic *a)
    :mmmData(a->mmmUnique ? a->mmmUnique : a) {
}





