#include "Klee.h"

Klee::Klee()
{
    atk = atk_Klee;
    hp = hp_NormalYuanshen;
    time = int(1.4 * 1000 / 33);
    setMovie(":/images/Klee.gif");
    setSound((":/images/KleeJoin.wav"));
}

void Klee::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if (!collidingItems().isEmpty())
        {
            ATK *pea = new ATK(atk,ElementState::FIRE);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool Klee::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Slime::Type && qFuzzyCompare(other->y(), y());
}
