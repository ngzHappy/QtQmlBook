#pragma once

#include <sstd_library.hpp>
#include <QtWidgets/qapplication.h>
#include "../global/sstd_qt_and_qml_global.hpp"
#include "sstd_application_environment.hpp"

namespace sstd {

    class EXPORT_SSTD_QT_AND_QML_LIBRARY Application :
        public QApplication,
        public virtual ApplicationEnvironment,
        SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(Application){
        Q_OBJECT
    public:
        Application(int &, char **);
    private:
        using Super = QApplication;
        SSTD_DELETE_COPY_ASSIGN(Application);
        SSTD_END_DEFINE_VIRTUAL_CLASS(Application);
    };

}/*namespace sstd*/





