#ifndef REAPTER_H
#define REAPTER_H

#include "plant.h"
#include "../zombie/zombie.h"
#include "../other/pea.h"

//可莉火法
class Repeater : public Plant
{
public:
    Repeater();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // REAPTER_H
