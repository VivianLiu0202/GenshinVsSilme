#include "atk.h"

//攻击

ATK::ATK(int attack, ElementState flag)
{
    switch(flag)
    {
    case ElementState::SNOW:
    {
        snow=true;
        break;
    }
    case ElementState::WATER:
    {
        water=true;
        break;
    }
    case ElementState::FIRE:
    {
        fire=true;
        break;
    }
    case ElementState::WIND:
    {
        wind=true;
        break;
    }
    case ElementState::GRASS: ;
    case ElementState::THUNDER: ;
    }

    atk = attack;
    speed = 360.0 * 40 / 1000;
}

ATK::~ATK()
{
    snow=false;
    water=false;
    fire=false;
    wind=false;
}

QRectF ATK::boundingRect() const
{
    return QRectF(-12, -28, 24, 24);
}
//绘制攻击
void ATK::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    QString path;
    if(water)
    {
        path=":/images/ShuiPea.png";
    }
    if(fire)
    {
        path=":/images/KleeBoom.png";
    }
    if(wind)
    {
        path=":/images/FengPea.png";
    }
    if(snow)
    {
        path=":/images/BingPea.png";
    }
    painter->drawPixmap(QRect(-12, -28, 30, 30), QPixmap(path));
}

//碰撞检测
bool ATK::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Slime::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

//完成行动和状态转移
void ATK::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Slime *slime = qgraphicsitem_cast<Slime *>(items[qrand() % items.size()]);


        //元素反应数值系统
        if(water && slime->now==ElementState::SNOW)
        {
            if(slime->speed > 0.55) slime->speed /= 2;
        }
        if(water && slime->now==ElementState::WATER) slime->hp-=0;
        if(water && slime->now==ElementState::FIRE) slime->hp-=atk*1.5;
        if(water && slime->now==ElementState::WIND) slime->hp-=atk+50;//扩散50
        if(water && slime->now==ElementState::THUNDER) slime->hp-=75;
        if(water && slime->now==ElementState::GRASS) slime->hp-=atk;


        if(snow && slime->now==ElementState::SNOW) slime->hp-=0;
        if(snow && slime->now==ElementState::WATER)
        {
            if(slime->speed > 0.55) slime->speed /= 2;
        }
        if(snow && slime->now==ElementState::FIRE) slime->hp-=atk*1.5;
        if(snow && slime->now==ElementState::WIND) slime->hp-=atk+50;
        if(snow && slime->now==ElementState::THUNDER) slime->hp-=75;
        if(snow && slime->now==ElementState::GRASS) slime->hp-=atk;


        if(fire && slime->now==ElementState::SNOW) slime->hp-=atk*2;
        if(fire && slime->now==ElementState::WATER) slime->hp-=atk*2;
        if(fire && slime->now==ElementState::FIRE) slime->hp-=0;
        if(fire && slime->now==ElementState::WIND) slime->hp-=atk+50;
        if(fire && slime->now==ElementState::THUNDER) slime->hp-=75;
        if(fire && slime->now==ElementState::GRASS)
        {
            slime->hp-=100;
        }


        if(wind && slime->now==ElementState::SNOW) slime->hp-=atk+50;
        if(wind && slime->now==ElementState::WATER) slime->hp-=atk+50;
        if(wind && slime->now==ElementState::FIRE) slime->hp-=atk+50;
        if(wind && slime->now==ElementState::WIND) slime->hp-=atk+50;
        if(wind && slime->now==ElementState::THUNDER) slime->hp-=atk+50;
        if(wind && slime->now==ElementState::GRASS) slime->hp-=atk;

        snow=false;
        water=false;
        fire=false;
        wind=false;
        delete this;
        return ;
    }
    setX(x() + speed);
    if (x() > 1069) delete this;
}
