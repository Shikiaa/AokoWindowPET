#include "MainWindow.h"
#include "ui_MainWindow.h"


void MainWindow::mouseLock(){

    actionFixedLocation->setChecked(true);
    positionSignalNum=false;
    ui->fixedBtn->setStyleSheet(QString("image: url(:/assets/icon/lock.png)"));



}


void MainWindow::mouseUnlock(){


    actionFixedLocation->setChecked(false);
    positionSignalNum=true;
    ui->fixedBtn->setStyleSheet(QString("image: url(:/assets/icon/unlock.png)"));


}


void MainWindow::homeBtnDefaultAttribute(){

    //结束随机移动，并且锁定鼠标
    actionRandomMove->setChecked(false);
    mouseLock();


}
