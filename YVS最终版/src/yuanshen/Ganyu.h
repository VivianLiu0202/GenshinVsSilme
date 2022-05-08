#ifndef GANYU_H
#define GANYU_H

#include "yuanshen.h"
#include "../slime/slime.h"
#include "../other/atk.h"

//甘雨冰弓箭手

class Ganyu : public yuanshen
{
public:
    Ganyu();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};
#endif // GANYU_H
