#include "Qiqi.h"
#include <QDebug>

Qiqi::Qiqi()
{
    hp = hp_NormalYuanshen;
    time = int(10.0 * 1000 / 33);
    setMovie(":/images/Qiqi.gif");
    setSound((":/images/QiqiJoin.wav"));
}

//生产阳光
void Qiqi::advance(int phase)
{
    if (!phase) return;
    update();
    if (hp <= 0) delete this;

    //无论是否执行里面的语句，都会++counter
    else if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun(pos()));
    }
}


