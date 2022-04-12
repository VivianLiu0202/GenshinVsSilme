#include "mainwindow.h"
#include "ui_mainwindow.h"

int MainWindow::ZOMBIE_GEN_TIMES_NOW=0;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowIcon(QIcon(""));//设置图标
    //随机数种子
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));

   // sound = new QSound("");
   // sound->setLoops(QSound::Infinite);//无线循环播放音乐

    timer = new QTimer;
    //创建新场景
    scene = new QGraphicsScene(this);
    scene->setSceneRect(150,0,900,600);
    /*
     * 索引算法，在场景中进行图形项查找
     */
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    //加入卡片槽等部件


    //背景图场景
    view = new QGraphicsView(scene,this);
    view->resize(902,602);

    view->setRenderHint(QPainter::Antialiasing);
    //view->setBackgroundBrush(QPixmap(""));

    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    connect(timer,&QTimer::timeout,scene,&QGraphicsScene::advance);
    connect(timer,&QTimer::timeout,this,&MainWindow::addZombies);
    connect(timer,&QTimer::timeout,this,&MainWindow::check);

    //sound->play();
    timer->start(33);
    view->show();
}

MainWindow::~MainWindow()
{
    //delete sound;
    delete timer;
    delete scene;
    delete view;
    delete ui;
}

void MainWindow::addZombies()
{
    /*static int time = GEN_ONE_TIME;
    static int counter=0;
    if(ZOMBIE_GEN_TIMES_NOW < ZOMBIE_GEN_TIMES)
    {
        if(++counter >= time)
        {
            ZOMBIE_GEN_TIMES_NOW++;
            counter=0;
            //随机生成类型与出现位置
            int type = qrand()%100;
            int i=qrand() % 5;
        }
    }
    */
}

//检查胜负状态
//使用静态变量
void MainWindow::check()
{


}










