#include "sstd_library.hpp"

namespace {

    static _1_sstd_runtime_static_basic nullptr_id{ false,typeid(nullptr) };

    class NamedData :
        public _wrap_data_sstd_virtual_basic {
    public:
        sstd::string name;
        std::pair<void *, sstd_type_index > data_index;
        NamedData() : data_index(nullptr, &nullptr_id) {
        }
    private:
        _SSTD_MEMORY_1_DFINE
    };

    class RuntimeData :
        public _wrap_data_sstd_virtual_basic {
        sstd::forward_list< std::unique_ptr< _wrap_data_sstd_virtual_basic > > mmmItems;
        sstd::map< std::string_view, _named_wrap_data_sstd_virtual_basic * > mmmNamedItems;
    public:

        RuntimeData() {
        }

        ~RuntimeData() {
            while (false == mmmItems.empty()) {
                mmmItems.pop_front();
            }
        }

        void append(_wrap_data_sstd_virtual_basic * arg) try {
            mmmItems.emplace_front(arg);
        } catch (...) {
            delete arg;
            throw;
        }

        void append(std::string_view name, _named_wrap_data_sstd_virtual_basic * arg) {
            append(arg);
            name = arg->setName(name);
            mmmNamedItems.emplace(name, arg);
        }

        const std::pair<void *, sstd_type_index> * find(const std::string_view & arg) {
            auto varPos = std::as_const( mmmNamedItems ).find(arg);
            if (varPos == std::as_const( mmmNamedItems ).end()) {
                return nullptr;
            }
            return varPos->second->getData();
        }

    private:
        _SSTD_MEMORY_1_DFINE
    };

}/**/

_wrap_data_sstd_virtual_basic::~_wrap_data_sstd_virtual_basic() {

}

const std::pair<void *, sstd_type_index> * _data_sstd_virtual_basic::_find(std::string_view arg) const {
    auto varItem = static_cast<RuntimeData *>(mmmData);
    return varItem->find(arg);
}

void _data_sstd_virtual_basic::_append(
    _wrap_data_sstd_virtual_basic * arg) {
    auto varItem = static_cast<RuntimeData *>(mmmData);
    varItem->append(arg);
}

void _data_sstd_virtual_basic::_append(
    std::string_view name,
    _named_wrap_data_sstd_virtual_basic * value) {
    auto varItem = static_cast<RuntimeData *>(mmmData);
    varItem->append(name, value);
}

std::string_view _named_wrap_data_sstd_virtual_basic::setName(
    const std::string_view & arg) {
    auto varItem = static_cast<NamedData *>(mmmItem);
    varItem->name = arg;
    return varItem->name;
}

_named_wrap_data_sstd_virtual_basic::_named_wrap_data_sstd_virtual_basic()
    :mmmItem(sstd_new<NamedData>()) {
}

_named_wrap_data_sstd_virtual_basic::~_named_wrap_data_sstd_virtual_basic() {
    delete mmmItem;
}

void _named_wrap_data_sstd_virtual_basic::setData(const std::pair<void *, sstd_type_index > & arg) {
    auto varItem = static_cast<NamedData *>(mmmItem);
    varItem->data_index = arg;
}

const std::pair<void *, sstd_type_index > * _named_wrap_data_sstd_virtual_basic::getData() const {
    auto varItem = static_cast<const NamedData *>(mmmItem);
    return &(varItem->data_index);
}

_data_sstd_virtual_basic::_data_sstd_virtual_basic() :
    mmmData(sstd_new<RuntimeData>()) {

}

_data_sstd_virtual_basic::~_data_sstd_virtual_basic() {
    delete mmmData;
}



