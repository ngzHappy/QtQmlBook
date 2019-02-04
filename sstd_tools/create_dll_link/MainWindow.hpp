#pragma once

#include <QtWidgets/QtWidgets>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_sourceButton_clicked();
    void on_targetButton_clicked();
    void on_runButton_clicked();

private:
    Ui::MainWindow *ui;
};
