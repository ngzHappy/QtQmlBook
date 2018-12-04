#include "sstd_application_environment.hpp"
#include <cstdlib>

namespace sstd {

    ApplicationEnvironment::ApplicationEnvironment() {
        {
            /*初始化随机种子*/
            sstdg::srand(static_cast<unsigned>(sstdg::time(nullptr)));
        }

    }

}/*namespace sstd*/















