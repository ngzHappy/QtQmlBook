/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *leA;
    QPushButton *sbA;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *leB;
    QPushButton *sbB;
    QLineEdit *la;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *rb;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(699, 232);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        leA = new QLineEdit(centralwidget);
        leA->setObjectName(QString::fromUtf8("leA"));

        horizontalLayout->addWidget(leA);

        sbA = new QPushButton(centralwidget);
        sbA->setObjectName(QString::fromUtf8("sbA"));

        horizontalLayout->addWidget(sbA);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        leB = new QLineEdit(centralwidget);
        leB->setObjectName(QString::fromUtf8("leB"));

        horizontalLayout_2->addWidget(leB);

        sbB = new QPushButton(centralwidget);
        sbB->setObjectName(QString::fromUtf8("sbB"));

        horizontalLayout_2->addWidget(sbB);


        verticalLayout->addLayout(horizontalLayout_2);

        la = new QLineEdit(centralwidget);
        la->setObjectName(QString::fromUtf8("la"));

        verticalLayout->addWidget(la);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        rb = new QPushButton(centralwidget);
        rb->setObjectName(QString::fromUtf8("rb"));

        horizontalLayout_3->addWidget(rb);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 699, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204A\357\274\232", nullptr));
        sbA->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204B\357\274\232", nullptr));
        sbB->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251", nullptr));
        rb->setText(QApplication::translate("MainWindow", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
