#ifndef XIANGLING_H
#define XIANGLING_H

#include "yuanshen.h"
#include "../slime/slime.h"

//香菱锅巴炸弹

class Xiangling : public yuanshen
{
public:
    Xiangling();
    QRectF boundingRect() const override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // XIANGLING_H
