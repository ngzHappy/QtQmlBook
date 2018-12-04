#pragma once

#include <sstd_library.hpp>
#include "../global/sstd_qt_and_qml_global.hpp"

namespace sstd {

    /*用于在QApplication构造之前构造*/
    class EXPORT_SSTD_QT_AND_QML_LIBRARY ApplicationEnvironment : SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ApplicationEnvironment) {
    public:
        ApplicationEnvironment();
    private:
        SSTD_DELETE_COPY_ASSIGN(ApplicationEnvironment);
        SSTD_END_DEFINE_VIRTUAL_CLASS(ApplicationEnvironment);
    };

}/**/


















