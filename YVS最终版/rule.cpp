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
    setWindowIcon(QIcon(":/images/Icon.png"));


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

    ui->pushButton->setGeometry(0,0,200,80);

}
Rule::~Rule()
{
    delete ui;
}

void Rule::on_pushButton_clicked()
{
    emit mySignal();
}
