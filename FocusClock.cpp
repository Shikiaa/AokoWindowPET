#include "FocusClock.h"
#include "ui_FocusClock.h"

FocusClock::FocusClock(QWidget *parent)
    : QWidget(parent)
    , focusClockUi(new Ui::FocusClock)
{

    focusClockUi->setupUi(this);
    initFocusClock(); //初始化参数与行为的函数


}

//初始化参数与行为的函数
void FocusClock::initFocusClock()
{

    windowStatusTimer = new QTimer(this); //检查窗体状态的定时器
    connect(windowStatusTimer, &QTimer::timeout, this, &FocusClock::checkMousePosition);
    windowStatusTimer->start(500); // 每500ms检查一次

    this->setFixedSize(540,120);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    focusTimer = new QTimer(this);
    connect(focusTimer, &QTimer::timeout, this, &FocusClock::updateClock);
    focusTimer->start(1000);

    setInitPosition();
    focusClockUi->workTimeSpinBox->setMinimum(0);
    focusClockUi->workTimeSpinBox->setMaximum(999);

    focusClockUi->startFocusBtn->setEnabled(false);
    focusClockUi->startFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    focusClockUi->pauseFocusBtn->setEnabled(false);
    focusClockUi->pauseFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    focusClockUi->finishFocusBtn->setEnabled(false);
    focusClockUi->finishFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");

    musicOutput = new QAudioOutput(this);
    musicPlayer = new QMediaPlayer(this);
    musicPlayer->setAudioOutput(musicOutput);
    //加载设置
    loadSettings();

    focusClockUi->helpBtn->setToolTip("1.如果想保存专注时长，每次中途退出请先点击finish或等待一个工作周期结束自动保存\n"
                                      "2.点击保存后下次无需设置时长和铃声路径，本地更改铃声路径需要重新设置");
    focusClockUi->helpBtn->setToolTipDuration(10000);
    focusClockUi->helpBtn->show();

}





//启动动画
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

    setInitPositionAnimation->start(QAbstractAnimation::DeleteWhenStopped);

}

//检查鼠标是否停留在窗体上
void FocusClock::enterEvent(QEnterEvent *event)
{

    windowStatusTimer->stop();

}
//检查鼠标是否离开窗体
void FocusClock::leaveEvent(QEvent *event)
{
    windowStatusTimer->start(500);
    slideOut();

}

//检查鼠标在桌面的位置上
void FocusClock::checkMousePosition()
{

    QPoint mousePos = QCursor::pos();
    QRect screenRect = QGuiApplication::primaryScreen()->geometry();

    // 检查鼠标是否接近顶部
    if (mousePos.y() < 5&&windowStatusValue) { // 50 像素的阈值
        slideIn();
        windowStatusValue=false;
    } else if (!underMouse()) {
        slideOut();
        windowStatusValue=true;
    }

}
//窗体的滑出动画
void FocusClock::slideOut()
{

    if (y() >= 0) {
        setWindowAnimation = new QPropertyAnimation(this, "pos");
        setWindowAnimation->setDuration(500);
        setWindowAnimation->setStartValue(QPoint(x(), 0));
        setWindowAnimation->setEndValue(QPoint(x(), -height()));
        setWindowAnimation->start();
    }

}
//滑入动画
void FocusClock::slideIn()
{

    if (y() < 0) {
        setWindowAnimation = new QPropertyAnimation(this, "pos");
        setWindowAnimation->setDuration(200);
        setWindowAnimation->setStartValue(QPoint(x(), -height()));
        setWindowAnimation->setEndValue(QPoint(x(), 0));
        setWindowAnimation->start();
    }

}
//更新时钟
void FocusClock::updateClock()
{

    currentDateTime = QDateTime::currentDateTime();
    currentTime = currentDateTime.toString("hh:mm:ss");
    focusClockUi->showTimeLabel->setText(currentTime);

}


