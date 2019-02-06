#include "sstd_application_environment.hpp"
#include "../opengl_default_format/sstd_opengl_default_format.hpp"
#include <cstdlib>
#include <QtCore/qcoreapplication.h>


namespace sstd {

    /*在QApplication初始化之前执行*/
    ApplicationEnvironment::ApplicationEnvironment() {
        {
            /*初始化随机种子*/
            sstdg::srand(static_cast<unsigned>(sstdg::time(nullptr)));
        }
        {
            /*高分屏支持*/
            QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
        }
        {
            /*OpenGL共享资源*/
            QCoreApplication::setAttribute(Qt::AA_ShareOpenGLContexts);
        }
        {
            /*设置默认opengl环境*/
            QSurfaceFormat::setDefaultFormat(sstd::getDefaultQSurfaceFormat());
        }
        {
            /*关闭异步渲染*/
            ::qputenv("QSG_RENDER_LOOP","basic");
        }
    }

}/*namespace sstd*/
