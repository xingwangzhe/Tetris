#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"
#include "option.h"
#include "gamestart.h"
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
setFixedSize(1000, 800);
  about=new class about();
  option=new class option();
  //gamestart=new class gamestart();
    connect(ui->pushButton_3, &QPushButton::clicked, this,  [this](){ openWindow(about); });
    connect(ui->pushButton_2, &QPushButton::clicked, this,  [this](){ openWindow(option); });
    connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
       class gamestart *startWindow = new class gamestart;
        startWindow->show();
    });


}
void MainWindow::openWindow(QWidget *window)
{
    window->setWindowModality(Qt::ApplicationModal);
    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width() - window->width()) / 2;
    int y = (screenGeometry.height() - window->height()) / 2;
    window->setGeometry(x, y, window->width(), window->height());
    window->show();
}
MainWindow::~MainWindow()
{
    delete ui;
}

