#include "mower.h"

//割草机

Mower::Mower()
{
    flag = false;
    speed = 270.0 * 33 / 1000;
}

QRectF Mower::boundingRect() const
{
    return QRectF(-30, -30, 60, 60);
}

//绘制割草机
void Mower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-30, -30, 60, 60), QPixmap(":/images/LawnMower.png"));
}


//检测碰撞：碰到史莱姆 && 纵坐标一样 && 横坐标接近
bool Mower::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Slime::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

//割草机与史莱姆碰撞，史莱姆死亡

void Mower::advance(int phase)
{
    if (!phase) return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.empty())
    {
        flag = true;
        foreach (QGraphicsItem *item, items)
        {
            Slime *slime = qgraphicsitem_cast<Slime *>(item);
            slime->hp = 0;
        }
    }
    if (flag) setX(x() + speed);
    if (x() > 1069) delete this;
}
