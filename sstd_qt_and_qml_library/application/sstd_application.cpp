#include "sstd_application.hpp"
#include <QtGui/qimage.h>

namespace sstd {

    Application::Application(int & argc, char ** argv) :Super(argc, argv) {
        /*在QApplication构造之后构造*/
        {
            /*强制加载QImage插件*/
            QImage varImage{ QStringLiteral(":/qtandqmlglobal/image/foreceLoadQImage.png") };
            (void)varImage;
        }
    }

}/*namespace sstd*/













