/********************************************************************************
** Form generated from reading UI file 'FocusClock.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FOCUSCLOCK_H
#define UI_FOCUSCLOCK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FocusClock
{
public:
    QPushButton *startFocusBtn;
    QPushButton *pauseFocusBtn;
    QPushButton *finishFocusBtn;
    QLabel *showTimeLabel;
    QLabel *showTextLabel;
    QTabWidget *tabWidget;
    QWidget *focusSettingsTab;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QPushButton *pushButton;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QWidget *tab_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QProgressBar *progressBar;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QWidget *FocusClock)
    {
        if (FocusClock->objectName().isEmpty())
            FocusClock->setObjectName("FocusClock");
        FocusClock->resize(600, 100);
        FocusClock->setMinimumSize(QSize(600, 100));
        FocusClock->setMaximumSize(QSize(600, 100));
        FocusClock->setWindowOpacity(0.900000000000000);
        FocusClock->setStyleSheet(QString::fromUtf8(""));
        startFocusBtn = new QPushButton(FocusClock);
        startFocusBtn->setObjectName("startFocusBtn");
        startFocusBtn->setGeometry(QRect(510, 40, 80, 23));
        pauseFocusBtn = new QPushButton(FocusClock);
        pauseFocusBtn->setObjectName("pauseFocusBtn");
        pauseFocusBtn->setGeometry(QRect(450, 10, 51, 23));
        finishFocusBtn = new QPushButton(FocusClock);
        finishFocusBtn->setObjectName("finishFocusBtn");
        finishFocusBtn->setGeometry(QRect(510, 10, 80, 23));
        showTimeLabel = new QLabel(FocusClock);
        showTimeLabel->setObjectName("showTimeLabel");
        showTimeLabel->setGeometry(QRect(320, 0, 91, 21));
        showTextLabel = new QLabel(FocusClock);
        showTextLabel->setObjectName("showTextLabel");
        showTextLabel->setGeometry(QRect(260, 0, 51, 21));
        tabWidget = new QTabWidget(FocusClock);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 241, 101));
        focusSettingsTab = new QWidget();
        focusSettingsTab->setObjectName("focusSettingsTab");
        label = new QLabel(focusSettingsTab);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 81, 20));
        label_2 = new QLabel(focusSettingsTab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 91, 20));
        label_3 = new QLabel(focusSettingsTab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 19, 81, 31));
        lineEdit = new QLineEdit(focusSettingsTab);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(80, 0, 31, 21));
        lineEdit_2 = new QLineEdit(focusSettingsTab);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(80, 20, 31, 21));
        label_4 = new QLabel(focusSettingsTab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(120, 10, 61, 21));
        pushButton = new QPushButton(focusSettingsTab);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(180, 10, 31, 21));
        radioButton = new QRadioButton(focusSettingsTab);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(10, 50, 51, 21));
        radioButton_2 = new QRadioButton(focusSettingsTab);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(60, 50, 51, 21));
        tabWidget->addTab(focusSettingsTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 30, 71, 16));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 50, 71, 16));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 10, 101, 16));
        tabWidget->addTab(tab_2, QString());
        progressBar = new QProgressBar(FocusClock);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(280, 70, 118, 23));
        progressBar->setValue(24);
        label_8 = new QLabel(FocusClock);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(280, 50, 61, 16));
        label_9 = new QLabel(FocusClock);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(220, 10, 81, 91));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/assets/icon/alice01.png);"));
        tabWidget->raise();
        startFocusBtn->raise();
        pauseFocusBtn->raise();
        finishFocusBtn->raise();
        showTimeLabel->raise();
        showTextLabel->raise();
        progressBar->raise();
        label_8->raise();
        label_9->raise();

        retranslateUi(FocusClock);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FocusClock);
    } // setupUi

    void retranslateUi(QWidget *FocusClock)
    {
        FocusClock->setWindowTitle(QCoreApplication::translate("FocusClock", "Form", nullptr));
        startFocusBtn->setText(QCoreApplication::translate("FocusClock", "\345\274\200\345\247\213\344\270\223\346\263\250", nullptr));
        pauseFocusBtn->setText(QCoreApplication::translate("FocusClock", "\346\232\202\345\201\234", nullptr));
        finishFocusBtn->setText(QCoreApplication::translate("FocusClock", "\345\201\234\346\255\242\344\270\223\346\263\250", nullptr));
        showTimeLabel->setText(QString());
        showTextLabel->setText(QCoreApplication::translate("FocusClock", "\345\275\223\345\211\215\346\227\266\351\227\264:", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("FocusClock", "\345\212\236\345\205\254\346\227\266\351\227\264\351\227\264\351\232\224\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("FocusClock", "\344\274\221\346\201\257\346\227\266\351\227\264\351\227\264\351\232\224:", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QString());
        label_4->setText(QCoreApplication::translate("FocusClock", "\346\217\220\351\206\222\351\223\203\345\243\260:", nullptr));
        pushButton->setText(QString());
        radioButton->setText(QCoreApplication::translate("FocusClock", "\344\277\235\345\255\230", nullptr));
        radioButton_2->setText(QCoreApplication::translate("FocusClock", "\344\277\256\346\224\271", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(focusSettingsTab), QCoreApplication::translate("FocusClock", "\344\270\223\346\263\250\350\256\276\347\275\256(min)", nullptr));
        label_5->setText(QCoreApplication::translate("FocusClock", "\346\234\254\345\271\264\345\267\262\344\270\223\346\263\250:", nullptr));
        label_6->setText(QCoreApplication::translate("FocusClock", "\346\234\254\346\234\210\345\267\262\344\270\223\346\263\250:", nullptr));
        label_7->setText(QCoreApplication::translate("FocusClock", "\344\273\216\345\244\264\345\210\260\347\216\260\345\234\250\345\267\262\344\270\223\346\263\250:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FocusClock", "\346\210\221\347\232\204\350\256\260\345\275\225", nullptr));
        label_8->setText(QCoreApplication::translate("FocusClock", "\346\234\254\345\271\264\350\277\230\345\211\251:", nullptr));
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FocusClock: public Ui_FocusClock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOCUSCLOCK_H