//开始专注
void FocusClock::startFocus()
{

    workTimer=new QTimer(this);
    countTimer = new QElapsedTimer();
    workTimer->setInterval(workTime);
    connect(workTimer,&QTimer::timeout, this,&FocusClock::workTimerOut);
    countdownTimer=new QTimer(this);
    countdownTimer->setInterval(1000);
    countDownTime=workTime;
    focusClockUi->countDownTimeLabel->setText(QString::number(countDownTime/1000));
    workTimer->start();
    countTimer->start();
    countdownTimer->start();
    allfocusTimes++;
    QSettings settings("focusClock","AokoPet");
    settings.setValue("focusTimesSetting",allfocusTimes);

}


//一段专注时间结束后
void FocusClock::workTimerOut()
{

    musicPlayer->play();
    qDebug()<<workTime/1000<<"s工作周期结束";
    focusClockUi->countDownTimeLabel->setText("0");
    finishFocus();
}


//更新剩余时间
void FocusClock::countdownTimerOut()
{
    countDownTime-=1000;
    focusClockUi->countDownTimeLabel->setText(QString::number(countDownTime/1000));
}




//保存设置
void FocusClock::saveSettings()
{
    QSettings settings("focusClock","AokoPet");
    settings.setValue("musicFilePathSetting",musicFilePath);
    settings.setValue("workTimeSetting",workTime/1000/60);


}

//加载设置
void FocusClock::loadSettings()
{
    QSettings settings("focusClock","AokoPet");

    if (settings.contains("musicFilePathSetting")) {

        musicFilePath=settings.value("musicFilePathSetting","").toString();
        QFileInfo fileInfo(musicFilePath);
        musicFileName = fileInfo.fileName();
        focusClockUi->musicLabel->setText(musicFileName);
        musicPlayer->setSource(musicFilePath);

    }else{

        qDebug()<<"没有音乐路径,请选择";

    }
    if(settings.contains("workTimeSetting"))
    {

        int workTimeMin=settings.value("workTimeSetting","").toInt();
        focusClockUi->workTimeSpinBox->setValue(workTimeMin);

    }else {

        qDebug()<<"没有工作时间,请输入";

    }

    if(settings.contains("focusTimesSetting")){


        allfocusTimes=settings.value("focusTimesSetting","").toInt();
        focusClockUi->focusTimes->setText(QString::number(allfocusTimes));

    }else{

    }

    if (settings.contains("focusTimesMinSetting")) {

        allfocusTimesMin=settings.value("focusTimesMinSetting","").toInt();
        focusClockUi->focusTimesMin->setText(QString::number(allfocusTimesMin));
    }


}


void FocusClock::finishFocus()
{

    curfocusTimesMin+=countTimer->elapsed();
    allfocusTimesMin+=curfocusTimesMin/1000;
    QSettings settings("focusClock","AokoPet");
    settings.setValue("focusTimesMinSetting",allfocusTimesMin);


    workTimer->stop();
    countdownTimer->stop();
    qDebug()<<"计数器停止并销毁";
    delete workTimer;
    delete countdownTimer;
    countTimer=nullptr;

    //暂停按钮
    focusClockUi->pauseFocusBtn->setEnabled(false);
    focusClockUi->pauseFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    //结束按钮
    focusClockUi->finishFocusBtn->setEnabled(false);
    focusClockUi->finishFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    //开始按钮
    focusClockUi->startFocusBtn->setEnabled(true);
    focusClockUi->startFocusBtn->setStyleSheet("QPushButton { }");

    //
    focusClockUi->workTimeSpinBox->setEnabled(false);
    //
    focusClockUi->countDownTimeLabel->setText("0");
    //保存按钮
    focusClockUi->saveRBtn->setEnabled(true);
    focusClockUi->saveRBtn->setStyleSheet("QPushButton { }");

    //修改按钮
    focusClockUi->changeRBtn->setEnabled(true);
    focusClockUi->changeRBtn->setStyleSheet("QPushButton { }");

    //选择铃声按钮
    focusClockUi->ringBtn->setEnabled(true);
    focusClockUi->ringBtn->setStyleSheet("QPushButton { }");



}


