#include <QtWidgets/QtWidgets>
#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui->sbA,&QPushButton::clicked,
        this,&MainWindow::_on_sbA_clicked);
    connect(ui->sbB,&QPushButton::clicked,
        this,&MainWindow::_on_sbB_clicked);
    connect(ui->rb,&QPushButton::clicked,
        this,&MainWindow::_on_rb_clicked);

    QDir varDir{ CURRENT_DEBUG_PATH };
    ui->leA->setText(QDir(
        varDir.absoluteFilePath((QStringLiteral("../../TheBook"))))
        .canonicalPath());

    ui->leB->setText(ui->leA->text()
        + QStringLiteral("/main_index.txt"));

}

MainWindow::~MainWindow() {
    delete ui;
}

namespace {

    QString selectFile(QLineEdit * arg) {
        const QDir varDir{ arg->text() };
        return QFileDialog::getOpenFileName(
            nullptr,
            QObject::trUtf8(u8R"(选择文件：)"),
            varDir.dirName());
    }

    QString selectDir(QLineEdit * arg) {
        return QFileDialog::getExistingDirectory(
            nullptr,
            QObject::trUtf8(u8R"(选择文件夹：)"),
            arg->text());
    }

}/*namespace*/

void MainWindow::_on_sbA_clicked() {
    auto varAns = selectDir(ui->leA);
    if(varAns.isEmpty()) {
        return;
    }
    ui->leA->setText(varAns);
}

void MainWindow::_on_sbB_clicked() {
    auto varAns = selectFile(ui->leB);
    if(varAns.isEmpty()) {
        return;
    }
    ui->leB->setText(varAns);
}

void MainWindow::_on_rb_clicked() {
    auto varRootPath = ui->leA->text();
    auto varFilePath = ui->leB->text();

    QDir varRoot{ varRootPath };
    auto varAns =
        varRoot.relativeFilePath(varFilePath);

    ui->la->setText(varAns);

}





