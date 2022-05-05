#ifndef KLEE_H
#define KLEE_H

#include "yuanshen.h"
#include "../slime/slime.h"
#include "../other/pea.h"

//可莉火法
class Klee : public yuanshen
{
public:
    Klee();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // KLEE_H
