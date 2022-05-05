#include "Cyro.h"

//普通史莱姆类
//有4种状态，行走，攻击，死亡，被烧焦

Cyro::Cyro()
{
    hp = hp_Cyro;
    atk = atk_Slime;
    speed = speed_slime_1;
    now = ElementState::SNOW;
    setMovie(":/images/bingslm.gif");
}

//僵尸的状态变化
void Cyro::advance(int phase)
{
    if (!phase)
        return;
    update();


    QList<QGraphicsItem *> items = collidingItems();

    //如果死亡
    if (hp <= 0)
    {
        if (state < SlimeType::DIE)
        {
            state = SlimeType::DIE;
            delete this;
        }
        else if (movie->currentFrameNumber() == movie->frameCount() - 1)
            delete this;
        return;
    }

    //如果发生碰撞
    else if (!items.isEmpty())
    {
        yuanshen *Yuanshen = qgraphicsitem_cast<yuanshen *>(items[0]);
        Yuanshen->hp -= atk;
        if (state != SlimeType::ATTACK)
        {
            state = SlimeType::ATTACK;
            setMovie(":/images/bingslm.gif");
        }
        return;
    }

    //没死，没碰撞，就继续行走
    else
    {
        state = SlimeType::WALK;
        setMovie(":/images/bingslm.gif");

    }

    // 向前移动
    setX(x() - speed);
}
