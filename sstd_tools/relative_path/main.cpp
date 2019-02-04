#include <QtWidgets/QtWidgets>
#include "MainWindow.hpp"

int main(int argc, char ** argv) {
    QApplication varApp{ argc, argv };

    MainWindow varWindow;
    varWindow.show();

    return varApp.exec();
}
