#pragma once

#include "the_book_global.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
public:
    MainWindow();
    ~MainWindow();
public:
    void rebuild();
private:
};
