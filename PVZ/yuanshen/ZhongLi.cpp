#include "ZhongLi.h"
#include <QDebug>

Zhongli::Zhongli()
{
    hp = hp_Zhongli;
    setMovie(":/images/ZhongLi.gif");
}

//受损状态转换
void Zhongli::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    /*else if (hp <= 1333 && state != 2)
    {
        state = 2;
        setMovie(":/images/WallNut2.gif");
    }
    else if (1333 < hp && hp <= 2667 && state != 1)
    {
        state = 1;
        setMovie(":/images/WallNut1.gif");
    }*/
    else {;}
}
