#include "Venti.h"

Venti::Venti()
{
    atk = atk_Venti;
    hp = hp_NormalYuanshen;
    time = int(1.4 * 1000 / 33);
    setMovie(":/images/Venti.gif");
    setSound((":/images/VentiJoin.wav"));
}

void Venti::advance(int phase)
{
    if (!phase) return;
    update();
    if (hp <= 0) delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            ATK *pea = new ATK(atk,ElementState::WIND);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return;
        }
    }
}

bool Venti::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == Slime::Type && qFuzzyCompare(other->y(), y());
}
