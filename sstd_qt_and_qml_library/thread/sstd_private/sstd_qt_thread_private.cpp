#include "sstd_qt_thread_private.hpp"
#include <sstd_library.hpp>
#include <mutex>
#include <shared_mutex>
#include <array>

namespace {

    class Register final :
        public sstd_intrusive_ptr_basic,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Register){
    public:

        using Key = std::array< QThread *, 1 >;

        class KeyHash {
        public:
            std::size_t operator()(const Key & arg) const {
                return reinterpret_cast<std::size_t>(arg[0]);
            }
        };

        std::shared_mutex mmmMutex;
        sstd::UnorderedMap<Key, sstd::intrusive_ptr<_0_sstd_qt_thread_object>, KeyHash> mmmMap;
        inline void remove(Key arg) {
            std::unique_lock varWriteLock{ mmmMutex };
            mmmMap.erase(arg);
        }
        inline sstd::intrusive_ptr<_0_sstd_qt_thread_object> add(const Key & arg) {
            sstd::intrusive_ptr<_0_sstd_qt_thread_object> varAns;
            {
                std::shared_lock varReadLock{ mmmMutex };
                varAns = raw_find(arg);
                if (varAns) {
                    return std::move(varAns);
                }
            }
            std::unique_lock varWriteLock{ mmmMutex };
            varAns = raw_find(arg);
            if (varAns) {
                return std::move(varAns);
            }
            varAns = sstd_new< _0_sstd_qt_thread_object >();
            mmmMap.emplace(arg, varAns);
            return std::move(varAns);
        }
        inline sstd::intrusive_ptr<_0_sstd_qt_thread_object> find(const Key & arg) {
            std::shared_lock varReadLock{ mmmMutex };
            return raw_find(arg);
        }
    private:
        inline sstd::intrusive_ptr<_0_sstd_qt_thread_object> raw_find(const Key & arg) const {
            auto varPos = std::as_const(mmmMap).find(arg);
            if (varPos != std::as_const(mmmMap).end()) {
                return varPos->second;
            }
            return {};
        }
    public:
        SSTD_END_DEFINE_VIRTUAL_CLASS(Register);
    };

}/*namespace*/

sstd_register_qthread_object_private::sstd_register_qthread_object_private() :
    mmmData{ sstd_new<Register>() } {

}

void sstd_register_qthread_object_private::remove_qthread(QThread * arg) {
    auto varRegister = static_cast<Register *>(mmmData.get());
    return varRegister->remove({ arg });
}

sstd::intrusive_ptr<_0_sstd_qt_thread_object>
sstd_register_qthread_object_private::add_qthread(QThread * arg) {
    auto varRegister = static_cast<Register *>(mmmData.get());
    return varRegister->add({ arg });
}

sstd::intrusive_ptr<_0_sstd_qt_thread_object> sstd_register_qthread_object_private::find_qthread(QThread * arg) {
    auto varRegister = static_cast<Register *>(mmmData.get());
    return varRegister->find({ arg });
}

extern sstd_register_qthread_object_private * instance_sstd_register_qthread_object_private() {
    static auto varAns = sstd_new<sstd_register_qthread_object_private>();
    return varAns;
}
