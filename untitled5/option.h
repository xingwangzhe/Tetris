#ifndef OPTION_H
#define OPTION_H

#include <QWidget>
#include <QSlider>
#include <QLabel>
#include <QMediaPlayer>
#include <QCheckBox>
namespace Ui {
class option;
}

class option : public QWidget
{
    Q_OBJECT

public:
    explicit option(QWidget *parent = nullptr);
    ~option();
    QSlider *horizontalSlider;
    QLabel *label_4;
private slots:
    void music(int state);
    void music_volume(int volume);
private:
    Ui::option *ui;
    QMediaPlayer *player;
    //QCheckBox *checkbox;
};

#endif // OPTION_H
