#pragma once

#include "../global/sstd_basic_library_global.hpp"
#include "../memory/sstd_memory.hpp"
#include "../runtime/sstd_runtime.hpp"
#include <boost/intrusive_ptr.hpp>
#include <atomic>

class _1_SSTD_CORE_EXPORT sstd_intrusive_ptr_basic :
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(sstd_intrusive_ptr_basic) {
    std::atomic< std::intptr_t > mmmCount;
public:
    virtual ~sstd_intrusive_ptr_basic();
    sstd_intrusive_ptr_basic();
    inline std::intptr_t sstd_get_intrusive_ptr_count() const;
    void sstd_intrusive_ptr_add_ref();
    void sstd_intrusive_ptr_release();
    inline std::intptr_t sstd_intrusive_ptr_count() const ;
    inline friend void intrusive_ptr_release(sstd_intrusive_ptr_basic * a) {
        a->sstd_intrusive_ptr_release();
    }
    inline friend void intrusive_ptr_add_ref(sstd_intrusive_ptr_basic * a) {
        a->sstd_intrusive_ptr_add_ref();
    }
    SSTD_END_DEFINE_VIRTUAL_CLASS(sstd_intrusive_ptr_basic);
};

inline std::intptr_t sstd_intrusive_ptr_basic::sstd_intrusive_ptr_count() const {
    return mmmCount.load();
}

namespace sstd {
    template<typename T>
    using intrusive_ptr = boost::intrusive_ptr<T> ;
}/*sstd*/












