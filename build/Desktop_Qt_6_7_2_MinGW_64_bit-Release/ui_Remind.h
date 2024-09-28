/********************************************************************************
** Form generated from reading UI file 'Remind.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMIND_H
#define UI_REMIND_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_remind
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *remind)
    {
        if (remind->objectName().isEmpty())
            remind->setObjectName("remind");
        remind->resize(100, 300);
        remind->setMinimumSize(QSize(100, 300));
        remind->setMaximumSize(QSize(100, 300));
        label = new QLabel(remind);
        label->setObjectName("label");
        label->setGeometry(QRect(-10, -50, 121, 211));
        label->setStyleSheet(QString::fromUtf8("image: url(:/assets/icon/line.png);"));
        label_2 = new QLabel(remind);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 80, 101, 151));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/assets/icon/alice02.png);"));

        retranslateUi(remind);

        QMetaObject::connectSlotsByName(remind);
    } // setupUi

    void retranslateUi(QWidget *remind)
    {
        remind->setWindowTitle(QCoreApplication::translate("remind", "Form", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class remind: public Ui_remind {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMIND_H
