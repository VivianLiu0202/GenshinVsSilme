#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

    QPalette palette;
    QPixmap pixmap(":/images/Title.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->label->setPalette(palette);
    ui->label->setGeometry(100,130,700,150);


    ui->pushButton1->setGeometry(180,350,220,100);
    ui->pushButton2->setGeometry(490,350,220,100);



    //信号与槽的连接
    /*connect(pushButton1,SIGNAL(clicked()),this,
            SLOT(pushButton1_clicked()));

    connect(pushButton2,SIGNAL(clicked()),this,
            SLOT(pushButton2_clicked()));*/

    /*connect(pushButton2,&QPushButton::released,this,
            &Form::changeWin);*/
    /*connect(rulewindow,&Rule::mySignal,this,
            [=](){&Form::dealRule});*/


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
    //this->hide();
    sound->stop();
    mainwindow = new MainWindow;
    mainwindow->setFixedSize(900, 600);
    mainwindow->setWindowTitle("原神大战史莱姆QAQ");
    mainwindow->show();
}

void Form::on_pushButton2_clicked()
{
    //this->hide();
    //sound->stop();
    rulewindow = new Rule;
    rulewindow->show();
}

//使本窗口显示，子窗口隐藏
void Form::dealRule()
{
    this->show();
    sound->play();
    rulewindow->hide();
}
























