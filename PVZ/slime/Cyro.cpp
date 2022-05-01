#include "Cyro.h"

//普通僵尸类
//有4种状态，行走，攻击，死亡，被烧焦

Cyro::Cyro()
{
    hp = hp_BasicZombie;
    atk = atk_Zombie;
    speed = speed_zombie_1;
    setMovie(":/images/ZombieWalk1.gif");
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
            setMovie(":/images/ZombieDie.gif");
            setHead(":/images/ZombieHead.gif");
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
            setMovie(":/images/ZombieAttack.gif");
        }
        return;
    }

    //没死，没碰撞，就继续行走
    else
    {
        state = SlimeType::WALK;
        //两个都要可能会显示混乱
        //if (qrand() % 2)
            setMovie(":/images/ZombieWalk1.gif");
        //else
            //setMovie(":/images/ZombieWalk2.gif");
    }

    // 向前移动
    setX(x() - speed);
}
