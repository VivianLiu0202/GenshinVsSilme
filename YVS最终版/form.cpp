#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/images/Icon.png"));

    QPalette palette;
    QPixmap pixmap(":/images/Title.png");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    ui->label->setPalette(palette);
    ui->label->setGeometry(100,130,700,150);


    ui->pushButton1->setGeometry(180,350,220,100);
    ui->pushButton2->setGeometry(490,350,220,100);
    rulewindow = new Rule;
    connect(rulewindow,&Rule::mySignal,this,
            &Form::dealRule);

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
    this->hide();
    sound->stop();
    mainwindow = new MainWindow;
    mainwindow->setFixedSize(900, 600);
    mainwindow->setWindowTitle("原神大战史莱姆QAQ");
    mainwindow->show();
}

void Form::on_pushButton2_clicked()
{
    this->hide();
    rulewindow->show();
}

//使本窗口显示，子窗口隐藏
void Form::dealRule()
{
    this->show();
    rulewindow->hide();
}























