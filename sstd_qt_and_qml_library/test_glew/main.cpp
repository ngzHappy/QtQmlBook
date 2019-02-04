#include <sstd_qt_and_qml_library.hpp>
#include "MainWidget.hpp"

int main(int argc,char ** argv){

    sstd::Application varApp{argc,argv};

    MainWidget widget ;
    widget.resize(512,512);
    widget.show();

    return varApp.exec();

}
