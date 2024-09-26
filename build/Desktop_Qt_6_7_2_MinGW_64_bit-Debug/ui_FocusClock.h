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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FocusClock
{
public:
    QLabel *showTimeLabel;
    QLabel *showTextLabel;
    QTabWidget *tabWidget;
    QWidget *focusSettingsTab;
    QLabel *workTextLabel;
    QLabel *ringTextLabel;
    QPushButton *ringBtn;
    QRadioButton *saveRBtn;
    QRadioButton *changeRBtn;
    QPushButton *startFocusBtn;
    QPushButton *finishFocusBtn;
    QPushButton *pauseFocusBtn;
    QSpinBox *workTimeSpinBox;
    QWidget *tab_2;
    QLabel *label_7;
    QLabel *focusTimes;
    QLabel *label_3;
    QLabel *focusTimesMin;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *closeBtn;
    QLabel *label;
    QLabel *countDownTimeLabel;
    QLabel *label_2;
    QLabel *musicLabel;
    QPushButton *helpBtn;

    void setupUi(QWidget *FocusClock)
    {
        if (FocusClock->objectName().isEmpty())
            FocusClock->setObjectName("FocusClock");
        FocusClock->resize(529, 120);
        FocusClock->setMinimumSize(QSize(0, 120));
        FocusClock->setMaximumSize(QSize(540, 120));
        FocusClock->setWindowOpacity(0.995000000000000);
        FocusClock->setStyleSheet(QString::fromUtf8(""));
        showTimeLabel = new QLabel(FocusClock);
        showTimeLabel->setObjectName("showTimeLabel");
        showTimeLabel->setGeometry(QRect(320, 0, 81, 21));
        showTextLabel = new QLabel(FocusClock);
        showTextLabel->setObjectName("showTextLabel");
        showTextLabel->setGeometry(QRect(270, 0, 51, 21));
        tabWidget = new QTabWidget(FocusClock);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(10, 0, 251, 121));
        focusSettingsTab = new QWidget();
        focusSettingsTab->setObjectName("focusSettingsTab");
        workTextLabel = new QLabel(focusSettingsTab);
        workTextLabel->setObjectName("workTextLabel");
        workTextLabel->setGeometry(QRect(0, -1, 101, 31));
        ringTextLabel = new QLabel(focusSettingsTab);
        ringTextLabel->setObjectName("ringTextLabel");
        ringTextLabel->setGeometry(QRect(0, 30, 101, 41));
        ringBtn = new QPushButton(focusSettingsTab);
        ringBtn->setObjectName("ringBtn");
        ringBtn->setGeometry(QRect(80, 40, 91, 20));
        saveRBtn = new QRadioButton(focusSettingsTab);
        saveRBtn->setObjectName("saveRBtn");
        saveRBtn->setGeometry(QRect(20, 70, 51, 21));
        changeRBtn = new QRadioButton(focusSettingsTab);
        changeRBtn->setObjectName("changeRBtn");
        changeRBtn->setGeometry(QRect(90, 70, 51, 21));
        startFocusBtn = new QPushButton(focusSettingsTab);
        startFocusBtn->setObjectName("startFocusBtn");
        startFocusBtn->setGeometry(QRect(180, 70, 61, 21));
        finishFocusBtn = new QPushButton(focusSettingsTab);
        finishFocusBtn->setObjectName("finishFocusBtn");
        finishFocusBtn->setGeometry(QRect(180, 10, 61, 21));
        pauseFocusBtn = new QPushButton(focusSettingsTab);
        pauseFocusBtn->setObjectName("pauseFocusBtn");
        pauseFocusBtn->setGeometry(QRect(180, 40, 61, 21));
        workTimeSpinBox = new QSpinBox(focusSettingsTab);
        workTimeSpinBox->setObjectName("workTimeSpinBox");
        workTimeSpinBox->setGeometry(QRect(80, 3, 71, 21));
        tabWidget->addTab(focusSettingsTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        label_7 = new QLabel(tab_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 10, 141, 16));
        focusTimes = new QLabel(tab_2);
        focusTimes->setObjectName("focusTimes");
        focusTimes->setGeometry(QRect(140, 10, 31, 21));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 10, 21, 21));
        focusTimesMin = new QLabel(tab_2);
        focusTimesMin->setObjectName("focusTimesMin");
        focusTimesMin->setGeometry(QRect(140, 30, 53, 15));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(190, 30, 16, 16));
        tabWidget->addTab(tab_2, QString());
        label_8 = new QLabel(FocusClock);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(270, 20, 61, 20));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_9 = new QLabel(FocusClock);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(420, -10, 141, 141));
        label_9->setStyleSheet(QString::fromUtf8("image: url(:/assets/icon/alice01.png);"));
        closeBtn = new QPushButton(FocusClock);
        closeBtn->setObjectName("closeBtn");
        closeBtn->setGeometry(QRect(390, 0, 71, 31));
        label = new QLabel(FocusClock);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 20, 16, 19));
        countDownTimeLabel = new QLabel(FocusClock);
        countDownTimeLabel->setObjectName("countDownTimeLabel");
        countDownTimeLabel->setGeometry(QRect(330, 20, 41, 19));
        label_2 = new QLabel(FocusClock);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 40, 53, 15));
        musicLabel = new QLabel(FocusClock);
        musicLabel->setObjectName("musicLabel");
        musicLabel->setGeometry(QRect(330, 40, 151, 16));
        helpBtn = new QPushButton(FocusClock);
        helpBtn->setObjectName("helpBtn");
        helpBtn->setGeometry(QRect(220, 0, 41, 23));
        tabWidget->raise();
        showTimeLabel->raise();
        showTextLabel->raise();
        label_8->raise();
        label_9->raise();
        closeBtn->raise();
        label->raise();
        countDownTimeLabel->raise();
        label_2->raise();
        musicLabel->raise();
        helpBtn->raise();

        retranslateUi(FocusClock);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(FocusClock);
    } // setupUi

    void retranslateUi(QWidget *FocusClock)
    {
        FocusClock->setWindowTitle(QCoreApplication::translate("FocusClock", "Form", nullptr));
        showTimeLabel->setText(QString());
        showTextLabel->setText(QCoreApplication::translate("FocusClock", "\345\275\223\345\211\215\346\227\266\351\227\264:", nullptr));
        workTextLabel->setText(QCoreApplication::translate("FocusClock", "\345\212\236\345\205\254\346\227\266\351\227\264\351\227\264\351\232\224\357\274\232", nullptr));
        ringTextLabel->setText(QCoreApplication::translate("FocusClock", "\346\217\220\351\206\222\351\223\203\345\243\260\350\256\276\347\275\256:", nullptr));
        ringBtn->setText(QString());
        saveRBtn->setText(QCoreApplication::translate("FocusClock", "\344\277\235\345\255\230", nullptr));
        changeRBtn->setText(QCoreApplication::translate("FocusClock", "\344\277\256\346\224\271", nullptr));
        startFocusBtn->setText(QCoreApplication::translate("FocusClock", "start", nullptr));
        finishFocusBtn->setText(QCoreApplication::translate("FocusClock", "finish", nullptr));
        pauseFocusBtn->setText(QCoreApplication::translate("FocusClock", "pause", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(focusSettingsTab), QCoreApplication::translate("FocusClock", "\344\270\223\346\263\250\350\256\276\347\275\256(min)", nullptr));
        label_7->setText(QCoreApplication::translate("FocusClock", "\344\273\216\345\256\211\350\243\205\347\250\213\345\272\217\345\210\260\347\216\260\345\234\250\345\267\262\344\270\223\346\263\250:", nullptr));
        focusTimes->setText(QCoreApplication::translate("FocusClock", "null", nullptr));
        label_3->setText(QCoreApplication::translate("FocusClock", "\346\254\241", nullptr));
        focusTimesMin->setText(QCoreApplication::translate("FocusClock", "null", nullptr));
        label_5->setText(QCoreApplication::translate("FocusClock", "\347\247\222", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("FocusClock", "\346\210\221\347\232\204\350\256\260\345\275\225", nullptr));
        label_8->setText(QCoreApplication::translate("FocusClock", "\344\270\223\346\263\250\350\277\230\345\211\251", nullptr));
        label_9->setText(QString());
        closeBtn->setText(QCoreApplication::translate("FocusClock", "close", nullptr));
        label->setText(QCoreApplication::translate("FocusClock", "\347\247\222", nullptr));
        countDownTimeLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("FocusClock", "\345\275\223\345\211\215\351\223\203\345\243\260:", nullptr));
        musicLabel->setText(QCoreApplication::translate("FocusClock", "null", nullptr));
        helpBtn->setText(QCoreApplication::translate("FocusClock", "help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FocusClock: public Ui_FocusClock {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FOCUSCLOCK_H
