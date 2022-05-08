#include "Tartaglia.h"

Tartaglia::Tartaglia()
{
    atk = atk_Tartaglia;
    hp = hp_NormalYuanshen;
    time = int(1.4 * 1000 / 33);
    setMovie(":/images/Tartaglia.gif");
    setSound((":/images/TartagliaJoin.wav"));
}

//根据计数器和状态，进行碰撞检测，完成行动和状态转移
void Tartaglia::advance(int phase)
{
    if (!phase) return;
    update();
    if (hp <= 0) delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            ATK *pea = new ATK(atk,ElementState::WATER);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool Tartaglia::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Slime::Type && qFuzzyCompare(other->y(), y());
}

