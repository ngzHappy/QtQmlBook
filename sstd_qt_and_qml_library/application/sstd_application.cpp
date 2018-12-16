#include "sstd_application.hpp"
#include <QtGui/qimage.h>
#include <QtGui/qoffscreensurface.h>
#include <QtGui/qopenglcontext.h>
#include <QtQml/QtQml>
#include <QtQuick/QtQuick>
#include "../glew/sstd_glew_initialization.hpp"
#include "../opengl_default_format/sstd_opengl_default_format.hpp"
#include <string_view>
#include <fstream>

using namespace std::string_view_literals;

namespace {

    class RunOnceApplicationConstruct;
    inline static void run_once_application_construct(RunOnceApplicationConstruct *);

    /*用于Application仅构造一次*/
    class RunOnceApplicationConstruct {
    public:
        inline RunOnceApplicationConstruct() {
            run_once_application_construct(this);
        }
        QOffscreenSurface surface;
        QOpenGLContext contex;
    private:
        SSTD_DEFINE_STATIC_CLASS(RunOnceApplicationConstruct);
    };

    inline static void run_once_application_construct(RunOnceApplicationConstruct * arg) {
        {
            /*强制加载QImage插件
            防止第一次加载速度过慢*/
            QImage varImage{ QStringLiteral(":/qtandqmlglobal/image/foreceLoadQImage.png") };
            (void)varImage;
        }
        {
            /*初始化glew*/
            arg->surface.setFormat(sstd::getDefaultQSurfaceFormat());
            arg->surface.create();
            arg->contex.setFormat(sstd::getDefaultQSurfaceFormat());
            arg->contex.create();
            arg->contex.makeCurrent(&(arg->surface));
            if (false == sstd::glew_initialize()) {
                sstd_error(u8R"(can not construct glew!!!)"sv);
                return;
            }
            /*由于开启了OpenGL Contex资源共享，
            可以在这里初始化OpenGL全局资源*/
        }
        {
            /*强制加载Qml相关组件,
            避免第一次加载速度过慢*/
            QQmlEngine varEngine;
            QQmlContext varContex{ &varEngine };
            QQmlComponent varComponent{ &varEngine };
            varComponent.setData(u8R"+++(
import QtQuick 2.9
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.6

Item {

    width : 512 ;
    height : 512 ;

    Text {
        id : idText
        text : "今天"
        anchors.fill: parent
    }

    DropShadow {
        anchors.fill: idText
        source: idText
    }

    TextField {
        text : "today"
    }

}
)+++", QUrl{});
            auto varObject = sstd_runtime_cast<QQuickItem>(
                varComponent.create(&varContex) );
            assert(varObject);
            {
                QQuickView varView;
                assert(varView.rootObject());
                varObject->setParent(varView.rootObject());
                varObject->setParentItem(varView.rootObject());
                varView.grabWindow();
            }
        }
    }

}/**/

namespace sstd {

    Application::Application(ApplicationArgs v) :
        Super(v.getArgC(), v.getArgV()),
        mmmArgs(v) {
        /*在QApplication构造之后构造*/
            {
                /*never delete*/
                static auto * varRunonceApplicationConstruct =
                    sstd_new<RunOnceApplicationConstruct>();
                (void)varRunonceApplicationConstruct;
            }
    }

    /*
    在初始Application之前
    将运行时参数拷贝一遍，
    这样做可以自行增加和删除和修改参数*/
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
            mmmArgvFinal = const_cast<char **>(
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

    namespace {
        inline static void try_load_qml_app_style(
            const char * argAppPath,
            const std::string_view & arg) {

            bool varHasFile;

            sstd::string varAppFullPath{ arg };
            {
                std::ifstream varRead(
                    varAppFullPath.c_str(),
                    std::ios::in);
                varHasFile = varRead.is_open();
            }

            if (false == varHasFile) {
                varAppFullPath = argAppPath;
                {
                    auto varPos =
                        varAppFullPath.find_last_of(u8R"(/\)"sv);
                    if (varPos == std::string::npos) {
                        return;
                    }
                    varAppFullPath.resize(varPos +
                        (arg.find_first_of(u8R"(/\)"sv) != 0));
                    varAppFullPath += arg;
                }

                {
                    std::ifstream varRead(
                        varAppFullPath.c_str(),
                        std::ios::in);
                    varHasFile = varRead.is_open();
                }
            }

            if (false == varHasFile) {
                sstd_log(arg);
                return;
            }

            ::qputenv("QT_QUICK_CONTROLS_CONF",
                QByteArray(varAppFullPath.c_str(),
                    static_cast<int>(varAppFullPath.size())));

        }
    }

    ApplicationArgs::ApplicationArgs(int argc, char ** argv,
        std::string_view argQmlStyleName) {
        mmmData = sstd_make_shared<_ApplicationArgsPrivate>(argc, argv);
        {
            /*Supported Environment Variables in Qt Quick Controls 2*/
            if (!argQmlStyleName.empty()) {
                try_load_qml_app_style(argv[0], argQmlStyleName);
            }
        }
    }

}/*namespace sstd*/













