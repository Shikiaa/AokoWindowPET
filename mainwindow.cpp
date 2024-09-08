#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    initMyWindow();
    initMenu();
    initValues();

    //定时器
    updateTimer =new QTimer(this);
    updateTimer->callOnTimeout(this,&MainWindow::updateAnimePicture);
    updateTimer->start(TIME_INTERVAL);

    this->installEventFilter(this);


}

//初始化窗口与出场
void MainWindow::initMyWindow()
{
    //隐藏边框和窗体底
    setWindowFlags(Qt::WindowType::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    this->setFixedSize(334,485);
    screenGeometry = QGuiApplication::primaryScreen()->geometry();
    move(screenGeometry.x() + (screenGeometry.width() - width()) / 2,
         screenGeometry.height() + height()); // 初始位置在屏幕底部之外

    // 创建动画
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(1200); // 动画持续时间1000毫秒
    animation->setStartValue(QRect(screenGeometry.x() + (screenGeometry.width() - width()+50),
                                   screenGeometry.height() + height(),
                                   width(), height()));
    animation->setEndValue(QRect(screenGeometry.x() + (screenGeometry.width()-width()+50),
                                 screenGeometry.height() - height()-42,
                                 width(), height())); // 滑入到屏幕中央
    animation->setEasingCurve(QEasingCurve::OutQuad); // 使用平滑的缓出曲线

    // 启动动画
    animation->start(QAbstractAnimation::DeleteWhenStopped);

    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
}


//初始化参数
void MainWindow::initValues()
{

    //X轴
    XLCR.push_back(screenGeometry.x());
    XLCR.push_back(screenGeometry.center().x()- width() / 2);
    XLCR.push_back(screenGeometry.x() + (screenGeometry.width()-width()+50));


    //Y轴
    YTCB.push_back(screenGeometry.y());
    YTCB.push_back(screenGeometry.center().y()- height() / 2);
    YTCB.push_back(screenGeometry.height() - height()-42);



}


void MainWindow::updateAnimePicture()
{
    //更新差分图片
    ui->differenceLabel->setStyleSheet(QString("image: url(:/assets/aokohalf/01scarf/01scanf_all/%1.png);").arg(this->curTime));
    this->curTime=(this->curTime+1)%29;
}



//事件监听鼠标位置，移动人物
bool MainWindow::eventFilter(QObject *watched, QEvent *ev)
{
    QMouseEvent* mousev=static_cast<QMouseEvent*>(ev);
    static QPoint begpos;
    if(ev->type()==QEvent::MouseButtonPress&&positionSignalNum)
    {
        begpos=mousev->globalPos()-this->pos();

    }else if (ev->type()==QEvent::MouseMove&&
        mousev->buttons()&Qt::MouseButton::LeftButton&&positionSignalNum)
    {
        this->move(mousev->globalPos()-begpos);
    }
    (void)watched;
    return false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


//自动归位
void MainWindow::on_homeBtn_clicked()
{

    animation_random_move->destroyed();
    actionRandomMove->setChecked(false);
    // 创建动画
    QPoint pos = this->pos();
    QPropertyAnimation *homeAnimation = new QPropertyAnimation(this, "geometry");
    homeAnimation->setDuration(1100); // 动画持续时间1100毫秒
    homeAnimation->setStartValue(QRect(pos.x(),pos.y(),
                                   width(), height()));
    homeAnimation->setEndValue(QRect(screenGeometry.x() + (screenGeometry.width()-width()+50),
                                 screenGeometry.height() - height()-42,
                                 width(), height())); // 滑入到屏幕中央
    homeAnimation->setEasingCurve(QEasingCurve::OutQuad); // 使用平滑的缓出曲线

    // 启动动画
    homeAnimation->start(QAbstractAnimation::DeleteWhenStopped);


}

