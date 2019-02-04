#pragma once

#include <sstd_library.hpp>
#include <QtWidgets/qapplication.h>
#include "../global/sstd_qt_and_qml_global.hpp"
#include "sstd_application_environment.hpp"

namespace sstd {

    class _ApplicationArgsPrivate;
    class EXPORT_SSTD_QT_AND_QML_LIBRARY ApplicationArgs {
    public:
        ApplicationArgs(int, char **,std::string_view);
        inline ApplicationArgs(const ApplicationArgs &)=default;
        inline ApplicationArgs(ApplicationArgs &&) = default;
        inline ApplicationArgs&operator=(const ApplicationArgs &) = default;
        inline ApplicationArgs&operator=(ApplicationArgs &&) = default;
    public:
        int & getArgC() const;
        char ** getArgV() const;
    private:
        std::shared_ptr<const _ApplicationArgsPrivate> mmmData;
    private:
        SSTD_DEFINE_STATIC_CLASS(ApplicationArgs);
    };

    class EXPORT_SSTD_QT_AND_QML_LIBRARY Application :
        public QApplication,
        public virtual ApplicationEnvironment,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Application){
        Q_OBJECT
    public:
        inline Application(int, char **, std::string_view = {});
        Application(ApplicationArgs);
    private:
        ApplicationArgs mmmArgs;
        using Super = QApplication;
        SSTD_DELETE_COPY_ASSIGN(Application);
        SSTD_END_DEFINE_VIRTUAL_CLASS(Application);
    };

    inline Application::Application(int argc, char ** argv,
        std::string_view argQmlStyleName) :
        Application(ApplicationArgs{ argc,argv,argQmlStyleName }) {
    }

}/*namespace sstd*/
