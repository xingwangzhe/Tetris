#include "option.h"
#include "ui_option.h"
#include <QMediaPlayer>
option::option(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::option)
{
    ui->setupUi(this);
  player = new QMediaPlayer(this);
   player->setMedia(QUrl("qrc:/PNG/Black/ssb.mp3"));
    // 设置窗口标志，禁用最小化按钮
    setWindowFlags(windowFlags() & ~Qt::WindowMinimizeButtonHint);
    setFixedSize(400, 300);

    // 初始状态：水平滑块不启用
    //ui->horizontalSlider->setEnabled(false);

    // 连接复选框的状态更改信号到 music 函数
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &option::music);

    // 连接水平滑块的值更改信号到 music_volume 函数
    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &option::music_volume);
}

void option::music(int state)
{
    if(state == Qt::Checked)
    {

        // 播放音乐
        player->play();

        // 当复选框被选中时启用option类中的水平滑块
        ui->horizontalSlider->setEnabled(true);
    }
    else
    {
        if(player)
        {
            // 当复选框未被选中时禁用option类中的水平滑块
            ui->horizontalSlider->setEnabled(false);

            // 暂停音乐播放
            player->pause();
        }
    }
}

void option::music_volume(int volume)
{
    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(100);
    ui->label_4->setText(QString::number(volume) + "%");

    if (player != nullptr) {
       player->setVolume(volume);
    }
}

option::~option()
{
    delete ui;
}
