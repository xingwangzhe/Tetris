#include "mainwindow.h"

#include <QApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("俄罗斯方块");//设置应用程序名
    a.setWindowIcon(QIcon("qrc:/PNG/buttonSquare_beige_pressed.png"));//设置应用程序图标
    MainWindow w;
    w.show();
    return a.exec();
}


