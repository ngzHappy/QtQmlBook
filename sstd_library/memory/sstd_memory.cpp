#include "sstd_memory.hpp"

#ifdef _0_SSTD_HAS_JE_MALLLOC
extern "C"{
extern void *je_malloc(size_t size);
extern void je_free(void *);
extern void *je_aligned_alloc(size_t alignment, size_t size) ;
}
#endif

#ifdef _0_SSTD_HAS_TC_MALLOC
#include <gperftools/tcmalloc.h>
#endif

namespace  {
    inline void * auto_malloc(std::size_t n){
#ifdef _0_SSTD_HAS_TC_MALLOC
        return tc_malloc(n);
#else
#ifdef _0_SSTD_HAS_JE_MALLLOC
    return je_malloc(n);
#else
    return ::operator new(n);
#endif
#endif
    }
    inline void auto_free(void *ptr){
#ifdef _0_SSTD_HAS_TC_MALLOC
        return tc_free(ptr);
#else
#if defined( _0_SSTD_HAS_JE_MALLLOC )
        return je_free(ptr);
#else
        ::operator delete(ptr);
#endif
#endif
    }
    inline void * auto_malloc(std::size_t c, std::align_val_t a){
#ifdef _0_SSTD_HAS_TC_MALLOC
        return tc_memalign( static_cast<std::size_t>(a) , c );
#else
#ifdef _0_SSTD_HAS_JE_MALLLOC
    return je_aligned_alloc(static_cast<size_t>(a),c);
#else
        return ::operator new(c, a);
#endif
#endif
    }
    inline void auto_free(void* ptr, std::align_val_t al){
#ifdef _0_SSTD_HAS_TC_MALLOC
        return tc_free(ptr);
        (void)al;
#else
#ifdef _0_SSTD_HAS_JE_MALLLOC
        return je_free(ptr);
        (void)(al);
#else
        return ::operator delete(ptr, al);
#endif
#endif
    }
}/*namespace*/

_1_sstd_memory_dynamic_class_basic::~_1_sstd_memory_dynamic_class_basic(){

}

void* _1_sstd_memory_static_class_basic::operator new (std::size_t count) {
    return ::auto_malloc(count);
}

void _1_sstd_memory_static_class_basic::operator delete(void * ptr) {
    return ::auto_free(ptr);
}

void* _1_sstd_memory_static_class_basic::operator new[](std::size_t count) {
    return ::auto_malloc(count);
}

void _1_sstd_memory_static_class_basic::operator delete[](void * ptr) {
    return ::auto_free(ptr);
}

void* _1_sstd_memory_static_class_basic::operator new(std::size_t count, std::align_val_t al) {
    return ::auto_malloc(count, al);
}

void _1_sstd_memory_static_class_basic::operator delete(void* ptr, std::align_val_t al) {
    return ::auto_free(ptr, al);
}

void* _1_sstd_memory_static_class_basic::operator new[](std::size_t count, std::align_val_t al) {
    return ::auto_malloc(count, al);
}

void _1_sstd_memory_static_class_basic::operator delete[](void* ptr, std::align_val_t al) {
    return ::auto_free(ptr, al);
}









