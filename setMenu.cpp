#include "mainWindow.h"
#include "ui_mainWindow.h"


void MainWindow::initMenu()
{

    menu=new QMenu(this);
    actionExpression = menu->addAction("所有表情轮换");
    actionExpression->setCheckable(true);
    actionExpression->setChecked(false);

    actionFixedLocation = menu->addAction("鼠标锁定");
    actionFixedLocation->setCheckable(true);
    actionFixedLocation->setChecked(false);

    actionRandomMove = menu->addAction("随机移动");
    actionRandomMove->setCheckable(true);
    actionRandomMove->setChecked(false);
    randomMoveSpeedSetMenu=menu->addMenu("移动速度");
    setRandomMoveSpeedGroup=new QActionGroup(this);
    setRandomMoveSpeedGroup->setExclusive(true);
    moveSpeedLow=randomMoveSpeedSetMenu->addAction("慢");
    moveSpeedMid=randomMoveSpeedSetMenu->addAction("中");
    moveSpeedFast=randomMoveSpeedSetMenu->addAction("快");
    menu->addSeparator();

    clothsSetMenu=menu->addMenu("更换衣服套装");
    setClothsActionGroup = new QActionGroup(this);
    setClothsActionGroup->setExclusive(true);
    actionSet_01=clothsSetMenu->addAction("围巾校服");
    actionSet_01->setActionGroup(setClothsActionGroup);
    actionSet_02=clothsSetMenu->addAction("家居便服");
    actionSet_02->setActionGroup(setClothsActionGroup);
    actionSet_03=clothsSetMenu->addAction("蓝领毛衣");
    actionSet_03->setActionGroup(setClothsActionGroup);
    actionSet_04=clothsSetMenu->addAction("围巾大衣");
    actionSet_04->setActionGroup(setClothsActionGroup);


    menu->addSeparator();
    actionSetTop=menu->addAction("置顶");
    actionSetTop->setCheckable(true);
    actionSetTop->setChecked(true);
    menu->addSeparator();
    actionStartCalc=menu->addAction("系统计算器");
    actionStartNotepad=menu->addAction("记事本");
    actionOpenGithub=menu->addAction("Github");
    menu->addSeparator();
    actionHideTray=menu->addAction("隐藏到托盘");
    actionExit= menu->addAction("关闭");

    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested, [=]() {
        menu->exec(QCursor::pos());
    });


    //更换差分表情
    connect(actionExpression,&QAction::triggered,this,[=](bool checked){

        if(checked)
        {
            updateTimer->start(TIME_INTERVAL);

        }else
        {
            updateTimer->stop();
        }

    });


    //置顶
    connect(actionSetTop,&QAction::triggered,this,[=](bool checked){

        if(checked)
        {
            this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

        }else
        {

            this->setWindowFlags(this->windowFlags() & ~Qt::WindowStaysOnTopHint);

        }
        this->show();

    });


    //鼠标锁定
    connect(actionFixedLocation,&QAction::triggered,this,[=](bool checked){
        if (checked)
        {

            positionSignalNum=false;
            ui->fixedBtn->setStyleSheet(QString("image: url(:/assets/icon/lock.png)"));

        } else
        {

            positionSignalNum=true;
            ui->fixedBtn->setStyleSheet(QString("image: url(:/assets/icon/unlock.png)"));

        }


    });

    //调用计算器
    connect(actionStartCalc,&QAction::triggered,this,[=](){

        process=new QProcess(this);
        process->start("calc");


    });

    //调用记事本
    connect(actionStartNotepad,&QAction::triggered,this,[=](){

        process=new QProcess(this);
        process->start("notepad");


    });


    //进入github
    connect(actionOpenGithub,&QAction::triggered,this,[=](){

        QUrl url("https://www.Github.com");
        QDesktopServices::openUrl(url);

    });

    //随机运动
    connect(actionRandomMove,&QAction::triggered,this,[=](bool checked){

            randomMove(checked);

    });


    connect(actionSet_01,&QAction::triggered,this,[=](){


        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/01.png);"));


    });



    connect(actionSet_02,&QAction::triggered,this,[=](){


        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/02.png);"));


    });

    connect(actionSet_03,&QAction::triggered,this,[=](){


        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/03.png);"));


    });
    connect(actionSet_04,&QAction::triggered,this,[=](){


        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/04.png);"));


    });

    //隐藏到托盘
    connect(actionHideTray,&QAction::triggered,this,[=](){this->hide();});


    //关闭
    connect(actionExit,&QAction::triggered,this,[=](){

        int reply;
        reply = QMessageBox::question(this, "警告", "是否关闭?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {

            this->close();
        }

    });


}
