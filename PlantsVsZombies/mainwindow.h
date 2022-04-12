#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() override;
    void addZombies();
    void check();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QGraphicsScene *scene;
    QGraphicsView *view;

    static int ZOMBIE_GEN_TIMES_NOW;
};

#endif // MAINWINDOW_H
