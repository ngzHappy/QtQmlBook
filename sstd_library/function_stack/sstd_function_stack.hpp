#pragma once

#include "../runtime/sstd_runtime.hpp"
#include "../intrusive_ptr/sstd_intrusive_ptr.hpp"

class _1_SSTD_CORE_EXPORT sstd_function_stack :
    public virtual sstd_intrusive_ptr_basic,
    SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(sstd_function_stack) {
public:
    sstd_function_stack();
    virtual ~sstd_function_stack();
private:
    SSTD_DELETE_COPY_ASSIGN(sstd_function_stack);
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_function_stack);
};




