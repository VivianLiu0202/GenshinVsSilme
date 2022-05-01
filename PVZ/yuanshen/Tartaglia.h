#ifndef TARTAGLIA_H
#define TARTAGLIA_H

#include "yuanshen.h"
#include "../slime/slime.h"

//达达利亚水弓箭手

class Tartaglia : public yuanshen
{
public:
    Tartaglia();
    QRectF boundingRect() const override;
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // TARTAGLIA_H
