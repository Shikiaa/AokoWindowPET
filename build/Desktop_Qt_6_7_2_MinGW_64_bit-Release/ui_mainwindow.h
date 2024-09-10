/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *differenceLabel;
    QPushButton *fixedBtn;
    QPushButton *homeBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(329, 504);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton { background-color: transparent; border: none; }"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 70, 281, 411));
        label->setStyleSheet(QString::fromUtf8("image: url(:/assets/aokohalf/02.png);"));
        differenceLabel = new QLabel(centralwidget);
        differenceLabel->setObjectName("differenceLabel");
        differenceLabel->setGeometry(QRect(130, 70, 61, 91));
        differenceLabel->setStyleSheet(QString::fromUtf8("image: url(:/assets/aokohalf/01scarf/01scanf_all/1.png);"));
        fixedBtn = new QPushButton(centralwidget);
        fixedBtn->setObjectName("fixedBtn");
        fixedBtn->setGeometry(QRect(230, 90, 61, 61));
        fixedBtn->setStyleSheet(QString::fromUtf8("image: url(:/assets/icon/unlock.png);"));
        fixedBtn->setCheckable(true);
        homeBtn = new QPushButton(centralwidget);
        homeBtn->setObjectName("homeBtn");
        homeBtn->setGeometry(QRect(20, 160, 61, 61));
        homeBtn->setStyleSheet(QString::fromUtf8("image: url(:/assets/icon/aoko3.png);"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        differenceLabel->setText(QString());
        fixedBtn->setText(QString());
        homeBtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
