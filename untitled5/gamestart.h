#ifndef GAMESTART_H
#define GAMESTART_H

#include <QKeyEvent>
#include <QMainWindow>

namespace Ui {
    class gamestart;
}

class gamestart : public QMainWindow
{
    Q_OBJECT

public:
    explicit gamestart(QWidget *parent = nullptr);
    ~gamestart();

protected:
    void keyPressEvent(QKeyEvent *e);

public slots:
    void slotUpdateScore(int nScore);
    void slotUpdateLevel(int nSpeed);
    void openWindow();

private:
    Ui::gamestart *ui;
};

#endif

