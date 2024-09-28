#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define TIME_INTERVAL 1200 //自动归位动画的时间毫秒值
#define RANDOM_ANIMATION_TIME 2000 //随机移动动画的毫秒值

#include "FocusClock.h"
#include "ui_FocusClock.h"
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>
#include <QContextMenuEvent>
#include <QDesktopServices>
#include <QRandomGenerator>
#include <QSystemTrayIcon>
#include <QActionGroup>
#include <QSharedMemory>
#include <QMessageBox>
#include <QMouseEvent>
#include <QMouseEvent>
#include <QMainWindow>
#include <QPushButton>
#include <QProcess>
#include <QWidget>
#include <QScreen>
#include <QDialog>
#include <QTimer>
#include <QMenu>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    /*---初始化参数与界面窗口------------*/
    void initMyWindow(); //初始化主窗口
    void initValues(); //初始化全局参数
    void initMenu(); //初始化菜单
    void initTrayIcon(); //初始化托盘



    void updateAnimePicture(); //更新差分表情
    void randomMove(bool checked);//随机移动
    void setTrayIconMenu(); //设置托盘菜单

    /*---工具函数，便于随时设置------------*/
    void mouseLock();//鼠标解锁
    void mouseUnlock();//鼠标锁定
    void homeBtnDefaultAttribute();//每次点击"回家"键(归位键），默认设置的属性与行为


    bool eventFilter(QObject*watched ,QEvent* ev) override;//监测鼠标事件

    ~MainWindow();



private slots:
    void on_homeBtn_clicked();//自动归位右下角
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);



private:
    Ui::MainWindow *ui;

    QTimer* updateTimer;//创建定时器
    QRect screenGeometry; //获取屏幕位置
    QProcess* process; //进程
    QPropertyAnimation* animation;
    QPropertyAnimation* homeAnimation;
    QPropertyAnimation* animation_start; //随机线性移动的起始
    QPropertyAnimation* animation_random_move;
    QMessageBox* closeMessageBox;

    QMenu* menu; //右键主菜单
    QMenu* clothsSetMenu; //更换套装副菜单
    QMenu* randomMoveSpeedSetMenu;//设置随机移动速度的副菜单
    QMenu* verticalPaintingModeMenu;//设置更换立绘模式的菜单


    QAction* actionRandomMove; //随机移动
    QAction* actionExpression; //控制差分表情
    QAction* actionFixedLocation; //鼠标锁定

    QActionGroup* setClothsActionGroup;//创建更换套装选项组
    QAction* actionSet_01; //半身第一套衣服，下同理
    QAction* actionSet_02;
    QAction* actionSet_03;
    QAction* actionSet_04;
    QAction* actionSet_05;
    QAction* actionSet_b011;//全身
    QAction* actionSet_b01;
    QAction* actionSet_b021;
    QAction* actionSet_b02;
    QAction* actionSet_b03;
    QAction* actionSet_b04;
    QAction* actionSet_b05;
    QAction* actionSet_b051;
    QAction* actionSet_b052;
    QAction* actionSet_b06;
    QAction* actionSet_b07;

    QAction* actionSetTop; //置顶
    QAction* actionFocusClock; //专注时钟
    QAction* actionStartCalc; //调用计算器
    QAction* actionStartNotepad; //打开记事本
    QAction* actionOpenGithub; //打开Github
    QAction* actionHideTray; //隐藏到托盘
    QAction* actionExit;    //退出

    QActionGroup* setRandomMoveSpeedGroup; //设置随机移动的速度的选项组
    QAction* moveSpeedFast;
    QAction* moveSpeedMid;
    QAction* moveSpeedLow;


    QActionGroup* setVerticalPaintingModeGroup; //设置立绘模式
    QAction* actionHalfBody; //半身立绘
    QAction* actionWholebody; //全身立绘


    QSystemTrayIcon* trayIcon;//托盘图标属性
    QMenu* trayIconMenu;//托盘菜单
    QAction* trayIconQuitAction; //退出程序
    QAction* trayIconClockShowAction; //时钟展示
    QAction* trayIconShowAction; //显示角色

    //bool verticalPaintingModeValue=true;

    std::vector<int> XLCR; //屏幕左上为原点 x方向左中右 LCR
    std::vector<int> YTCB; //y方向上心下 TCR  这样就有了九个随机位置
    int xRandomNum; //用于产生x轴的随机方向的信号数值，下同理
    int yRandomNum; //y轴
    int randomMoveSpeed; //随机移动速度
    bool positionSignalNum=true; //鼠标锁定信号值
    int messageBoxReply;
    int curTime=1; //用于选择差分表情的信号数值
    FocusClock* fc=nullptr;
    Ui::FocusClock *fcUi=nullptr;
};

#endif // MAINWINDOW_H
