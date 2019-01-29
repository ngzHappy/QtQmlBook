#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <list>
#include <iostream>
#include <exception>

#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_sourceButton_clicked() {
    const auto varDir = QFileDialog::getExistingDirectory();
    if (varDir.isEmpty()) {
        return;
    }
    ui->sourceText->setText(varDir);
}

void MainWindow::on_targetButton_clicked() {
    const auto varDir = QFileDialog::getExistingDirectory();
    if (varDir.isEmpty()) {
        return;
    }
    ui->targetText->setText(varDir);
}

namespace this_file {
    class Duty {
    public:
        QFileInfo source_file;
    public:
        inline Duty(QFileInfo arg) :
            source_file(std::move(arg)) {
        }
    };
}/*namespace this_file*/

void MainWindow::on_runButton_clicked() {
    const auto varSourceText =
        ui->sourceText->text();
    const auto varTargetText =
        ui->targetText->text();

    std::list< this_file::Duty > varDuty;
    {
        QDirIterator varDir{ varSourceText };
        while (varDir.hasNext()) {
            const auto varFileName = varDir.next();
            auto varFileInfo = varDir.fileInfo();
            if (!varFileInfo.isFile()) {
                continue;
            }
            varDuty.emplace_back(std::move(varFileInfo));
        }
    }

    QDir varTargetDir{ varTargetText };
    for (const auto & varI : varDuty) {
        const auto varFileName =
            varI.source_file.fileName();
        const auto varTarget =
            varTargetDir.absoluteFilePath(varFileName);
        const auto varSource =
            varI.source_file.absoluteFilePath();
        const fs::path varTargetSTD{
            varTarget.toStdWString() };
        const fs::path varSourceSTD{
            varSource.toStdWString() };
        try {
            fs::create_symlink(varSourceSTD, varTargetSTD);
        } catch (const std::exception & arg) {
            std::cout<< arg.what() <<std::endl ;
            continue;
        }
    }

}