FocusClock::~FocusClock()
{

    delete focusClockUi;
}




//保存按钮
void FocusClock::on_saveRBtn_clicked()
{

    workTime=focusClockUi->workTimeSpinBox->value()*60*1000;
    focusClockUi->workTimeSpinBox->setEnabled(false);
    focusClockUi->ringBtn->setEnabled(false);
    focusClockUi->ringBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    focusClockUi->startFocusBtn->setEnabled(true);
    focusClockUi->startFocusBtn->setStyleSheet("QPushButton {}");
    //保存设置
    saveSettings();
}


//修改
void FocusClock::on_changeRBtn_clicked()
{
    focusClockUi->workTimeSpinBox->setEnabled(true);
    focusClockUi->startFocusBtn->setEnabled(false);
    focusClockUi->startFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    focusClockUi->pauseFocusBtn->setEnabled(false);
    focusClockUi->pauseFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    focusClockUi->finishFocusBtn->setEnabled(false);
    focusClockUi->finishFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");
    focusClockUi->ringBtn->setEnabled(true);
    focusClockUi->ringBtn->setStyleSheet("QPushButton { }");
    musicPlayer->stop();

}



//开始专注按钮
void FocusClock::on_startFocusBtn_clicked()
{
    startFocus();
    connect(countdownTimer,&QTimer::timeout,this,&FocusClock::countdownTimerOut);

    //暂停按钮
    focusClockUi->pauseFocusBtn->setEnabled(true);
    focusClockUi->pauseFocusBtn->setStyleSheet("QPushButton {}");
    //结束按钮
    focusClockUi->finishFocusBtn->setEnabled(true);
    focusClockUi->finishFocusBtn->setStyleSheet("QPushButton {}");

    // 开始按钮
    focusClockUi->startFocusBtn->setEnabled(false);
    focusClockUi->startFocusBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");


    focusClockUi->workTimeSpinBox->setEnabled(false);

    //保存按钮
    focusClockUi->saveRBtn->setEnabled(false);
    focusClockUi->saveRBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");

    //修改按钮
    focusClockUi->changeRBtn->setEnabled(false);
    focusClockUi->changeRBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");

    //选择铃声按钮
    focusClockUi->ringBtn->setEnabled(false);
    focusClockUi->ringBtn->setStyleSheet("QPushButton { color: gray; background-color: #C0C0C0; }");

}

//暂停按钮
void FocusClock::on_pauseFocusBtn_clicked()
{
    if(pauseBtnValue){
        focusClockUi->pauseFocusBtn->setText("continue");
        workTimer->stop();
        countdownTimer->stop();
        qDebug()<<"工作时间暂停,计时停止";
        remainingTime=workTime-countTimer->elapsed();
        curfocusTimesMin=workTime-remainingTime;
        pauseBtnValue=false;
    }else{
        focusClockUi->pauseFocusBtn->setText("pause");
        workTimer->start(remainingTime);
        countDownTime=remainingTime;
        workTime=countDownTime;
        countdownTimer->start();
        qDebug()<<"工作时间开始，重新计时";
        countTimer->start();
        pauseBtnValue=true;
    }
}

// 停止按钮
void FocusClock::on_finishFocusBtn_clicked()
{

    finishFocus();

}

//选择音乐按钮
void FocusClock::on_ringBtn_clicked()
{
    musicFilePath = QFileDialog::getOpenFileName(this,
                                                tr("Open Audio File"), "", tr("Audio Files (*.mp3 *.wav)"));


    if(!musicFilePath.isEmpty())
    {
        QFileInfo fileInfo(musicFilePath);
        musicFileName = fileInfo.fileName();
        focusClockUi->musicLabel->setText(musicFileName);
        musicPlayer->setSource(musicFilePath);

    }


}

