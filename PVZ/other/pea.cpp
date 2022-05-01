#include "pea.h"
#include "../slime/slime.h"

//攻击

Pea::Pea(int attack, bool flag)
{
    snow = flag;
    atk = attack;
    speed = 360.0 * 40 / 1000;
}

QRectF Pea::boundingRect() const
{
    return QRectF(-12, -28, 24, 24);
}
//绘制豌豆子弹
void Pea::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-12, -28, 24, 24), QPixmap(snow ? ":/images/PeaSnow.png" : ":/images/Pea.png"));
}

//碰撞检测
bool Pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Slime::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

//完成行动和状态转移
void Pea::advance(int phase)
{
    if (!phase)
        return;
    update();
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        Slime *slime = qgraphicsitem_cast<Slime *>(items[qrand() % items.size()]);
        slime->hp -= atk;
        //防止给僵尸一直减速
        if (snow && slime->speed > 0.55) slime->speed /= 2;
        delete this;
        return ;
    }
    setX(x() + speed);
    if (x() > 1069) delete this;
}
