#pragma once

#include <sstd_library.hpp>
#include "../global/sstd_qt_and_qml_global.hpp"
#include <QtCore/qeventloop.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qrunnable.h>

namespace sstd {

    class EXPORT_SSTD_QT_AND_QML_LIBRARY RunEvent :
        public QEvent,
        public QRunnable,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(RunEvent) {
    public:
        RunEvent();
    public:
        static QEvent::Type  getEventID();
        template<typename Tx>
        inline static RunEvent * createRunEvent(Tx&&);
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(RunEvent);
    };

    namespace _private_api_function{
        template<typename T>
        class _RunEvent : 
            public sstd::RunEvent ,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_RunEvent<T>){
            T mmmFunction;
        public:

            template<typename U>
            inline _RunEvent(U && arg) : 
                mmmFunction(std::forward<U>(arg)) {
            }

            inline void run() override {
                mmmFunction();
            }

        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(_RunEvent);
        };
    }/*****/

    template<typename Tx>
    inline static RunEvent * RunEvent::createRunEvent(Tx&& argFunction) {
        using T = std::remove_cv_t<
            std::remove_reference_t<Tx> >;
        return sstd_new< _private_api_function::_RunEvent<T> >(
            std::forward<Tx>(argFunction) );
    }

}/*namespace sstd*/


