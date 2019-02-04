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
    void sstd_intrusive_ptr_add_ref();
    void sstd_intrusive_ptr_release();
    inline std::intptr_t sstd_intrusive_ptr_count() const ;
    inline friend void intrusive_ptr_release(const sstd_intrusive_ptr_basic * a) {
        const_cast<sstd_intrusive_ptr_basic *>(a)
            ->sstd_intrusive_ptr_release();
    }
    inline friend void intrusive_ptr_add_ref(const sstd_intrusive_ptr_basic * a) {
        const_cast<sstd_intrusive_ptr_basic *>(a)
            ->sstd_intrusive_ptr_add_ref();
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


template<typename T,typename ... Args>
inline sstd::intrusive_ptr<T> sstd_make_intrusive_ptr(Args && ... args) {
    using U = std::remove_cv_t< std::remove_reference_t<T> >;
    using ans_type = sstd::intrusive_ptr<T>;
    return ans_type{ sstd_new<U>(std::forward<Args>(args)...) };
}
