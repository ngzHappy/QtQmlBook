#include <sstd_qt_and_qml_library.hpp>

#include <QtWidgets/qwidget.h>

int main(int argc,char ** argv){

    sstd::Application varApp{argc,argv};

    QWidget window;
    window.show();

    return varApp.exec();

}





