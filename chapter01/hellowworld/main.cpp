#include <sstd_qt_and_qml_library.hpp>

int main(int argc , char ** argv){

    auto varApp = sstd_make_unique< sstd::Application >( argc,argv );

    auto varWindow = sstd_make_unique< sstd::DefaultRoowWindow >();

    varWindow->show();

    return varApp->exec();

}







