#include "FocusClock.h"
#include "ui_FocusClock.h"

FocusClock::FocusClock(QWidget *parent)
    : QWidget(parent)
    , focusClockUi(new Ui::FocusClock)
{
    focusClockUi->setupUi(this);
    initFocusClock();


     // 每1000毫秒（1秒）更新一次




}
void FocusClock::createFocusClock()
{

    this->show();

}
void FocusClock::initFocusClock()
{

    this->setFixedSize(600,100);

    focusTimer = new QTimer(this);
    connect(focusTimer, &QTimer::timeout, this, &FocusClock::updateClock);
    focusTimer->start(1000);

     setInitPosition();
    //初始情况下，专注的三个按键都不能使用
    focusClockUi->startFocusBtn->setEnabled(false);
     focusClockUi->startFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    focusClockUi->pauseFocusBtn->setEnabled(false);
    focusClockUi->pauseFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    focusClockUi->finishFocusBtn->setEnabled(false);
    focusClockUi->finishFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
}



void FocusClock::setInitPosition()
{

    screenGeometryClock = QGuiApplication::primaryScreen()->geometry();

    setInitPositionAnimation = new QPropertyAnimation(this, "geometry");
    setInitPositionAnimation->setDuration(1500); // 动画持续时间1000毫秒
    setInitPositionAnimation->setStartValue(QRect(screenGeometryClock.x()+(screenGeometryClock.width()-width())/2,
                                                  screenGeometryClock.y()-height(),
                                   width(), height()));
    setInitPositionAnimation->setEndValue(QRect(screenGeometryClock.x() + (screenGeometryClock.width()-width())/2,
                                 screenGeometryClock.y(),
                                 width(), height())); // 滑入到屏幕中央
    setInitPositionAnimation->setEasingCurve(QEasingCurve::OutQuad); // 使用平滑的缓出曲线

    // 启动动画
    setInitPositionAnimation->start(QAbstractAnimation::DeleteWhenStopped);


}

void FocusClock::updateClock()
{

    currentDateTime = QDateTime::currentDateTime();
    currentTime = currentDateTime.toString("hh:mm:ss");
    focusClockUi->showTimeLabel->setText(currentTime);

}

FocusClock::~FocusClock()
{
    delete focusClockUi;
}
