#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <about.h>
#include <option.h>
#include <gamestart.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
   void openWindow(QWidget *window);

private:
    Ui::MainWindow *ui;
    class about *about;
    class option *option;
    class gamestart *gamestart;

};
#endif // MAINWINDOW_H
