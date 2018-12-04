#pragma once

#include <sstd_library.hpp>

namespace sstd {

    /*用于在QApplication构造之前构造*/
    class ApplicationEnvironment : SSTD_BEGIN_DEFINE_VIRTUAL_CLASS(ApplicationEnvironment) {
    public:
        ApplicationEnvironment();
    private:
        SSTD_DELETE_COPY_ASSIGN(ApplicationEnvironment);
        SSTD_END_DEFINE_VIRTUAL_CLASS(ApplicationEnvironment);
    };

}/**/


















