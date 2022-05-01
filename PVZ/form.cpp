#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    pushButton1 = new QPushButton("开始游戏",this);
    pushButton2 = new QPushButton("玩法简介",this);

    label = new QLabel(this);
    label->setStyleSheet("font-size:80px;color:blue");
    label->setText("原神大战丘丘人");
    label->setGeometry(150,100,600,100);

    pushButton1->setGeometry(250,400,100,50);
    pushButton2->setGeometry(550,400,100,50);

    connect(pushButton1,SIGNAL(clicked()),this,
            SLOT(on_pushButton1_clicked()));
    connect(pushButton2,SIGNAL(clicked()),this,
            SLOT(on_pushButton2_clicked()));

    sound = new QSound(":/images/Music1.wav");
    sound->setLoops(QSound::Infinite);
    sound->play();
}

Form::~Form()
{
    delete ui;
    delete sound;
}

void Form::on_pushButton1_clicked()
{
    emit signal_Test();
    this->hide();
    mainwindow = new MainWindow;
    mainwindow->setFixedSize(900, 600);
    mainwindow->setWindowTitle("原神大战丘丘人QAQ");
    mainwindow->show();
}

void Form::on_pushButton2_clicked()
{
    this->hide();
    rulewindow = new Rule;
    rulewindow->setFixedSize(900,600);
    rulewindow->setWindowTitle("玩法介绍");
    rulewindow->show();
}

