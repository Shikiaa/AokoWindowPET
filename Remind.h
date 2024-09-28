#ifndef REMIND_H
#define REMIND_H

#include <QPropertyAnimation>
#include <QWidget>
#include <QScreen>
#include <QTimer>

namespace Ui {
class remind;
}

class remind : public QWidget
{
    Q_OBJECT

public:
    explicit remind(QWidget *parent = nullptr);

    void remindInitAnimation();
    void remindMidAnimation();

    ~remind();

private:
    Ui::remind *ui;
    QTimer* controlTimer;
    QPropertyAnimation* outWindowAnimation;
    QRect screenGeometryRemind;

};

#endif // REMIND_H
