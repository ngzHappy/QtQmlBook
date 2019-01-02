#include "the_book_global.hpp"
#include "MainWindow.hpp"

int main(int argc, char ** argv) try {
    QApplication varApplication{ argc,argv };

    MainWindow varMainWindow;


    varMainWindow.show();

    return varApplication.exec();

} catch (...) {
    return -1;
}




























