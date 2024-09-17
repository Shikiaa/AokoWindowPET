#include "ui_MainWindow.h"
#include "MainWindow.h"

void MainWindow::initTrayIcon(){

    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/mainIconBig.ico"));
    if(QSystemTrayIcon::isSystemTrayAvailable()){
        trayIcon->show();
    }

    setTrayIconMenu();

    connect(trayIcon, &QSystemTrayIcon::activated, this, &MainWindow::onTrayIconActivated);

}

void MainWindow::setTrayIconMenu(){

    trayIconMenu=new QMenu(this);
    trayIconShowAction = trayIconMenu->addAction("显示");
    trayIconQuitAction = trayIconMenu->addAction("退出");

    connect(trayIconShowAction,&QAction::triggered,this,[=](){

        this->show();

    });


    connect(trayIconQuitAction,&QAction::triggered,this,[=](){

        this->show();
        int reply;
        reply = QMessageBox::question(this, "警告", "是否关闭?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            this->close();
        }

    });


    trayIcon->setContextMenu(trayIconMenu);
}


void MainWindow::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason) {
    switch (reason) {
    case QSystemTrayIcon::Trigger:

        break;
    case QSystemTrayIcon::DoubleClick:
        // 处理双击事件

        break;
        // 其他情况...
    }
}
