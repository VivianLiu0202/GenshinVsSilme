#include "rule.h"
#include "ui_rule.h"

Rule::Rule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rule)
{
    ui->setupUi(this);
    this->resize(QSize(900, 600));//设置界面大小
    this->setWindowTitle("玩法介绍");
    this->setWindowTitle("玩法简介");

    //pushButtonBackForm = new QPushButton("返回",this);
    //pushButtonBackForm->setGeometry(550,400,100,50);

    QPalette palette;
    QPixmap pixmap(":/images/RuleWindowBackground.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    ui->label1->setGeometry(90,75,675,450);
    ui->label2->setGeometry(90,75,675,450);

    QPalette palette1;
    QPixmap pixmap1(":/images/Gamerules.png");
    palette1.setBrush(QPalette::Window, QBrush(pixmap1));
    ui->label2->setPalette(palette1);



    /*connect(pushButtonBackForm,&QPushButton::pressed,this,
            [=](){&Rule::sendSlot});*/
}
Rule::~Rule()
{
    delete ui;
}

/*void Rule::sendSlot()
{
    emit mySignal();
}*/
//在SubWidget的成员函数中自定义了一个槽函数，用来emit mySignal();，
//接着主窗口就会收到并处理子窗口的信号（Form 中自定义槽函数实现）。
