#include "the_book_global.hpp"
#include "MainWindow.hpp"

int main(int argc,char ** argv){
    QApplication varApplication{argc,argv};

    MainWindow varMainWindow;
    varMainWindow.show();

    return varApplication.exec();
}




























