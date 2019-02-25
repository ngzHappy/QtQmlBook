#include "GetThreadObject.hpp"
#include <memory>
#include <optional>
#include <cassert>
#include <shared_mutex>

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
        std::shared_mutex objectMutex;
    };

    inline GlobalStaticData & getGlobalData();

}/**/


QObject * sstd_get_thread_object(QThread * arg){

    if(arg == nullptr){
        return nullptr;
    }

    auto & var = this_file::getGlobalData();
    QObjectUserData * varUserDataRaw = nullptr;

    {/*read ...*/
        std::shared_lock varReadLock{ var.objectMutex };
        varUserDataRaw = arg->userData(var.objectIndex);
    }

    if(!varUserDataRaw) {
        do {/*write ...*/
            std::unique_lock varWriteLock{ var.objectMutex };

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

}/**/


