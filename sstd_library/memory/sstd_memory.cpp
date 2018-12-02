#include "sstd_memory.hpp"

_1_sstd_memory_dynamic_class_basic::~_1_sstd_memory_dynamic_class_basic(){

}

void* _1_sstd_memory_static_class_basic::operator new (std::size_t count) {
    return ::operator new(count);
}

void _1_sstd_memory_static_class_basic::operator delete(void * ptr) {
    return ::operator delete(ptr);
}

void* _1_sstd_memory_static_class_basic::operator new[](std::size_t count) {
    return ::operator new(count);
}

void _1_sstd_memory_static_class_basic::operator delete[](void * ptr) {
    return ::operator delete(ptr);
}

void* _1_sstd_memory_static_class_basic::operator new(std::size_t count, std::align_val_t al) {
    return ::operator new(count, al);
}

void _1_sstd_memory_static_class_basic::operator delete(void* ptr, std::align_val_t al) {
    return ::operator delete(ptr, al);
}

void* _1_sstd_memory_static_class_basic::operator new[](std::size_t count, std::align_val_t al) {
    return ::operator new(count, al);
}

void _1_sstd_memory_static_class_basic::operator delete[](void* ptr, std::align_val_t al) {
    return ::operator delete(ptr, al);
}









