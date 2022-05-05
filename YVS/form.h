#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QPushButton>
#include <QSound>
#include <Qmediaplayer>
#include <QLabel>
#include "./src/other/mainwindow.h"
#include <rule.h>
#include<QDebug>


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    void dealRule();
    //void changeWin();
    //void myslot();
    ~Form();

private slots:
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();

private:
    Ui::Form *ui;
    MainWindow *mainwindow;
    Rule *rulewindow;
    //QPushButton *pushButton1;//开始游戏的按钮
    //QPushButton *pushButton2;//介绍游戏规则
    QSound *sound;

};

#endif // FORM_H
