#include "MainWindow.hpp"
#include "output_main_index.hpp"

class CenterWidget :
    public QWidget {
    MainWindow * const super;
    QPushButton * button;
public:
    inline CenterWidget(MainWindow * arg) :
        super(arg) {
        auto varButton = new QPushButton;
        button = varButton;
        auto varLayout = new QVBoxLayout;
        this->setLayout(varLayout);
        varButton->setMaximumWidth(256);
        varButton->setMinimumHeight(64);
        {
            auto varHLayout = new QHBoxLayout;
            varHLayout->addWidget(varButton);
            varLayout->addLayout(varHLayout);
        }
        connect(
            varButton, &QPushButton::clicked,
            this, [this]() {rebuild(); });
        varButton->setText(trUtf8(u8R"(重新构建)"));
    }

    inline void rebuild() {
        button->setEnabled(false);
        _rebuild();
        button->setEnabled(true);
    }

    inline void _rebuild() try {

        output_main_index();

    } catch (...) {

    }

};

void MainWindow::rebuild() {
    static_cast<CenterWidget *>(
        this->centralWidget())
        ->rebuild();
}

MainWindow::MainWindow() {
    this->setMinimumSize({ 512,512 });
    this->setCentralWidget(new CenterWidget{ this });
}

MainWindow::~MainWindow() {

}
