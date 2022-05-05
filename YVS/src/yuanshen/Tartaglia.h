#ifndef TARTAGLIA_H
#define TARTAGLIA_H

#include "yuanshen.h"
#include "../slime/slime.h"
#include "../other/pea.h"

//达达利亚水弓箭手

class Tartaglia : public yuanshen
{
public:
    Tartaglia();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // TARTAGLIA_H
