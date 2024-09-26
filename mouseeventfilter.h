#ifndef MOUSEEVENTFILTER_H
#define MOUSEEVENTFILTER_H

#include <QObject>
#include <QMouseEvent>
class MouseEventFilter : public QObject
{
    Q_OBJECT
public:
    explicit MouseEventFilter(QObject *parent = nullptr);

signals:

protected:
    bool eventFilter(QObject *obj, QEvent *event) override {
        if (event->type() == QEvent::MouseMove) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
            if (mouseEvent->pos().y() <= 10) { // 假设屏幕顶部10像素内为触发区域
                qDebug() << "Mouse moved to the top of the screen!";
                // 在这里调用你的自定义槽函数或执行其他操作
                // customSlotFunction();
                return true; // 表示事件已被处理
            }
        }
        // 对于其他事件，调用基类的eventFilter
        return QObject::eventFilter(obj, event);
    }

};

#endif // MOUSEEVENTFILTER_H
