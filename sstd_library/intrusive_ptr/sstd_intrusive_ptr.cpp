#include "sstd_intrusive_ptr.hpp"


inline std::intptr_t sstd_intrusive_ptr_basic::sstd_get_intrusive_ptr_count() const {
    return mmmCount.load();
}

sstd_intrusive_ptr_basic::~sstd_intrusive_ptr_basic() {
}

sstd_intrusive_ptr_basic::sstd_intrusive_ptr_basic() : mmmCount{ 0 } {
}

void sstd_intrusive_ptr_basic::sstd_intrusive_ptr_add_ref() {
    ++mmmCount;
}

void sstd_intrusive_ptr_basic::sstd_intrusive_ptr_release() {
    const auto varCount = --mmmCount;
    if (varCount < 1) {
        delete this;
    }
}











