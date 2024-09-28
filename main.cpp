#include "MainWindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSharedMemory sharedMemory("aokoPet");
    // 尝试附加到共享内存
    if (!sharedMemory.create(1)) {
        // 如果创建失败，说明另一个实例正在运行
        QMessageBox::warning(nullptr, "Warning", "已有程序运行");
        return 0; // 退出程序
    }


    MainWindow w;
    w.setWindowIcon(QIcon(":/mainIconBig.ico"));
    w.show();

    return a.exec();
}
