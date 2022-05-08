#include "ZhongLi.h"
#include <QDebug>

Zhongli::Zhongli()
{
    hp = hp_Zhongli;
    setMovie(":/images/ZhongLi.gif");
    setSound((":/images/ZhongLiJoin.wav"));
}

//受损状态转换
void Zhongli::advance(int phase)
{
    if (!phase) return;
    update();
    if (hp <= 0) delete this;
    else {;}
}
