/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
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
    QWidget *widget;
    QPushButton *fixedBtn;
    QLabel *label;
    QPushButton *homeBtn;
    QLabel *differenceLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(350, 425);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        centralwidget->setStyleSheet(QString::fromUtf8("QPushButton { background-color: transparent; border: none; }"));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setEnabled(true);
        widget->setGeometry(QRect(20, 10, 321, 601));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        fixedBtn = new QPushButton(widget);
        fixedBtn->setObjectName("fixedBtn");
        fixedBtn->setGeometry(QRect(-10, 60, 81, 61));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fixedBtn->sizePolicy().hasHeightForWidth());
        fixedBtn->setSizePolicy(sizePolicy2);
        fixedBtn->setStyleSheet(QString::fromUtf8("image: url(:/assets/icon/unlock.png);"));
        fixedBtn->setCheckable(true);
        label = new QLabel(widget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 291, 411));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setStyleSheet(QString::fromUtf8("image: url(:/assets/aokohalf/03.png);"));
        homeBtn = new QPushButton(widget);
        homeBtn->setObjectName("homeBtn");
        homeBtn->setGeometry(QRect(-10, 120, 81, 71));
        sizePolicy2.setHeightForWidth(homeBtn->sizePolicy().hasHeightForWidth());
        homeBtn->setSizePolicy(sizePolicy2);
        homeBtn->setStyleSheet(QString::fromUtf8("image: url(:/assets/icon/aoko3.png);"));
        differenceLabel = new QLabel(widget);
        differenceLabel->setObjectName("differenceLabel");
        differenceLabel->setGeometry(QRect(100, 0, 111, 91));
        differenceLabel->setStyleSheet(QString::fromUtf8("image: url(:/assets/aokohalf/01scarf/01scanf_all/14.png);"));
        label->raise();
        fixedBtn->raise();
        homeBtn->raise();
        differenceLabel->raise();
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        fixedBtn->setText(QString());
        label->setText(QString());
        homeBtn->setText(QString());
        differenceLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
