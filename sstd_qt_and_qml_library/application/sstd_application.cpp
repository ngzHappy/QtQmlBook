#include "sstd_application.hpp"
#include <QtGui/qimage.h>

namespace sstd {

    Application::Application(ApplicationArgs v) :
        Super(v.getArgC(), v.getArgV()),
        mmmArgs(v) {
        /*在QApplication构造之后构造*/
            {
                /*强制加载QImage插件*/
                QImage varImage{ QStringLiteral(":/qtandqmlglobal/image/foreceLoadQImage.png") };
                (void)varImage;
            }
    }

    class _ApplicationArgsPrivate {
    public:
        int mmmArgc{ 0 };
        sstd::Vector< sstd::string > mmmArgv;
        sstd::Vector< char * > mmmArgvCStyle;
        char ** mmmArgvFinal{ nullptr };
        _ApplicationArgsPrivate(const int argc, char ** argv) :mmmArgc(argc) {
            mmmArgv.reserve(argc);
            mmmArgvCStyle.reserve(argc);
            for (int varI = 0; varI < argc; ++varI) {
                mmmArgv.emplace_back(argv[varI]);
            }
            for (const auto & varI : std::as_const(mmmArgv)) {
                mmmArgvCStyle.push_back(
                    const_cast<char *>(std::as_const(varI).c_str()));
            }
            mmmArgvFinal =const_cast<char **>(
                &(std::as_const(mmmArgvCStyle)[0]));
        }
        SSTD_DEFINE_STATIC_CLASS(_ApplicationArgsPrivate);
    };

    int & ApplicationArgs::getArgC() const {
        return const_cast<_ApplicationArgsPrivate *>(mmmData.get())->mmmArgc;
    }

    char ** ApplicationArgs::getArgV() const {
        return mmmData->mmmArgvFinal;
    }

    ApplicationArgs::ApplicationArgs(int argc, char ** argv) {
        mmmData = sstd_make_shared<_ApplicationArgsPrivate>(argc, argv);
    }

}/*namespace sstd*/













