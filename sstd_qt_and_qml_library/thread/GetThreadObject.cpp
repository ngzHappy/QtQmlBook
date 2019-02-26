#include "GetThreadObject.hpp"
#include <memory>
#include <optional>
#include <cassert>
#include <shared_mutex>
#include <array>

namespace this_file {

    class UserObject :
            public QObjectUserData {
        std::optional<QObject> mmmObject;
    public:
        inline UserObject(QThread *);
        inline QObject * get();
    };

    class GlobalStaticData{
    public:
        const static decltype(QObject::registerUserData()) objectIndex;
        mutable std::array<
        std::shared_mutex ,
        128/*必须是2的整数倍*/ > objectMutexs;
    public:
        inline std::shared_mutex & getMutext(const void *) const ;
    };

    inline GlobalStaticData & getGlobalData();

}/**/


QObject * sstd_get_thread_object(QThread * arg){

    if(arg == nullptr){
        return nullptr;
    }

    auto & var = this_file::getGlobalData();

    QObjectUserData * varUserDataRaw = nullptr;
    auto & varMutex = var.getMutext(arg);

    {/*read ...*/
        std::shared_lock varReadLock{ varMutex };
        varUserDataRaw = arg->userData(var.objectIndex);
    }

    if(!varUserDataRaw) {
        do {/*write ...*/
            std::unique_lock varWriteLock{ varMutex };

            {/*read again ...*/
                varUserDataRaw = arg->userData(var.objectIndex);
                if(varUserDataRaw){
                    break;
                }
            }

            {/*set new value ...*/
                auto varUserData = new this_file::UserObject{arg};
                arg->setUserData(var.objectIndex,varUserData );
                varUserDataRaw = varUserData;
                break;
            }

        }while(false);
    }

    auto varUserData =
            static_cast< this_file::UserObject * >(varUserDataRaw);
    return varUserData->get();

}


namespace this_file {

    inline UserObject::UserObject(QThread * arg){
        mmmObject.emplace();
        mmmObject->moveToThread(arg);
        QObject::connect(arg,&QThread::finished,
                         &mmmObject.value(),
                         [this](){mmmObject.reset();
        },Qt::DirectConnection);
    }

    inline QObject * UserObject::get(){
        assert(mmmObject);
        return &mmmObject.value();
    }

    const decltype(QObject::registerUserData())
    GlobalStaticData::objectIndex = QObject::registerUserData();

    inline GlobalStaticData & getGlobalData(){
        static GlobalStaticData varAns;
        return varAns;
    }

    inline std::shared_mutex & GlobalStaticData::getMutext(const void * arg) const {
        auto varPointer =
             reinterpret_cast<std::uintptr_t>(arg);
        return objectMutexs[
         ((varPointer >> 2)&(objectMutexs.size()-1))];
    }

}/**/


