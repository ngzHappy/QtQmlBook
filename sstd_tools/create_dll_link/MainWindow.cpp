#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <list>
#include <iostream>
#include <exception>
#include <string_view>
using namespace std::string_view_literals;

#define USE_FILESYSTEM 1

#if USE_FILESYSTEM
#if __has_include(<filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#else
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif
#endif

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->sourceText->setText(QT_BIN_DIR_WHERE);
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

    static inline bool needCreateLink(const QString & arg) {
        const static QRegularExpression varExp{
            QStringLiteral(R"!((?:dll)|(?:conf))!"),
            QRegularExpression::CaseInsensitiveOption };
        return varExp.match(arg).hasMatch();
    }

}/*namespace this_file*/

void MainWindow::on_runButton_clicked() {

    std::cout << u8R"(
change qt.conf lick this ...
[Paths]
Documentation=D:/Qt/Qt5.12.0/Docs/Qt-5.12.0
Examples=D:/Qt/Qt5.12.0/Examples/Qt-5.12.0
Prefix=D:/Qt/Qt5.12.0/5.12.0/msvc2017_64

)"sv;

    const auto varSourceText =
        ui->sourceText->text();
    const auto varTargetText =
        ui->targetText->text();

    std::list< this_file::Duty > varDuty;
    {
        QDirIterator varDir{ varSourceText };
        while (varDir.hasNext()) {
            varDir.next();
            auto varFileInfo = varDir.fileInfo();
            if (!varFileInfo.isFile()) {
                continue;
            }
            if (!this_file::needCreateLink(varFileInfo.suffix())) {
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
#if USE_FILESYSTEM
        const fs::path varTargetSTD{
            varTarget.toStdWString() };
        const fs::path varSourceSTD{
            varSource.toStdWString() };
        try {
            fs::create_symlink(varSourceSTD, varTargetSTD);
        } catch (const std::exception & arg) {
            std::cout << arg.what() << std::endl;
            continue;
        }
#else
        QFile::link( varSource , varTarget );
#endif
    }

}








