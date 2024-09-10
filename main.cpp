#include "mainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowIcon(QIcon(":/mainIconBig.ico"));
    w.show();

    return a.exec();
}
