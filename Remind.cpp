#include "Remind.h"
#include "ui_Remind.h"


//专注完成后的提醒窗口

remind::remind(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::remind)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);
    screenGeometryRemind = QGuiApplication::primaryScreen()->geometry();
    this->move(screenGeometryRemind.x() + (screenGeometryRemind.width()-width()-300),screenGeometryRemind.y()-height());
    controlTimer=new QTimer();
    connect(controlTimer, &QTimer::timeout, this, [=](){

        remindMidAnimation();

    });

}

void remind::remindMidAnimation()
{


    screenGeometryRemind = QGuiApplication::primaryScreen()->geometry();

    outWindowAnimation = new QPropertyAnimation(this, "geometry");
    outWindowAnimation->setDuration(5000);
    outWindowAnimation->setStartValue(QRect(screenGeometryRemind.x() + (screenGeometryRemind.width()-width()-300),
                                                  screenGeometryRemind.y(),
                                                  width(), height()));
    outWindowAnimation->setEndValue(QRect(screenGeometryRemind.x() + (screenGeometryRemind.width()-width()-300),
                                          screenGeometryRemind.y()-height(),
                                          width(), height())); // 滑入到屏幕中央
    outWindowAnimation->setEasingCurve(QEasingCurve::OutQuad); // 使用平滑的缓出曲线

    outWindowAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    controlTimer->stop();
    //delete this;

}

void remind::remindInitAnimation()
{


    screenGeometryRemind = QGuiApplication::primaryScreen()->geometry();

    outWindowAnimation = new QPropertyAnimation(this, "geometry");
    outWindowAnimation->setDuration(5000);
    outWindowAnimation->setStartValue(QRect(screenGeometryRemind.x()+(screenGeometryRemind.width()-width()-300),
                                                  screenGeometryRemind.y()-height(),
                                                  width(), height()));
    outWindowAnimation->setEndValue(QRect(screenGeometryRemind.x() + (screenGeometryRemind.width()-width()-300),
                                                screenGeometryRemind.y(),
                                                width(), height())); // 滑入到屏幕中央
    outWindowAnimation->setEasingCurve(QEasingCurve::OutQuad); // 使用平滑的缓出曲线

    outWindowAnimation->start(QAbstractAnimation::DeleteWhenStopped);

    controlTimer->start(5000);
}

remind::~remind()
{
    delete ui;
}
