#pragma once

#include <sstd_library.hpp>
#include "../global/sstd_qt_and_qml_global.hpp"
#include <QtCore/qeventloop.h>
#include <QtCore/qcoreevent.h>
#include <QtCore/qrunnable.h>
#include <QtCore/qobject.h>
#include <QtCore/qpointer.h>

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

    namespace _private_api_function {
        class MultiRunEventData {
        public:
            QPointer< QObject > target;
            int priority = Qt::NormalEventPriority;
            sstd::list< std::unique_ptr< RunEvent > > events;
        };
    }/**/

    class EXPORT_SSTD_QT_AND_QML_LIBRARY MultiRunEvent :
        public RunEvent,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(MultiRunEvent) {
    protected:
        std::unique_ptr<_private_api_function::MultiRunEventData> mmmData;
    public:
        MultiRunEvent(std::unique_ptr<_private_api_function::MultiRunEventData> &&);
        void append(RunEvent *);
        void start();
        virtual bool doNotCallNext() ;
        virtual std::unique_ptr<MultiRunEvent> clone() = 0;
        template<typename Tx>
        inline static MultiRunEvent * createMultiRunEvent(
            QPointer<QObject> argTarget,
            int argPriority ,
            Tx&& argDoNotRunNext );
        inline static MultiRunEvent * createMultiRunEvent(
            QPointer<QObject> argTarget) {
            return createMultiRunEvent(
                argTarget, 
                Qt::NormalEventPriority, 
                []() ->bool {return false; });
        }
        inline static MultiRunEvent * createMultiRunEvent(
            QPointer<QObject> argTarget,
            int argP) {
            return createMultiRunEvent(
                argTarget,
                argP,
                []() ->bool {return false; });
        }
        template<typename Tx>
        inline void appendFunction(Tx &&);
    private:
        void run() override;
    private:
        SSTD_END_DEFINE_VIRTUAL_CLASS(MultiRunEvent);
    };

    namespace _private_api_function {

        template<typename T>
        class _RunEvent :
            public sstd::RunEvent,
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

        template<typename T>
        class _MultiRunEvent :
            public sstd::MultiRunEvent,
            SSTD_BEGIN_DEFINE_VIRTUAL_CLASS_OVERRIDE(_MultiRunEvent<T>){
            T mmmDoNotCallNext;
        public:
            inline bool doNotCallNext() override {
                return mmmDoNotCallNext();
            }
        public:
            template<typename A, typename B>
            inline _MultiRunEvent(A && a, B && b) :
                MultiRunEvent(std::forward<A>(a)),
                mmmDoNotCallNext(std::forward<B>(b)) {
            }
            inline std::unique_ptr<MultiRunEvent> clone() override {
                return sstd_make_unique<_MultiRunEvent>(
                    std::move(this->mmmData),
                    std::move(mmmDoNotCallNext));
            }
        private:
            SSTD_END_DEFINE_VIRTUAL_CLASS(_MultiRunEvent);
        };

    }/*****/

    template<typename Tx>
    inline RunEvent * RunEvent::createRunEvent(Tx&& argFunction) {
        using T = std::remove_cv_t<
            std::remove_reference_t<Tx> >;
        return sstd_new< _private_api_function::_RunEvent<T> >(
            std::forward<Tx>(argFunction));
    }

    template<typename Tx>
    inline static MultiRunEvent * MultiRunEvent::createMultiRunEvent(
        QPointer<QObject> argTarget,
        int argPriority,
        Tx&& argDoNotRunNext) {

        using T = std::remove_cv_t<
            std::remove_reference_t<Tx> >;

        auto varData =
            sstd_make_unique< _private_api_function::MultiRunEventData >();

        varData->priority = argPriority;
        varData->target = argTarget;

        return sstd_new< _private_api_function::_MultiRunEvent<T> >(
            std::move(varData),
            std::forward<Tx>(argDoNotRunNext));

    }

    template<typename Tx>
    inline void MultiRunEvent::appendFunction(Tx && arg) {
        auto varFunction =
            RunEvent::createRunEvent(std::forward<Tx>(arg));
        this->append(varFunction);
    }


}/*namespace sstd*/


