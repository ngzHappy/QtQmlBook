#pragma once

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void _on_sbA_clicked();
    void _on_sbB_clicked();
    void _on_rb_clicked();

private:
    Ui::MainWindow *ui;
};


