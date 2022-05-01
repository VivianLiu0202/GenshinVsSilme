#include "mainwindow.h"

/*MainWindow控制整个游戏的运行，具体流程为：
1. 播放背景音乐
2. 创建场景，设置边界
3. 创建商店（卡片槽）、卡片、铲子、地图、割草机，加入场景（背景图）
4. 创建视图，设置背景和大小
5. 创建计时器，将计时器事件timeout()绑定到场景advance()
6. 将计时器事件绑定到僵尸生成函数addZombie()和胜负判断函数check()
*/


//初始化！！！在源文件！！！
int MainWindow::SLIME_GEN_TIMES_NOW=0;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowIcon(QIcon("./images/window.ico"));

    //随机数种子
    qsrand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));

    sound = new QSound(":/images/Music2.wav");
    sound->setLoops(QSound::Infinite);


    timer = new QTimer;

    //创建场景
    scene = new QGraphicsScene(this);//建立坐标系
    scene->setSceneRect(150, 0, 900, 600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);


    //加入卡片槽等部件
    Shop *shop = new Shop;
    shop->setPos(520, 45);
    scene->addItem(shop);

    Shovel *shovel = new Shovel;
    shovel->setPos(830, 40);
    scene->addItem(shovel);

    Button *button = new Button(sound, timer);
    button->setPos(970, 20);
    scene->addItem(button);

    Map *map = new Map;
    map->setPos(619, 325);
    scene->addItem(map);

    for (int i = 0; i < 5; ++i)
    {
        Mower *mower = new Mower;
        mower->setPos(210, 130 + 98 * i);
        scene->addItem(mower);
    }


    //背景图场景
    view = new QGraphicsView(scene, this);
    view->resize(902, 602);

    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/images/Background.jpg"));

    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    connect(timer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    connect(timer, &QTimer::timeout, this, &MainWindow::addSlime);
    connect(timer, &QTimer::timeout, this, &MainWindow::check);

    //播放音乐，启动定时器等等
    sound->play();

    timer->start(40);//表示每次timeout的时间间隔是40ms
    view->show();
}

MainWindow::~MainWindow()
{
    //delete sound;
    delete player;
    delete timer;
    delete scene;
    delete view;
}

//生成僵尸
void MainWindow::addSlime()
{
    static int time = GEN_ONE_TIME;
    static int counter = 0;

    if (SLIME_GEN_TIMES_NOW < SLIME_GEN_TIMES)
    {
        if (++counter >= time)
        {
            SLIME_GEN_TIMES_NOW++;
            counter = 0;

            //随机生成类型和出现
            int type = qrand() % 100;//设置生成僵尸的概率
            int i = qrand() % 5;//设置僵尸出现

            Slime *slime;
            if (type < 20) slime = new Anemo();
            else if (type < 40) slime = new Cyro();
            else if (type < 60) slime = new Eletro();
            else if (type < 80) slime = new Hydro();
            else slime = new Pyro();

            slime->setPos(1028, 130 + 98 * i);

            scene->addItem(slime);
        }
    }
    
}

//检查胜负状态,使用静态变量！！！
void MainWindow::check()
{
    static int time = GEN_ONE_TIME/10;
    static int counter = 0;
    if (++counter >= time)
    {
        //判断是否输了
        counter = 0;
        const QList<QGraphicsItem *> items = scene->items();
        foreach (QGraphicsItem *item, items)
        {
            //僵尸到达了左边
            if (item->type() == Slime::Type && item->x() < 200)
            {
                scene->addPixmap(QPixmap(":/images/ZombiesWon.png"))->setPos(336, 92);
                scene->advance();
                timer->stop();
                return;
            }
        }

        //没输，再判断是不是最后一次，如果是的话：并且没有僵尸了，就赢了
        if (SLIME_GEN_TIMES_NOW == SLIME_GEN_TIMES)
        {
            foreach (QGraphicsItem *item, items)
            {
                //还有僵尸就return
                if (item->type() == Slime::Type)
                {
                    return;
                }
            }
            //到这里说明没有僵尸了，赢了！！！
            scene->addPixmap(QPixmap(":/images/PlantsWin.jpg"))->setPos(336, 92);
            scene->advance();
            timer->stop();
            return;
        }
    }
}
