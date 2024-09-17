#ifndef FOCUSCLOCK_H
#define FOCUSCLOCK_H

#include <QPropertyAnimation>
#include <QTimer>
#include <QDateTime>
#include <QScreen>
#include <QWidget>

namespace Ui {
class FocusClock;
}

class FocusClock : public QWidget
{
    Q_OBJECT

public:
    explicit FocusClock(QWidget *parent = nullptr);

    void initFocusClock();
    void createFocusClock(); //其他窗口调用函数
    void setInitPosition(); //设置归位与右上角的动画
    void updateClock(); //更新系统时间

    ~FocusClock();

private:
    Ui::FocusClock* focusClockUi;
    QPropertyAnimation* setInitPositionAnimation;
    QDateTime currentDateTime;
    QRect screenGeometryClock;
    QString currentTime;
    QTimer *focusTimer;


};

#endif // FOCUSCLOCK_H
