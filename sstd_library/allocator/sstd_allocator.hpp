#pragma once

#include "../memory/sstd_memory.hpp"

namespace sstd {

    inline namespace abi_memory_sstd_private{
        using SSTDMemory = _1_sstd_memory_static_class_basic;
    }/*abi_memory_sstd_private*/

    template<class _Ty>
    class allocator {	// generic allocator for objects of class _Ty
    public:
        static_assert(!std::is_const_v<_Ty>,
                      "The C++ Standard forbids containers of const elements "
                      "because allocator<const T> is ill-formed.");

        using value_type = _Ty;

        typedef _Ty * pointer;
        typedef const _Ty * const_pointer;

        typedef _Ty& reference;
        typedef const _Ty& const_reference;

        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

        template<class _Other>
        struct rebind {	// convert this type to allocator<_Other>
            using other = allocator<_Other>;
        };

        _Ty * address(_Ty& _Val) const noexcept {	// return address of mutable _Val
            return (std::addressof(_Val));
        }

        const _Ty * address(const _Ty& _Val) const noexcept {	// return address of nonmutable _Val
            return (std::addressof(_Val));
        }

        constexpr allocator() noexcept {	// construct default allocator (do nothing)
        }

        constexpr allocator(const allocator&) noexcept = default;
        template<class _Other>
        constexpr allocator(const allocator<_Other>&) noexcept {	// construct from a related allocator (do nothing)
        }

        void deallocate(_Ty * const _Ptr, const size_t _Count) {	// deallocate object at _Ptr
            // no overflow check on the following multiply; we assume _Allocate did that check
            SSTDMemory::operator delete(_Ptr, static_cast<std::align_val_t>(alignof(_Ty)));
            (void)_Count;
        }

        _Ty * allocate(const size_t _Count) {	// allocate array of _Count elements
            return reinterpret_cast<_Ty *>(SSTDMemory::operator new((_Count * sizeof(_Ty)),
                                                                    static_cast<std::align_val_t>(alignof(_Ty))));
        }

        _Ty * allocate(const size_t _Count, const void *) {	// allocate array of _Count elements, ignore hint
            return (this->allocate(_Count));
        }

        template<class _Objty, class... _Types>
        void construct(_Objty * const _Ptr, _Types&&... _Args) {	// construct _Objty(_Types...) at _Ptr
            if constexpr ((std::is_constructible_v < _Objty, _Types&&... > /**/ == false) ||
                          (sizeof...(_Args) == 0)) {
                ::new (const_cast<void *>(static_cast<const volatile void *>(_Ptr)))
                        _Objty{ std::forward<_Types>(_Args)... };
            } else {
                ::new (const_cast<void *>(static_cast<const volatile void *>(_Ptr)))
                        _Objty(std::forward<_Types>(_Args)...);
            }
        }

        template<class _Uty>
        void destroy(_Uty * const _Ptr) {	// destroy object at _Ptr
            _Ptr->~_Uty();
        }

        size_t max_size() const noexcept {	// estimate maximum array size
            return (static_cast<size_t>(-1) / sizeof(_Ty));
        }

        /*msvc*/
        using propagate_on_container_move_assignment = std::true_type;
        using is_always_equal = std::true_type;

    };

    template<>
    class allocator<void> {	// generic allocator for type void
    public:
        using value_type = void;
        using pointer = void *;
        using const_pointer = const void *;

        template<class _Other>
        struct rebind {	// convert this type to an allocator<_Other>
            using other = allocator<_Other>;
        };
    };

    template<class _Ty, class _Other>
    inline bool operator==(const allocator<_Ty>&,
                           const allocator<_Other>&) noexcept {	// test for allocator equality
        return (true);
    }

    template<class _Ty, class _Other>
    inline bool operator!=(const allocator<_Ty>&,
                           const allocator<_Other>&) noexcept {	// test for allocator inequality
        return (false);
    }


}/*namespace sstd*/















