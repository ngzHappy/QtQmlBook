#include "sstd_runtime.hpp"

_1_sstd_runtime_static_basic::_1_sstd_runtime_static_basic(
        bool isDynamic,
        const std::type_info & typeInfo):
    mmmIsDynamic(isDynamic),
    mmmTypeInfo(typeInfo),
    mmmTypeIndex(typeInfo){}

sstd_virtual_basic::~sstd_virtual_basic(){

}







