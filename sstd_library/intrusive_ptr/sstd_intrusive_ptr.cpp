#include "sstd_intrusive_ptr.hpp"

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











