#if defined(_MSC_VER)

#include <typeindex>
#include <typeinfo>
#include <rttidata.h>

namespace sstd {

    extern void * private_runtime_dynamic_cast(
        void * argInput/*dynamic_cast<void *>*/,
        const std::type_info * argInputType/*type_id(remove_cvr)*/,
        const std::type_info * argOutputType/*type_id(remove_cvr)*/) {
        /*
        https://github.com/scottslacksmith/__RTDynamicCast/blob/master/main.cpp
        */
        return __RTDynamicCast(
            argInput, 0,
            const_cast<std::type_info *>(argInputType),
            const_cast<std::type_info *>(argOutputType),
            false);
    }

}/*namespace sstd*/

#endif
