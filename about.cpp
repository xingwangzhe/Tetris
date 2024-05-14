#include "about.h"
#include "ui_about.h"

about::about(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::about)
{
    ui->setupUi(this);
    // 设置窗口标志，禁用最小化按钮
    setWindowFlags(windowFlags() & ~Qt::WindowMinimizeButtonHint);

    setFixedSize(400, 300);
}

about::~about()
{
    delete ui;
}
