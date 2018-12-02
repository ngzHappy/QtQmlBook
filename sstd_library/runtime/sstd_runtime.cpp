#include "sstd_runtime.hpp"

_1_sstd_runtime_static_basic::_1_sstd_runtime_static_basic(
        bool isDynamic,
        const std::type_info & typeInfo):
    mmmIsDynamic(isDynamic),
    mmmTypeInfo(typeInfo),
    mmmTypeIndex(typeInfo),
    mmmHashCode(typeInfo.hash_code()){}

sstd_virtual_basic::~sstd_virtual_basic(){

}

sstd_type_index::sstd_type_index(const _1_sstd_runtime_static_basic *a)
    :mmmData(a){}





