#include "mainwindow.h"
//#include "ui_mainwindow.h"


    //左screenGeometry.x(),
    //上screenGeometry.y(),

    //左screenGeometry.x(),
    //心screenGeometry.center().y()- height() / 2,
    //
    //左screenGeometry.x(),
    //下screenGeometry.height() - height()-42,


    //中上
    //screenGeometry.center().x()- width() / 2,
    //screenGeometry.y(),
    //中心坐标
    //screenGeometry.center().x()- width() / 2,
    //screenGeometry.center().y()- height() / 2,
    //中下
    //screenGeometry.center().x()- width() / 2,
    //screenGeometry.height() - height()-42


    //右上
    //screenGeometry.x() + (screenGeometry.width()-width()+50),
    //screenGeometry.y(),
    //右心
    //screenGeometry.x() + (screenGeometry.width()-width()+50),
    //screenGeometry.center().y()- height() / 2,
    //右下
    //screenGeometry.x() + (screenGeometry.width()-width()+50),
    //screenGeometry.height() - height()-42



void MainWindow::randomMove(bool checked){


    if(!checked)
    animation_random_move->destroyed();
    QPoint pos= this->pos();
    animation_random_move = new QPropertyAnimation(this, "geometry");
    animation_random_move->setDuration(RANDOM_ANIMATION_TIME);
    animation_random_move->setEasingCurve(QEasingCurve::OutQuad);
    xRandomNum = QRandomGenerator::global()->bounded(3);
    yRandomNum = QRandomGenerator::global()->bounded(3);
    animation_random_move->setStartValue(QRect(pos.x(),pos.y(),
                                               width(), height()));
    animation_random_move->setEndValue(QRect(XLCR[xRandomNum],YTCB[yRandomNum],width(), height()));
    if(checked){
        animation_random_move->start();
    }


    connect(animation_random_move, &QPropertyAnimation::finished, this,[=](){

        QPoint pos = this->pos();
        xRandomNum = QRandomGenerator::global()->bounded(3);
        yRandomNum = QRandomGenerator::global()->bounded(3);
        animation_random_move->setStartValue(QRect(pos.x(),pos.y(),
                                                   width(), height()));
        animation_random_move->setEndValue(QRect(XLCR[xRandomNum],YTCB[yRandomNum],width(), height()));

        if(checked)
        animation_random_move->start();

    });

}







