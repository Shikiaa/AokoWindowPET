#ifndef FOCUSCLOCK_H
#define FOCUSCLOCK_H


#include <QPropertyAnimation>
#include <QElapsedTimer>
#include <QApplication>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QFileDialog>
#include <QMouseEvent>
#include <QDateTime>
#include <QSettings>
#include <QScreen>
#include <QWidget>
#include <QTimer>

#include <QUrl>

namespace Ui {
class FocusClock;
}

class FocusClock : public QWidget
{
    Q_OBJECT

public:
    explicit FocusClock(QWidget *parent = nullptr);

    void initFocusClock(); //初始化设置
    void finishFocus(); //结束一段时间的专注后
    void setInitPosition(); //设置归位与右上角的动画
    void updateClock(); //更新系统时间
    void slideOut(); //窗体出现
    void slideIn(); //窗体收回

    void startFocus(); //开始专注
    void pauseFocus(); //暂停专注
    void endFocus(); //结束专注

    void workTimerOut();//一个工作周期结束
    void countdownTimerOut();
    void saveSettings(); //保存设置
    void loadSettings(); //读取设置



    Ui::FocusClock* focusClockUi;

    ~FocusClock();

protected:
    void enterEvent(QEnterEvent* event) override;
    void leaveEvent(QEvent* event) override;


private slots:

    void on_saveRBtn_clicked();  //保存设置按钮
    void on_changeRBtn_clicked(); //修改设置按钮

    void on_startFocusBtn_clicked(); //开始专注
    void on_pauseFocusBtn_clicked(); //暂停专注
    void on_finishFocusBtn_clicked(); //停止专注

    void on_ringBtn_clicked();

private:
    void checkMousePosition();


public:
    int allfocusTimesMin=0;//总专注分钟
private:

    QPropertyAnimation* setInitPositionAnimation; //初始动画
    QPropertyAnimation* setWindowAnimation; //隐藏与出现动画
    QDateTime currentDateTime; //当前时间
    QElapsedTimer* countTimer;
    QMediaPlayer* musicPlayer;
    QAudioOutput* musicOutput;
    QTimer* focusTimer;
    QTimer* workTimer;
    QTimer* windowStatusTimer;
    QTimer* countdownTimer;
    QString workTimeText;
    QString musicFilePath;
    QString musicFileName;
    QString currentTime;
    QRect screenGeometryClock;
    qint64 countDownTime;


    int workTime=0; //工作时间间隔
    int allfocusTimes=0; //总专注次数

    int curfocusTimesMin=0; //本次专注分钟
    bool windowStatusValue=true;
    bool pauseBtnValue=true;
    int remainingTime=0;


};

#endif // FOCUSCLOCK_H
