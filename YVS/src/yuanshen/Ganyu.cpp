#include "Ganyu.h"

Ganyu::Ganyu()
{
    atk = atk_Ganyu;
    hp = hp_NormalYuanshen;
    time = int(1.4 * 1000 / 33);
    setMovie(":/images/Ganyu.gif");
    setSound((":/images/GanyuJoin.wav"));
}

void Ganyu::advance(int phase)
{
    if (!phase) return;
    update();
    if (hp <= 0) delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            Pea *pea = new Pea(atk, ElementState::SNOW);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool Ganyu::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Slime::Type && qFuzzyCompare(other->y(), y());
}
