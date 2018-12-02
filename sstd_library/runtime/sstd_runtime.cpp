#include "sstd_runtime.hpp"
#include <set>
#include <map>
#include <shared_mutex>
#include <optional>

namespace {

    template<typename T,typename V>
    using this_map=std::map<T,V>;

    class RuntimeStaticBasicItem{
    public:
        RuntimeStaticBasicItem(std::unique_ptr<_1_sstd_runtime_static_basic> &&a)
            :mmmIndex(std::move(a)){}
        std::unique_ptr<_1_sstd_runtime_static_basic> mmmIndex;
    };

     class RuntimeStaticBasic {
     public:
        this_map< sstd_type_index , std::unique_ptr<RuntimeStaticBasicItem>  > mmmTypeSet;
        std::shared_mutex mmmTypeSetMutex;
        const _1_sstd_runtime_static_basic * insert(const _1_sstd_runtime_static_basic & arg){
            sstd_type_index varIndex{&arg};
            {
                std::shared_lock varReadLock{ mmmTypeSetMutex };
                auto varPos = std::as_const( mmmTypeSet ).find( varIndex );
                if(varPos != std::as_const( mmmTypeSet).end() ){
                    return varPos->second->mmmIndex.get() ;
                }
            }
            std::unique_lock varWriteLock{ mmmTypeSetMutex };
            {
                auto varPos = std::as_const( mmmTypeSet ).find(varIndex );
                if(varPos != std::as_const( mmmTypeSet).end() ){
                    return varPos->second->mmmIndex.get() ;
                }
            }
            auto varIndexBasic = std::make_unique<_1_sstd_runtime_static_basic>(arg);
            auto varAns = varIndexBasic.get();
            varIndexBasic->mmmUnique=varAns;
            mmmTypeSet.emplace(sstd_type_index {varAns},
                               std::make_unique<RuntimeStaticBasicItem>(
                                   std::move(varIndexBasic)));
            return varAns;
        }
     };

     inline RuntimeStaticBasic & getRuntimeStaticBasic(){
         static RuntimeStaticBasic varAns;
         return varAns;
     }

}/**********/

_1_sstd_runtime_static_basic::_1_sstd_runtime_static_basic(
        bool isDynamic,
        const std::type_info & typeInfo):
    _1_sstd_runtime_static_basic(typeInfo) {
    this->mmmIsDynamic=isDynamic;
    this->mmmUnique = getRuntimeStaticBasic().insert(*this);
}

_1_sstd_runtime_static_basic::_1_sstd_runtime_static_basic(
        const std::type_info & typeInfo) :
    mmmTypeInfo(typeInfo),
    mmmTypeIndex(typeInfo),
    mmmHashCode(typeInfo.hash_code()) {
    this->mmmIsDynamic=2;
    this->mmmUnique=nullptr;
}

sstd_virtual_basic::~sstd_virtual_basic(){

}

sstd_type_index::sstd_type_index(const _1_sstd_runtime_static_basic *a)
    :mmmData(a){}





