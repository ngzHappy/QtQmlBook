#include "the_book_global.hpp"
#include "MainWindow.hpp"

int main(int argc, char ** argv) try {
    QApplication varApplication{ argc,argv };

    MainWindow varMainWindow;
    varMainWindow.rebuild();
    varMainWindow.show();

    return varApplication.exec();

} catch (...) {
    return -1;
}
