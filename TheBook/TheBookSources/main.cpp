﻿#include "the_book_global.hpp"
#include "MainWindow.hpp"
#include "output_main_index.hpp"

int main(int argc,char ** argv){
    QApplication varApplication{argc,argv};

    MainWindow varMainWindow;

    output_main_index();

    varMainWindow.show();

    return varApplication.exec();
}




























