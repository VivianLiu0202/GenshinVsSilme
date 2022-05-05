#ifndef PEA_H
#define PEA_H

#include "other.h"
#include "../slime/slime.h"

//豌豆子弹

class Pea : public Other
{
public:
    Pea(int attack = 0, ElementState flag = ElementState::SNOW);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void advance(int phase) override;
    ~Pea();
private:
    //元素，杀伤力，速度
    bool snow = false;
    bool water = false;
    bool fire = false;
    bool wind = false;
    int atk;
    qreal speed;
};

#endif // PEA_H
