#include "MainWindow.h"
#include "ui_MainWindow.h"

void MainWindow::initMenu()
{

    menu=new QMenu(this);
    verticalPaintingModeMenu=menu->addMenu("设置立绘模式");
    setVerticalPaintingModeGroup=new QActionGroup(verticalPaintingModeMenu);
    setVerticalPaintingModeGroup->setExclusive(true);
    actionHalfBody=verticalPaintingModeMenu->addAction("半身立绘");
    actionHalfBody->setCheckable(true);
    actionHalfBody->setChecked(true);
    setVerticalPaintingModeGroup->addAction(actionHalfBody);
    actionWholebody=verticalPaintingModeMenu->addAction("全身立绘");
    actionWholebody->setCheckable(true);
    setVerticalPaintingModeGroup->addAction(actionWholebody);

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
    setRandomMoveSpeedGroup=new QActionGroup(menu);
    setRandomMoveSpeedGroup->setExclusive(true);
    moveSpeedLow=randomMoveSpeedSetMenu->addAction("慢");
    moveSpeedLow->setCheckable(true);
    setRandomMoveSpeedGroup->addAction(moveSpeedLow);
    moveSpeedMid=randomMoveSpeedSetMenu->addAction("中");
    moveSpeedMid->setCheckable(true);
    moveSpeedMid->setChecked(true);
    setRandomMoveSpeedGroup->addAction(moveSpeedMid);
    moveSpeedFast=randomMoveSpeedSetMenu->addAction("快");
    moveSpeedFast->setCheckable(true);
    setRandomMoveSpeedGroup->addAction(moveSpeedFast);

    menu->addSeparator();

    clothsSetMenu=menu->addMenu("更换衣服套装");
    setClothsActionGroup = new QActionGroup(menu);
    setClothsActionGroup->setExclusive(true);
    actionSet_01=clothsSetMenu->addAction("(半)围巾校服");
    setClothsActionGroup->addAction(actionSet_01);
    actionSet_02=clothsSetMenu->addAction("(半)家居便服");
    setClothsActionGroup->addAction(actionSet_02);
    actionSet_03=clothsSetMenu->addAction("(半)蓝领毛衣😍");
    setClothsActionGroup->addAction(actionSet_03);
    actionSet_04=clothsSetMenu->addAction("(半)围巾大衣");
    setClothsActionGroup->addAction(actionSet_04);
    actionSet_05=clothsSetMenu->addAction("(半)白羽绒");
    setClothsActionGroup->addAction(actionSet_05);
    clothsSetMenu->addSeparator();
    actionSet_b011=clothsSetMenu->addAction("(全)红连衣裙长黑靴");
    setClothsActionGroup->addAction(actionSet_b011);
    actionSet_b01=clothsSetMenu->addAction("(全)红连衣裙黑裤袜");
    setClothsActionGroup->addAction(actionSet_b01);
    actionSet_b021=clothsSetMenu->addAction("(全)白高领毛衣黑短裙过膝袜雪地靴");
    setClothsActionGroup->addAction(actionSet_b021);
    actionSet_b02=clothsSetMenu->addAction("(全)白羽绒红短裙长黑靴");
    setClothsActionGroup->addAction(actionSet_b02);
    actionSet_b03=clothsSetMenu->addAction("(全)白毛衣红短裙小皮鞋");
    setClothsActionGroup->addAction(actionSet_b03);
    actionSet_b04=clothsSetMenu->addAction("(全)蓝高领毛衣灰牛仔蓝帆布鞋");
    setClothsActionGroup->addAction(actionSet_b04);
    actionSet_b051=clothsSetMenu->addAction("(全)三咲学园校服黑及膝袜");
    setClothsActionGroup->addAction(actionSet_b051);
    actionSet_b052=clothsSetMenu->addAction("(全)三咲学园校服格子围巾黑及膝袜");
    setClothsActionGroup->addAction(actionSet_b052);
    actionSet_b05=clothsSetMenu->addAction("(全)三咲学园校服小皮鞋");
    setClothsActionGroup->addAction(actionSet_b05);
    actionSet_b06=clothsSetMenu->addAction("(全)格子围巾大衣短裙黑及膝袜");
    setClothsActionGroup->addAction(actionSet_b06);
    actionSet_b07=clothsSetMenu->addAction("(全)红发露脐蓝牛仔");
    setClothsActionGroup->addAction(actionSet_b07);


    menu->addSeparator();
    actionSetTop=menu->addAction("置顶");
    actionSetTop->setCheckable(true);
    actionSetTop->setChecked(true);
    menu->addSeparator();
    actionFocusClock=menu->addAction("专注时钟");
    actionStartCalc=menu->addAction("系统计算器");
    actionStartNotepad=menu->addAction("记事本");
    actionOpenGithub=menu->addAction("Github");
    menu->addSeparator();
    actionHideTray=menu->addAction("隐藏到托盘");
    actionExit= menu->addAction("关闭");

    actionSet_b01->setEnabled(false);
    actionSet_b011->setEnabled(false);
    actionSet_b02->setEnabled(false);
    actionSet_b021->setEnabled(false);
    actionSet_b03->setEnabled(false);
    actionSet_b04->setEnabled(false);
    actionSet_b05->setEnabled(false);
    actionSet_b051->setEnabled(false);
    actionSet_b052->setEnabled(false);
    actionSet_b06->setEnabled(false);
    actionSet_b07->setEnabled(false);


    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested, [=]() {
        menu->exec(QCursor::pos());
    });


    //半身立绘
    connect(actionHalfBody,&QAction::triggered,this,[=](bool checked){

        actionExpression->setEnabled(true);
        actionSet_01->setEnabled(true);
        actionSet_02->setEnabled(true);
        actionSet_03->setEnabled(true);
        actionSet_04->setEnabled(true);
        actionSet_05->setEnabled(true);

        actionSet_b01->setEnabled(false);
        actionSet_b011->setEnabled(false);
        actionSet_b02->setEnabled(false);
        actionSet_b021->setEnabled(false);
        actionSet_b03->setEnabled(false);
        actionSet_b04->setEnabled(false);
        actionSet_b05->setEnabled(false);
        actionSet_b051->setEnabled(false);
        actionSet_b052->setEnabled(false);
        actionSet_b06->setEnabled(false);
        actionSet_b07->setEnabled(false);
        MainWindow::resize(350,438);
        ui->label->resize(291,411);
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/03.png)"));
        ui->differenceLabel->setStyleSheet("image: url(:/assets/aokohalf/01scarf/01scanf_all/14.png)");

        on_homeBtn_clicked();

    });

    //全身立绘
    connect(actionWholebody,&QAction::triggered,this,[=](){

        actionExpression->setEnabled(false);
        if(updateTimer->isActive()){
            actionExpression->setChecked(false);
            updateTimer->stop();
        }
        actionSet_01->setEnabled(false);
        actionSet_02->setEnabled(false);
        actionSet_03->setEnabled(false);
        actionSet_04->setEnabled(false);
        actionSet_05->setEnabled(false);

        actionSet_b01->setEnabled(true);
        actionSet_b011->setEnabled(true);
        actionSet_b02->setEnabled(true);
        actionSet_b021->setEnabled(true);
        actionSet_b03->setEnabled(true);
        actionSet_b04->setEnabled(true);
        actionSet_b05->setEnabled(true);
        actionSet_b051->setEnabled(true);
        actionSet_b052->setEnabled(true);
        actionSet_b06->setEnabled(true);
        actionSet_b07->setEnabled(true);

        ui->differenceLabel->setStyleSheet("QLabel { }");
        MainWindow::resize(350,620);
        ui->label->resize(291,600);
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b07.png)"));

        on_homeBtn_clicked();

    });



    //更换差分表情
    connect(actionExpression,&QAction::triggered,this,[=](bool checked){

        if(checked)
        {
            updateTimer->callOnTimeout(this,&MainWindow::updateAnimePicture);
            updateTimer->start(TIME_INTERVAL);

        }else
        {
            updateTimer->stop();
        }

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


    //随机运动
    connect(actionRandomMove,&QAction::triggered,this,[=](bool checked){

        randomMove(checked);

    });

    //移动速度
    connect(moveSpeedLow,&QAction::triggered,this,[=](){

        randomMoveSpeed=8000;

    });
    connect(moveSpeedMid,&QAction::triggered,this,[=](){

        randomMoveSpeed=4000;

    });
    connect(moveSpeedFast,&QAction::triggered,this,[=](){

        randomMoveSpeed=2000;

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


    //打开与关闭时钟
    connect(actionFocusClock,&QAction::triggered,this,[=](){


        messageBoxReply = QMessageBox::question(this, "温馨提示", "是否打开专注时钟?",
                                                QMessageBox::Yes|QMessageBox::No);
        if (messageBoxReply == QMessageBox::Yes) {

                fc=new FocusClock();
                fc->show();
                actionFocusClock->setEnabled(false);

        }

        connect(fc->focusClockUi->closeBtn,&QPushButton::clicked,fc,[=](){

            messageBoxReply = QMessageBox::question(this, "警告", "是否关闭专注时钟? 专注信息将会保存到本地",
                                                    QMessageBox::Yes|QMessageBox::No);

            if (messageBoxReply == QMessageBox::Yes) {

                fc->close();
                actionFocusClock->setEnabled(true);
                delete fc;
                fc=nullptr;
            }

        });

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




    //更换套装
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

    connect(actionSet_05,&QAction::triggered,this,[=](){


        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/05.png);"));


    });
    connect(actionSet_b01,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b01.png);"));});
    connect(actionSet_b011,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b01.1.png);"));});
    connect(actionSet_b021,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b02.1.png);"));});
    connect(actionSet_b02,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b02.png);"));});
    connect(actionSet_b03,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b03.png);"));});
    connect(actionSet_b04,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b04.png);"));});
    connect(actionSet_b051,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b05.1.png);"));});
    connect(actionSet_b052,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b05.2.png);"));});
    connect(actionSet_b05,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b05.png);"));});
    connect(actionSet_b06,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b06.png);"));});
    connect(actionSet_b07,&QAction::triggered,this,[=](){
        ui->label->setStyleSheet(QString("image: url(:/assets/aokohalf/systemic/b07.png);"));});



    //隐藏到托盘
    connect(actionHideTray,&QAction::triggered,this,[=](){this->hide();});


    //关闭
    connect(actionExit,&QAction::triggered,this,[=](){

        if(fc!=nullptr){

            messageBoxReply = QMessageBox::question(this, "警告", "是否连同专注时钟一同关闭? 专注信息将会保存到本地",
                                                    QMessageBox::Yes|QMessageBox::No);
            if (messageBoxReply == QMessageBox::Yes) {


                this->close();
                fc->close();
                delete fc;

            }

        }else{

            messageBoxReply = QMessageBox::question(this, "警告", "是否关闭主窗口？",
                                                    QMessageBox::Yes|QMessageBox::No);
            if (messageBoxReply == QMessageBox::Yes) {


                this->close();

            }

        }


    });


}


