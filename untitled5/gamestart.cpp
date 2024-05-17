#include "gamestart.h"
#include "ui_gamestart.h"
gamestart::gamestart(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gamestart)
{
    ui->setupUi(this);
    setFixedSize(1000, 800);
    //widgetGameArea 和 widgetNextArea 已在界面设计器内由普通QWidget分别提升成GameArea和NextArea
    //GameArea: 左侧游戏区域，自绘widget
    //NextArea: 右侧显示下个item的widget，也是自绘widget
    //游戏主运行逻辑在GameArea内，不过按键消息因为是MainWindow接受，通过ui->widgetGameArea->KeyPressed()函数调用传递下去
    //GameArea通过信号sigUpdateScore、sigUpdateLevel 通知MainWindow更新界面的得分和关卡
    //GameArea通过信号sigUpdateNextItem 通知 NextArea 刷新下一个元素
    connect(ui->widgetGameArea, &GameArea::sigUpdateScore, this, &gamestart::slotUpdateScore);
    connect(ui->widgetGameArea, &GameArea::sigUpdateLevel, this, &gamestart::slotUpdateLevel);
    connect(ui->widgetGameArea, &GameArea::sigUpdateNextItem, ui->widgetNextArea, &NextArea::slotUpdateNextItem);
    ui->widgetGameArea->NewGame();
}

gamestart::~gamestart()
{
    delete ui;
}
void gamestart::keyPressEvent(QKeyEvent *e)
{
    ui->widgetGameArea->KeyPressed(e->key());
    QMainWindow::keyPressEvent(e);
}
void gamestart::slotUpdateScore(int nScore)
{
    ui->labelScore->setText(QString::number(nScore));
}
void gamestart::slotUpdateLevel(int nSpeed)
{
    ui->labelSpeed->setText(QString::number(nSpeed));
}
void gamestart::openWindow()
{
    gamestart *startWindow = new gamestart;
    startWindow->show();
}
