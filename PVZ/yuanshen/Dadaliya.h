#ifndef POTATOMINE_H
#define POTATOMINE_H

#include "plant.h"
#include "../zombie/zombie.h"

//达达利亚水弓箭手

class PotatoMine : public Plant
{
public:
    PotatoMine();
    QRectF boundingRect() const override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // POTATOMINE_H
