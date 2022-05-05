#ifndef VENTI_H
#define VENTI_H

#include "yuanshen.h"
#include "../slime/slime.h"
#include "../other/pea.h"

//温迪风弓箭手

class Venti : public yuanshen
{
public:
    Venti();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};
#endif // VENTI_H
